
#ifndef CONNECTION_H
#define CONNECTION_H

#include <cstdint>
#include "CircuitItem.h"


class Bus;

typedef uint32_t BusValue;

class Connection : public CircuitItem {


public:

    Connection(std::string name, CircuitItem *parent, uint8_t size, int direction);

    enum {
        Output = 0,
        Input = 1
    };

    BusValue applyOutputValue(BusValue *value) const;
    [[nodiscard]] BusValue getBusValue() const;

    void setOutputValue(BusValue value);

    [[nodiscard]] int direction() const;

    [[nodiscard]] uint8_t size() const;


    void connect(Bus *bus, uint8_t bit_offset = 0);

    std::string status() override;

private:

    int m_direction = Output;

    uint8_t m_size = 0;

    // Parent
    Bus *m_bus = nullptr;
    uint8_t m_bit_offset;


    BusValue m_outputvalue = 0;


};


#endif
