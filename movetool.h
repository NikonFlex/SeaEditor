#ifndef MOVETOOL_H
#define MOVETOOL_H

#include <editormath.h>
#include <viewmodel.h>
#include <QMouseEvent>
#include <basetool.h>

class MoveTool : public BaseTool
{
public:
  MoveTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // MOVETOOL_H
