
#include <iostream>
#include <utility>
#include "Circuit.h"
#include <iomanip>

std::vector<CircuitItem *> Circuit::Items;
std::list<CircuitItem *> Circuit::ItemsToRecalculate;
Bus *Circuit::Ground_Bus = nullptr;
Bus *Circuit::Power_Bus = nullptr;

void Circuit::tick() {


  while (!ItemsToRecalculate.empty()) {
    ItemsToRecalculate.front()->update();
    ItemsToRecalculate.pop_front();
  }


}

Circuit::Circuit(std::string mName) : CircuitItem(std::move(mName), nullptr) {

  Ground_Bus = new Bus("GROUND", this, 1, false);
  // Power_Bus = new Bus("POWER", this, 1, true);

}


void Circuit::debugAllItems() {

  for (auto &item: Items) {
    std::cout << std::left << std::setw(40) << item->status() << " " << item->fullname() << "\n";
  }

}

