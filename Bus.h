
#ifndef BUS_H
#define BUS_H


#include <cstdint>
#include <set>
#include "CircuitItem.h"

typedef uint32_t BusValue;

class Connection;
class Pin;
class EventLoop;

class Bus : public CircuitItem {


public:
    Bus(std::string  name, CircuitItem *parent, uint8_t size, bool pullup = false, Pin *pin1 = nullptr, Pin *pin2 = nullptr);

    [[nodiscard]] BusValue value() const;


    void addConnection(Connection *connector);

    void update(EventLoop &eventLoop);

    uint8_t size() const;

    std::string status() override;

private:
    BusValue m_value = 0;

    bool m_pullup = false;
    bool m_debug = false;
    uint8_t m_size = 0;

    std::set<Connection *> m_connections;

};


#endif
