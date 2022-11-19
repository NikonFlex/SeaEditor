#ifndef APPENDTOOL_H
#define APPENDTOOL_H

#include <editormath.h>
#include <viewmodel.h>
#include <QMouseEvent>
#include <basetool.h>

class AppendTool : public BaseTool
{
public:
  AppendTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // APPENDTOOL_H
