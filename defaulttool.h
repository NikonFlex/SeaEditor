#ifndef DEFAULTTOOL
#define DEFAULTTOOL

#include <basetool.h>

class DefaultTool : public BaseTool
{
public:
  DefaultTool(iMainService* service) : BaseTool(service) {}
  void MouseMove(QMouseEvent *event, QPoint delta) override final;
  void MousePress(QMouseEvent *event) override final;

protected:
  void onActivate() override final;
  void onDeActivate()  override final;
};

#endif // DEFAULTTOOL

