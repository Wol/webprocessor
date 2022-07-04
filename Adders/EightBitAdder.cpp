
#include "EightBitAdder.h"
#include "../Circuit.h";

EightBitAdder::EightBitAdder(std::string mName, CircuitItem *mParent) :
        CircuitItem(mName, mParent),
        Adders{
                {"Adder_0", this},
                {"Adder_1", this},
                {"Adder_2", this},
                {"Adder_3", this},
                {"Adder_4", this},
                {"Adder_5", this},
                {"Adder_6", this},
                {"Adder_7", this},
        },
        Adder_Carry{
                {"Carry_01", this, 1, false},
                {"Carry_12", this, 1, false},
                {"Carry_23", this, 1, false},
                {"Carry_34", this, 1, false},
                {"Carry_45", this, 1, false},
                {"Carry_56", this, 1, false},
                {"Carry_67", this, 1, false},
        } {

  for (int i = 0; i < 7; i++) {
    Adders[i].Carry_Out.connect(&Adder_Carry[i]);
    Adders[i + 1].Carry_In.connect(&Adder_Carry[i]);
  }

  for (int i = 0; i < 8; i++) {

    A.addInternalPin(Adders[i].A, i);
    B.addInternalPin(Adders[i].B, i);

    Sum.addInternalPin(Adders[i].Sum, i);
  }

  Carry_In.addInternalPin(Adders[0].Carry_In);
  Carry_Out.addInternalPin(Adders[7].Carry_Out);


}
