#include "deletetool.h"
#include "scenarioeditutils.h"

void DeleteTool::MouseMove(QMouseEvent *event, QPoint)
{

}

void DeleteTool::MousePress(QMouseEvent *event)
{
  if (!(event->buttons() & Qt::LeftButton))
  {
    _main_service->SetDefaultTool();
    return;
  }

  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  for (int i = 0; i < view_models.size(); i++)
  {
    if (!view_models[i].GetPicture()->geometry().contains(event->pos()))
      continue;
    if (view_models[i].GetTarget().ownship)
      continue;

    _main_service->GetProjectService()->DeleteObject(view_models[i].GetId());
  }
}

void DeleteTool::onActivate()
{

}

void DeleteTool::onDeActivate()
{

}
