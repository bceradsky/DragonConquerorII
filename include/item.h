#include <string>

using namespace std;

class Item {
private:
  string name;
  string type;
  int atk;
  int def;
public:
  Item(string itemName, string itemType, int itemAtk = 0, int itemDef = 0) {
    name = itemName;
    type = itemType;
    atk = itemAtk;
    def = itemDef;
  }

  void getInfo();
  string getName() const;
  string getType();
  int getAtk();
  int getDef();
};

/*
class Potion {
private:
  string name;
  int hlthChange;
public:
  Potion(string potionName, int potionHealth) {
    name = potionName;
    hlthChange = potionHealth;
  }
  ~Potion();
};
*/
