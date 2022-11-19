#include "viewmodel.h"
#include "scenarioeditutils.h"
#include "svgiconset.h"
#include "interfacesceneview.h"
#include <QPainter>

ViewModel::ViewModel(Scenario::scenario_data* scenario, int target_id, QWidget* parent, iMainService* main_service)
{
  _scenario = scenario;
  _id = target_id;
  _t = find_target(_scenario->targets, _id);
  _picture = new ShipLabel(parent);
  _hovered = false;
  _selected = false;
  _property_label = new QLabel(parent);
  _route.SetParent(parent);
  _parent = parent;
  _main_service = main_service;
  bringLabelToCommonForm(_property_label);
}

void ViewModel::UpdatePicture()
{
  updatePicture();
}

bool ViewModel::Contains(const QPoint& screen_pos)
{
  return _picture->geometry().contains(screen_pos);
}

void ViewModel::Draw()
{
  drawShip();
  _route.Draw(_pos, _main_service);
}

void ViewModel::SetHovered(bool is_hovered)
{
  if (_hovered == is_hovered)
    return;
  _hovered = is_hovered;
  updatePicture();
}

void ViewModel::SetPos(const Point &p)
{
  _pos = p;
}

void ViewModel::SetSelected(bool is_selected)
{
  if (_selected == is_selected)
    return;
  _selected = is_selected;
  updatePicture();
  if (!is_selected)
  {
    for (int i = 0; i < _route.GetSize(); ++i)
      SetRoutePointSelected(false, i);
  }
}

void ViewModel::SetTarget(Scenario::target &t)
{
  _t = t;
  updatePicture();
}

void ViewModel::SetId(int id)
{
  _id = id;
}

void ViewModel::SetPropertyLabelText(QString text)
{
  _property_label->setText(text);
}

void ViewModel::SetScenario(Scenario::scenario_data *scenario)
{
  _scenario = scenario;
}

void ViewModel::AddRoutePoint(const Point &p)
{
  _t.route_points_vector.push_back(point_xy(p.x, p.y));
  _route.AddPoint(p);
}

void ViewModel::DeleteRoutePoint(int index)
{
  _t.route_points_vector.remove(index);
  _route.DeletePoint(index);
}

void ViewModel::ChangeRoutePos(const Point &p, int index)
{
  _t.route_points_vector[index] = point_xy(p.x, p.y);
  _route.ChangePos(p, index);
}

void ViewModel::SetRoutePointHovered(bool is_hovered, int index)
{
  _route.SetPointHovered(is_hovered, index);
}

void ViewModel::SetRoutePointSelected(bool is_selected, int index)
{
  _route.SetPointSelected(is_selected, index);
}

Point ViewModel::GetRoutePoint(int index) const
{
  return _route.GetPoint(index);
}

int ViewModel::GetRouteSize() const
{
  return _route.GetSize();
}

void ViewModel::StartEditRoute()
{
  _route.SetEditMode(true);
}

void ViewModel::FinishEditRoute()
{
  _route.SetEditMode(false);
}

bool ViewModel::IsHovered() const
{
  return _hovered;
}

Point ViewModel::GetPos() const
{
  return _pos;
}

bool ViewModel::IsSelected() const
{
  return _selected;
}

Scenario::target ViewModel::GetTarget() const
{
  return _t;
}

int ViewModel::GetId() const
{
  return _id;
}

ShipLabel *ViewModel::GetPicture() const
{
  return _picture;
}

QLabel *ViewModel::GetPropertyLabel() const
{
  return _property_label;
}

bool ViewModel::IsRoutePointHovered(int index) const
{
  _route.IsPointHovered(index);
}

bool ViewModel::IsRoutePointSelected(int index) const
{
  _route.IsPointSelected(index);
}

int ViewModel::IsAnyPointHovered() const
{
  return _route.IsAnyPointHovered();
}

int ViewModel::IsAnyPointSelected() const
{
  return _route.IsAnyPointSelected();
}

void ViewModel::bringLabelToCommonForm(QLabel* label)
{
  QFont f("Bahnschrift Light Condensed", 11);
  label->setFont(f);
  label->setStyleSheet("background: rgba(255, 0, 0, 0); color:rgb(2, 191, 150);");
  label->setGeometry(0, 0, 200, 50);
  label->setAlignment(Qt::AlignCenter);
}

void ViewModel::drawShip()
{
  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();

  QPoint screen_pos;
  screen_pos = transformator.WorldToScreen(_pos);
  _picture->setGeometry(screen_pos.x() - _picture->width() / 2,
                                   screen_pos.y() - _picture->height() / 2,
                                   _picture->width(),
                                   _picture->height());
  _picture->setAlignment(Qt::AlignCenter);

  if (_hovered && !_selected)
  {
    _property_label->setGeometry(screen_pos.x() - _property_label->width() / 2,
                                            screen_pos.y() + _picture->width() / 2,
                                            _property_label->width(),
                                            _property_label->height());
    _property_label->show();
  }

  _picture->show();
}

void ViewModel::updatePicture()
{
  Point ship_size;
  ship_size = _hovered ? Point{ 100, 100 } : Point{ 90, 90 };

  QString icon_name;
  if (_t.ownship && _selected)
    icon_name = "selected_ownship";
  else if (_t.ownship)
    icon_name = "ownship";
  else if (_selected)
    icon_name = "selected_ship";
  else
    icon_name = "ship";

  auto svgr = SvgIconSet::GetRenderer(icon_name);
  QRect size = svgr->viewBox();
  double scale_i = size.height() / (double)size.width();

  QTransform trans;
  trans.translate(ship_size.x / 2, ship_size.y / 2);
  trans.rotate(find_target(_scenario->targets, _id).course);
  trans.translate(-ship_size.x / 2, -ship_size.y / 2);

  QPixmap rotatePixmap(ship_size.x, ship_size.y);
  rotatePixmap.fill(Qt::transparent);
  QPainter p;

  p.begin(&rotatePixmap);
  p.setRenderHint(QPainter::Antialiasing);
  p.setRenderHint(QPainter::SmoothPixmapTransform);
  p.setRenderHint(QPainter::HighQualityAntialiasing);
  p.setTransform(trans);

  svgr->render(&p, QRectF((ship_size.x - ship_size.x / scale_i) / 2, 0, ship_size.x / scale_i, ship_size.y));
  p.end();

  _picture->setGeometry(0, 0, ship_size.x, ship_size.y);
  _picture->setPixmap(rotatePixmap);
  _picture->setStyleSheet("background: rgba(255, 0, 0, 0);");
}
