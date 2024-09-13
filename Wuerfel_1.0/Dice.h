#pragma once
#include <iostream>
using namespace std;

// Eltern-Klasse f�r den W�rfel
class Dice{
protected:
	int sides; // Anzahl der Seiten des W�rfels (W6, W8, W10, etc.)

public:
	// Konstruktor: Initialisiert den W�rfel mit einer bestimmten Anzahl von Seiten
	Dice(int s);

	//Methode zum W�rfeln: Gibt eine zuf�llige Zahl zwischen 1 un der Anzahl der Seiten zur�ck
	virtual int roll() const;

	// Virtueller Destruktor: Wird verwendet, um sicherzustellen, dass Kindklassen korrekt gel�scht werden
	virtual ~Dice();
}; 

