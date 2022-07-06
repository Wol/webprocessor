
#include "And.h"
#include "../Connection.h"

And::And(std::string  name, CircuitItem *parent) :
  CircuitItem(name, parent),
        A("A", this, 1, Connection::Input),
        B("B", this, 1, Connection::Input),
        Out("Out", this, 1, Connection::Output) {


}

void And::update() {
  Out.setOutputValue(A.getBusValue() & B.getBusValue());
}
