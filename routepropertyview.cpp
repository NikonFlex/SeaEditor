#include "routepropertyview.h"
#include "ui_routepropertyview.h"
#include "scenarioeditutils.h"

RoutePropertyView::RoutePropertyView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RoutePropertyView)
{
  ui->setupUi(this);

  _selected_point_hide_label = new QLabel(this);
  _selected_point_hide_label->setGeometry(0, 180, 500, 500);
  _selected_point_hide_label->setStyleSheet("background-color:rgb(30, 33, 39)");

  _route_property_hide_label = new QLabel(this);
  _route_property_hide_label->setGeometry(0, 60, 500, 120);
  _route_property_hide_label->setStyleSheet("background-color:rgb(30, 33, 39)");

  //ограничение ввода букв
  QDoubleValidator* validator =  new QDoubleValidator(0, 1000000, 5, this);
  ui->XLineEdit->setValidator(validator);
  ui->YLineEdit->setValidator(validator);

  hideSelectedPointProperty();
  hideRouteProperty();
}

RoutePropertyView::~RoutePropertyView()
{
  delete ui;
}

void RoutePropertyView::SetMainService(iMainService *i_main_service)
{
  _main_service = i_main_service;
}

void RoutePropertyView::SetScenario(Scenario::scenario_data *scenario)
{
  _scenario = scenario;
}

void RoutePropertyView::ScenarioChanged()
{
  if (_selection_d.ship_id != -1)
  {
    _points_list.clear();
    Scenario::target trg = find_target(_scenario->targets, _selection_d.ship_id);
    QVector<point_xy> route_points = trg.route_points_vector;
    if (route_points.size() == 0)
    {
      hideSelectedPointProperty();
      ui->PointsNumberLabel->setText("маршрут не построен");
      ui->RouteLengthLabel->setText("маршрут не построен");
      ui->RouteTimeLabel->setText("маршрут не построен");
    }
    else
    {
      for (auto p : route_points)
      {
        _points_list.append(Point(p.x, p.y));
      }
      ui->PointsNumberLabel->setText(QString::number(_points_list.size()));
      ui->RouteLengthLabel->setText(QString::number(calculateRouteLength(trg)));
      ui->RouteTimeLabel->setText(calculateRouteTime(trg));
      showRouteProperty();

      if (_selection_d.route_point != -1 && _points_list.size() != 0)
      {
        ui->XLineEdit->setText(QString::number(_points_list[_selection_d.route_point].x));
        ui->YLineEdit->setText(QString::number(_points_list[_selection_d.route_point].y));
        ui->PointPosLabel->setText((QString::number(_selection_d.route_point + 1)));
        showSelectedPointProperty();
      }
      else
      {
        hideSelectedPointProperty();
      }
    }
  }
  else
  {
    hideSelectedPointProperty();
    hideRouteProperty();
  }
}

void RoutePropertyView::SelectionChanged(selection_data& selection_d)
{
  _selection_d = selection_d;

  _points_list.clear();
  if (_selection_d.ship_id != -1)
  {
    Scenario::target trg = find_target(_scenario->targets, _selection_d.ship_id);
    QVector<point_xy> route_points = trg.route_points_vector;
    for (auto p : route_points)
      _points_list.append(Point(p.x, p.y));

    ui->PointsNumberLabel->setText(QString::number(_points_list.size()));
    ui->RouteLengthLabel->setText(QString::number(calculateRouteLength(trg)));
    ui->RouteTimeLabel->setText(calculateRouteTime(trg));
    showRouteProperty();

    if (_points_list.size() != 0 && _selection_d.route_point != -1)
    {
      ui->XLineEdit->setText(QString::number(_points_list[_selection_d.route_point].x));
      ui->YLineEdit->setText(QString::number(_points_list[_selection_d.route_point].y));
      ui->PointPosLabel->setText((QString::number(_selection_d.route_point + 1)));
      showSelectedPointProperty();
    }
    else
    {
      hideSelectedPointProperty();
    }
  }
  else
  {
    hideSelectedPointProperty();
    hideRouteProperty();
  }
}

void RoutePropertyView::WindowChanged()
{

}

QString RoutePropertyView::GetName() const
{
  return QString("RoutePropertyView");
}

void RoutePropertyView::hideSelectedPointProperty()
{
  _selected_point_hide_label->show();
}

void RoutePropertyView::showSelectedPointProperty()
{
  _selected_point_hide_label->hide();
}

void RoutePropertyView::hideRouteProperty()
{
  _route_property_hide_label->show();
}

void RoutePropertyView::showRouteProperty()
{
  _route_property_hide_label->hide();
}

int RoutePropertyView::distBetweenPoints(const point_xy &p1, const point_xy &p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int RoutePropertyView::calculateRouteLength(const Scenario::target &target)
{
  QVector<point_xy> route_points = target.route_points_vector;
  Point ship_xy = ConvertToPoint(DistanceBearing(target.distance, target.bearing));
  route_points.push_front(point_xy(ship_xy.x, ship_xy.y));

  int length = 0;
  for (int i = 1; i < route_points.size(); ++i)
    length += distBetweenPoints(route_points[i - 1],route_points[i]);

  return length;
}

QString RoutePropertyView::calculateRouteTime(const Scenario::target &target)
{
  int length = calculateRouteLength(target);
  int sec;
  if (target.speed != 0)
    sec = length / target.speed;
  else
    return QString("скорость не определена");

  int hour, min, s;
  hour = sec / 3600;
  QString str_hour = QString::number(hour);
  min = (sec - hour * 3600) / 60;
  QString str_min = min > 9 ? QString::number(min) : "0" + QString::number(min);
  s = sec - hour * 3600 - min * 60;
  QString str_s = s > 9 ? QString::number(s) : "0" + QString::number(s);
  return QString(str_hour + ":" + str_min + ":" + str_s);
}

void RoutePropertyView::coordEditingFinished()
{
  auto target = find_target(_scenario->targets, _selection_d.ship_id);
  QVector<point_xy> route_points = target.route_points_vector;

  route_points[_selection_d.route_point].x = ui->XLineEdit->text().toDouble();
  route_points[_selection_d.route_point].y = ui->YLineEdit->text().toDouble();
  target.route_points_vector = route_points;

  for (Scenario::target& trg : _scenario->targets)
  {
    if (trg.id == target.id)
      trg = target;
  }
  _main_service->ChangeScenario(GetName());
}

void RoutePropertyView::on_XLineEdit_editingFinished()
{
  coordEditingFinished();
}

void RoutePropertyView::on_YLineEdit_editingFinished()
{
  coordEditingFinished();
}
