
#include "ALU.h"

ALU::ALU(std::string name, CircuitItem *parent) :
        CircuitItem(name, parent),

        B_Input_Xors{
                {"B_Xor_0", this},
                {"B_Xor_1", this},
                {"B_Xor_2", this},
                {"B_Xor_3", this},
                {"B_Xor_4", this},
                {"B_Xor_5", this},
                {"B_Xor_6", this},
                {"B_Xor_7", this},
        },
        B_Input_Or("B_Input_Or", this),
        B_Input_Ands{
                {"B_And_1", this},
                {"B_And_2", this},
                {"B_And_3", this},
                {"B_And_4", this},
                {"B_And_5", this},
                {"B_And_6", this},
                {"B_And_7", this},
        },
        Adder("Adder", this, 8),
        B_Xored("XOred_B", this, 8, false),
        B_Anded("Anded_B", this, 8, false),
        B_Bus_Enable_Not("B_Bus_Enable_Not", this),
        B_Bus_Enable_Inverted("B_Bus_Enable_Inverted", this, 1, false)

{


  B_Bus_Enable.addInternalConnection(B_Bus_Enable_Not.In);
  B_Bus_Enable_Not.Out.connect(&B_Bus_Enable_Inverted);

  // The Subtract pin XOr's (inverts) the B bus
  for(int i = 0; i < 8; i++) {

    if(i == 0) {
      B.addInternalConnection(B_Input_Or.A, i);
      B_Input_Or.B.connect(&B_Bus_Enable_Inverted);
      B_Input_Or.Out.connect(&B_Anded, i);
    } else {
      B.addInternalConnection(B_Input_Ands[i - 1].A, i);
      B_Bus_Enable.addInternalConnection(B_Input_Ands[i - 1].B);
      B_Input_Ands[i - 1].Out.connect(&B_Anded, i);
    }

    // Connect the And gate output to the XOr bus input.
    B_Input_Xors[i].A.connect(&B_Anded, i);
    Subtract.addInternalConnection(B_Input_Xors[i].B);

    B_Input_Xors[i].Out.connect(&B_Xored, i);
  }

  Subtract.addInternalPin(Adder.Carry_In);


  Adder.B.connect(&B_Xored);
  A.addInternalPin(Adder.A);

  DataBus.addInternalPin(Adder.Sum);

}
