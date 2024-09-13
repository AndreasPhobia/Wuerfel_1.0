#pragma once
#include "Dice.h"
using namespace std;

// Kindklasse f�r den magischen W�rfel
class MagicDice :
    public Dice
{ 
public:
    // Konstruktor: Initialisiert den magischen W�rfel mit einer bestimmten Anzahl an Seiten
    MagicDice(int s);

    // �berschreibt die roll() -Methode, um einen Bonus hinzuzuf�gen, ernn die h�chste Zahl geworfen wird
    int roll() const override;
};

