#pragma once
#include "Dice.h"
using namespace std;

// Kindklasse f�r den Skill-W�rfel
class SkillDice :
    public Dice
{
private:
    int skillBonus; // Speichert den benutzerdefinierten Bonus

public:

    // Konstruktor: Initialisiert den Skill-W�rfel und fragt den Benutzer nach einem Skillbonus
    SkillDice(int s);

    // �berscheibt die roll() -Methode, um den Skillbonus zum Ergebnis hinzuf�gen
    int roll() const override;

};
 