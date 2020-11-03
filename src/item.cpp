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


// Sword funcs


// Armor funcs


// Potion funcs
int Potion::getHealing() {
  return healing;
}


// Chest funcs
void Chest::openChest() {
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  int c = rand() % 10 + 1;
  chest.push_back(a);
  chest.push_back(b);
  chest.push_back(c);
  slowText("You open the chest...\n");
  slowText("You got: \n");
  slowText(to_string(a));
  cout << "\n";
  slowText(to_string(b));
  cout << "\n";
  slowText(to_string(c));
  cout << "\n";
}
