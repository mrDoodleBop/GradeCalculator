/*
    File Name : SecStack.h
    Author Name : Michael Cates
    Date : 10/16/2024
    Purpose : This is the file that holds the Course class definition, allowing multiple course objects to be created 
    
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <stack>

#include <fstream>//for saving stack information to a file


using namespace std;


template <typename T>
class SecStack{

    private:

        //structure for the stack nodes:
        struct StackNode{
            
            T value;
            StackNode *next;

        };

        //pointer for the top of the stack:
        StackNode *top;


    public:

        //constructor:
        SecStack(){
            top = NULL;
        }

        //Destructor
        ~SecStack();

        //pop:
        void pop(T&);

        //push:
        void push(T);

        //isEmpty:
        bool isEmpty();

        //saveToFile:
        void saveTofile(string fileName, string courseName, double finalGrade);


};//end of SecStack class

//Member function definitions:

template <typename T>
SecStack<T>::~SecStack(){

    StackNode *nodePtr, *nextNode;

    //position nodePtr at the top of the stack:
    nodePtr = top;

    //traverse the list deleting each node:
    while (nodePtr != NULL){

        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;

    }//end of while loop

}//end of destructor

template <typename T>
void SecStack<T>::pop(T& item){

    StackNode *temp = NULL;

    //Check if stack is empty:
    if(isEmpty()){

        cout << "\n\nThe stack is empty";

    } else {

        //Delete the top node and set the top equal to the next node:
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;

    }

}//end of pop function

template <typename T>
void SecStack<T>::push(T item){

    StackNode *newNode = NULL;

    //allocate a new node and store num there
    newNode = new StackNode;
    newNode->value = item;

    if(isEmpty()){

        top = newNode;
        newNode->next = NULL;

    } else {

        //insert newNode before top:
        newNode->next = top;
        top = newNode;

    }

}//end of push function

template <typename T>
bool SecStack<T>::isEmpty(){

    bool status;

    //check is the list has a top node or not:
    if(!top){
        status = true;
    } else {
        status = false;
    }

    //return the status of the list:
    return status;

}//end if is empty function

template <typename T>
void SecStack<T>::saveTofile(string fileName, string courseName, double finalGrade){

    //Variables:
    StackNode *nodePtr, *nextNode;

    nodePtr = top;

    //Open a file:
    ofstream stackFile;

    stackFile.open(fileName);

    stackFile << "\n|---------- " << courseName << " Grade Information----------|";


    //Traverse through the list
    //-->at each iteration, save node information to the file in a readable format:
    while(nodePtr != NULL){

        nextNode = nodePtr->next;

        stackFile << "\n-----Section:";
        stackFile << "\nName: " << nodePtr->value.getName();
        stackFile << "\nCurrent Grade : " << nodePtr->value.getGrade() << "%";
        stackFile << "\nWeight on Final :  " << (nodePtr->value.getWeight() * 10000) << "%";

        nodePtr = nextNode;


    }//end of while loop

    stackFile << "\n\nFINAL GRADE : " << finalGrade << "%";

    //Display a message informing the user that their file has been created and saved:
    cout << "\n\n\t\tYour grade information has been saved under the name " << fileName << ".";

    stackFile.close();

}//end of save to file function




#endif