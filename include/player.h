#include "item.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Player {
private:
  string name;
  int health = 100;
  int atk = 1;
  int def = 1;

  vector<Item> holding;
public:
  Player(string playerName) {
    name = playerName;
  }

  string getName();
  int getHealth();
  int getAtk();
  int getDef();

  void equip(Item item);
  void showEquipped();
  void doEquip(Item item);
  void healthChange(int chg);
  void usePotion(Potion p);
  void useItem(Item item);
};
