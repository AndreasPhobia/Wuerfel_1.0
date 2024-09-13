#include "SkillDice.h"
#include <iostream>
using namespace std;

// Konstruktor von SkillDice: Fragt den Benutzer nach einem Bonuswert
SkillDice::SkillDice(int s) : Dice(s) {
	cout << "Gib deinen Faehigkeitswert als Bonus ein: ";
	cin >> skillBonus; // Benutzer gibt den Bonuswert ein
}

int SkillDice::roll() const {
	return Dice::roll();
}
