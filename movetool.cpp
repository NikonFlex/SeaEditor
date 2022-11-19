#include "movetool.h"

void MoveTool::MouseMove(QMouseEvent *event, QPoint)
{
  if (!(event->buttons() & Qt::LeftButton))
    return;

  const QVector<ViewModel>& view_models = _main_service->GetProjectService()->GetObjects();
  Transformation transformator = _main_service->GetScreenViewService()->GetScreenTransform();

  for (const ViewModel& view_model : view_models)
  {
    if (!(view_model.IsSelected() & !view_model.GetTarget().ownship))
      continue;

    ViewModel modified = view_model;

    modified.GetPicture()->setGeometry(event->pos().x() - view_model.GetPicture()->width() / 2,
                                    event->pos().y() - view_model.GetPicture()->height() / 2,
                                    view_model.GetPicture()->width(),
                                    view_model.GetPicture()->height());

    modified.SetPos(transformator.ScreenToWorld(event->pos()));

    Point xy_pos = modified.GetPos();
    //point_geo ship_geo_pos = to_geo(QPoint(xy_pos.x, xy_pos.y), _scenario->base_point);

//    view_model->t.distance = geo_distance(ship_geo_pos, _scenario->base_point);
//    view_model->t.bearing = geo_bearing(_scenario->base_point, ship_geo_pos);

    DistanceBearing ship_distance_bearing(xy_pos);
    auto target = modified.GetTarget();
    target.distance = ship_distance_bearing.distance;
    target.bearing = ship_distance_bearing.bearing;
    modified.SetTarget(target);

    modified.GetPropertyLabel()->setText(QString::number(modified.GetTarget().distance)
                                       + "\n"
                                       + QString::number(modified.GetTarget().bearing));

    _main_service->GetProjectService()->ChangeObject(modified);
  }
}

void MoveTool::MousePress(QMouseEvent *event)
{
  if (!(event->buttons() & Qt::LeftButton))
  {
    _main_service->SetDefaultTool();
    return;
  }

  //tryChangeSelection(event->pos());
}

void MoveTool::onActivate()
{

}

void MoveTool::onDeActivate()
{

}
