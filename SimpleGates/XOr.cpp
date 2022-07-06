
#include "XOr.h"
#include "../Connection.h"

XOr::XOr(std::string  name, CircuitItem *parent) :
  CircuitItem(name, parent),
  A("A", this, 1, Connection::Input),
  B("B", this, 1, Connection::Input),
  Out("Out", this, 1, Connection::Output) {


}

void XOr::update() {
  Out.setOutputValue(A.getBusValue() ^ B.getBusValue());
}

std::string XOr::status()
{
  return "[XOR]\t" + std::to_string(A.getBusValue()) + "^" + std::to_string(B.getBusValue());
}
