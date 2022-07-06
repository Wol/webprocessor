
#ifndef CIRCUITITEM_H
#define CIRCUITITEM_H

#include <string>
#include <vector>


class CircuitItem {

public:


    CircuitItem(std::string mName, CircuitItem *mParent);

    std::string   name();
    std::string   fullname();
    CircuitItem* parent();

    void enableDebug();

    void needsRecalculating();


    virtual std::string status();
    virtual void update();

protected:

    std::string   m_name = nullptr;

    CircuitItem *m_parent = nullptr;

    bool m_debug = false;

};


#endif
