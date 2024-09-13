#include "MagicDice.h"
#include "DamageDice.h"
#include "SkillDice.h"
#include <iostream>
using namespace std;

// Diese Funktion steuert den Ablauf des W�rfelns
void DiceAndRoll() {
    int diceType;           // Variable f�r den vom Benutzer gew�hlten W�rfel
    int Rolls;              // Anzahl der W�rfe
    int numberOfDice;       // Anzahl der W�rfel, die der Benutzer werfen m�chte
    int totalPoints = 0;    // Variable f�r die Summe aller geworfenen Punkte
    Dice* diceArray[10];    // Array, um bis zu 10 W�rfel zu speichern
    int maxDice = sizeof(diceArray) / sizeof(diceArray[0]); // Maximale Anzahl von W�rfeln im Array

    // Auswahl des W�rfeltyps
    cout << "Waehle einen Wuerfel: \n";
    cout << "1. W4\n";
    cout << "2. W6\n";
    cout << "3. W8\n";
    cout << "4. W10\n";
    cout << "5. W20\n";
    cout << "6. W100\n";
    cout << "7. Magischer W6\n";
    cout << "8. Schadenswurf W12\n";
    cout << "9. Faehigkeitswurf W10 mit Skill-Bonus\n";
    cin >> diceType; // Benutzer w�hlt den W�rfeltyp

    // Abfrage, wie viele W�rfel geworfen werden sollen
    cout << "Wie viele Wuerfel moechtest du werfen? (Max. " << maxDice << "): ";
    cin >> numberOfDice;

    // �berpr�fen, ob die Anzahl der W�rfel g�ltig ist
    if (numberOfDice <= 0 || numberOfDice > maxDice) {
        cout << "Ungueltige Anzahl an Wuerfeln!" << endl;
        return;
    }

    // Initialisieren der W�rfel im Array basierend auf der Benutzerauswahl
    for (int i = 0; i < numberOfDice; ++i) {
        switch (diceType) {
        case 1: diceArray[i] = new Dice(4); // Normaler W4
            break;
        case 2: diceArray[i] = new Dice(6); // Normaler W6
            break;
        case 3: diceArray[i] = new Dice(8); // Normaler W8
            break;
        case 4: diceArray[i] = new Dice(10); // Normaler W10
            break;
        case 5: diceArray[i] = new Dice(20); // Normaler W20
            break;
        case 6: diceArray[i] = new Dice(100); // Normaler W100
            break;
        case 7: diceArray[i] = new MagicDice(6); // Magischer W6
            break;
        case 8: diceArray[i] = new DamageDice(12, 3); // Schadensw�rfel W12 +3
            break;
        case 9: diceArray[i] = new SkillDice(10); // Skillw�rfel W10 mit Benutzerdefiniertem Bonus
            break;
        default:
            cout << "Ungueltige Wahl!" << endl; // Wenn die Auswahl ung�ltig ist
            return;
        }
    }

    // Abfrage, wie oft der Benutzer w�rfeln m�chte
    cout << "Wie oft moechtest du wuerfeln? ";
    cin >> Rolls;

    // �berpr�fen, ob die Anzahl der W�rfe g�ltig ist
    if (Rolls <= 0) {
        cout << "Ungueltige Anzahl von Wuerfen!" << endl;
        return;
    }

    // W�rfeln und Ergebnisse sammeln
    for (int i = 0; i < numberOfDice; ++i) { // F�r jeden W�rfel im Array
        cout << "Wuerfeln mit Wuerfel " << (i + 1) << ":" << endl;
        for (int j = 0; j < Rolls; ++j) { // F�r die angegebene Anzahl an W�rfen
            int result = diceArray[i]->roll(); // Ergebnis jedes Wurfs
            cout << "Wurf " << (j + 1) << ": " << result << endl;
            totalPoints += result; // Addiere die Ergebnisse
        }
    }

    // Gesamtergebnis anzeigen
    cout << "Gesamtsumme der Punkte: " << totalPoints << endl;

    // Speicher freigeben
    for (int i = 0; i < numberOfDice; ++i) {
        delete diceArray[i]; // Freigeben des Speichers f�r jeden W�rfel im Array
    }
}

// Hauptprogramm
int main() {
    srand(time(0)); // Initialisieren des Zufallsgenerators

    char repeat = 'j'; // Variable zur Steuerung der Wiederholung des Programms
    while (repeat == 'j') {
        DiceAndRoll(); // Aufruf der Funktion zum W�rfeln
        cout << "Erneut wuerfeln? (j/n): ";  // Fragt den Benutzer, ob er erneut w�rfeln m�chte
        cin >> repeat;
    }
    return 0;
}