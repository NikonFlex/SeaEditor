#ifndef DELETEROUTEPOINTTOOL_H
#define DELETEROUTEPOINTTOOL_H

#include "basetool.h"

class DeleteRoutePointTool : public BaseTool
{
public:
  DeleteRoutePointTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // DELETEROUTEPOINTTOOL_H
