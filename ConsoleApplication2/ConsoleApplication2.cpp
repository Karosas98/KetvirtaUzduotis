#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    bool ProgramWorks = true;

    while (ProgramWorks) {
        int choice;
        cout << "Kokia funkcija noretume pasirinkti?" << endl;
        cout << "1. Apskaiciuoti kiek ir uz kokia suma bilietu buvo parduota." << endl;
        cout << "2. Apskaiciuoti darbuotoju atlyginimus." << endl;
        cout << "3. Pabaigti programa." << endl;
        cin >> choice;

        if (choice == 1) {
            double price;
            int amount;
            ifstream fr;
            fr.open("Duomenys.txt");

            double total = 0;
            int total_tickets = 0;
            if (fr.is_open()) {
                for (int i = 0; i < 4; i++) {
                    fr >> price >> amount;
                    total = total + double(price * amount);
                    total_tickets = total_tickets + amount;
                }
            }
            else
                perror("Error opening the file");

            fr.close();

            cout << "Is viso isleista: " << fixed << setprecision(2) << total << " Eur" << endl;
            cout << "Is viso nupirkta: " << total_tickets << " bilietu" << endl;
        }

        else if (choice == 2) {
            string Name, Surname;
            double salary, increase;

            ifstream fr;
            ofstream fd;

            fr.open("salary.txt");
            fd.open("newSalary.txt");

            double total = 0;
            int total_tickets = 0;
            if (fr.is_open()) {
                while (!fr.eof()) {
                    fr >> Name >> Surname >> salary >> increase;
                    salary = salary * (1 + (increase / 100));
                    fd << Name << " " << Surname << " " << fixed << setprecision(2) << salary << endl;
                }
            }
            else
                perror("Error opening the file");

            fr.close();
            fd.close();
        }
        else if (choice == 3)
            return 0;
    }
    }
