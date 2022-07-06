
#ifndef PIN_H
#define PIN_H

#include "Connection.h"
#include <map>

/**
 * A Pin is a Proxy for multiple connections. This is used when a "Gate" contains multiple "Gates", where an external
 * pin/connection connects to multiple Gates internally.
 */
class Pin : public CircuitItem {

public:

    Pin(const std::string &mName, CircuitItem *mParent, uint8_t mSize);


    void addInternalConnection(Connection &connection, uint8_t bit_offset = 0);
    void addInternalPin(Pin &pin, uint8_t bit_offset = 0);

    void connect(Bus *bus, uint8_t bit_offset = 0);

    [[nodiscard]] uint8_t size() const {
      return m_size;
    }

    std::string status() override;


private:

    // We can use a map here to store the internal connections as we'll never have a state where
    // one pin will be connected to the _same_ connection multiple times as that's the equivalent
    // of shorting two parts together.
    std::map<Connection *, uint8_t> m_connections;

    // As we can have Pin > Connection (connections have the actual value/state/IO), as well as
    // Pin > Pin wirings, we keep two separate lists here.
    std::map<Pin *, uint8_t> m_pins;


    Bus *m_bus = nullptr;

    uint8_t m_size = 0;

};


#endif
