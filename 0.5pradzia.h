#ifndef 0.5PARDZIA_H_INCLUDED
#define 0.5PARDZIA_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

class studentas
{ public:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    vector<double> galutinis;
};

 double galut (vector<int> studentoPazymiai) {
    int suma = 0;
    int i = 0;
    double vid=0, galutinis=0;
    vector<int>::iterator des;

    for (i ; i < studentoPazymiai.size() - 1; i++){
        suma += studentoPazymiai[i];
        sort(studentoPazymiai.begin(), studentoPazymiai.end());
        des = find (studentoPazymiai.begin(), studentoPazymiai.end(), 10); //randami studentø paþymiø eilutëje esantys 10
    };
      vid=(double)suma/i;
      galutinis=0.4*vid+0.6*studentoPazymiai[i];
      //sort(galutinis.begin(), galutinis.end());
      return galutinis;
};

double med (vector<int> studentoPazymiai) {
    int suma = 0;
    int i = 0;
    double mediana = 0;

    for (i ; i < studentoPazymiai.size() - 1; i++){
        suma += studentoPazymiai[i];
    };

    if (i % 2 == 0)
      mediana = (studentoPazymiai[i / 2 - 1] + studentoPazymiai[i / 2]) / 2;
    else
      mediana =  studentoPazymiai[i / 2];
   try {
    mediana=studentoPazymiai[i/2];
   } catch (const double mediana) {}
      return mediana;
};


#endif // 0.5PARDZIA_H_INCLUDED
