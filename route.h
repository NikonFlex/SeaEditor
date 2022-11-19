#ifndef ROUTE_H
#define ROUTE_H

#include "editormath.h"
#include <QVector>
#include <QWidget>
#include <QLabel>

struct route_view_point
{
  route_view_point() = default;
  route_view_point(const Point& p) { world_pos = p; }
  Point world_pos;
  bool hovered = false;
  bool selected = false;
};

struct iMainService;

class Route
{
public:
  void SetParent(QWidget* parent);
  void ChangePos(const Point& p, int index);
  void AddPoint(const Point& p);
  void DeletePoint(int index);
  Point GetPoint(int index) const;
  int GetSize() const;
  void SetPointHovered(bool is_hovered, int index);
  void SetPointSelected(bool is_selected, int index);
  bool IsPointHovered(int index) const;
  bool IsPointSelected(int index) const;
  int IsAnyPointSelected() const;
  int IsAnyPointHovered() const;
  void Draw(const Point& view_model_xy, iMainService* main_service) const;
  void SetEditMode(bool is_edit);

private:
  QVector<route_view_point> _points_list;
  QWidget* _parent = nullptr;
  QLabel* _property_label = nullptr;
  bool _is_edit = false;
  
};

#endif // ROUTE_H
