#include "deleteroutecommand.h"

void DeleteRouteCommand::DoCommand(int id)
{
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();

  for (const ViewModel& view_model : view_models)
  {
    if (view_model.GetId() != id)
      continue;

    ViewModel modified = view_model;
    int route_size = modified.GetRouteSize();

    for (int i = route_size - 1; i >= 0; --i)
    {
      modified.SetRoutePointSelected(false, i);
      modified.DeleteRoutePoint(i);
    }
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

