/******************************************************/
/* Autor: Thomas Lödige                               */
/* Datum: 30.10.2016                                  */
/* Projekt: P5A2                                      */
/* Beschreibung: Berechnung von p und q				  */
/******************************************************/

// fehlerbehebung wegen scanf
#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>	// Bibliotheken einbinden
#include<math.h>

// Definitionen

int main(void) {	// Hauptteil
	float a = 0.0, b = 0.0, c = 0.0, x1 = 0.0, x2 = 0.0, p1 = 0.0, q1 = 0.0, p2 = 0.0, q2 = 0.0;		// Initialisierungen
	int fall = 1, wahl = 0;

	while (wahl != 3) {		// Endlosschleife mit Bedingung
		printf("Geben sie vorerst ein womit sie \ndiese Rechnung durchfuehren moechten.\n\n1: mit der If- Schleife\n2: mit der Switch/Case- Methode\n3: beendet das Programm!");
		printf("\n\nIhre Angabe:\t");			// Textausgabe
		scanf("%i", &wahl);

		if (wahl != 3) {		// Bedingung die erfuellt sein muss damit die unten ausgefuehrten Befehle auch ausgefuehrt werden.
			printf("Geben sie ihre drei Werte fuer \na*x^2, b*x und c (also a, b und c) ein.\n\n");
			printf("a:\t");
			scanf("%f", &a);	// a/b/c Zahl eingeben
			printf("b:\t");
			scanf("%f", &b);
			printf("c:\t");
			scanf("%f", &c);
			printf("\n");		// Zeilensprung
		}

		if (c != 0.0) fall = fall + 1;		// überprüft welcher fall auftritt
		if (b != 0.0) fall = fall + 2;
		if (a != 0.0) fall = fall + 4;

		// Für die zweite untere Rechnung. Hier oben weil sich beim Programmdurchlauf die Werte
		// von a, b und c ändern.
		if (fall == 8 || fall == 6) {
			p2 = b / a;
			q2 = c / a;
		}

		if (wahl == 1) {		// Wenn der Wert erfuellt ist dann fuehrt er die IF- Bedingungen durch
			if (a == 0) {
				if (b == 0) {
					if (c == 0) {
						printf("Triviale Gleichung!\n\n\n");	// fall 1
					}
					else {
						printf("Wiederspruch!\n\n");		// fall 2
					}
				}
				else {
					if (c == 0) {
						x1 = 0.0;				// Setzt den Wert von x auf 0	// fall 3
						printf("Lineare Gleichung!\naus a, b, c: x1 = 0.\n");
					}
					else {			
						x1 = -c / b;			// fall 4
						x2 = -c / b;			// Rechnet x1 und x2 aus
						printf("Lineare Gleichung! x1 = %.2f und x2 = %.2f.\n", x1, x2);
					}
				}
			}
			else {
				if (b == 0) {
					if (c == 0) {
						x1 = 0.0;			// fall 5
						x2 = 0.0;
						printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
					}
					else {
						if (-c / a >= 0.0) {		// fall 6
							x1 = sqrt(-c / a);		// Rechnet x1 und x2 aus
							x2 = -sqrt(-c / a);
							printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);	
						}
						else {
							printf("-c / a ist nicht groesser als 0\n\n\n");		// Fehlermeldung für fall 6
							wahl = 4;		// Damit das Programm Satz von Vieta NICHT ausrechnet
						}
					}
				}
				else {
					if (c == 0) {
						x1 == 0.0;		// fall 7
						x2 = -b / a;
						printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
					}
					else {
						if (pow(b, 2) >= 4 * a * c) {		// fall 8
							x1 = (1.0 / (2.0 * a)) * (-b + sqrt(pow(b, 2) - 4.0 * a * c));		// Rechnet x1 und x2 aus
							x2 = (1.0 / (2.0 * a)) * (-b - sqrt(pow(b, 2) - 4.0 * a * c));
							printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
						}
						else {
							printf("b^2 ist nicht groesser als 4 * a * c\n\n\n");	// Fehlermeldung für fall 8
							wahl = 4;		// Damit das Programm Satz von Vieta NICHT ausrechnet
						}
					}
				}
			}
		}

		if (wahl == 2) {
			switch (fall) {		// Es soll den Wert von der Variable auslesen und dementsprechend der folgenden case Befehle aussuchen.
			case 1:				// erfuellt wenn fall = 1 ist
				printf("Triviale Gleichung!\n\n");
				break;			// verlaesst die switch/case- Bedingung

			case 2:				// fall 2
				printf("Wiederspruch!\n\n");
				break;

			case 3:				// fall 3
				x1 = 0.0;		// setzt x = 0
				printf("Lineare Gleichung!\naus a, b, c: %.2f.\n\n", x1);
				break;
			case 4:				// fall 4
				x1 = -c / b;		// Rechnet x1 und x2 aus
				x2 = -c / b;
				printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n\n\n", x1, x2);
				break;

			case 5:				// fall 5
				x1 = 0.0;
				x2 = 0.0;
				printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n\n\n", x1, x2);
				break;

			case 6:				// fall 6
				if (-c / a >= 0.0) {
					x1 = sqrt(-c / a);		// rechnet x1 und x2 aus
					x2 = -sqrt(-c / a);
					printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
				}
				else {
					printf("-c / a ist nicht groesser als 0\n\n");		// Fehlermeldung für fall 6
					wahl = 4;
				}
				break;

			case 7:				// fall 7
				x1 = 0.0;
				x2 = -b / a;
				printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
				break;

			case 8:				// fall 8
				if (pow(b, 2) >= 4 * a * c) {
					x1 = (1.0 / (2.0 * a)) * (-b + sqrt(pow(b, 2) - 4.0 * a * c));		// Rechnet x1 und x2 aus
					x2 = (1.0 / (2.0 * a)) * (-b - sqrt(pow(b, 2) - 4.0 * a * c));
					printf("aus a, b, c: x1 = %.2f, x2 = %.2f\n", x1, x2);
				}
				else {
					printf("b^2 ist nicht groesser als 4 * a * c\n\n");		// Fehlermeldung für fall 8
					wahl = 4;
				}
				break;

			default:		// Bei einem Wert welches nicht bei den case vorliegen, wird dies hier ausgefuehrt. Also nur eine Textausgabe und verlassen des Sw/Case- Bedingungs
				printf("ungueltiger Wert!\n\n\n");
				break;
			}
		}

		if (fall > 2 && fall < 9 && wahl != 4) {
			// Fuer P-Q-Formel
			if (a > 0) {		// Sonst kommen da ungueltige werte raus
				b = b / a;
				c = c / a;
				x1 = -(b / 2.0) + sqrt(pow(b / 2.0, 2) - c);
				x2 = -(b / 2.0) - sqrt(pow(b / 2.0, 2) - c);
				printf("Aus dem P-Q Formel: x1 = %.2f, x2 = %.2f\n", x1, x2);
			}
			else if (a < 0 && wahl != 4) {		// Damit a einen Positiven Wert hat
				a = a * (-1);
				b = b * (-1);
				c = c * (-1);
				b = b / a;			// b geteilt a
				c = c / a;
				x1 = -(b / 2.0) + sqrt(pow(b / 2.0, 2) - c);	// x1 ausrechnen
				x2 = -(b / 2.0) - sqrt(pow(b / 2.0, 2) - c);	// x2 ausrechnen
				printf("Aus dem P-Q Formel: x1 = %.2f, x2 %.2f\n", x1, x2);		// werte von x1 und x2 ausgeben
			}
			else {
				printf("Rechnung mit P-Q-Formel nicht möglich da a gleich 0 ist.\n");	// Fehlermeldung für P-Q-Formel
			}
		}
		// Satz von Vieta
		if (fall == 8 && wahl != 4 || fall == 6 && wahl != 4) {
			p1 = x1 + x2;		// p und q werden berechnet
			p1 = p1 * (-1);
			q1 = x1 * x2;
			printf("\nNach Vieta p: %.2f q: %.2f\nNach a, b, c p: %.2f q: %.2f\n\n", p1, q1, p2, q2);
			printf("Der %i.te Fall traf zu.\n", fall);		// gibt den fall aus der zu traf
			printf("\n\n\n\n\n\n");		// Zeilenspruenge
		}
		else {
			printf("Der %i.te Fall traf zu.\n", fall);		// gibt den fall aus der zu traf
			printf("\n\n\n\n\n\n");		// Zeilenspruenge
		}
		fall = 1;	// setzt den Wert auf 1 damit er oben bei der IF- Bedingung keine fehlrechnung macht.
	}
	return(1);		// Rueckgabewert
}