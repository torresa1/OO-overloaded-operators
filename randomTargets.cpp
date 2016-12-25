//Andrew Torres
//randomTargets.cpp
//Version: 1.5
//DESCRIPTION: Implementation of randomTargets.h

#include "randomTargets.h"


randomTargets::randomTargets()
{
	size = -1;
	targets = new targetInt[1];
}

randomTargets::randomTargets(int numTargets)
{
	targets = new targetInt[numTargets];

	size = numTargets;
}

void randomTargets::setTargets(int index, int num)
{
	targets[index].setRandom(num);
}


void randomTargets::deleteTarget(int index)
{
	if (targets[index].getKnown())
	{
		//Move every targetInt above the target's index down by one
		for (int a = index; a < size - 1; a++)
			targets[a] = targets[a + 1];

		size--;


	}
}


void randomTargets::deleteKnown()
{
	for (int x = size - 1; x >= 0; x--)
	{
		if (targets[x].getKnown())
			deleteTarget(x);

	}

}


int randomTargets::checkGuess(int num)
{
	int totalRight = 0;

	if (size <= 0)
		return -1;

	for (int b = 0; b < size; b++)
	{
		if (targets[b].guess(num) == 0)
			totalRight++;

	}

	return totalRight;
}


int randomTargets::getHighestHigh()
{
	int high = -1;

	for (int a = 0; a < size; a++)
	{
		if (targets[a].getHigh() > high)
		{
			high = targets[a].getHigh();
		}
	}

	return high;
}


int randomTargets::getHighestLow()
{
	int low = -1;   //highest guess of low numbers

	for (int a = 0; a < size; a++)
	{
		if (targets[a].getLow() > low)
		{
			low = targets[a].getLow();
		}
	}

	return low;
}


double randomTargets::getAverage()
{
	return targets[0].getAverage();
}


int randomTargets::getSize()
{
	return size;
}


randomTargets::~randomTargets()
{
	delete[] targets;
}

randomTargets::randomTargets(const randomTargets &obj)
{
	size = obj.size;

	targets = new targetInt[size];

	for (int a = 0; a < size; a++)
		targets[a] = obj.targets[a];

}

void randomTargets::operator=(const randomTargets &obj)
{
	size = obj.size;

	delete[] targets;

	targets = new targetInt[size];

	for (int a = 0; a < size; a++)
		targets[a] = obj.targets[a];
}

randomTargets randomTargets::operator+(const randomTargets &obj)
{
	int a;
	int b;

	int tempSize = this->size + obj.size;
	randomTargets temp(tempSize);


	//Fill first half with lhs targetInts
	for (a = 0; a < this->size; a++)
		temp.targets[a] = this->targets[a];

	//Fill second half with rhs targetInts
	for (b = 0; b < obj.size; b++)
		temp.targets[a + b] = obj.targets[b];

	return temp;
}

randomTargets randomTargets::operator+(const int a)
{
	int tempSize = this->size + 1;

	randomTargets temp(tempSize);

	//Fill targets with the original targets
	for (int c = 0; c < tempSize - 1; c++)
		temp.targets[c] = this->targets[c];

	//add another value to targets with target being a
	targetInt newTarg;
	newTarg.setRandom(a);

	temp.targets[tempSize - 1] = newTarg;

	return temp;
}

randomTargets operator+(int a, randomTargets &obj)
{
	int tempSize = obj.size + 1;

	randomTargets temp(tempSize);

	//add first value to targets with target being a
	targetInt newTarg;
	newTarg.setRandom(a);

	temp.targets[0] = newTarg;

	//Fill the rest of targets with the original targets
	for (int c = 1; c < tempSize; c++)
		temp.targets[c] = obj.targets[c - 1];



	return temp;

}

void randomTargets::operator+=(const randomTargets &obj)
{
	//Make a temp array for holding this targets
	targetInt *temp;
	temp = new targetInt[this->size];
	for (int a = 0; a < this->size; a++)
		temp[a] = this->targets[a];
	
	//Update size
	this->size = this->size + obj.size;

	//Delete original targets
	delete[] this->targets;

	//Make new targets of appropriate size
	this->targets = new targetInt[this->size];

	//Fill first half with original values
	for (int z = 0; z < this->size - obj.size; z++)
		this->targets[z] = temp[z];
	//Fill second half with rhs values
	for (int y = this->size - obj.size; y < this->size; y++)
		this->targets[y] = obj.targets[y - obj.size];

	delete[] temp;

}

void randomTargets::operator+=(const int a)
{
	targetInt *temp;
	temp = new targetInt[this->size];
	for (int b = 0; b < this->size; b++)
		temp[b] = this->targets[b];

	//Update size
	this->size = this->size + 1;

	//Delete original targets
	delete[] this->targets;

	//Make new targets of appropriate size
	this->targets = new targetInt[this->size];

	//Fill first half with original values
	for (int z = 0; z < this->size - 1; z++)
		this->targets[z] = temp[z];
	
	//Make and fill the last targetInt to end array
	targetInt tint;
	tint.setRandom(a);

	this->targets[this->size - 1] = tint;

	delete[] temp;
}

bool randomTargets::operator==(const randomTargets &obj) const
{
	if (this->size != obj.size)
		return false;

	for (int a = 0; a < this->size; a++)
		if (this->targets[a] != obj.targets[a])
			return false;
	
	return true;
}

bool randomTargets::operator!=(const randomTargets &obj) const
{
	return !(*this == obj);
}

bool randomTargets::operator<(const randomTargets &obj) const
{
	return this->size < obj.size;
}

bool randomTargets::operator<=(const randomTargets &obj) const
{
	return this->size <= obj.size;
}

bool randomTargets::operator>(const randomTargets &obj) const
{
	return this->size > obj.size;
}

bool randomTargets::operator>=(const randomTargets &obj) const
{
	return this->size >= obj.size;
}