#include "screenview.h"
#include "geodesy_helper.h"
#include "ShipLabel.h"
#include "QMouseEvent"
#include "viewmodel.h"
#include "movetool.h"
#include "rotatetool.h"
#include "appendtool.h"
#include "deletetool.h"
#include "scenarioeditutils.h"
#include <QPainter>
#include <QDebug>
#include <QtGlobal>

ScreenView::ScreenView(QWidget *parent) : QWidget(parent)
{
  setMouseTracking(true);
}

void ScreenView::ZoomAll()
{
  BoundRect bRect;

  for (auto ship : _scenario->targets)
    bRect.AddPoint(ConvertToPoint(DistanceBearing(ship.distance, ship.bearing)));
  _transformator = Transformation(width(), height(), 100.0, bRect);

  for (ViewModel& view_model : _view_models)
    view_model.SetPos(ConvertToPoint(DistanceBearing(view_model.GetTarget().distance, view_model.GetTarget().bearing)));

  repaint();
}

void ScreenView::draw()
{
  for (ViewModel& view_model : _view_models)
    view_model.Draw();
}

void ScreenView::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  draw();
}

void ScreenView::mouseMoveEvent(QMouseEvent*event)
{
  QPoint mouse_delta(event->pos() - _last_mouse_pos);
  if (_main_service->GetActiveTool() != nullptr)
    _main_service->GetActiveTool()->MouseMove(event, mouse_delta);
  _main_service->ChangeScenario(GetName());
  repaint();
  _last_mouse_pos = event->pos();
}

void ScreenView::mousePressEvent(QMouseEvent*event)
{
  if (_main_service->GetActiveTool() != nullptr)
    _main_service->GetActiveTool()->MousePress(event);
  _main_service->ChangeScenario(GetName());
  repaint();
}

void ScreenView::wheelEvent(QWheelEvent *event)
{
  Point shift(_transformator.ScreenToWorld(event->pos()));

  if (event->delta() < 0)
    _transformator.UpdateScale(0.95);
  else
    _transformator.UpdateScale(1.095);

  Point new_shift(_transformator.ScreenToWorld(event->pos()));
  _transformator.SetWorldShift(Point(shift.x - new_shift.x, shift.y - new_shift.y));
  repaint();
}

void ScreenView::SetMainService(iMainService* i_main_service)
{
  _main_service = i_main_service;
}

void ScreenView::SetScenario(Scenario::scenario_data *scenario)
{
  _scenario = scenario;

  if (_transformator.IsEmpty())
  {
    BoundRect bRect;

    for (auto& ship : scenario->targets)
      bRect.AddPoint(ConvertToPoint(DistanceBearing(ship.distance, ship.bearing)));

    _transformator = Transformation(width(), height(), 100.0, bRect); 
  }

  for (ViewModel& view_model : _view_models)
    view_model.GetPicture()->hide();
  _view_models.clear();
  for (int i = 0; i < _scenario->targets.size(); i++)
  {
    _scenario->targets[i].id = i;
    ViewModel ship_view_model = ViewModel(_scenario, i, this, _main_service);
    ship_view_model.SetPos(ConvertToPoint(DistanceBearing(ship_view_model.GetTarget().distance, ship_view_model.GetTarget().bearing)));
    ship_view_model.UpdatePicture();
    for (int j = 0; j < _scenario->targets[i].route_points_vector.size(); ++j)
      ship_view_model.AddRoutePoint(Point(_scenario->targets[i].route_points_vector[j].x, _scenario->targets[i].route_points_vector[j].y));
    _view_models.push_back(ship_view_model);
  }
  repaint();
}

void ScreenView::ScenarioChanged()
{
  for (ViewModel& view_model : _view_models)
  {
    if (!view_model.IsSelected())
      continue;

    if (view_model.GetTarget().course != _scenario->targets[view_model.GetId()].course)
      view_model.UpdatePicture();

    Scenario::target target = find_target(_scenario->targets, view_model.GetId());
    view_model.SetTarget(target);
    view_model.SetPos(ConvertToPoint(DistanceBearing(view_model.GetTarget().distance, view_model.GetTarget().bearing)));
    for (int i = 0; i < view_model.GetRouteSize(); ++i)
      view_model.ChangeRoutePos(Point(target.route_points_vector[i].x, target.route_points_vector[i].y), i);
  }
  repaint();
}

void ScreenView::SelectionChanged(selection_data &selection_d){}

void ScreenView::WindowChanged()
{
  if (_scenario == nullptr)
    return;

  BoundRect bRect;
  for (auto ship : _scenario->targets)
    bRect.AddPoint(ConvertToPoint(DistanceBearing(ship.distance, ship.bearing)));

  _transformator = Transformation(this->size().width(), this->size().height(), 100.0, bRect);

  for (int i = 0; i < _scenario->targets.size(); i++)
    _view_models[i].SetPos(ConvertToPoint(DistanceBearing(_scenario->targets[i].distance, _scenario->targets[i].bearing)));
}

QString ScreenView::GetName() const
{
  return QString("ScreenView");
}

const Transformation ScreenView::GetScreenTransform() const
{
  return _transformator;
}

void ScreenView::SetScreenTransform(const Transformation &transformator)
{
  _transformator = transformator;
}

void ScreenView::SetCursor(Qt::CursorShape cursor)
{
  setCursor(cursor);
}

QSize ScreenView::GetScreenSize() const
{
  return QSize(width(), height());
}

const QVector<ViewModel> &ScreenView::GetObjects() const
{
  return _view_models;
}

int ScreenView::AddObject()
{
  ViewModel new_view_model = ViewModel(_scenario, _scenario->targets.back().id, this, _main_service);
  new_view_model.UpdatePicture();
  new_view_model.SetPos(ConvertToPoint(DistanceBearing(new_view_model.GetTarget().distance, new_view_model.GetTarget().bearing)));
  _view_models.append(new_view_model);
}

void ScreenView::DeleteObject(int id)
{
  for (int i = 0; i < _view_models.size(); i++)
  {
    if (_view_models[i].GetId() == id)
    {
      delete_target(_scenario->targets, _view_models[i].GetId());
      _view_models[i].GetPicture()->hide();
      _view_models[i].GetPropertyLabel()->hide();
      if (_view_models[i].IsSelected())
      {
        selection_data selection_d;
        _main_service->ChangeSelection(selection_d);
      }
      _view_models.remove(i);
    }
  }
}

void ScreenView::ChangeObject(const ViewModel& view_model)
{
  for (ViewModel& v_model : _view_models)
  {
    if (v_model.GetId() == view_model.GetId())
      v_model = view_model;
  }
  for (Scenario::target& target : _scenario->targets)
  {
    if (target.id == view_model.GetId())
      target = view_model.GetTarget();
  }
}
