
#include "FullAdder.h"


FullAdder::FullAdder(std::string  name, CircuitItem *parent) :
        CircuitItem(name, parent),

        AB_Xor("AB_Xor", this),
        AB_And("AB_And", this),
        AB_C_Xor("AB_C_Xor", this),
        AB_C_And("AB_C_And", this),
        Carry_Or("Carry_Or", this),
        AB_Xor_Out("AB_Xor_Out", this, 1, false),
        AB_And_Out("AB_And_Out", this, 1, false),
        AB_C_And_Out("AB_C_And_Out", this, 1, false)
{


  AB_Xor.Out.connect(&AB_Xor_Out);
  AB_C_Xor.A.connect(&AB_Xor_Out);
  AB_C_And.A.connect(&AB_Xor_Out);


  AB_C_And.Out.connect(&AB_C_And_Out);
  Carry_Or.A.connect(&AB_C_And_Out);


  AB_And.Out.connect(&AB_And_Out);
  Carry_Or.B.connect(&AB_And_Out);


  Carry_In.addInternalConnection(AB_C_And.B);
  Carry_In.addInternalConnection(AB_C_Xor.B);

  A.addInternalConnection(AB_Xor.A);
  A.addInternalConnection(AB_And.A);

  B.addInternalConnection(AB_Xor.B);
  B.addInternalConnection(AB_And.B);

  Sum.addInternalConnection(AB_C_Xor.Out);

  Carry_Out.addInternalConnection(Carry_Or.Out);

}

