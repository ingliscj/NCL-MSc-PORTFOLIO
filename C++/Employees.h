#include <iostream>
#include <string.h>
#include "Employee.h"
#include "person.h"
#include "Address.h"
#include "contact.h"

using namespace std;

int main(int argc, char** argv)
{
	Employee x;
	Employee y;

	x.setlname("Smith");
	x.setfname("Jane");
	x.setage(21);
	x.setID("123-456-7890");

	cout << "Input Y: ";
	cin >> y;

	if (x==y)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;


    system("PAUSE");
	return 0;
}
