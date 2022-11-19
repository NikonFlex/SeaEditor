#ifndef STARTEDITORDIALOG_H
#define STARTEDITORDIALOG_H

#include <QMainWindow>
#include "editor.h"
#include <QListWidget>

namespace Ui {
  class StartEditorDialog;
}

class StartEditorDialog : public QMainWindow
{
  Q_OBJECT

public:
  explicit StartEditorDialog(QWidget *parent = 0);
  ~StartEditorDialog();
  void SetScenarios(const QVector<Scenario::scenario_data> scenarios);

private slots:
  void on_scenarios_widget_itemClicked(QListWidgetItem *item);
  void on_delete_scenario_button_clicked();
  void on_create_scenario_button_clicked();
  void on_edit_scenario_button_clicked();

private:
  Ui::StartEditorDialog *ui;
  QVector<Scenario::scenario_data> _scenarios;
  Editor _editor;
};

#endif // STARTEDITORDIALOG_H
