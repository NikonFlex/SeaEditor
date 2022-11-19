#ifndef EDITROUTETOOL_H
#define EDITROUTETOOL_H

#include "basetool.h"

class EditRouteTool : public BaseTool
{
public:
  EditRouteTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // EDITROUTETOOL_H
