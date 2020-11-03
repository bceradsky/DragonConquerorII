#include <iostream>
#include <string>
#include <windows.h>
#include "../include/funcs.h"
#include "../include/global.h"
#include "../include/tinyxml2.h"
#include "../include/player.h"



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
  Item sword("Sword 1", "sword", 5);
  Item sword2("Sword 2", "sword", 5);

  inventory.addItem(sword);
  inventory.addItem(sword2);

  inventory.search("SworD");

}
