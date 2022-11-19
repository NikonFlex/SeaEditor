#include "appendtool.h"
#include "scenarioeditutils.h"

void AppendTool::MouseMove(QMouseEvent *event, QPoint)
{

}

void AppendTool::MousePress(QMouseEvent *event)
{
  if (!(event->buttons() & Qt::LeftButton))
  {
    _main_service->SetDefaultTool();
    return;
  }

  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();
  Scenario::scenario_data* scenario = _main_service->GetScenario();

  Point new_ship_xy_pos = transformator.ScreenToWorld(event->pos());

  Scenario::target new_ship;

  DistanceBearing ship_distance_bearing(new_ship_xy_pos);
  new_ship.distance = ship_distance_bearing.distance;
  new_ship.bearing = ship_distance_bearing.bearing;
  new_ship.model_name = "неизвестная модель";
  new_ship.course = 0;
  new_ship.speed = 0;
  new_ship.ownship = false;
  new_ship.id = make_new_id(scenario->targets);

  scenario->targets.push_back(new_ship);
  _main_service->GetProjectService()->AddObject();
}

void AppendTool::onActivate()
{

}

void AppendTool::onDeActivate()
{

}
