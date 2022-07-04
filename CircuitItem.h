
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


    virtual std::string status();

protected:

    std::string   m_name = nullptr;

    CircuitItem *m_parent = nullptr;

    bool m_debug = false;

private:



};


#endif
