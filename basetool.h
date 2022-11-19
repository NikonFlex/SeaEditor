#ifndef BASETOOL
#define BASETOOL

#include "interfacetool.h"
#include "interfacesceneview.h"

class BaseTool : public iTool
{
public:
  BaseTool(iMainService* main_service) : _main_service(main_service){}

  void Activate() override final
  {
    _is_active = true;
     onActivate();
  }

  void DeActivate() override final
  {
    _is_active = false;
    onDeActivate();
  }

  bool IsActive() override final
  {
    return _is_active;
  }

protected:
  iMainService* _main_service = nullptr;
  virtual void onActivate(){}
  virtual void onDeActivate(){}

protected:
  int tryChangeSelection(const QPoint& pos);

private:
  bool _is_active = false;
};

#endif // BASETOOL

