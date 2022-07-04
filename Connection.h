
#ifndef CONNECTION_H
#define CONNECTION_H

#include <cstdint>
#include "Gate.h"
#include "CircuitItem.h"


class Bus;
class EventLoop;
class Gate;


typedef uint32_t BusValue;

class Connection : public CircuitItem {

    friend class Gate;

public:

    Connection(Gate *gate, uint8_t size, int direction, std::string name);

    enum {
        Output = 0,
        Input = 1
    };

    Gate *gate() const;

    BusValue applyOutputValue(BusValue *value) const;
    [[nodiscard]] BusValue getBusValue() const;

    void setOutputValue(EventLoop &eventLoop, BusValue value);

    int direction() const;

    uint8_t size() const;


    void connect(Bus *bus, uint8_t bit_offset = 0);

    std::string status() override;

private:

    int m_direction = Output;

    uint8_t m_size = 0;
    Gate *m_gate;


    // Parent
    Bus *m_bus = nullptr;
    uint8_t m_bit_offset;


    BusValue m_outputvalue = 0;


};


#endif
