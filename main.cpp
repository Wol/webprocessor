#include <iostream>
#include "Processor.h"

int main() {


  Processor p;

  BusValue i = 149;
  BusValue j = 37;

  BusValue sub = 0;
  BusValue enable_b = 1;

//
  for (i = 0; i <= 255; i+=5) {
    std::cout << "\n";
    for (j = 0; j <= 255; j+=5) {
      for (sub = 0; sub < 2; ++sub) {
        for (enable_b = 0; enable_b < 2; ++enable_b) {

          p.setInputs(i, j, sub, enable_b, 0);
          p.tick();

          uint8_t expected = (i) + ( sub ? -1 : 1) * (enable_b ? j : 1);

          if((expected != p.getSumOutput())){
            std::cout << "Wrong!!!!" << i << " " << (sub == 0 ? "+" : "-") << " " << (enable_b ? j : 1) << " = " << p.getSumOutput()  << " " << (expected == p.getSumOutput()) << "\n";
            Circuit::debugAllItems();
          } else {
            std::cout << "✓";
          }



        }
      }
    }
  }

  std::cout << "\n";
  Circuit::debugAllItems();


}
