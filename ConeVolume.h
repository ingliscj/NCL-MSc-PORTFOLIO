#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void msgBox();
void volCone();
void mainmenu(char&);

const double pi = 3.14159;

int main()
{
    char choice;
    
 do {
        mainmenu(choice);
        
           
        switch (choice)
        {
               case 'C':
               case 'c':
               case '1': msgBox(); break;
               case 'V':
               case 'v':
               case '2': volCone(); break;
               case 'e':
               case 'E':
               case '0': break;
               default: cout << "Please select a valid option";
        }
        cout << endl;
    } while(choice != '0' && choice != 'E' && choice != 'e');
    
    system("pause");
    return 0;
}


void mainmenu(char& c)
{
        cout << "\nMain menu\n";
        cout << "1. Print a message box\n";
        cout << "2. Calculate the volume of a cone\n";
        cout << "0. Exit\n";
        cout << "Please select an item: \n";
        cin >> c;
}

void msgBox()
{
      
    
    cout << "Please enter your name: "; //asks user to enter name
    string name;
    getline(cin, name); //program reads the full name including whitespaces
    
    double n = name.length(); //declaring integer n, as the number of characters in user's name
    
    cout << setfill('*') << setw(60) << '*' << endl; //displays 60 asterix characters across the width of message box
    cout << setfill('*') << setw(1) << left << '*'; //displays single asterix, left-justified
    cout << setfill(' ') << setw(59) << right << '*' << endl; //displays 59 whitespaces and then a single asterix right-justified
    cout << left << '*' << " COMSC 1450: C++ Programming" << setfill(' ') << setw(30) << right << "Fall, 2013 " << right << '*' << endl; //displays single asterix left-justified then class name, 30 whitespaces and then semester name right-justified with a single asterix to the right.
    cout << setfill('*') << setw(1) << left << '*'; //displays single asterix, left-justified
    cout << setfill(' ') << setw(59) << right << '*' << endl; // displays 59 whitespaces and single asterix right-justified
    cout << setfill('*') << setw(1) << left << '*'; 
    cout << setfill(' ') << setw(59) << right << '*' << endl;
    cout << "*" << setfill(' ') << setw(29 - n/2) << " "; //displays single asterix left-justified. The program computes number of spaces needed to keep name centered/
    cout << name; //displays name in center of box
    cout << setw(29 - n/2) << " " << right << "*" << endl; //program computes number of spaces needed depending on name length to keep name centered
    cout << setfill('*') << setw(1) << left << '*'; //same as top half of message box
    cout << setfill(' ') << setw(59) << right << '*' << endl;
    cout << setfill('*') << setw(1) << left << '*';
    cout << setfill(' ') << setw(59) << right << '*' << endl;
    cout << "*" << setfill(' ') << setw(17) << ' ' << "Assignment 2 : Problem A" << setw(17) << ' ' << right << '*' << endl;
    cout << setfill('*') << setw(1) << left << '*';
    cout << setfill(' ') << setw(59) << right << '*' << endl;
    cout << setfill('*') << setw(60) << '*' << endl;
    cout << endl;
}


void volCone()
{
     float r, h, v;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Please enter radius of cone: ";
    cin >> r;
    cout << "Please enter height of cone: ";
    cin >> h;
    v = pi * h * ((pow(r, 2))/3.0); 
    cout << "Volume of cone: \n" << v << endl;
}
