//*******************************************************************************
// Program Assignment: 3
// Program Name: Assignment3.cpp
// Author Name: Cameron Inglis
// Date: 03/01/2016
// Course: COMSC-1450 Section: A
//
// Description: This program utilizes the bianry search algorithm to 'guess' 
// the number that the user is thinking of using higher or lower commands.
//*******************************************************************************
#include <iostream> //Calling preprocessor directives
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int high = 101, low = -1, x, y, i, r;  
    char resp;                             //Declaring variables
    
    cout << "Please pick a number between 0 and 100" << endl;

srand(time(0));  //ensuring that we get a different random number each time the program is run
r = rand()%((high - low) - low );  // this will be the initial random number (the first guess)

    cout << endl << "Is your number :" << r<< endl;
    cout << "Yes - Y. Higher - H. Lower - L: "; 
    cin >> resp;                                
       
    i = r;      
    
  while (resp)   //beginning a loop that repeats itself as long as the user inputs H,Y, or L
        {             
        if(resp == 'H'){  //if user chooses higher, these statements will run
            x= (i + (high-i)/2); //this is my binary search algorithm
            cout<< "Is your number :" << x<< endl;
            cout << "Yes - Y. Higher - H. Lower - L: ";
            cin >> resp;
            if (low < i) //ensuring that the lower boundary is always the lowest number
            {
             low = i;
            }
            i=x;
        }
      else if  (resp == 'L') //these statements will run if the user chooses lower
     {
           y=(i - (i-low)/2); //binary search algorithm
           cout<< "Is your number :" <<y<< endl;
           cout << "Yes - Y. Higher - H. Lower - L: ";
           cin >> resp;
               if (high > i) //ensuring that the higher boundary remains the highest number in the game
                  {
                        high = i;
                  }           
           i=y;
     }
           else if (resp == 'Y') //when the program gets the number right these statements will run
           {
                cout << "Your number is: "<<i<<endl<<"\n";
                cout<<"Computer Wins!!!"<<"\n"; //outputting a winning message 
                break; //breaking the loop
           }
           else //Making sure that the user does not enter other characters that are not used in game
           {
                cout<<"ERROR!";
                break; 
           }
     }
        system("PAUSE");
        return 0;
        }



