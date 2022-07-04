
#ifndef GATE_H
#define GATE_H

#include <vector>

#include "Connection.h"
#include "CircuitItem.h"

class EventLoop;


class Gate : public CircuitItem {
public:

    Gate(std::string  name, CircuitItem *parent);

    virtual void update(EventLoop &eventLoop) = 0;

};


#endif
