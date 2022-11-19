#ifndef VIEWMODEL
#define VIEWMODEL
#include "editormath.h"
#include "shiplabel.h"
#include "scenario_data.h"
#include "route.h"
#include <QLabel>
#include <QPixmap>
#include <QPainter>

struct iMainService;

class ViewModel
{
public:
  ViewModel() = default;
  ~ViewModel(){}
  ViewModel(Scenario::scenario_data* scenario, int target_id, QWidget* parent, iMainService* main_service);
  void SetPictures();
  void UpdatePicture();
  bool Contains(const QPoint& screen_pos);
  void Draw();

  void SetHovered(bool is_hovered);
  void SetPos(const Point& p);
  void SetSelected(bool is_selected);
  void SetTarget(Scenario::target& t);
  void SetId(int id);
  void SetPropertyLabelText(QString text);
  void SetScenario(Scenario::scenario_data* scenario);
  void AddRoutePoint(const Point& p);
  void DeleteRoutePoint(int index);
  void ChangeRoutePos(const Point& p, int index);
  void SetRoutePointHovered(bool is_hovered, int index);
  void SetRoutePointSelected(bool is_selected, int index);
  Point GetRoutePoint(int index) const;
  int GetRouteSize() const;
  void StartEditRoute();
  void FinishEditRoute();

  bool IsHovered() const;
  Point GetPos() const;
  bool IsSelected() const;
  Scenario::target GetTarget() const;
  int GetId() const;
  ShipLabel* GetPicture() const;
  QLabel* GetPropertyLabel() const;
  bool IsRoutePointHovered(int index) const;
  bool IsRoutePointSelected(int index) const;
  int IsAnyPointHovered() const;
  int IsAnyPointSelected() const;

private:
  Scenario::target _t;
  ShipLabel* _picture = nullptr;
  Point _pos;
  int _id = -1;
  bool _hovered = false;
  bool _selected = false;
  QLabel* _property_label;
  Scenario::scenario_data* _scenario = nullptr;
  QWidget* _parent;
  iMainService* _main_service;
  Route _route;

private:
  void updatePicture();
  void bringLabelToCommonForm(QLabel* label);
  void drawShip();
};

#endif // VIEWMODEL
