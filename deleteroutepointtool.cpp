#include "deleteroutepointtool.h"

void DeleteRoutePointTool::MouseMove(QMouseEvent *event, QPoint)
{
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();

  for (const ViewModel& view_model : view_models)
  {
    ViewModel modified = view_model;
    int route_size = modified.GetRouteSize();

    for (int i = 0; i < route_size; ++i)
    {
      QPoint screen_pos = transformator.WorldToScreen(modified.GetRoutePoint(i));
      QRect hover_area = QRect(screen_pos.x() - 5, screen_pos.y() - 5, 10, 10);

      if (hover_area.contains(event->pos()) && (modified.IsAnyPointHovered() == -1 || modified.IsAnyPointHovered() == i))
        modified.SetRoutePointHovered(true, i);
      else
        modified.SetRoutePointHovered(false, i);

      _main_service->GetProjectService()->ChangeObject(modified);
    }
  }
}

void DeleteRoutePointTool::MousePress(QMouseEvent *event)
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
    int route_size = modified.GetRouteSize();

    for (int i = route_size - 1; i >= 0; --i)
    {
      QPoint screen_pos = transformator.WorldToScreen(modified.GetRoutePoint(i));
      QRect hover_area = QRect(screen_pos.x() - 5, screen_pos.y() - 5, 10, 10);
      if (hover_area.contains(event->pos()))
        modified.DeleteRoutePoint(i);
    }
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

void DeleteRoutePointTool::onActivate()
{
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();

  for (const ViewModel& view_model : view_models)
  {
    ViewModel modified = view_model;

    if (view_model.IsSelected())
      modified.StartEditRoute();
    else
      modified.FinishEditRoute();
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

void DeleteRoutePointTool::onDeActivate()
{
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();

  for (const ViewModel& view_model : view_models)
  {
    ViewModel modified = view_model;
    modified.FinishEditRoute();
    int route_size = modified.GetRouteSize();
    for (int i = route_size - 1; i >= 0; --i)
      modified.SetRoutePointSelected(false, i);

    selection_data selection_d;
    selection_d.route_point = -1;
    for (const ViewModel& view_model : view_models)
    {
      if (view_model.IsSelected())
      {
        selection_d.ship_id = view_model.GetId();
        break;
      }
    }
    _main_service->ChangeSelection(selection_d);
    _main_service->GetProjectService()->ChangeObject(modified);
  }
}
