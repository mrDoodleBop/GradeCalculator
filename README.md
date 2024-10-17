# GradeCalculator
Calculates a final grade based off of weighted grade sections

RUNNING THE PROGRAM:
1. To allow the program to run correctly or at all, you must download the required software:
   a. You need mingw to run c++
   b. you need to be able to run Makefiles

2. After you have ensured all required software is downloaded, you can download the program
   a. Download into a ZIP folder
   b. Extract all
   c. From the file directory inside the folder, open the command prompt
     i. inside of the command prompt, you have options:
   
     *Option 1 -> type "g++ *.cpp" and the enter button and then type "a"
       - this will allow you to manually enter the information that the program asks for
   
     *Option 2 -> type "make Calculator" and the enter button and then type "make run"
       - this runs the Option 1 commands but in an easier to memorize fashion
       - it also takes out most of the user error from typing in the original commands
   
     *Option 3 ->
       1. Fill out the automated input text file
       2. in the command prompt, type "make Calculator" and the enter button and then type "make testSomething"
         - in order for this to work, you must fill out the provided AUTO_INPUT.txt file


INSTRUCTIONS ON AUTOMATED INPUT:
y or n -> y to begin the program, n to not
name of the course 
number of weighted sections in the course

***you will repeat the next 3 lines for the number of weighted sections you have in the course
name of the weighted sections
weight of the section on the final grade (.25, .05, .75, etc.)
current grade in the section
***end of the process

y or n -> y to save to a file, n to not

//if you entered y:
name of the file you would like to save the information to(preferably ending with ".txt")
y or n -> y to re-run the program for another course and repeat the process, n to not

//if you decide you want to run the program for multiple courses, you will enter y for the
above input and below you will repeat that process - starting with the course name

EXAMPLE for One Course:
y
MATH 1910
3
Assignments
.25
78.9
Quizzes
.25
82.4
Exams
.50
75.6
y
testingFunctions.txt
n

EXAMPLE for More then One Course:

y
MATH 1910
3
Assignments
.25
78.9
Quizzes
.25
82.4
Exams
.50
75.6
y
testingFunctions1.txt
y
GEOL 1045
3
Assignments
.25
78.9
Quizzes
.25
82.4
Exams
.50
75.6
y
testingFunctions2.txt

***Note: if you save more than one file, make sure that you save each course under its own file name, otherwise every time you save one course, the previous will be deleted :)


