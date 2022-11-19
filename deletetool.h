#ifndef DELETETOOL_H
#define DELETETOOL_H

#include <editormath.h>
#include <viewmodel.h>
#include <QMouseEvent>
#include <basetool.h>

class DeleteTool : public BaseTool
{
public:
  DeleteTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;};

#endif // DELETESHIPTOOL_H
