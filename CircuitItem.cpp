
#include "CircuitItem.h"

#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Circuit.h"

CircuitItem::CircuitItem(std::string name, CircuitItem *parent) : m_name(std::move(name)), m_parent(parent) {
  Circuit::Items.push_back(this);
}


std::string CircuitItem::name() {
  return m_name;
}

CircuitItem *CircuitItem::parent() {
  return m_parent;
}


void CircuitItem::enableDebug()
{
  m_debug = true;
}

std::string CircuitItem::fullname()
{
  std::string _fullname = m_name;

  CircuitItem* recurs = m_parent;

  while(recurs) {

    _fullname = recurs->m_name + "," + _fullname;

    recurs = recurs->m_parent;
  }



  return _fullname;
}

std::string CircuitItem::status()
{
  return "[---]\t-";
}

