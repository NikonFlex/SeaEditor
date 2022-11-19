#include "route.h"
#include "interfacesceneview.h"
#include <QPainter>

void Route::SetParent(QWidget *parent)
{
  _parent = parent;
  _property_label = new QLabel(_parent);
  QFont f("Bahnschrift Light Condensed", 11);
  _property_label->setFont(f);
  _property_label->setStyleSheet("background: rgba(255, 0, 0, 0); color:rgb(2, 191, 150);");
  _property_label->setAlignment(Qt::AlignCenter);
}

void Route::ChangePos(const Point& p, int index)
{
  _points_list[index].world_pos = p;
}

void Route::AddPoint(const Point& p)
{
  route_view_point new_point = route_view_point(p);
  _points_list.push_back(new_point);
}

void Route::DeletePoint(int index)
{
  _points_list.remove(index);
}

Point Route::GetPoint(int index) const
{
  return _points_list[index].world_pos;
}

int Route::GetSize() const
{
  return _points_list.size();
}

void Route::SetPointHovered(bool is_hovered, int index)
{
  _points_list[index].hovered = is_hovered;
}

void Route::SetPointSelected(bool is_selected, int index)
{
  _points_list[index].selected = is_selected;
}

bool Route::IsPointHovered(int index) const
{
  return _points_list[index].hovered;
}

bool Route::IsPointSelected(int index) const
{
  return _points_list[index].selected;
}


int Route::IsAnyPointHovered() const
{
  for (int i = 0; i < _points_list.size(); ++i)
  {
    if (_points_list[i].hovered)
      return i;
  }
  return -1;
}

int Route::IsAnyPointSelected() const
{
  for (int i = 0; i < _points_list.size(); ++i)
  {
    if (_points_list[i].selected)
      return i;
  }
  return -1;
}

void Route::Draw(const Point& view_model_xy, iMainService* main_service) const
{
  Transformation transformator = main_service->GetScreenViewService()->GetScreenTransform();

  QPainter painter(_parent);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::HighQualityAntialiasing);
  painter.setPen(QPen(QBrush(QColor(2, 191, 150)), 2, Qt::SolidLine, Qt::RoundCap));
  if (_points_list.empty())
    return;

  painter.drawLine(transformator.WorldToScreen(view_model_xy), transformator.WorldToScreen(_points_list[0].world_pos));
  for (int i = 1; i < _points_list.size(); i++)
  {
    painter.drawLine(transformator.WorldToScreen(_points_list[i - 1].world_pos), transformator.WorldToScreen(_points_list[i].world_pos));
  }

  if (_is_edit)
  {
    for (int i = 0; i < _points_list.size(); ++i)
    {
      if (_points_list[i].selected)
        painter.setPen(QPen(QBrush(QColor(3, 105, 159)), 2, Qt::SolidLine, Qt::RoundCap));
      else
        painter.setPen(QPen(QBrush(QColor(215, 2, 64)), 2, Qt::SolidLine, Qt::RoundCap));

      QPoint screen_p = transformator.WorldToScreen(_points_list[i].world_pos);
      if (_points_list[i].hovered)
        painter.drawRect(screen_p.x() - 7, screen_p.y() - 7, 14, 14);
      else
        painter.drawRect(screen_p.x() - 5, screen_p.y() - 5, 10, 10);
    }
  }

  for (int i = 0; i < _points_list.size(); ++i)
  {
    QPoint screen_p = transformator.WorldToScreen(_points_list[i].world_pos);
    if (!_points_list[i].selected && _points_list[i].hovered)
    {
      _property_label->setGeometry(screen_p.x() - 15, screen_p.y() + 10, 30, 30);
      _property_label->setText(QString::number(i + 1));
      _property_label->show();
      break;
    }
    else
    {
      _property_label->hide();
    }
  }
}

void Route::SetEditMode(bool is_edit)
{
  if (is_edit)
    int a = 2 + 2;
  _is_edit = is_edit;
  for (auto p : _points_list)
  {
    p.selected = false;
    p.hovered = false;
  }
}
