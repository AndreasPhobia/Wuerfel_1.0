#pragma once
#include "Dice.h"
using namespace std;

// Kindklasse f�r den Schadensw�rfel
class DamageDice :
    public Dice
{ 
private: 
    int bonus; // speichert den Schadensbonus

public:
    // Konstrukto: Initialisiert den Schadensw�rfel mit Seiten und Bonus
    DamageDice(int s, int b);

    // �berschreibt die roll() -Methode, um den Schadensbonus zum Ergebnis hinzuzuf�gen
    int roll() const override;

};

