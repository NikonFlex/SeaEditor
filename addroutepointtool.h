#ifndef ADDROUTEPOINTTOOL_H
#define ADDROUTEPOINTTOOL_H

#include "basetool.h"

class AddRoutePointTool : public BaseTool
{
public:
  AddRoutePointTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // ADDROUTEPOINTTOOL_H

