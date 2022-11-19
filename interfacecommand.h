#ifndef INTERFACECOMMAND
#define INTERFACECOMMAND

#include "interfacesceneview.h"

class iCommand
{
public:
  iCommand(iMainService* main_service) : _main_service(main_service){}
  virtual ~iCommand() {}
  virtual void DoCommand(int id) = 0;

protected:
  iMainService* _main_service;
};

#endif // INTERFACECOMMAND

