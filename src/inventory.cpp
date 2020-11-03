#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "../include/inventory.h"
#include "../include/funcs.h"
#include "../include/item.h"

using namespace std;

void Inventory::showInventory() {
  for (auto const& i: inventory) {
    slowText(i.getName(), 1);
    slowText(" ", 1);
  }
}

void Inventory::addItem(Item item) {
  inventory.push_back(item);
  slowText(item.getName());
  slowText(" has been added to your inventory.\n");
}

void Inventory::search(string s) {
  s = lowercase(s);
  bool found = false;
  for (int i = 0; i < inventory.size(); i++) {
    string temp = inventory[i].getType();
    if (temp.find(s) != string::npos) {
      slowText(inventory[i].getName());
      cout << "\n";
      found = true;
    }
  }
  if (!found) {
    slowText("Item not found in inventory.");
    cout << "\n";
  }
}
