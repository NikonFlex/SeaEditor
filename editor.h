#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QToolButton>
#include "screenview.h"
#include "interfacesceneview.h"
#include "interfacetool.h"
#include "interfacecommand.h"

namespace Ui
{
  class Editor;
}


enum class ToolID
{
  Default = 0,
  Rotate = 1,
  Move = 2,
  Add = 3,
  Delete = 4,
  AddRoute = 5,
  EditRoute = 7,
  AddRoutePoint = 8,
  DeleteRoutePoint = 9,
  Unknown = 10
};

enum class CommandID
{
  ZoomAll = 0,
  DeleteRoute = 1,
  Unknown = 2
};

struct tool_map
{
  tool_map() = default;
  tool_map(ToolID id_, QToolButton* ui_tool_, iTool* tool_) : id(id_), ui_tool(ui_tool_), tool(tool_){}
  ToolID id = ToolID::Unknown;
  QToolButton* ui_tool = nullptr;
  iTool* tool = nullptr;
};

struct command_map
{
  command_map() = default;
  command_map(CommandID id_, QToolButton* ui_command_, iCommand* command_) : id(id_), ui_command(ui_command_), command(command_){}
  CommandID id = CommandID::Unknown;
  QToolButton* ui_command = nullptr;
  iCommand* command = nullptr;
};

class Editor : public QMainWindow, public iMainService
{
  Q_OBJECT

public:
  explicit Editor(QWidget *parent = 0);
  ~Editor();
  void LoadScenario(const Scenario::scenario_data& scenario);

private slots:
  //void on_default_tool_clicked();
  void on_move_tool_clicked();
  void on_rotate_tool_clicked();
  void on_add_ship_tool_clicked();
  void on_zoom_all_command_clicked();
  void on_delete_ship_tool_clicked();
  void on_add_route_tool_clicked();
  void on_delete_route_command_clicked();
  void on_edit_route_point_tool_triggered();
  void on_add_route_point_tool_triggered();
  void on_delete_route_point_tool_triggered();
  void on_save_command_triggered();
  void on_load_command_triggered();
  void on_edit_route_tool_clicked();

  void on_default_tool_clicked();

private:
  // iMainService implementation
  void ChangeScenario(const QString& sender_name) override final;
  void ChangeSelection(selection_data& selection_d) override final;
  void ChangeWindow() override final;
  Scenario::scenario_data* GetScenario() override final;
  iScreenViewService* GetScreenViewService() const override final;
  iTool* GetActiveTool() const override final;
  iEditorProject* GetProjectService() const override final;
  void SetDefaultTool() override final;

  void activateTool(ToolID toolId);
  void doCommand(CommandID commandId);
  void deActivateUITools(ToolID activated_tool_id);
  void updateRouteTools();
  void addToolsToToolBar();
  ToolID getActiveToolID();

protected:
  void resizeEvent(QResizeEvent * /* event */);

private:
  Ui::Editor *ui;
  QVector<iSceneViewComponent*> _components;
  Scenario::scenario_data _scenario;
  QVector<tool_map> _tools;
  QVector<command_map> _commands;
  int _current_selected_ship = -1;
};

#endif // EDITOR_H
