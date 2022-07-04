
#include "XOr.h"

XOr::XOr(std::string  name, CircuitItem *parent) :
        Gate(name, parent),
        A(this, 1, Connection::Input, "A"),
        B(this, 1, Connection::Input, "B"),
        Out(this, 1, Connection::Output, "Out") {


}

void XOr::update(EventLoop &eventLoop) {
  Out.setOutputValue(eventLoop, A.getBusValue() ^ B.getBusValue());
}

std::string XOr::status()
{
  return "[XOR]\t" + std::to_string(A.getBusValue()) + "^" + std::to_string(B.getBusValue());
}
