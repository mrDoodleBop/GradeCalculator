#################################
# Makefile for Grade Calculator #
#################################



all 				:	Calculator

Calculator			:	Calculator.cpp CalcFunctions.cpp
					g++ *.cpp

testSomething 		: 
	a.exe < AUTO_INPUT.txt

run					: 
	a.exe