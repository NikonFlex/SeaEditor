#include "rotatetool.h"

void RotateTool::MouseMove(QMouseEvent *event, QPoint)
{
  if (!(event->buttons() & Qt::LeftButton))
    return;

  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();

  Point p(event->pos().x(), event->pos().y());
  for (const ViewModel& view_model : view_models)
  {
    if (!(view_model.IsSelected() & !view_model.GetTarget().ownship))
      continue;

    ViewModel modified = view_model;
    auto target = modified.GetTarget();
    QPoint view_model_pos;
    view_model_pos = transformator.WorldToScreen(modified.GetPos());
    target.course = CalculateAngleOnPoint(Point(view_model_pos.x(), view_model_pos.y()), p);
    modified.SetTarget(target);

    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

void RotateTool::MousePress(QMouseEvent *event)
{
  if (!(event->buttons() & Qt::LeftButton))
  {
    _main_service->SetDefaultTool();
    return;
  }

  //tryChangeSelection(event->pos());
}

void RotateTool::onActivate()
{

}

void RotateTool::onDeActivate()
{

}
