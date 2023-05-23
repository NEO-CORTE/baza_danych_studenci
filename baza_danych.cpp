#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#include "student.h"
#include "additional.h"


int main()
{
    string filter_string;
    int filter_int;
    int ex = 0;
    int option = 1;
    int suboption = 0;
    student st;
    vector<student> studenci;
    vector<string> menu;
    menu.push_back("\u001b[32m1 - wprowadz studentow recznie");
    menu.push_back("\u001b[34m2 - wczytaj z pliku data.txt");
    menu.push_back("\u001b[35;1m3 - zapisz do pliku out.txt");
    menu.push_back("\u001b[37;1m4 - Wyswietl studentów (wedlug kryterium - opcje dostepne po wybraniu)");
    menu.push_back("\u001b[31;1m5 - wyjdz z programu");
    dashes();
    for (auto m : menu) {
        cout << m << endl;
    }
    dashes();
    while (true) {
        cin >> option;
        if (option == 1 or option > 5 or option < 1) {
            ex = 0;
            while (true) {
                cin >> st;
                studenci.push_back(st);
                cout << "Press 1 and ENTER to exit input" << endl;
                cin >> ex;
                if (ex == 1) {
                    break;
                }
            }
        }
        if (option == 2) {
            ifstream file("data.txt");
            while (file >> st)
            {
                studenci.push_back(st);
            }
            file.close();
            cout << "Wczytano z pliku" << endl;
        }
        if (option == 3) {
            ofstream file2("out.txt");
            for (auto t : studenci) {
                file2 << t;
            }
            file2.close();
            cout << "Zapisano do pliku" << endl;
        }
        if (option == 4) {
            cout << "Filtrowanie po:" << endl;
            cout << "0 - brak filtrowania" << endl;
            cout << "\u001b[36m1 - Nazwisku" << endl;
            cout << "\u001b[34m2 - Imieniu" << endl;
            cout << "\u001b[32m3 - Nr. Albumu" << endl;
            cout << "\u001b[33m4 - Grupie" << endl;
            cout << "\u001b[35;1m5 - Roku\u001b[0m" << endl;
            cin >> suboption;
            if (suboption == 0) {
                cout << "Liczba wszystkich studentow " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNr_Albumu(); }) << endl;
                for_each(studenci.begin(), studenci.end(), [](student st) {cout << st << endl; });
            }
            if (suboption == 1) {
                cout << "Podaj nazwisko do filtrowania: ";
                cin >> filter_string;
                cout << endl;
                cout << "Liczba studentow o podanym nazwisku: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                cout << endl;
                for_each(studenci.begin(), studenci.end(), [=](student st) {if (st.returnNazwisko() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 2) {
                cout << "Podaj imie do filtrowania: ";
                cin >> filter_string;
                cout << endl;
                cout << "Liczba studentow o podanym imieniu: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnImie() == filter_string; });
                cout << endl;
                for_each(studenci.begin(), studenci.end(), [=](student st) {if (st.returnImie() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 3) {
                cout << "Podaj numer albumu do filtrowania: ";
                cin >> filter_int;
                cout << endl;
                cout << "Liczba studentow o podanym numerze albumu: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNr_Albumu() == filter_int; });
                cout << endl;
                for_each(studenci.begin(), studenci.end(), [=](student st) {if (st.returnNr_Albumu() == filter_int) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 4) {
                cout << "Podaj grupe do filtrowania: ";
                cin >> filter_string;
                cout << endl;
                cout << "Liczba studentow w tej grupie: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnGrupa() == filter_string; });
                cout << endl;
                for_each(studenci.begin(), studenci.end(), [=](student st) {if (st.returnGrupa() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 5) {
                cout << "Podaj rok studiow do filtrowania: ";
                cin >> filter_int;
                cout << endl;
                cout << "Liczba studentow na tym roku studiow: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnRok() == filter_int; });
                cout << endl;
                for_each(studenci.begin(), studenci.end(), [=](student st) {if (st.returnRok() == filter_int) {
                    cout << st << endl;
                }; });
            }
        }
        if (option == 5) {
            break;
        }
    }
    exit(1);
    //for_each(studenci.begin(), studenci.end(), student());
    //vector<student>::iterator it;
    //for (it = studenci.begin(); it != studenci.end(); it++) {
    //    cout << *it;
    //
}
