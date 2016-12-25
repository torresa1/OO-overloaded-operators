//Andrew Torres
//targetInt.cpp
//Version: 2.0
//DESCRIPTION: implementation of targetInt.h


#include "targetInt.h"



targetInt::targetInt()
{
	//Initialize all variables to 0.
	target = 0;
	queries = 0;
	highGuesses = 0;
	lowGuesses = 0;
	averageGuess = 0;
	known = false;
}


targetInt::~targetInt()
{
}

int targetInt::guess(int userGuess)
{
	queries++;

	//A formula for calculating the new mean guess value given queries,
	//previous mean, and the new guess.
	averageGuess = ((averageGuess * (queries - 1)) + userGuess) / queries;

	if (userGuess > target)
	{
		highGuesses++;
		return 1;
	}
	else if (userGuess < target)
	{
		lowGuesses++;
		return -1;
	}

	//If not too low or too high, then object is known and correct
	known = true;
	return 0;

}

void targetInt::setRandom(int rnd)
{
	target = rnd;
}

void targetInt::reset()
{
	target = 0;
	queries = 0;
	highGuesses = 0;
	lowGuesses = 0;
	averageGuess = 0;
	known = false;
}

int targetInt::getQueries()
{
	return queries;
}

int targetInt::getHigh()
{
	return highGuesses;
}

int targetInt::getLow()
{
	return lowGuesses;
}

double targetInt::getAverage()
{
	return averageGuess;
}

bool targetInt::getKnown()
{
	return known;
}

void targetInt::operator=(const targetInt &obj)
{
	target = obj.target;
	queries = obj.queries;
	highGuesses = obj.highGuesses;
	lowGuesses = obj.lowGuesses;
	averageGuess = obj.averageGuess;
	known = obj.known;
}

targetInt::targetInt(const targetInt &obj)
{
	target = obj.target;
	queries = obj.queries;
	highGuesses = obj.highGuesses;
	lowGuesses = obj.lowGuesses;
	averageGuess = obj.averageGuess;
	known = obj.known;
}


targetInt targetInt::operator+(const targetInt &obj)
{
	targetInt temp;
	temp.target = this->target + obj.target;
	temp.queries = 0;
	temp.highGuesses = 0;
	temp.lowGuesses = 0;
	temp.averageGuess = 0;
	temp.known = false;

	return temp;

}

targetInt targetInt::operator+(const int a)
{
	targetInt temp;
	temp.target = this->target + a;
	temp.queries = 0;
	temp.highGuesses = 0;
	temp.lowGuesses = 0;
	temp.averageGuess = 0;
	temp.known = false;
	return temp;
}

targetInt operator+(int a, targetInt &obj)
{
	targetInt temp;
	temp.target = a + obj.target;
	temp.queries = 0;
	temp.highGuesses = 0;
	temp.lowGuesses = 0;
	temp.averageGuess = 0;
	temp.known = false;
	return temp;
}

void targetInt::operator+=(const targetInt &obj)
{
	this->target = this->target + obj.target;
	this->queries = 0;
	this->highGuesses = 0;
	this->lowGuesses = 0;
	this->averageGuess = 0;
	this->known = false;

}

void targetInt::operator+=(const int a)
{
	this->target = this->target + a;
	this->queries = 0;
	this->highGuesses = 0;
	this->lowGuesses = 0;
	this->averageGuess = 0;
	this->known = false;

}

bool targetInt::operator==(const targetInt &obj) const
{
	return (this->target == obj.target 
		&& this->queries == obj.queries 
		&& this->highGuesses == obj.highGuesses 
		&& this->lowGuesses == obj.lowGuesses 
		&& this->averageGuess == obj.averageGuess);
}

bool targetInt::operator!=(const targetInt &obj) const
{
	return !(this->target == obj.target
		&& this->queries == obj.queries
		&& this->highGuesses == obj.highGuesses
		&& this->lowGuesses == obj.lowGuesses
		&& this->averageGuess == obj.averageGuess);
}

bool targetInt::operator<(const targetInt &obj) const
{
	return (this->target < obj.target);
}

bool targetInt::operator<=(const targetInt &obj) const
{
	return (this->target <= obj.target);
}

bool targetInt::operator>(const targetInt &obj) const
{
	return (this->target > obj.target);
}

bool targetInt::operator>=(const targetInt &obj) const
{
	return (this->target >= obj.target);
}