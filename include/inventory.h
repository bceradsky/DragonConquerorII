#include "item.h"

using namespace std;

class Inventory {
private:
  vector<Item> inventory;
public:
  void showInventory();
  void addItem(Item item);
  void search(string s);
};
