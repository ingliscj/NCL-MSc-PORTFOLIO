//Cameron Inglis - Program that evaluates, adds, subtracts, multiplies and 
//differentiates a polynomial.

#include <iostream>
#include <cmath>
using namespace std;

const unsigned short N = 30;  // max size of polynomials
double temp[N];
double dif1[N];
double dif2[N];
double result;

// Calculates degree of polynomial to be used in evaluation 
int degree1(double a[]) {
    for(int i=N-1; i; --i)
        if (a[i])
            return i;
    return 0;
}

//Evaluates the polynomial
double Evaluate( double a[], double x, int pDegree)
{
    double result = a[pDegree];
    for(int i=pDegree-1; i >= 0 ; --i)
        result = result * x + a[i];
    return result;
}

//Adds the two polynomials together
void add(double a[], double b[], double result[]) {
	for(int i=0; i<N; i++)
		result[i] = a[i] + b[i];
}

//Subtracts the two polynomials
void subtract(double a[], double b[], double result[]) {
	for(int i=0; i<N; i++)
		result[i] = a[i] - b[i];
}

//Multiplies the two polynomials
void multiply(double a[], double b[], double result[]) {
	for(int i=0; i<N; i++)
		result[i] = 0;
	for(int i=0; i<N; i++){
		for(int j = 0; j<N; j++) 
			if(i + j <N)
				result[i+j] += a[i]*b[j]; 
}}

//Differentiates the polynomial
void differentiate(double a[], int x) {
	// one for loop
	// one array
	int n;
	for(int i=1; i<N; i++) {
		temp[i-1] = (a[i]*i);
	}
	
	if(x>1) {
		for(int i=1; i<N; i++) {
			dif2[i-1] = (temp[i]*i); 
		}
	}
}

// prints polynomials nicely
void print(double poly[]) {
    bool first = true;  // true for first non-zero coefficient
    for (int i=N-1; i>=0; i--) {
        if (!poly[i]) 
            continue;
        // print coefficient 
        if (i && poly[i] == 1)   // special case for 1
            cout << (first ? "" : " +");
        else if (i && poly[i] == -1) // special case for -1
            cout << (first ? "-" : " -");  
        else 
            cout << ' ' << (first ? noshowpos : showpos) << poly[i];
        cout << noshowpos;
        // print variable
        if (i>0)   
            cout << "x"; 
        // print power
        if (i>1) 
            cout << '^' << i;  
        first = false;
    }
    if(first)  // print 0 if all zeros
        cout << 0;
}

int main() {
double a[N] = {12, 1, 0, -32.5, 0, 1}; // The first polynomial
double b[N] = {1, 1, -1}; // The second polynomial
double c[N];
double x = -7.3;
int pDegree = degree1(a);
differentiate(a,1);
for(int i=0; i<N; i++) {
	dif1[i] = temp[i];
}
differentiate(a,2);

cout << "The evaluation of ";
print(a);
cout << " for " << x;
cout << " is " << Evaluate(a, x, degree1(a)) << endl; 

cout << endl << "Addition:" << endl;
add(a,b,c);
cout << '(';
print(a);
cout << ") + (";
print(b);
cout << ") = ";
print(c);
cout << endl;

cout << endl << "Subtraction:" << endl;
subtract(a,b,c);
cout << '(';
print(a);
cout << ") - (";
print(b);
cout << ") = ";
print(c);
cout << endl;

cout << endl << "Multiplication:" << endl;
multiply(a,b,c);
cout << '(';
print(a);
cout << ") * (";
print(b);
cout << ") = ";
print(c);
cout << endl;

cout << endl << "Differentiation:" << endl;
cout << "The derivative of (";
print(a);
cout << ") is (";
print(dif1);
cout << ')' << endl;

cout << "Its second derivative is (";
print(dif2);
cout << ')' << endl;
system("PAUSE");
}
