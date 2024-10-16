/*
    File Name : Calculator.cpp
    Author Name : Michael Cates
    Date : 10/16/2024
    Purpose : This is the driver file for the grade calculator program
    --> this program will calculate a student's grade based off of a course's respective weighted sections
*/


#include "SecStack.h"
#include "WeightedSec.h"

//main function:
int main(){

    //Variables:
    char flag;
    int numSec;

    string name;
    double weight, grade;

    SecStack<WeightedSec> stack; //list of weighted sections

    WeightedSec section; //WeightedSec object

    //Ask the user if they would like to begin the program:
    system("CLS");
    cout << "\n\n\t\t|----------Grade Calculator----------|";
    cout << "\n\t\tWould you like to calculate your final grade? (y/n): ";
    cin >> flag;

    //Start the while loop:
    while(flag != 'n'){

        //Find the number of weighted sections for the course:
        cout << "\n\n\t\tEnter the number of weighted sections for your course (integer): ";
        cin >> numSec;

        cout << "\n\n\t\t|----------Creating " << numSec << " Sections----------|";

        //For loop to create the specified number of weighted grade sections:
        for(int i = 0; i < numSec; i++){

            //Take in the information for the section:
            cout << "\n\t\tEnter the name of the weighted section: ";
            cin.ignore();
            getline(cin, name);

            cout << "\n\t\tEnter the section's weight on your final grade \n( ex: 35.0, 65.5, etc.) : "; //enter the weight
            cin >> weight;
            weight = weight/100;

            cout << "\n\t\tEnter the current grade average you have \nfor this section (ex: 96.7, 78.3, etc.) : "; //enter the grade
            cin >> grade;

            section = WeightedSec(name, weight, grade);

        }//end of for loop

        //After the for loop, traverse the stack again to multiply each grade by its respective section weight:

        //Add together all sums:

        //If the weights don't add up to 1, divide new grade sums by the sum of the weights:

        //Return the final grade:

        //Ask the user if they would like to do it again:

    }//end of while loop


    //Main function return value:
    return 0;

}//end of main function


