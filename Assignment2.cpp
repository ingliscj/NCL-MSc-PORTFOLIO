//*******************************************************************************
// Program Assignment: 2
// Program Name: Assignment2.cpp
// Author Name: Cameron Inglis
// Date: 02/16/2016
// Course: COMSC-1450 Section: A
//
// Description: This program reads three variables from a text file, manipulates 
// the variables and then formats them in different ways before exporting them
// to a new text file.
//*******************************************************************************

#include <fstream>  //calling the necessary preprocessor directives
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//Declaring variables a, b, and c. 
	double a, b, c;
	ifstream f("input.txt");  //Importing the file "input.txt" from program root folder
	f >> a;
	f.ignore(100, ',');   //commanding program to ignore commas so we only get numbers
	f >> b;
	f.ignore(100, ',');
	f >> c;
	
//Calculating the different means, ready to be called upon later in program
	double m, g, h;
	m=(a+b+c)/3;
	g= cbrt((a*b*c));
	h=(3/((1/a)+(1/b)+(1/c)));
	
//Outputting the different means in different formats to the common output (Computer screen)
	cout << setw(10) << setprecision(4)<< right << m;
    cout << ',' << setw(10) << setprecision(4)<< right << g;
    cout << ',' << setw(10) << setprecision(4)<< right << h << endl;
 	cout << setw(10) << setprecision(6)<< right << m;
    cout << ',' << setw(10) << setprecision(6)<< right << g;
    cout << ',' << setw(10) << setprecision(6)<< right << h << endl;
   	cout << setw(10) << scientific << setprecision(2)<< right << m;
    cout << ',' << setw(10) << scientific << setprecision(2)<< right << g;
    cout << ',' << setw(10) << scientific << setprecision(2)<< right << h << endl;   
    
//Commanding program to save the caluclated output above, along with added info to a new text file called "output.txt"
    ofstream of("output.txt");
    of << "Cameron Inglis - February 18, 2016" << endl;
    of << "INPUT" << endl;
    of << setw(10) << right << a << ',' << setw(10) << right << b << ',' << setw(10) << right << c << endl;
    of << "OUTPUT" << endl;
    of <<  setw(10) << setprecision(4)<< right << m;
    of << ',' << setw(10) << setprecision(4)<< right << g;
    of << ',' << setw(10) << setprecision(4)<< right << h << endl;
 	of << setw(10) << setprecision(6)<< right << m;
    of << ',' << setw(10) << setprecision(6)<< right << g;
    of << ',' << setw(10) << setprecision(6)<< right << h << endl;
   	of << setw(10) << scientific << setprecision(2)<< right << m;
    of << ',' << setw(10) << scientific << setprecision(2)<< right << g;
    of << ',' << setw(10) << scientific << setprecision(2)<< right << h << endl;
    
    
	system("pause");
}
