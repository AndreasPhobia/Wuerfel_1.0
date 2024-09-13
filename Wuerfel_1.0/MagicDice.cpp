#include "MagicDice.h"
#include <iostream>
using namespace std;

// Konstruktor von MagicDice: Ruft den Konstruktor der Elternklasse Dice auf
MagicDice::MagicDice(int s) : Dice (s) {}

// roll() -Methode von MagicDice: f�gt einen Bonus hinzu, wenn der h�chste Wert geworfen wird
int MagicDice::roll() const {
	int result = Dice::roll(); // F�hrt den normalen W�rfelwurf durch
	if (result == sides) { // Wenn die h�chste Zahl gewordfen wird
		cout << "Magischer Bonus! Extra Punkte!" << endl;
		result += 5; // F�ge 5 Bonuspunkte hinzu
	}
	return result;
}
