
#include <iostream>
#include "Processor.h"


Processor::Processor() :
        alu("ALU", this),
        A("A", this, 8, Connection::Output),
        B("B", this, 8, Connection::Output),
        Sum("Sum", this, 8, Connection::Input),
        X("Subtract", this, 1, Connection::Output),
        Y("B_Bus_Enable", this, 1, Connection::Output),
        Z("Z", this, 8, Connection::Output),

        a("a_bus", this, 8, false, &A.IO, &alu.A),
        b("b_bus", this, 8, false, &B.IO, &alu.B),
        sum_bus("sum_bus", this, 8, false, &alu.DataBus, &Sum.IO),
        x_bus("x_bus", this, 1, false, &X.IO, &alu.Subtract),
        y_bus("y_bus", this, 1, false, &Y.IO, &alu.B_Bus_Enable),
        z_bus("z_bus", this, 1, false),
        Circuit("Processor")
{


  // Z.IO.connect(&a);

}

void Processor::setInputs(BusValue a, BusValue b, BusValue x, BusValue y, BusValue z)
{

  A.setOutputValue(a);
  B.setOutputValue(b);
  X.setOutputValue(x);
  Y.setOutputValue(y);
  Z.setOutputValue(z);
}

BusValue Processor::getCarryOutput()
{
  return Y.getInputValue();
}


BusValue Processor::getSumOutput()
{
  return Sum.getInputValue();
}
