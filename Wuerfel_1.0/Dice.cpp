#include "Dice.h"
#include <iostream>
using namespace std;

// Konstruktor: Initialisiert den W�rfel mit der Anzahl an Seiten
Dice::Dice(int s) : sides(s) {}

// roll() -Methode: Gibt eine zuf�llige Zahl zwischen 1 und der Anzahl der Seiten zur�ck
int Dice::roll() const {
	return (rand() % sides) + 1; // Zufallszahl zwischen 1 und sides
}

// Destruktor
Dice::~Dice() {}