#include "../include/player.h"
#include "../include/funcs.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Player::getName() {
  return name;
}

int Player::getHealth() {
  return health;
}

int Player::getAtk() {
  return atk;
}

int Player::getDef() {
  return def;
}

void Player::equip(Item item) {
  string itm;
  if ((item.getName().find("Sword") != string::npos) || (item.getName().find("Excalibur") != string::npos)) {
    itm = "a sword";
  } else if (item.getName().find("Armor") != string::npos) {
    itm = "armor";
  }
  if (holding.size() != 0) {
    for (int i = 0; i < holding.size(); i++) {
      if (holding[i].getType() == item.getType()) {
        slowText("You already have ");
        slowText(itm);
        slowText(" equipped. Would you like to change?\n");
        string ans;
        cin >> ans; // Replace with Lexicon
        if (ans == "yes") {
          holding.erase(holding.begin() + i);
          cout << "\n";
          doEquip(item);
          break;
        }
      } else {
        doEquip(item);
      }
    }
  } else {
    doEquip(item);
  }
}

void Player::doEquip(Item item) {
  holding.push_back(item);
  atk += item.getAtk();
  def += item.getDef();
  slowText(item.getName());
  slowText(" has now been equipped.");
}

void Player::showEquipped() {
  for (int i = 0; i < holding.size(); i++) {
    cout << holding[i].getName() << "\n";
  }
}

void Player::healthChange(int chg) {
  slowText("Current Health: ");
  slowText(to_string(getHealth()));
  cout << ".\n";
  health += chg;
  slowText("Updated Health: ");
  slowText(to_string(getHealth()));
  cout << ".\n";
}

void Player::usePotion(Potion p) {
  slowText("You decide to drink the potion.\n");
  healthChange(p.getHealing());
}
