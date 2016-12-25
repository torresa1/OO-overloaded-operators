//Andrew Torres
//randomTargets.h
//Version: 1.5
//DESCRIPTION: This class encapsulates the targetInt class,
//and has-A several distinct targetInt objects that allows the user to
//guess integer values and see if any of them match the contained targetInts
//as well as receive statistics from the contained targetInts
//Added implementation of operator overloading through c++

#ifndef RANDOMTARGETS_H
#define RANDOMTARGETS_H


#include "targetInt.h"

using namespace std;

class randomTargets
{
public:
	//Default Constructor
	//Functionally useless. Use constructor with a parameter to set size
	//Sets size to be -1 and initializes the dynamic array with a size of 1
	//for general functionality purposes
	randomTargets();

	//Constructor
	//Pass in the number of targetInts you want in randomTargets
	//POSTCONDITION: targets becomes an array of size numTargets
	//and private int size is assigned the value numTargets.
	//Must use setTargets to fill class with non-default targetInts
	randomTargets(int numTargets);

	//Set the target integer for the given index
	//PRECONDITION: index should be within the range of 0 and size - 1
	//POSTCONDITION: the targetInt at the given index within targets
	//is set to num's value
	void setTargets(int index, int num);

	//Helper function for the public deleteKnown function.
	//"Delete" the target at the given index if it is known.
	//PRECONDITION: index should be within the range of 0 and size - 1
	//and the targetInt at targets[index] should be known
	//POSTCONDITION: if known, then each targetInt within in targets
	//that has an index above the target to delete has their index
	//moved down by one within the array until the target to delete
	//is written over. If unknown, then no changes are made.
	//Dynamic memory is still allocated!
	void deleteTarget(int index);

	//"Delete" all known targetInts through the deleteTarget helper function
	//PRECONDITION: There are > 0 targetInts in the array 'targets'
	//POSTCONDITION: All known targetInts within targets is replaced and
	//written over. With each replacement, the index of each targetInt
	//above the replaced targetInt has their index decremented by one
	//until the replaced targetInt is written over. Size is then
	//decremented for each replaced targetInt.
	//Dynamic memory is still allocated!
	void deleteKnown();

	//Cycle through the targetInts, checking if any have the given num.
	//return the number of targetInts that match the given number.
	//return -1 if size is 0 or less.
	//PRECONDITION: There should be targetInts within this instance of
	//randomTargets and the size should therefore also be greater than 0
	//POSTCONDITION: The statistics for each of the targetInts in targets
	//that have an index below size have their statistics updated with the
	//given guessed number.
	int checkGuess(int num);

	//Return the highest amount of high guesses from the remaining objects
	//(deleted objects will not count anymore)
	//PRECONDITION: size is > 0 and targetInt objects are present
	int getHighestHigh();

	//Return the highest amount of low guesses from the remaining objects
	//(deleted objects will not count anymore)
	//PRECONDITION: size is > 0 and targetInt objects are present
	int getHighestLow();

	//Return the mean guess for the first element in randomTargets class
	//PRECONDITION: That there is a targetInt in targets[0].
	//The number of guesses should be greater than 0 as well.
	double getAverage();

	//Return the amount of remaining targetInts
	//in the randomTargets class
	int getSize();

	//Destructor
	~randomTargets();

	//Copy Constructor
	randomTargets(const randomTargets &obj);

	//Overloaded Assignment Operator
	//PRECONDITION: targets should have dynamically allocated memory
	//as to make delete[] targets be functional.
	//POSTCONDITION: lhs randomTargets gets all data members of rhs
	void operator=(const randomTargets &obj);

	//Overloaded Addition Operators
	//Add all the targetInts from obj to the end of the original randomTargets
	randomTargets operator+(const randomTargets &obj);
	//Add targetInt with target 'a' to the end of the original randomTargets
	randomTargets operator+(const int a);
	//Add targetInt with target 'a' to the beginning of the original randomTargets
	friend randomTargets operator+(int a, randomTargets &obj);
	//Add all the targetInts from obj to the end of the original randomTargets
	void operator+=(const randomTargets &obj);
	//Add targetInt with target 'a' to the end of the original randomTargets
	void operator+=(const int a);

	//Overloaded Comparison Operators
	//See if same size and if so, if all targetInts in order are equivalent to
	//their corresponding targetInt in all data members
	bool operator==(const randomTargets &obj) const;
	//Returns the opposite of the overloaded ==
	bool operator!=(const randomTargets &obj) const;

	//All of these are simply the equivalent comparison to the sizes
	bool operator<(const randomTargets &obj) const;
	bool operator<=(const randomTargets &obj) const;
	bool operator>=(const randomTargets &obj) const;
	bool operator>(const randomTargets &obj) const;


private:
	targetInt *targets;	//Dynamic array of targetInts
	int size;
};

#endif
