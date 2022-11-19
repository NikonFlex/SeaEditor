#include "addroutepointtool.h"

void AddRoutePointTool::MouseMove(QMouseEvent *event, QPoint)
{

}

void AddRoutePointTool::MousePress(QMouseEvent *event)
{
  if (!(event->buttons() & Qt::LeftButton))
  {
    _main_service->SetDefaultTool();
    return;
  }

  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();

  for (const ViewModel& view_model : view_models)
  {
    if (!view_model.IsSelected())
      continue;

    ViewModel modified = view_model;
    modified.AddRoutePoint(transformator.ScreenToWorld(event->pos()));
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

void AddRoutePointTool::onActivate()
{

}

void AddRoutePointTool::onDeActivate()
{

}
