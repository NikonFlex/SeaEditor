#include "targetpropertyview.h"
#include "ui_targetpropertyview.h"
#include "geodesy_helper.h"
#include "scenarioeditutils.h"
#include <QDebug>

TargetPropertyView::TargetPropertyView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TargetPropertyView)
{
  ui->setupUi(this);
  ui->XYRadioButton->setChecked(true);
  ui->XBearingLabel->setText("X");
  ui->YDistanceLabel->setText("Y");
  _hide_label = new QLabel(this);
  _hide_label->setGeometry(0, 45, 500, 500);
  _hide_label->setStyleSheet("background-color:rgb(30, 33, 39)");

  //ограничение ввода букв
  QDoubleValidator* validator =  new QDoubleValidator(0, 1000000, 5, this);
  ui->SpeedLineEdit->setValidator(validator);
  ui->TargetCourseLineEdit->setValidator(validator);
  ui->XBearingLineEdit->setValidator(validator);
  ui->YDistanceLineEdit->setValidator(validator);

  hideAllElements();
}

TargetPropertyView::~TargetPropertyView()
{
  delete ui;
}

void TargetPropertyView::SetMainService(iMainService *i_main_service)
{
  _main_service = i_main_service;
}

void TargetPropertyView::SetScenario(Scenario::scenario_data *scenario)
{
  _scenario = scenario;
}

void TargetPropertyView::ScenarioChanged()
{
  if (_selected_ship.id == -1)
    return;

  _selected_ship = find_target(_scenario->targets, _selected_ship.id);

  ui->TargetCourseLineEdit->setText(QString::number(_selected_ship.course, 'g', 5));
  ui->SpeedLineEdit->setText(QString::number(_selected_ship.speed, 'g', 5));
  ui->TargetNameLineEdit->setText(_selected_ship.model_name);

  if (ui->XYRadioButton->isChecked())
  {
//    point_geo ship_geo_pos = geo_offset(_scenario->base_point, _scenario->targets[_selection_d.current_selected_target].bearing, _scenario->targets[_selection_d.current_selected_target].distance);
//    QPointF ship_xy = to_meters(ship_geo_pos, _scenario->base_point);

    Point ship_xy = ConvertToPoint(DistanceBearing(_selected_ship.distance, _selected_ship.bearing));

    ui->XBearingLineEdit->setText(QString::number(ship_xy.x, 'g', 5));
    ui->YDistanceLineEdit->setText(QString::number(ship_xy.y, 'g', 5));
  }
  else
  {
    ui->XBearingLineEdit->setText(QString::number(_selected_ship.bearing, 'g', 5));
    ui->YDistanceLineEdit->setText(QString::number(_selected_ship.distance, 'g', 5));
  }
}

void TargetPropertyView::SelectionChanged(selection_data &selection_d)
{
  if (selection_d.ship_id == -1)
  {
    hideAllElements();
    return;
  }

  showAllElements();

  _selected_ship = find_target(_scenario->targets, selection_d.ship_id);

  if (ui->BearingDistanceRadioButton->isChecked())
  {
    ui->XBearingLineEdit->setText(QString::number(_selected_ship.bearing, 'g', 5));
    ui->YDistanceLineEdit->setText(QString::number(_selected_ship.distance, 'g', 5));
  }
  else
  {
//      point_geo ship_geo_pos = geo_offset(_scenario->base_point, _selected_ship.bearing, _selected_ship.distance);
//      QPointF ship_xy = to_meters(ship_geo_pos, _scenario->base_point);

    Point ship_xy = ConvertToPoint(DistanceBearing(_selected_ship.distance, _selected_ship.bearing));

    ui->XBearingLineEdit->setText(QString::number(ship_xy.x, 'g', 5));
    ui->YDistanceLineEdit->setText(QString::number(ship_xy.y, 'g', 5));
  }


  ui->TargetCourseLineEdit->setText(QString::number(_selected_ship.course, 'g', 5));
  ui->SpeedLineEdit->setText(QString::number(_selected_ship.speed, 'g', 5));
  ui->TargetNameLineEdit->setText(_selected_ship.model_name);
}

void TargetPropertyView::WindowChanged(){}

QString TargetPropertyView::GetName() const
{
  return QString("TargetPropertyView");
}

void TargetPropertyView::showAllElements()
{
  _hide_label->hide();
}

void TargetPropertyView::hideAllElements()
{
  _hide_label->show();
}

void TargetPropertyView::on_BearingDistanceRadioButton_clicked()
{
  ui->XBearingLabel->setText("Пелленг");
  ui->YDistanceLabel->setText("Дистанция");
  ui->XBearingLineEdit->setText(QString::number(_selected_ship.bearing, 'g', 5));
  ui->YDistanceLineEdit->setText(QString::number(_selected_ship.distance, 'g', 5));
}

void TargetPropertyView::on_XYRadioButton_clicked()
{
//  point_geo ship_geo_pos = geo_offset(_scenario->base_point, _selected_ship.bearing, _selected_ship.distance);
//  QPointF ship_xy = to_meters(ship_geo_pos, _scenario->base_point);
  Point ship_xy = ConvertToPoint(DistanceBearing(_selected_ship.distance, _selected_ship.bearing));

  ui->XBearingLabel->setText("X");
  ui->YDistanceLabel->setText("Y");
  ui->XBearingLineEdit->setText(QString::number(ship_xy.x, 'g', 5));
  ui->YDistanceLineEdit->setText(QString::number(ship_xy.y, 'g', 5));
}

void TargetPropertyView::coordEditingFinished()
{
  auto target = find_target(_scenario->targets, _selected_ship.id);

  if (ui->BearingDistanceRadioButton->isChecked())
  {
    target.bearing = ui->XBearingLineEdit->text().toDouble();
    target.distance = ui->YDistanceLineEdit->text().toDouble();
  }
  else
  {
    DistanceBearing ship_distance_bearing(Point(ui->XBearingLineEdit->text().toDouble(), ui->YDistanceLineEdit->text().toDouble()));

    target.bearing = ship_distance_bearing.bearing;
    target.distance = ship_distance_bearing.distance;
  }
  _selected_ship = target;
  for (Scenario::target& trg : _scenario->targets)
  {
    if (trg.id == target.id)
      trg = target;
  }
  _main_service->ChangeScenario(GetName());
}

void TargetPropertyView::on_XBearingLineEdit_editingFinished()
{
  coordEditingFinished();
}

void TargetPropertyView::on_YDistanceLineEdit_editingFinished()
{
  coordEditingFinished();
}

void TargetPropertyView::on_TargetNameLineEdit_editingFinished()
{
  Scenario::target target = find_target(_scenario->targets, _selected_ship.id);
  target.model_name = ui->TargetNameLineEdit->text();
  _selected_ship = target;
  for (Scenario::target& trg : _scenario->targets)
  {
    if (trg.id == target.id)
      trg = target;
  }
  _main_service->ChangeScenario(GetName());
}

void TargetPropertyView::on_SpeedLineEdit_editingFinished()
{
  Scenario::target target = find_target(_scenario->targets, _selected_ship.id);
  target.speed = ui->SpeedLineEdit->text().toDouble();
  _selected_ship = target;
  for (Scenario::target& trg : _scenario->targets)
  {
    if (trg.id == target.id)
      trg = target;
  }
  _main_service->ChangeScenario(GetName());
}

void TargetPropertyView::on_TargetCourseLineEdit_editingFinished()
{
  Scenario::target target = find_target(_scenario->targets, _selected_ship.id);
  target.course = ui->TargetCourseLineEdit->text().toDouble();
  _selected_ship = target;
  for (Scenario::target& trg : _scenario->targets)
  {
    if (trg.id == target.id)
      trg = target;
  }
  _main_service->ChangeScenario(GetName());
}
