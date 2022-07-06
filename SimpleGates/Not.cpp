#include "Not.h"
#include "../Connection.h"


Not::Not(std::string  name, CircuitItem *parent) :
  CircuitItem(name, parent),
        In("In", this, 1, Connection::Input),
        Out("Out", this, 1, Connection::Output) {

  needsRecalculating();
}

void Not::update() {
  Out.setOutputValue(!In.getBusValue());
}
