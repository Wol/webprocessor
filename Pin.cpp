
#include <cassert>
#include "Pin.h"


/**
 * Connects this external facing pin to an internal 'Connection' in a Gate (or another internal Pin)
 * This doesn't care about which gates it's connected to, only their Connections.
 * @param connection
 */
void Pin::addInternalConnection(Connection &connection, uint8_t bit_offset) {

  assert(connection.size() <= m_size);
  m_connections[&connection] = bit_offset;
}

/**
 * As above, just this connects to another pin for when there are nested circuit items
 * @param pin
 * @param bit_offset
 */
void Pin::addInternalPin(Pin &pin, uint8_t bit_offset) {

  assert(pin.size() <= m_size);
  m_pins[&pin] = bit_offset;
}



/**
 * This connects a specific bus onto the given pin at the given bit offset. This will proxy the call to any child
 * pins or connections added via the addInternal* methods
 * @param bus
 * @param bit_offset
 */
void Pin::connect(Bus *bus, uint8_t bit_offset) {

  for(auto pin: m_pins) {
    // .first is the pointer to the pin we want to connect
    // .second is the bit offset within the bus this pin should look at
    // however, we also have a bit_offset passed in in case this is recursive.
    pin.first->connect(bus, bit_offset + pin.second);
  }

  for(auto connection: m_connections) {
    // .first is the connection pointer itself.
    // .second is the bit offset within the bus this connection should look at.
    connection.first->connect(bus, bit_offset + connection.second);
  }

}

Pin::Pin(uint8_t mSize) : m_size(mSize) {


}
