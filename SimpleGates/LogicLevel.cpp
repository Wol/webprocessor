
#include "LogicLevel.h"

#include <iostream>

LogicLevel::LogicLevel(std::string  name, CircuitItem *parent, uint8_t size, int direction) :
        Gate(name, parent),
        IO("IO", this, size),
        _io(this, size, direction, "IO")
        {

  IO.addInternalConnection(_io);

}

void LogicLevel::update(EventLoop &eventLoop) {



}

void LogicLevel::setOutputValue(EventLoop &eventLoop, BusValue i) {
  _io.setOutputValue(eventLoop, i);
}

BusValue LogicLevel::getInputValue() {
  return _io.getBusValue();
}
