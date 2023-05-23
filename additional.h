#pragma once
#include <iostream>
using namespace std;
void dashes() {
    cout << "\u001b[35m";
    for (int i = 1; i <= 70; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "\u001b[0m";
}