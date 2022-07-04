#include <iostream>
#include "Processor.h"
#include "EventLoop.h"

int main() {


  Processor p;

  BusValue i = 149;
  BusValue j = 37;

  BusValue sub = 0;
  BusValue enable_b = 1;

//
//  for (i = 0; i <= 255; i+=5) {
//    for (j = 0; j <= 255; j+=5) {

      p.setInputs(i, j, sub, enable_b);
      p.tick();
      std::cout << "I1: " << i << " I2: " << j << "   Out: " << p.getSumOutput()  << " " << "\n";


//      Circuit::debugAllItems();

//
//    }
//  }


//  p.setInputs(1, 1);output value f
//  p.tick();
//  std::cout << "I1: " << 1 << " I2: " << 1 << " Out: " << p.getOutput() << "\n";

}
