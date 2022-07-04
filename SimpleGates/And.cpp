
#include "And.h"

And::And(std::string  name, CircuitItem *parent) :
        Gate(name, parent),
        A(this, 1, Connection::Input, "A"),
        B(this, 1, Connection::Input, "B"),
        Out(this, 1, Connection::Output, "Out") {


}

void And::update(EventLoop &eventLoop) {
  Out.setOutputValue(eventLoop, A.getBusValue() & B.getBusValue());
}
