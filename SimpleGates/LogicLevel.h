
#ifndef LOGICLEVEL_H
#define LOGICLEVEL_H

#include "../Gate.h"
#include "../Pin.h"

class LogicLevel : public Gate {

public:
    explicit LogicLevel(std::string  name, CircuitItem *parent, uint8_t size, int direction);

    void update(EventLoop &eventLoop) override;

    Pin IO;

    void setOutputValue(EventLoop &eventLoop, BusValue i);

    BusValue getInputValue();


private:
    Connection _io;

};


#endif
