
#include "Or.h"
#include "../Connection.h"

Or::Or(std::string  name, CircuitItem *parent) :
  CircuitItem(name, parent),
        A("A", this, 1, Connection::Input),
        B("B", this, 1, Connection::Input),
        Out("Out", this, 1, Connection::Output) {


}

void Or::update() {
  Out.setOutputValue(A.getBusValue() | B.getBusValue());
}

