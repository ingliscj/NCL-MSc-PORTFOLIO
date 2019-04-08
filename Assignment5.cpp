//*******************************************************************************
// Program Assignment: 5
// Program Name: Assignment5_Cameron_Inglis.cpp
// Author Name: Cameron Inglis
// Date: 03/17/2015
// Course: COMSC-1450 Section: A
//
// Description: This program will display the distance between two user-selected
// cities and will display it in km and miles on the screen and will also output 
// the info to an output text file.
//*******************************************************************************
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string file_city1, file_state1, file_city2, file_state2;//these are the temporary variables used to locate the user's cities in the file
char user_city1[100], user_state1[100], user_city2[100], user_state2[100]; //these are the variables where the user's choices are stored
double latitude1, longitude1, latitude2, longitude2;
int earth_r_km = 6371;

double distance_km(double lon1, double lon2, double lat1, double lat2){ //this is the haversine function
      double rad = 3.14159265359 / 180; //conversion factor for degrees to radians
      double rad_lat1 = lat1*rad;
      double rad_lon1 = lon1*rad;
      double rad_lat2 = lat2*rad;
      double rad_lon2 = lon2*rad;
      double dlon = rad_lon2-rad_lon1;
      double dlat = rad_lat2-rad_lat1;
      double a = pow((sin(dlat/2)),2) + (cos(rad_lat1)*cos(rad_lat2)*pow((sin(dlon/2)),2));
      double c = 2*atan2(sqrt(a),sqrt(1-a));
      double d_km = earth_r_km * c ;
       return d_km;
       }
       
void get_user_input() //this function will handle the user's input
{
    cout << "Input your starting city: "<<endl;
    cin.getline(user_city1, sizeof(user_city1)); //using getline to include whitespaces
    cout << "Input the 2 letter code for that city's state: "<<endl; 
    cin.getline(user_state1, sizeof(user_state1));
    cout<<"Input destination city: "<<endl;
    cin.getline(user_city2, sizeof(user_city2));
    cout << "Input the 2 letter code for that city's state: "<<endl; 
    cin.getline(user_state2, sizeof(user_state2));
}

void match1(string s, string c) //this function retrieves the longitude and latitude for the first city/state
{
     ifstream input("./statecity.csv"); //opening the file
      if(!input.is_open()) {   //incase the file cannot be opened
    cerr << "Cannot open file\n";
    abort();
    }
    input.ignore(200,'\n'); 
    while(input.good()) {
    getline(input, file_state1, ',');
    input.ignore(100, ','); // skip FIPS state code
    getline(input, file_city1, ',');
    input.ignore(100, ','); // skip FIPS city code
    input.ignore(100, ','); // skip GNIS city code
    input.ignore(100, ','); // skip city type
    input >> latitude1;
    input.ignore(8,',');
    input >> longitude1;
    input.ignore(8, '\n');
    if(user_state1 == file_state1) //this ensures the states match up
       if(user_city1 == file_city1) //and this ensures the city names match up
    {
                  break; //breaks the function so latitude1 and longitude1 store the correct values 
                  }
}
}

void match2(string s, string c) //same as above function but for the second city/state
{
     ifstream input("./statecity.csv");
      if(!input.is_open()) {  
    cerr << "Cannot open file\n";
    abort();
    }
    input.ignore(200,'\n');
     while(input.good()){
    getline(input, file_state2, ',');
    input.ignore(100, ','); // skip FIPS state code
    getline(input, file_city2, ',');
    input.ignore(100, ','); // skip FIPS city code
    input.ignore(100, ','); // skip GNIS city code
    input.ignore(100, ','); // skip city type
    input >> latitude2;
    input.ignore(8,',');
    input >> longitude2;
    input.ignore(8, '\n');
    if(user_state2 == file_state2)
       if(user_city2 == file_city2)
    {
                  break;
                  }
}
}

void output() //this function handles the output of the information
{
     cout << "\nThe distance between " << user_city1 <<", "<< user_state1<< " and "<< user_city2 <<", "<< user_state2;
     cout << " is "<< fixed << setprecision(1)<< distance_km(longitude1, longitude2, latitude1, latitude2)<<" km "; //outputting everything to the common output
     cout<< "(" << fixed << setprecision(1) << distance_km(longitude1, longitude2, latitude1, latitude2)/1.609344 << " miles)"<<endl;
    
    ofstream of("OutputAssignment5.txt");   //outputting everything to a text file
    of << "Programming Assignment #5." << endl;
    of << "Cameron Inglis" << endl;
    of << "March 11, 2016" << endl;
    of << "\nThe distance between " << user_city1 <<", "<< user_state1<< " and "<< user_city2 <<", "<< user_state2;
    of << " is "<< fixed << setprecision(1) << distance_km(longitude1, longitude2, latitude1, latitude2)<< " km ";
    of << "(" << fixed << setprecision(1) << distance_km(longitude1, longitude2, latitude1, latitude2)/1.609344 << " miles)";
    
    system("PAUSE");
}

int main() { //here I call on the functions in order 
    get_user_input();

    match1(user_state1, user_city1);
    
    match2(user_state2, user_city2);
        
    output();
        
}
