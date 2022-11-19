#ifndef INTERFACETOOL
#define INTERFACETOOL

#include <QMouseEvent>

struct iTool
{
  virtual ~iTool() {}
  virtual void Activate() = 0;
  virtual void DeActivate() = 0;
  virtual bool IsActive() = 0;

  virtual void MouseMove(QMouseEvent *event, QPoint delta) = 0;
  virtual void MousePress(QMouseEvent *event) = 0;
};


#endif // INTERFACETOOL

