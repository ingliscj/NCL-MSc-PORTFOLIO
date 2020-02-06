//******************************************************************************
// Program Assignment: 1
// Program Name: HeightConvert.cpp
// Author Name: Cameron Inglis
// Date: 02/08/2016
// Course: COMSC-1450 Section: A
//
// Description: This program converts a person height from feet and inches to
// centimeters.
//******************************************************************************
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    cout << setfill ('=') << setw(20) << " " << endl;
    cout << setfill (' ') << left << setw(14) << "Student-1" << right << "100.0"<< endl;
    cout << setfill (' ') << left << setw(15) << "Student-2" << right << "87.0" << endl;
    cout << setfill ('-') << setw(20)<< " " << endl;
    cout << setfill(' ') << "Average" << setw(12) << "93.5" << endl;
    cout << setfill('=') << setw(20) << " " << endl;
    getchar();
return 0;
}
