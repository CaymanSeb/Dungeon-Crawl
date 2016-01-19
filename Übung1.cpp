#include "stdafx.h"
#include <iostream>                  
#include <cmath>                     

using namespace std;

int main() {
	cout << "Bitte zwei Zahlen a, b eingeben:" << endl; //Gibt Satz in Console aus
	double p, q; //bestimmt zwei Variablen des Typ: double (float mit mehr Nachkommastellen)
	cin >> p >> q; //Verlangt vom Nutzer zwei Eingaben, welche in den Variablen p und q gespeichert werden
	double wert = p*p / 4.0 - q; //eine neue Variable wird festgelegt vom Typ double, der Wert errechnet sich aus den beiden eingegebenen Zahlen
	cout << "Ergebnis :" << endl;   /* Was wird hier ausgegeben? */// Falls mit diesem Blockkommentar nur diese Zeile gemeint ist: Es wird lediglich "Ergebnis :" ausgegeben.

	if (wert >= 0.0) { //Wenn der Wert der Variable "wert" größer oder gleich Null ist tue folgendes:
		double erg1 = -p / 2.0 + sqrt(wert); //neue double Variable "erg1" errechnet sich aus der: negativen ersten eingabe durch 2.0. Das ganze wird zur Wurzel des Wertes der Variable "wert" addiert.
		double erg2 = -p / 2.0 - sqrt(wert); //neue double Variable "erg2": dasselbe jedoch wird die Wurzel des Wertes der Variable "wert" subtrahiert.
		cout << "erg1= " << erg1 << " erg2= " << erg2 << endl; //Ausgabe beider zuvor errechneten Werte mit vorheriger Bezeichnung
	}
	else { //Wenn der Wert der Variable "wert" negativ ist (korrekt eigentlich kleiner als Null) wird dieser Zweig ausgeführt
		double wirklich = -p / 2.0; //neue Variable "wirklich" errechnet sich aus der negativen ersten Eingabe durch 2.0
		double unwirklich = sqrt(-wert);   /* (Wurzel aus negativer Zahl?) */ //neue Variable "unwirklich" Gibt die Wurzel des positiven Werts aus

		cout << "erg1= " << wirklich << " + " << unwirklich << " j" << endl; //Gibt die Bezeichnung "erg1=", den Wert der Variable "wirklich" - " + " - den Wert der Variable "unwirklich" und " j" aus
		cout << "erg2= " << wirklich << " - " << unwirklich << " j" << endl; //Gibt die Bezeichnung "erg1=", den Wert der Variable "wirklich" - " - " - den Wert der Variable "unwirklich" und " j" aus
	}
	return 0;
}
