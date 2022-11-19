#ifndef DELETEROUTECOMMAND_H
#define DELETEROUTECOMMAND_H

#include "interfacecommand.h"

class DeleteRouteCommand : public iCommand
{
public:
  DeleteRouteCommand(iMainService* service) : iCommand(service) {}
  void DoCommand(int id) override final;
};

#endif // DELETEROUTECOMMAND_H
