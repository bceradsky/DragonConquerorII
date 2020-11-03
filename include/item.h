#pragma once
#include <string>
#include <vector>

using namespace std;

class Item {
protected:
  string name;
  string type;
  int atk;
  int def;
  int healing;
public:
  Item(string itemName, string itemType) {
    name = itemName;
    type = itemType;
  }

  void getInfo();
  string getName() const;
  string getType();
  int getAtk();
  int getDef();
};

class Sword: public Item {
public:
  Sword(string itemName, int swdAtk, string itemType = "sword") : Item(itemName, itemType) {
    atk = swdAtk;
  }
};

class Armor: public Item {
public:
  Armor(string itemName, int armDef, string itemType = "armor") : Item(itemName, itemType) {
    def = armDef;
  }
};

class Potion: public Item {
public:
  Potion(string itemName, int potHealing, string itemType = "potion") : Item(itemName, itemType) {
    healing = potHealing;
  }

  int getHealing();
};

class Chest: public Item {
private:
  vector<int> chest;
public:
  Chest(string itemName, string itemType = "chest") : Item(itemName, itemType) {}

  void openChest();
};
