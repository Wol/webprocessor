
#include <iostream>
#include <cassert>
#include <bitset>
#include "Connection.h"
#include "Bus.h"

Connection::Connection(std::string name, CircuitItem *parent, uint8_t size, int direction) :
  m_size(size), m_direction(direction), m_bit_offset(0), CircuitItem(name, parent) {

}

/**
 * Used internally to get the current bus value.
 * @return
 */
BusValue Connection::getBusValue() const {
  if(!m_bus) return 0;
  return (m_bus->value() >> m_bit_offset) & (( 1u << m_size ) - 1);
}

/**
 * This is where the Bus will get our value if we have one.
 * @return
 */
BusValue Connection::applyOutputValue(BusValue *value) const {

  BusValue value_mask = ((1u << m_size) - 1) << m_bit_offset;

  *value &= ~value_mask;
  *value |= m_outputvalue << m_bit_offset;

  return value_mask; // TODO:
}

/**
 * This is called internally from the Gate this Connection belongs to
 * @param value
 */
void Connection::setOutputValue(BusValue value) {
  // TODO: If the value already is correct, then don't propagate as there won't be any changes

  // if(m_outputvalue == value) return;

  m_outputvalue = value;

  if(!m_bus) {
    // We might not actually have something connected to this output, so never mind!
    return;
  }

  m_bus->needsRecalculating();
}

int Connection::direction() const {
  return m_direction;
}

/**
 * Connects a Bus, at a given bit_offset, to this connection.
 * @param bus
 * @param bit_offset
 */
void Connection::connect(Bus *bus, uint8_t bit_offset) {

  assert(size() <= bus->size());
  if(m_bus) {
    std::cout << "Connection " << name() << " of " << parent()->name() << " has already been connected to bus " << m_bus->name() << " when attempting to connect to " << bus->name() << "\n";
  }

  assert(m_bus == nullptr);

  m_bus = bus;
  m_bit_offset = bit_offset;

  bus->addConnection(this); // Bus only needs to know _what_ it's connected to. The Connection handles the bit shift
}



uint8_t Connection::size() const {
  return m_size;
}

std::string Connection::status()
{
  if(m_direction == Output) {
    return "[OUT]\t" + std::to_string(m_outputvalue);
  }

  if(m_direction == Input) {
    if(!m_bus) return "[IN ]\tDisconnected!!!";

    return "[IN ]\t" + std::to_string(getBusValue()) + " (" + std::bitset<8>(m_bus->value()).to_string() + " " + std::to_string(m_size) + ":" + std::to_string(m_bit_offset) + ")";
  }

  return "????";

}

