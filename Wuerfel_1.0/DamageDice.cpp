#include "DamageDice.h"
#include <iostream>
using namespace std;

// Konstruktor von DamageDice: Initialisiert den W�rfel und den Schadensbonus
DamageDice::DamageDice(int s, int b) : Dice(s), bonus(b) {}

//roll() -Methode von DamageDice: F�gt den Schadensbonus zum Ergebnis hinzu
int DamageDice::roll() const {
	int result = Dice::roll(); // F�hrt den normalen Wurf durch
	cout << "Shaden + Bonus: " << bonus << endl;
	return result + bonus; // f�gt den Bonus hinzu
}
