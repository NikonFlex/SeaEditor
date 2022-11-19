#ifndef ADDROUTETOOL_H
#define ADDROUTETOOL_H

#include "basetool.h"

class AddRouteTool : public BaseTool
{
public:
  AddRouteTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // ADDROUTETOOL_H
