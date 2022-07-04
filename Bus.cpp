
#include <cassert>
#include <iostream>
#include "Bus.h"
#include "Connection.h"
#include "EventLoop.h"
#include "Pin.h"

BusValue Bus::value() const {
  return m_value;
}



void Bus::addConnection(Connection *connector) {
  assert(connector->size() <= m_size);

  m_connections.insert(connector);
}



void Bus::update(EventLoop &eventLoop) {

  // Loop through all the input connections to determine value

  BusValue bus_applied_mask = 0x0;

  BusValue new_bus_value = m_pullup ? (1u << (m_size) ) - 1 : 0;

//  std::cout << "Checking bus connections for " << fullname() << "\n";


  Connection * lastconnector = nullptr;

  for(auto connector : m_connections) {
    if(connector->direction() == Connection::Output) {



      // In theory we could have set multiple bits here.
      // TODO: Assert a bit mask of what's been set vs what we're about to set?
      //  assert(valueset == false);

      BusValue applied_mask = connector->applyOutputValue(&new_bus_value);


      if(applied_mask & bus_applied_mask) {
        // If there's any overlap between what we've already set, and what something else has set, then we have contention
        std::cout << "CONTENTION - Output value for bus " << name() << " set again by " << connector->name() << " of " << connector->parent()->name() << ".\n";
        std::cout << "Previous set by " << lastconnector->name() << " of " << lastconnector->parent()->name() << ". Previous mask was " << bus_applied_mask << "\n";
      }

      bus_applied_mask |= applied_mask;


      if(applied_mask) {
        lastconnector = connector;
      }


    }
  }

//  std::cout << "New output value is " << new_bus_value << " old value is " << m_value << "\n";

  if(bus_applied_mask == 0x0) {
    std::cout << "No value has been set- floaty?";
  }

  if(new_bus_value == m_value) return; // No change

  m_value = new_bus_value;

  // If the value has changed, mark the target gates as needing recalculating.
  for(auto connector : m_connections) {
    if(connector->direction() == Connection::Input) {
      eventLoop.addGateToRecalculate(connector->gate());
    }
  }


}

Bus::Bus(std::string  name, CircuitItem *parent, uint8_t size, bool pullup, Pin *pin1, Pin *pin2) : CircuitItem(name, parent), m_size(size), m_pullup(pullup) {


  if(pin1) pin1->connect(this);
  if(pin2) pin2->connect(this);
}



std::string Bus::status()
{
  return "[BUS]\t" + std::to_string(m_value);
}

uint8_t Bus::size() const {
  return m_size;
}
