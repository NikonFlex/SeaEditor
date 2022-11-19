#include "addroutetool.h"

void AddRouteTool::MouseMove(QMouseEvent *event, QPoint)
{

}

void AddRouteTool::MousePress(QMouseEvent *event)
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

    if (event->button() == Qt::LeftButton)
    {
      modified.AddRoutePoint(transformator.ScreenToWorld(event->pos()));
      _main_service->GetProjectService()->ChangeObject(modified);
    }
    else if (event->button() == Qt::RightButton)
    {
      _main_service->SetDefaultTool();
    }
  }
}

void AddRouteTool::onActivate()
{

}

void AddRouteTool::onDeActivate()
{

}
