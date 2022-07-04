
#include "Or.h"

Or::Or(std::string  name, CircuitItem *parent) :
        Gate(name, parent),
        A(this, 1, Connection::Input, "A"),
        B(this, 1, Connection::Input, "B"),
        Out(this, 1, Connection::Output, "Out") {


}

void Or::update(EventLoop &eventLoop) {
  Out.setOutputValue(eventLoop, A.getBusValue() | B.getBusValue());
}

