#ifndef ROTATETOOL_H
#define ROTATETOOL_H

#include <editormath.h>
#include <viewmodel.h>
#include <QMouseEvent>
#include <basetool.h>

class RotateTool : public BaseTool
{
public:
  RotateTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // ROTATETOOL_H
