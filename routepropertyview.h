#ifndef ROUTEPROPERTYVIEW_H
#define ROUTEPROPERTYVIEW_H

#include "interfacesceneview.h"
#include <QWidget>
#include <QStandardItem>

namespace Ui {
  class RoutePropertyView;
}

class RoutePropertyView : public QWidget, public iSceneViewComponent
{
  Q_OBJECT

public:
  explicit RoutePropertyView(QWidget *parent = 0);
  ~RoutePropertyView();

private slots:
  void on_XLineEdit_editingFinished();
  void on_YLineEdit_editingFinished();

private:
  void SetMainService(iMainService* i_main_service) override final;
  void SetScenario(Scenario::scenario_data *scenario) override final;
  void ScenarioChanged() override final;
  void SelectionChanged(selection_data &selection_d) override final;
  void WindowChanged() override final;
  QString GetName() const override final;

  void hideSelectedPointProperty();
  void showSelectedPointProperty();
  void hideRouteProperty();
  void showRouteProperty();
  int distBetweenPoints(const point_xy& p1,const point_xy& p2);
  int calculateRouteLength(const Scenario::target& target);
  QString calculateRouteTime(const Scenario::target& target);
  void coordEditingFinished();

private:
  Ui::RoutePropertyView *ui;
  iMainService* _main_service;
  Scenario::scenario_data* _scenario;
  QVector<Point> _points_list;
  QStandardItemModel *_model = new QStandardItemModel;
  QLabel* _route_property_hide_label;
  QLabel* _selected_point_hide_label;
  selection_data _selection_d;
};

#endif // ROUTEPROPERTYVIEW_H
