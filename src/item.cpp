#include <iostream>
#include <string>
#include "../include/item.h"
#include "../include/funcs.h"

using namespace std;

void Item::getInfo() {
  string atk_string = to_string(atk);
  string def_string = to_string(def);
  slowText(name);
  cout << "\n";
  slowText(type);
  cout << "\n";
  slowText(atk_string);
  cout << "\n";
  slowText(def_string);
  cout << "\n";
}

string Item::getName() const {
  return name;
}

string Item::getType() {
  return type;
}

int Item::getAtk() {
  return atk;
}

int Item::getDef() {
  return def;
}
