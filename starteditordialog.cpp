#include "starteditordialog.h"
#include "ui_starteditordialog.h"
#include "editor.h"

StartEditorDialog::StartEditorDialog(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::StartEditorDialog)
{
  ui->setupUi(this);
  ui->delete_scenario_button->setDisabled(true);
  ui->edit_scenario_button->setDisabled(true);
}

StartEditorDialog::~StartEditorDialog()
{
  delete ui;
}

void StartEditorDialog::SetScenarios(const QVector<Scenario::scenario_data> scenarios)
{
  _scenarios = scenarios;
  ui->scenarios_widget->clear();
  for (int i = 0; i < _scenarios.size(); i++)
    ui->scenarios_widget->addItem(_scenarios[i].name);
}

void StartEditorDialog::on_scenarios_widget_itemClicked(QListWidgetItem *item)
{
  ui->delete_scenario_button->setDisabled(false);
  ui->edit_scenario_button->setDisabled(false);
}

void StartEditorDialog::on_delete_scenario_button_clicked()
{
  QString scenario_for_delete_name = ui->scenarios_widget->selectedItems()[0]->text();
}

void StartEditorDialog::on_create_scenario_button_clicked()
{
  _editor.setWindowModality(Qt::ApplicationModal);
  _editor.show();
}

void StartEditorDialog::on_edit_scenario_button_clicked()
{
  Scenario::scenario_data selected_scenario;
  for (int i = 0; i < _scenarios.size(); i++)
  {
    if (_scenarios[i].name == ui->scenarios_widget->selectedItems()[0]->text())
      selected_scenario = _scenarios[i];
  }
  //_editor.LoadScenario(selected_scenario);
  _editor.setWindowModality(Qt::ApplicationModal);
  _editor.show();
}
