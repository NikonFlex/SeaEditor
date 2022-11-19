#include "editormath.h"
#include <iostream>

BoundRect::BoundRect()
{
  SetEmpty();
}

void BoundRect::SetEmpty()
{
  _low = Point(100, 100);
  _high = Point(0, 0);
}

bool BoundRect::IsEmpty() const
{
  return _low.x > _high.x;
}

inline void make_minmax(double &to_be_min, double &to_be_max, double x)
{
  if (to_be_min > x) to_be_min = x;
  if (to_be_max < x) to_be_max = x;
}

Point BoundRect::getCenter() const
{
  return Point{ (_high - _low).x / 2, (_high - _low).y / 2 };
}

void BoundRect::AddPoint(Point p)
{
  if (this->IsEmpty())
  {
    _low = p;
    _high = p;
    return;
  }

  make_minmax(_low.x, _high.x, p.x);
  make_minmax(_low.y, _high.y, p.y);
}

Point BoundRect::GetLow() const { return _low; }

Point BoundRect::GetHigh() const { return _high; }

double BoundRect::GetWidth() const { return _high.x - _low.x; }

double BoundRect::GetHeight() const { return _high.y - _low.y; }

void Transformation::SetViewShift(const Point& mouse_move_amount) { _view_shift = _view_shift + mouse_move_amount; }

void Transformation::SetWorldShift(const Point &p) { _world_shift = _world_shift + p; }

void Transformation::UpdateScale(double difference) { _scale *= difference; }

Transformation::Transformation(double screen_w, double screen_h, double border_shift, BoundRect& b_rect)
{
  _border_shift = border_shift;
  double w = (screen_w - 2 * _border_shift)/ b_rect.GetWidth();
  double h = (screen_h - 2 * _border_shift)/ b_rect.GetHeight();
  _scale = std::min(w, h);
  _screen_h = screen_h;
  _world_shift = b_rect.GetLow();
  _view_shift = Point(0, 0);
}

QPoint Transformation::WorldToScreen(const Point& world_pos) const
{
  Point transformed_point = (world_pos - _world_shift) * _scale;
  transformed_point.x += _border_shift + _view_shift.x;
  transformed_point.y = _screen_h - _border_shift - transformed_point.y + _view_shift.y;
  return QPoint(transformed_point.x, transformed_point.y);
}

Point Transformation::ScreenToWorld(const QPoint &screen_pos) const
{
  Point transformed_point;
  transformed_point.x = screen_pos.x() - _border_shift - _view_shift.x;
  transformed_point.y = _screen_h - _border_shift - screen_pos.y() + _view_shift.y;
  transformed_point = transformed_point / _scale + _world_shift;
  return transformed_point;
}
