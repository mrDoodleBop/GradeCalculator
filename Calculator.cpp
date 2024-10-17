/*
    File Name : Calculator.cpp
    Author Name : Michael Cates
    Date : 10/16/2024
    Purpose : This is the driver file for the grade calculator program
    --> this program will calculate a student's grade based off of a course's respective weighted sections
*/


#include "SecStack.h"
#include "WeightedSec.h"

//Function declarations:

//main function:
int main(){

    //Variables:
    char flag;
    char saveFlag;
    int numSec;

    string courseName;

    string fileName;

    double sumNewGrades =  0; //sum of the grades multiplied by their weights
    double sumWeights = 0; //sum of the weights

    double finalGrade;

    string name;
    double weight, grade;

    SecStack<WeightedSec> stack; //list of weighted sections

    WeightedSec section; //WeightedSec object; will be hold new values at every iteration of the for loop

    //Ask the user if they would like to begin the program:
    system("CLS");
    cout << "\n\n\t\t|----------Grade Calculator----------|";
    cout << "\n\t\tWould you like to calculate your final grade? (y/n): ";
    cin >> flag;

    //Start the while loop:
    while(flag != 'n'){

        cout << "\n\n\t\tEnter the course name : ";
        cin.ignore();
        getline(cin, courseName);

        //Find the number of weighted sections for the course:
        cout << "\n\t\tEnter the number of weighted sections for your course (integer): ";
        cin >> numSec;

        cout << "\n\n\t\t|----------Creating " << numSec << " Sections----------|";

        //For loop to create the specified number of weighted grade sections:
        for(int i = 0; i < numSec; i++){

            //Take in the information for the section:
            cout << "\n\t\tEnter the name of section " << i+1 << ": ";
            cin.ignore();
            getline(cin, name);

            cout << "\n\t\tEnter section " << i+1 << "'s weight on your final grade \n\t\t( ex: .35, .05, etc.) : "; //enter the weight
            cin >> weight;
            weight = weight/100;

            cout << "\n\t\tEnter the current grade average you have \n\t\tfor section " << i+1 << " (ex: 96.7, 78.3, etc.) : "; //enter the grade
            cin >> grade;

            //adding to sum of weights:
            sumWeights += weight;

            //adding to sum of grades:
            sumNewGrades += (grade*weight);

            section = WeightedSec(name, weight, grade); //create the section object

            stack.push(section); //push the object to the top of the stack

        }//end of for loop

        //Calculate final grade [(sum of the grades multiplied by their weights) / (sum of the weights)]:
        finalGrade = (sumNewGrades/sumWeights);

        //Return the final grade:
        cout << "\n\n\t\t|----------Your Final Grade----------|";
        cout << "\n\t\tFinal Grade : " << finalGrade;

        //Ask the user if they would like to save their grade information to a text file:
        cout << "\n\n\t\tWould you like to save your grade information to a text file? (y/n): ";
        cin >> saveFlag;

        //Branching based off of switchFlag value:
        switch(saveFlag){
            case 'y':
                //Run the function that saves all sections and their grade information to a text file under a user specified name:
                //--> maybe in the future you can do all of this using SQL with this program :)
                cout << "\n\n\t\tEnter the desired file name : ";
                cin >> fileName;

                stack.saveTofile(fileName, courseName, finalGrade);
                break;
            case 'n':
                //Do not save the data into a text file:
                cout << "\n\n\t\tMoving on without saving data to a file.";
                break;
            default:
                cout << "\n\t\tYou did not enter a valid response.";
        }


        //Ask the user if they would like to do it again:
        cout << "\n\n\t\tWould you like to run the program again? (y/n): ";
        cin >> flag;

    }//end of while loop


    //Main function return value:
    return 0;

}//end of main function

