
#include <cassert>
#include <iostream>
#include "EventLoop.h"

EventLoop::EventLoop(Circuit *circuit) : circuit(circuit) {





}

void EventLoop::tick() {
  /**
   * Loop through each Gate and get a list of buses changed
   * Loop through each changed bus, and get a list of Gates changed
   */

  bool needsprocessing = true;

  while(needsprocessing){


    for(auto gate: changed_gates) {
      gate->update(*this);
    }

    changed_gates.clear();

    for(auto bus: changed_buses){
      bus->update(*this);

    }

    changed_buses.clear();


    needsprocessing = !changed_buses.empty() || !changed_gates.empty();

  }


}

void EventLoop::addGateToRecalculate(Gate *gate) {
  assert(gate);
  changed_gates.insert(gate);

}

void EventLoop::addBusToRecalculate(Bus *bus) {
  if(!bus) {
    std::cout << "no bus";
  }
  changed_buses.insert(bus);

}
