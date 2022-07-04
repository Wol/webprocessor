
#include "NBitAdder.h"
#include "../Circuit.h"

NBitAdder::NBitAdder(std::string mName, CircuitItem *mParent, uint8_t size) :
        CircuitItem(mName, mParent),
        A(size),
        B(size),
        Sum(size)
        {


  for(int i = 0; i < size; i++){
    Adders.push_back(new FullAdder("Adder" + std::to_string(i), this));

    A.addInternalPin(Adders[i]->A, i);
    B.addInternalPin(Adders[i]->B, i);

    Sum.addInternalPin(Adders[i]->Sum, i);

    if(i > 0) {
      Bus * carry = new Bus("Carry" + std::to_string(i - 1) + std::to_string(i), this,1);
      Adder_Carry.push_back(carry);
      // As carry buses go between adders, we only need size-1 to go between.
      Adders[i - 1]->Carry_Out.connect(carry);
      Adders[i]->Carry_In.connect(carry);
    }
  }

  Carry_In.addInternalPin(Adders[0]->Carry_In);
  Carry_Out.addInternalPin(Adders[size - 1]->Carry_Out);


}
