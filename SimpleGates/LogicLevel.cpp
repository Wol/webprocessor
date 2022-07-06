
#include "LogicLevel.h"

#include <iostream>

LogicLevel::LogicLevel(std::string  name, CircuitItem *parent, uint8_t size, int direction) :
        CircuitItem(name, parent),
        IO("IO", this, size),
        _io("IO", this, size, direction)
        {

  IO.addInternalConnection(_io);

}

void LogicLevel::update() {



}

void LogicLevel::setOutputValue(BusValue i) {
  _io.setOutputValue(i);
}

BusValue LogicLevel::getInputValue() {
  return _io.getBusValue();
}
