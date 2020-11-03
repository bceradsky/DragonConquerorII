#include <iostream>
#include <string>
#include <windows.h>
#include "../include/item.h"
#include "../include/funcs.h"
#include "../include/global.h"
#include "../include/tinyxml2.h"
#include "../include/player.h"
#include "../include/inventory.h"



using namespace std;
using namespace tinyxml2;

int main() {
  clearScreen();
  setWindow(100, 50);
  int dx=1,i=5,l=0;
  // This is really bad, but it works
  while(l<5) {
    i=i+dx;
    if( (i<1) || (i>10)){ dx=-dx; l++;}

    setWindow(10*i,5*i);
  }

  //titleScreen();
  //Sleep(5000);
  slowText("What is your name, brave adventurer?\n");
  string name;
  getline(cin, name);
  Player player(name);
  clearScreen();
  Inventory inventory;

  Potion pot("Test Potion", 100);

  inventory.addItem(pot);
  inventory.showInventory();

  player.usePotion(pot);
  cout << "\n\n\n";

  Chest test("Test Chest");
  test.openChest();
}
