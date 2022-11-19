#include "editor.h"
#include "ui_editor.h"
#include "defaulttool.h"
#include "movetool.h"
#include "rotatetool.h"
#include "appendtool.h"
#include "deletetool.h"
#include "addroutetool.h"
#include "editroutetool.h"
#include "zoomallcommand.h"
#include "deleteroutecommand.h"
#include "addroutepointtool.h"
#include "deleteroutepointtool.h"
#include <QVector>
#include <QDebug>


Editor::Editor(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Editor)
{
  ui->setupUi(this);

  QList<int> sizes;
  sizes.append(4 * width() / 5);
  sizes.append(width() / 5);
  ui->VerticalSplitter->setSizes(sizes);
  sizes.clear();
  sizes.append(height() / 3);
  sizes.append(height() / 3);
  sizes.append(height() / 3);
  ui->HorizontalSplitter->setSizes(sizes);

  addToolsToToolBar();

  _components.push_back(static_cast<iSceneViewComponent*>(ui->TargetPropertyViewW));
  _components.push_back(static_cast<iSceneViewComponent*>(ui->RoutePropertyViewW));
  _components.push_back(static_cast<iSceneViewComponent*>(ui->ScreenViewW));

  for (auto component : _components)
  {
    component->SetMainService(this);
  }

  _tools.push_back(tool_map(ToolID::Default, ui->default_tool, static_cast<iTool*>(new DefaultTool(this))));
  _tools.push_back(tool_map(ToolID::Move, ui->move_tool, static_cast<iTool*>(new MoveTool(this))));
  _tools.push_back(tool_map(ToolID::Rotate, ui->rotate_tool, static_cast<iTool*>(new RotateTool(this))));
  _tools.push_back(tool_map(ToolID::Add, ui->add_ship_tool, static_cast<iTool*>(new AppendTool(this))));
  _tools.push_back(tool_map(ToolID::Delete, ui->delete_ship_tool, static_cast<iTool*>(new DeleteTool(this))));
  _tools.push_back(tool_map(ToolID::AddRoute, ui->add_route_tool, static_cast<iTool*>(new AddRouteTool(this))));
  _tools.push_back(tool_map(ToolID::DeleteRoutePoint, ui->edit_route_tool, static_cast<iTool*>(new DeleteRoutePointTool(this))));
  _tools.push_back(tool_map(ToolID::EditRoute, ui->edit_route_tool, static_cast<iTool*>(new EditRouteTool(this))));
  _tools.push_back(tool_map(ToolID::AddRoutePoint, ui->edit_route_tool, static_cast<iTool*>(new AddRoutePointTool(this))));

  _commands.push_back(command_map(CommandID::ZoomAll, ui->zoom_all_command, static_cast<iCommand*>(new ZoomAllCommand(this))));
  _commands.push_back(command_map(CommandID::DeleteRoute, ui->delete_route_command, static_cast<iCommand*>(new DeleteRouteCommand(this))));

  activateTool(ToolID::Default);
  SetDefaultTool();
  ui->statusbar->showMessage("DefaultTool");

  ui->add_route_tool->setDisabled(true);
  ui->delete_route_command->setDisabled(true);
  ui->edit_route_tool->setDisabled(true);

}

Editor::~Editor()
{
  delete ui;
}

void Editor::LoadScenario(const Scenario::scenario_data& scenario)
{
  _scenario = scenario;
  for (auto component : _components)
    component->SetScenario(&_scenario);
  //из-за бага сраного((
  ui->default_tool->setCheckable(true);
  ui->default_tool->setChecked(true);
}

void Editor::ChangeScenario(const QString &sender_name)
{
  updateRouteTools();

  for (auto component : _components)
  {
    if (sender_name != component->GetName())
      component->ScenarioChanged();
  }
}

void Editor::ChangeSelection(selection_data& selection_d)
{
  _current_selected_ship = selection_d.ship_id;
  updateRouteTools();

  for (auto component : _components)
    component->SelectionChanged(selection_d);
}

void Editor::ChangeWindow()
{
  for (auto component : _components)
    component->WindowChanged();

  QList<int> sizes;
  sizes.append(6 * width() / 7);
  sizes.append(width() / 7);
  ui->VerticalSplitter->setSizes(sizes);
}

Scenario::scenario_data* Editor::GetScenario()
{
  return &_scenario;
}

iScreenViewService* Editor::GetScreenViewService() const
{
  return static_cast<iScreenViewService*>(ui->ScreenViewW);
}

iTool* Editor::GetActiveTool() const
{
  for (const tool_map & t : _tools)
    if (t.tool->IsActive())
      return t.tool;

  return nullptr;
}

iEditorProject* Editor::GetProjectService() const
{
  return static_cast<iEditorProject*>(ui->ScreenViewW);
}


void Editor::activateTool(ToolID toolId)
{
  if (GetActiveTool() != nullptr)
  {
    if (getActiveToolID() != ToolID::Unknown)
    {
      for (tool_map& t : _tools)
      {
        if (getActiveToolID() == t.id)
          t.ui_tool->setChecked(false);
      }
    }
    GetActiveTool()->DeActivate();
  }

  for (tool_map& t : _tools)
  {
    if (toolId == t.id)
      t.tool->Activate();
  }
}

void Editor::doCommand(CommandID commandId)
{
  for (command_map& c : _commands)
  {
    if (commandId == c.id)
      c.command->DoCommand(_current_selected_ship);
    repaint();
  }
}

void Editor::updateRouteTools()
{
  if (_current_selected_ship != -1)
  {
    if (_scenario.targets[_current_selected_ship].route_points_vector.size() != 0)
    {
      ui->add_route_tool->setDisabled(true);
      ui->delete_route_command->setDisabled(false);
      ui->edit_route_tool->setDisabled(false);
    }
    else
    {
      ui->add_route_tool->setDisabled(false);
      ui->delete_route_command->setDisabled(true);
      ui->edit_route_tool->setDisabled(true);
    }
  }
  else
  {
    ui->add_route_tool->setDisabled(true);
    ui->delete_route_command->setDisabled(true);
    ui->edit_route_tool->setDisabled(true);
  }
}

void Editor::addToolsToToolBar()
{
  ui->default_tool->setIcon(QIcon(":/toolButton/res/default_tool.png"));
  ui->toolBar->addWidget(ui->default_tool);
  ui->move_tool->setIcon(QIcon(":/toolButton/res/move_tool.png"));
  ui->toolBar->addWidget(ui->move_tool);
  ui->rotate_tool->setIcon(QIcon(":/toolButton/res/rotate_tool.png"));
  ui->toolBar->addWidget(ui->rotate_tool);
  ui->zoom_all_command->setIcon(QIcon(":/toolButton/res/zoom_all_command.png"));
  ui->toolBar->addWidget(ui->zoom_all_command);
  ui->add_ship_tool->setIcon(QIcon(":/toolButton/res/add_ship_tool.png"));
  ui->toolBar->addWidget(ui->add_ship_tool);
  ui->delete_ship_tool->setIcon(QIcon(":/toolButton/res/delete_ship_tool.png"));
  ui->toolBar->addWidget(ui->delete_ship_tool);
  ui->add_route_tool->setIcon(QIcon(":/toolButton/res/add_route_tool.png"));
  ui->toolBar->addWidget(ui->add_route_tool);
  ui->delete_route_command->setIcon(QIcon(":/toolButton/res/delete_route_command.png"));
  ui->toolBar->addWidget(ui->delete_route_command);

  QMenu* edit_route_menu = new QMenu;
  edit_route_menu->addAction(ui->add_route_point_tool);
  edit_route_menu->addAction(ui->delete_route_point_tool);
  edit_route_menu->addAction(ui->edit_route_point_tool);

  QString  menuStyle(
    "QMenu"
    "{"
      "background-color: rgb(30, 33, 39);"
      "color: rgb(255, 255, 255);"
    "}"
    "QMenu::item"
    "{"
      "background-color: transparent;"
      "padding-left: 30px;"
      "padding-right: 15px;"
      "padding-top: 3px;"
      "padding-bottom: 3px;"
      "border-radius: 6;"
      "color:rgb(255, 255, 255);"
    "}"
    "QMenu::item:selected"
    "{"
      "border:2px solid rgb(2, 191, 150);"
      "color:rgb(255, 255, 255);"
    "}");
  edit_route_menu->setStyleSheet(menuStyle);
  QFont f("Bahnschrift Light Condensed", 11);
  edit_route_menu->setFont(f);
  ui->edit_route_tool->setMenu(edit_route_menu);
  ui->edit_route_tool->setDefaultAction(ui->edit_route_point_tool);
  ui->toolBar->addWidget(ui->edit_route_tool);
}

ToolID Editor::getActiveToolID()
{
  for (tool_map& t : _tools)
  {
    if (t.tool->IsActive())
      return t.id;
  }
  return ToolID::Unknown;
}

void Editor::SetDefaultTool()
{
  activateTool(ToolID::Default);
  updateRouteTools();
  ui->default_tool->setChecked(true);
  ui->statusbar->showMessage("DefaultTool");
}

void Editor::resizeEvent(QResizeEvent * /* event */)
{
  ChangeWindow();
}

void Editor::on_default_tool_clicked()
{
  activateTool(ToolID::Default);
  ui->default_tool->setChecked(true);
  ui->statusbar->showMessage("DefaultTool");
}

void Editor::on_move_tool_clicked()
{
  activateTool(ToolID::Move);
  ui->move_tool->setChecked(true);
  ui->statusbar->showMessage("MoveTool");
}

void Editor::on_rotate_tool_clicked()
{
  activateTool(ToolID::Rotate);
  ui->rotate_tool->setChecked(true);
  ui->statusbar->showMessage("RotateTool");
}

void Editor::on_zoom_all_command_clicked()
{
  doCommand(CommandID::ZoomAll);
  SetDefaultTool();
  ChangeScenario("a");
}

void Editor::on_add_ship_tool_clicked()
{
  activateTool(ToolID::Add);
  ui->add_ship_tool->setChecked(true);
  ui->statusbar->showMessage("AddTool");
}

void Editor::on_delete_ship_tool_clicked()
{
  activateTool(ToolID::Delete);
  ui->delete_ship_tool->setChecked(true);
  ui->statusbar->showMessage("DeleteTool");
}

void Editor::on_add_route_tool_clicked()
{
  activateTool(ToolID::AddRoute);
  ui->add_route_tool->setChecked(true);
  ui->statusbar->showMessage("AddRouteTool");
}

void Editor::on_delete_route_command_clicked()
{
  doCommand(CommandID::DeleteRoute);
  SetDefaultTool();
  ChangeScenario("a");
}

void Editor::on_edit_route_tool_clicked()
{
  ui->edit_route_tool->setChecked(true);
}

void Editor::on_edit_route_point_tool_triggered()
{
  activateTool(ToolID::EditRoute);
  ui->edit_route_tool->setChecked(true);
  ui->statusbar->showMessage("EditRouteTool");
}

void Editor::on_add_route_point_tool_triggered()
{
  activateTool(ToolID::AddRoutePoint);
  ui->edit_route_tool->setChecked(true);
  ui->statusbar->showMessage("AddRoutePoint");
}

void Editor::on_delete_route_point_tool_triggered()
{
  activateTool(ToolID::DeleteRoutePoint);
  ui->edit_route_tool->setChecked(true);
  ui->statusbar->showMessage("DeleteRoutePoint");
}

void Editor::on_save_command_triggered()
{
  write_json_to_file(save_object_to_json(_scenario), "H:/Nikon/proging/cpp/bip/Data/Scenarios/scenario_4.json");
}

void Editor::on_load_command_triggered()
{
  Scenario::scenario_data s = load_object_from_json<Scenario::scenario_data>(
        read_json_from_file("H:/Nikon/proging/cpp/bip/Data/Scenarios/scenario_4.json"));

  _scenario = s;
  for (auto component : _components)
    component->SetScenario(&_scenario);
}
