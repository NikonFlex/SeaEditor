#include "zoomallcommand.h"

void ZoomAllCommand::DoCommand(int)
{
  Scenario::scenario_data* scenario = _main_service->GetScenario();
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();

  BoundRect bRect;
  for (auto ship : scenario->targets)
    bRect.AddPoint(ConvertToPoint(DistanceBearing(ship.distance, ship.bearing)));

  QSize screen_size = _main_service->GetScreenViewService()->GetScreenSize();
  Transformation transformator = Transformation(screen_size.width(), screen_size.height(), 100.0, bRect);
  _main_service->GetScreenViewService()->SetScreenTransform(transformator);

  for (const ViewModel& view_model : view_models)
  {
    ViewModel modified = view_model;
    modified.SetPos(ConvertToPoint(DistanceBearing(modified.GetTarget().distance, modified.GetTarget().bearing)));
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

