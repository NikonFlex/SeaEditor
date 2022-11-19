#ifndef ZOOMALLCOMMAND_H
#define ZOOMALLCOMMAND_H

#include "interfacecommand.h"

class ZoomAllCommand : public iCommand
{
public:
  ZoomAllCommand(iMainService* service) : iCommand(service) {}
  void DoCommand(int) override final;
};

#endif // ZOOMALLCOMMAND_H
