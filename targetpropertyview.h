#ifndef TARGETPROPERTYVIEW_H
#define TARGETPROPERTYVIEW_H

#include <QWidget>
#include "interfacesceneview.h"
#include "editormath.h"
#include <QLabel>
#include <QDoubleValidator>

namespace Ui {
  class TargetPropertyView;
}

class TargetPropertyView : public QWidget, public iSceneViewComponent
{
  Q_OBJECT

public:
  explicit TargetPropertyView(QWidget *parent = 0);
  ~TargetPropertyView();

private slots:
  void on_BearingDistanceRadioButton_clicked();
  void on_XYRadioButton_clicked();
  void on_XBearingLineEdit_editingFinished();
  void on_YDistanceLineEdit_editingFinished();
  void on_TargetNameLineEdit_editingFinished();
  void on_SpeedLineEdit_editingFinished();
  void on_TargetCourseLineEdit_editingFinished();

private:
  void SetMainService(iMainService* i_main_service) override final;
  void SetScenario(Scenario::scenario_data *scenario) override final;
  void ScenarioChanged() override final;
  void SelectionChanged(selection_data& selection_d) override final;
  void WindowChanged() override final;
  QString GetName() const override final;
  void hideAllElements();
  void showAllElements();
  void coordEditingFinished();

private:
  Ui::TargetPropertyView *ui;
  iMainService* _main_service;
  Scenario::scenario_data* _scenario;
  Scenario::target _selected_ship;
  int _cur_selected_ship;
  QLabel* _hide_label;
};

#endif // TARGETPROPERTYVIEW_H
