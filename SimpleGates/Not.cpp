#include "Not.h"


Not::Not(std::string  name, CircuitItem *parent) :
        Gate(name, parent),
        A(this, 1, Connection::Input, "In"),
        Out(this, 1, Connection::Output, "Out") {


}

void Not::update(EventLoop &eventLoop) {
  Out.setOutputValue(eventLoop, !A.getBusValue());
}
