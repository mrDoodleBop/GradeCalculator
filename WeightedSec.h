/*
    File Name : WeightedSec.h
    Author Name : Michael Cates
    Date : 10/16/2024
    Purpose : File holds the weighted section class whose objects will be placed in the Course structure
*/

#ifndef WEIGHTEDSEC_H
#define WEIGHTEDSEC_H

#include <string>
using namespace std;

class WeightedSec{

    private:
        string secName; //name of the section

        double secWeight; // section's weight on the final grade
        double secGrade; // student's current grade for this section

    public:

        //constructors and destructor:
        WeightedSec(){

            secName = "N/A";
            secWeight = 0.0;
            secGrade = 0.0;

        }

        WeightedSec(string, double, double);

        ~WeightedSec();

        //Accessor functions:
        string getName(){
            return secName;
        }

        double getWeight(){
            return secWeight;
        }

        double getGrade(){
            return secGrade;
        }

        //Mutator Functions:
        void setName(string n){
            secName = n;
        }

        void setWeight(double w){
            secWeight = w;
        }

        void setGrade(double g){
            secGrade = g;
        }

        //Display Information Functions:
        void printInfo();


};//end of WeightedSec class

//Remaining function definitions:

//overloaded constructor:
WeightedSec::WeightedSec(string n, double w, double g){

    this->secName = n;
    this->secWeight = w;
    this->secGrade = g;

}//end of overloaded constructor

//Destructor:

//Print Info:



#endif