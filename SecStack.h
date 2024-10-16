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
void SecStack<T>::pop(T&){

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
void SecStack<T>::push(T){

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




#endif