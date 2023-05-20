#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#include "student.h"


int main()
{
    string filter_string;
    int filter_int;
    int ex = 0;
    int option = 1;
    int suboption = 0;
    student st;
    vector<student> studenci;
    
    cout << "1 - wprowadz studentow recznie" << endl << "2 - wczytaj z pliku data.txt" << endl << "3 - zapisz do pliku out.txt" << endl <<"4 - Wyswietl studentów (wedlug kryterium - opcje dostepne po wybraniu)" << endl <<"5 - wyjdz z programu" << endl;
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
            cout << "1 - Nazwisku" << endl;
            cout << "2 - Imieniu" << endl;
            cout << "3 - Nr. Albumu" << endl;
            cout << "4 - Grupie" << endl;
            cout << "5 - Albumu" << endl;
            cin >> suboption;
            if (suboption == 0) {
                for_each(studenci.begin(), studenci.end(), [](student st) {cout << st << endl; });
            }
            if (suboption == 1) {
                cout << "Podaj nazwisko do filtrowania: ";
                cin >> filter_string;
                cout << "Liczba studentow o podanym nazwisku: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                for_each(studenci.begin(), studenci.end(), [filter_string](student st) {if (st.returnNazwisko() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 2) {
                cout << "Podaj imie do filtrowania: ";
                cin >> filter_string;
                cout << "Liczba studentow o podanym imieniu: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                for_each(studenci.begin(), studenci.end(), [filter_string](student st) {if (st.returnImie() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 3) {
                cout << "Podaj numer albumu do filtrowania: ";
                cin >> filter_string;
                cout << "Liczba studentow o podanym numerze albumu: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                for_each(studenci.begin(), studenci.end(), [filter_int](student st) {if (st.returnNr_Albumu() == filter_int) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 4) {
                cout << "Podaj grupe do filtrowania: ";
                cin >> filter_string;
                cout << "Liczba studentow w tej grupie: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                for_each(studenci.begin(), studenci.end(), [filter_string](student st) {if (st.returnGrupa() == filter_string) {
                    cout << st << endl;
                }; });
            }
            if (suboption == 5) {
                cout << "Podaj rok studiow do filtrowania: ";
                cin >> filter_int;
                cout << "Liczba studentow na tym roku studiow: " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNazwisko() == filter_string; });
                for_each(studenci.begin(), studenci.end(), [filter_int](student st) {if (st.returnRok() == filter_int) {
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
