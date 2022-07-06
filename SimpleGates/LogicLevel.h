
#ifndef LOGICLEVEL_H
#define LOGICLEVEL_H

#include "../CircuitItem.h"
#include "../Pin.h"

class LogicLevel : public CircuitItem {

public:
    explicit LogicLevel(std::string  name, CircuitItem *parent, uint8_t size, int direction);

    void update() override;

    Pin IO;

    void setOutputValue(BusValue i);

    BusValue getInputValue();


private:
    Connection _io;

};


#endif
