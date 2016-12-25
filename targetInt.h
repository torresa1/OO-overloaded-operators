//Andrew Torres
//targetInt.h
//Version: 2.0
//DESCRIPTION: This class takes and hides an int from the driver and allows 
//repeated guesses for the target int. The class also records statistics 
//taken from the guessing game.
//Added implementation of operator overloading through c++

#ifndef TARGETINT_H
#define TARGETINT_H

using namespace std;

class targetInt
{
public:
	//Constructor
	//Set all data members to 0 and false
	targetInt();

	//Destructor (not needed)
	~targetInt();

	//Return 1 if guess is too high, -1 if too low, and 0 if correct.  
	//Parameter is the user's guess for the target int.
	//Update statistics given the new guess
	//PRECONDITION: the target has been set to an appropriate int
	//POSTCONDITION: If guess is too high, highGuesses is incremented
	//if guess is too low, lowGuesses is incremented.
	//averageGuess is recalculated with the new guess
	//queries is incremented
	int guess(int userGuess);

	//set the target int.
	//POSTCONDITION: target = rnd
	void setRandom(int rnd);

	//Resets the object to prepare for a new target int. 
	//Must call setRandom after resetting to set the new target!
	//POSTCONDITION: all integer statistics are set to zero
	//as well as target, and known is set to false.
	void reset();


	//Get functions for statistics and state
	int getQueries();
	int getHigh();
	int getLow();
	double getAverage();
	bool getKnown();

	//Copy Constructor
	targetInt(const targetInt &obj);

	//Overloaded Assignment Operator
	//All data members are set to the equivalent values in obj
	void operator = (const targetInt &obj);

	//Overloaded Addition Operators
	//set all statistics to 0 and known to false for targetInt to return
	//then add both targetInt's targets to get the new target
	//or add original targetInt's target with the given int
	//for the new target.
	targetInt operator+(const targetInt &obj);
	targetInt operator+(const int a);
	friend targetInt operator+(int a, targetInt &obj);
	void operator+=(const targetInt &obj);
	void operator+=(const int a);

	//Overloaded Comparison Operators
	//Compares all data types to see if all are equal
	bool operator==(const targetInt &obj) const;
	//Compares all data types to see if any are unequal
	bool operator!=(const targetInt &obj) const;

	//Compare only the target with the equivalent comparison
	bool operator<(const targetInt &obj) const;
	bool operator<=(const targetInt &obj) const;
	bool operator>=(const targetInt &obj) const;
	bool operator>(const targetInt &obj) const;
	

private:
	int target;
	int queries;
	int highGuesses;        //Number of guesses above target
	int lowGuesses;         //Number of guesses below target
	double averageGuess;    //Mean guess value
	bool known;             //Defines whether target is known or unknown
};


#endif