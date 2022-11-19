#include "defaulttool.h"

struct mouse_info
{
  Point last_mouse_pos;
  QMouseEvent * event;
};

void DefaultTool::MouseMove(QMouseEvent *event, QPoint delta)
{
  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();

  if (view_models.empty())
    return;

  //update hover
  bool hoveredFound = false;
  for (int i = view_models.size() - 1; i >=0; --i)
  {
    ViewModel modified = view_models[i];
    if ( !hoveredFound && modified.Contains(event->pos()))
    {
      modified.SetHovered(true);
      if (!modified.IsSelected())
        modified.SetPropertyLabelText(modified.GetTarget().model_name);
      hoveredFound = true;
    }
    else
    {
      modified.SetHovered(false);
      modified.GetPropertyLabel()->hide();
    }
    _main_service->GetProjectService()->ChangeObject(modified);
  }

  //update view
  if (event->buttons() & Qt::LeftButton)
  {
    Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();
    Point p(delta.x(), delta.y());
    transformator.SetViewShift(p);
    _main_service->GetScreenViewService()->SetScreenTransform(transformator);
    _main_service->GetScreenViewService()->SetCursor(Qt::ClosedHandCursor);
  }
  else
  {
    bool is_something_hovered = false;
    for (const ViewModel& view_model : view_models)
    {
      if (view_model.IsHovered())
      {
        is_something_hovered = true;
        break;
      }
    }
    if (!is_something_hovered)
      _main_service->GetScreenViewService()->SetCursor(Qt::ArrowCursor);
    else
      _main_service->GetScreenViewService()->SetCursor(Qt::PointingHandCursor);
  }
}

void DefaultTool::MousePress(QMouseEvent *event)
{
  tryChangeSelection(event->pos());
}

void DefaultTool::onActivate()
{

}

void DefaultTool::onDeActivate()
{

}
