#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand(static_cast<unsigned int>(time(0)));
	int secretNumber = rand() % 100 + 1, min = 0, max = 100;
	double secretNumber1 = secretNumber;
	int secretNumber2;
	int tries = 0;
	bool won = false;
	int guess, choice;
	do {
		cout << "\nViberi rejim:\n\n" << "Otgadivet igrok - 1\n" << "Otgadivaet komp - 2\n\n" << "Vibor: ";
		cin >> choice;
		switch (choice) {
		default:
			cout << "\ns0s1 (nevernoe zna4enie)\n\n";
			break;
		case 1:
			cout << "\nOtgadivet igrok\n";
			do {
				cout << "Vvedi 4islo: ";
				cin >> guess;
				tries++;
				if (guess > secretNumber) {
					cout << "4islo > zagadannogo\n\n";
				}
				else if (guess < secretNumber) {
					cout << "4islo < zagadannogo\n\n";
				}
				else {
					cout << "\nPobeda (win)!!\n" << "4islo popitok: " << tries;
				}
			} while (guess != secretNumber);
			break;
		case 2:
			do {
				cout << "\nOtgadivet komp\n";
				cout << "Vvedi chislo (<101 and >0): ";
				cin >> secretNumber2;
				if (secretNumber2 > 100 || secretNumber2 < 1) {
					cout << "\n\ns0s1!\n\n";
				}
			} while (secretNumber2 > 100 || secretNumber2 < 1);
			do {
				cout << "\n\n4islo kompa: " << secretNumber1 << "\nUgadal?\n" << "Tvoe 4islo: " << secretNumber2 << endl << endl;
				cout << "Ugadal - 1 \n" << "4islo > zagadannogo - 2\n" << "4islo < zagadannogo - 3\n\n" << "Vibor: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					if (secretNumber1 != secretNumber2) {
						cout << "\n\nNe pizdi.\n";
						break;
					}
					cout << "\nPobeda(win) kompa!\n" << "4islo popitok: " << tries;
					won = true;
					break;
				case 2:
					tries++;
					if (secretNumber2 == secretNumber1 || secretNumber1 > max || secretNumber1 < min || secretNumber1 < secretNumber2) {
						cout << "\n\nNe pizdi.\n";
						break;
					}
					max = secretNumber1;
					secretNumber1 = min + rand() % ((max - min) + 1);
					if (max == secretNumber1) {
						secretNumber1--;
					}
					break;
				case 3:
					tries++;
					if (secretNumber2 == secretNumber1 || secretNumber1 > max || secretNumber1 < min || secretNumber1 > secretNumber2) {
						cout << "\n\nNe pizdi.\n";
						break;
					}
					min = secretNumber1;
					secretNumber1 = min + rand() % ((max - min) + 1);
					if (secretNumber1 == min) {
						secretNumber1++;
					}
					break;
				default:
					cout << "s0s1 (neverniy vibor).\n";
				}
			} while (won != true);
		}
	} while (choice != 1 && choice != 2);
	return 0;
}