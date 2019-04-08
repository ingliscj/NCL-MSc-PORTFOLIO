//*******************************************************************************
// Program Assignment: 4
// Program Name: Assignment4_Cameron_Inglis.cpp
// Author Name: Cameron Inglis
// Date: 03/11/2015
// Course: COMSC-1450 Section: A
//
// Description: This program will display the number of cities in an user-selected
// state and will also calculate the most northern,southern,western and eastern 
// cities in that state. It will then output the info into a text file.
//*******************************************************************************
#include <iostream> //calling preprocessor directives
#include <fstream>
#include <string>
using namespace std;

string northcity, southcity, eastcity, westcity;

void keepnorth (double latitude, string city){ //creating the functions to calculate the required cities
	static double max_north = latitude;  //declaring static variable as it will need to be updated upon iteration of function
	if(max_north<latitude){
		max_north = latitude;
		northcity = city;
	}
}
void keepsouth (double latitude, string city){
	static double max_south = latitude;
	if(max_south>latitude || max_south == latitude){
		max_south = latitude;
		southcity = city;
	}
	}
void keepeast (double longitude, string city){
	static double max_east = longitude;
	if(max_east<longitude){
		max_east = longitude;
		eastcity = city;
	}
}
void keepwest (double longitude, string city){
	static double max_west = longitude;
	if(max_west>longitude || max_west==longitude){
		max_west = longitude;
		westcity = city;
	}
}


int main() {
string STATE;
cout << "Input 2 letters for a state: "; //asking user to enter their state choice
cin >> STATE;
ifstream input("./statecity.csv"); //asking program to search inside csv file
if(!input.is_open()) {   //in case we can't look in the file
cerr << "Cannot open file\n";
abort();
}
string state, city;
double latitude, longitude;
int city_count=0;
input.ignore(200,'\n'); // skip first line
while(input.good()) {
getline(input, state, ',');
input.ignore(100, ','); // skip FIPS state code
getline(input, city, ',');
input.ignore(100, ','); // skip FIPS city code
input.ignore(100, ','); // skip GNIS city code
input.ignore(100, ','); // skip city type
input >> latitude;
input.ignore(8,',');
input >> longitude;
input.ignore(8, '\n');
if (state==STATE) {
++city_count;

keepnorth(latitude, city); //using the functions that we made earlier

keepsouth(latitude, city);

keepeast(longitude, city);

keepwest(longitude, city);
}

} 
cout << "\n" << STATE << " has " << city_count << " cities.\n\n"; //outputting everything to the common output

cout << northcity << " is the northernmost city." << endl;

cout << southcity << " is the southernmost city." << endl;

cout << eastcity << " is the easternmost city." << endl;

cout << westcity << " is the westernmost city." << endl;

ofstream of("OutputAssignment4.txt");   //outputting everything to a text file
of << "Programming Assignment #4." << endl;
of << "Cameron Inglis" << endl;
of << "March 11, 2016" << endl;
of << "\n" << STATE << " has " << city_count << " cities.\n\n";
of << northcity << " is the northernmost city." << endl;
of << southcity << " is the southernmost city." << endl;
of << eastcity << " is the easternmost city." << endl;
of << westcity << " is the westernmost city." << endl;

system("PAUSE");
}

/*
This program processes information about US cities.
This free information is obtained from http://www.opengeocode.org/
and is downloaded in file statecity.csv
*/
