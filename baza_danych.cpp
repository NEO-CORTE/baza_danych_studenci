#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#include "student.h"


int main()
{
    string name = "Nowak";
    student st;
    vector<student> studenci;
    ifstream file("data.txt");
    while (file >> st)
    {
        //cout << st;
        studenci.push_back(st);
    }
    file.close();
    ofstream file2("out.txt");
    for (auto t : studenci) {
        file2 << t;
    }   
    //for_each(studenci.begin(), studenci.end(), student());

    //for_each(studenci.begin(), studenci.end(), [](student st){cout << st; });

    vector<student>::iterator it;
    for (it = studenci.begin(); it != studenci.end(); it++) {
        cout << *it;
    }

    cout << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.nazwisko == name; });
    file2.close();

}
