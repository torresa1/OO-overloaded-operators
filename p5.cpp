//Andrew Torres
//p5.cpp
//Version 1.0
//DESCRIPTION: Driver program to test targetInt and randomTargets with their
//added overloaded operators. This program requires and infile and outfile
//named as they are defined as a const (p5Infile.txt & p5Outfile.txt).
//The infile must have TESTNUM + (TESTNUM * RANDSIZE) distinct, positive 
//integers and nothing else.


#include "randomTargets.h"
#include "targetInt.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//consts
const int TESTNUM = 4;
const int RANDSIZE = 3;
const string INFILE = "p5Infile.txt";
const string OUTFILE = "p5Outfile.txt";


int main()
{
	//prepare the input file
	ifstream infile(INFILE.c_str());

	//prepare the output file
	ofstream outfile(OUTFILE.c_str());

	int num;	//General variable for testing
	int a;		//Variable used for for loops

	//Begin testing
	if (outfile.is_open())
	{

		//Open Input File
		if (infile.is_open())
		{
			//Instantiate targetInt array
			targetInt targetsArr[TESTNUM];
			for (a = 0; a < TESTNUM; a++)
			{
				infile >> num;

				outfile << "targetInt " << a + 1 << " encapsulates " << num << endl<< endl;

				targetInt targetTemp;
				targetTemp.setRandom(num);
				targetsArr[a] = targetTemp;

			}

			//First testing guessing functionality with stats for targetInt
			outfile << "Testing collection of targetInt" << endl;
			for (a = 0; a < TESTNUM; a++)
			{
				num = 0;

				outfile << "targetInt " << a + 1 << ": " << endl;
				while (!targetsArr[a].getKnown())
				{
					outfile << "Guess " << num << " gets: " << targetsArr[a].guess(num) << endl;
					num++;
				}

				//Display Stats
				outfile << endl << "Number of Guesses: " << targetsArr[a].getQueries() << endl;
				outfile << "Number of Low Guesses: " << targetsArr[a].getLow() << endl;
				outfile << "Number of High Guesses: " << targetsArr[a].getHigh() << endl;
				outfile << "Average Guess: " << targetsArr[a].getAverage() << endl;
				outfile << "Known: " << targetsArr[a].getKnown() << endl;
				outfile << endl << endl;

			}

			//Begin testing operators
			outfile << "targetInt 1 + targetInt 2 produces the following stats: " 
				<< endl;
			targetInt targAdd = targetsArr[0] + targetsArr[1];

			outfile << "Number of Guesses: " << targAdd.getQueries() << endl;
			outfile << "Number of Low Guesses: " << targAdd.getLow() << endl;
			outfile << "Number of High Guesses: " << targAdd.getHigh() << endl;
			outfile << "Average Guess: " << targAdd.getAverage() << endl;
			outfile << "Known: " << targAdd.getKnown() << endl;
			outfile << endl << endl;

			//Guess until hit target
			num = 0;
			while (!targAdd.getKnown())
			{
				outfile << "Guess " << num << " gets: " << targAdd.guess(num) << endl;
				num++;
			}
			outfile << endl;


			outfile << "targetInt 2 + 3 produces the following stats: "
				<< endl;
			targAdd = targetsArr[1] + 3;

			outfile << "Number of Guesses: " << targAdd.getQueries() << endl;
			outfile << "Number of Low Guesses: " << targAdd.getLow() << endl;
			outfile << "Number of High Guesses: " << targAdd.getHigh() << endl;
			outfile << "Average Guess: " << targAdd.getAverage() << endl;
			outfile << "Known: " << targAdd.getKnown() << endl;
			outfile << endl;

			//Guess until hit target
			num = 0;
			while (!targAdd.getKnown())
			{
				outfile << "Guess " << num << " gets: " << targAdd.guess(num) << endl;
				num++;
			}
			outfile << endl;


			outfile << "4 + targetInt 2 produces the following stats: "
				<< endl;
			targAdd = 4 + targetsArr[1];

			outfile << "Number of Guesses: " << targAdd.getQueries() << endl;
			outfile << "Number of Low Guesses: " << targAdd.getLow() << endl;
			outfile << "Number of High Guesses: " << targAdd.getHigh() << endl;
			outfile << "Average Guess: " << targAdd.getAverage() << endl;
			outfile << "Known: " << targAdd.getKnown() << endl;
			outfile << endl;

			//Guess until hit target
			num = 0;
			while (!targAdd.getKnown())
			{
				outfile << "Guess " << num << " gets: " << targAdd.guess(num) << endl;
				num++;
			}
			outfile << endl;


			outfile << "The previous targetInt += 5 produces the following stats: "
				<< endl << endl;
			targAdd += 5;

			outfile << "Number of Guesses: " << targAdd.getQueries() << endl;
			outfile << "Number of Low Guesses: " << targAdd.getLow() << endl;
			outfile << "Number of High Guesses: " << targAdd.getHigh() << endl;
			outfile << "Average Guess: " << targAdd.getAverage() << endl;
			outfile << "Known: " << targAdd.getKnown() << endl;
			outfile << endl;

			//Guess until hit target
			num = 0;
			while (!targAdd.getKnown())
			{
				outfile << "Guess " << num << " gets: " << targAdd.guess(num) << endl;
				num++;
			}
			outfile << endl;

			outfile << 
				"The previous targetInt += targetInt 1 produces the following stats: " 
				<< endl << endl;
			targAdd += targetsArr[0];

			outfile << "Number of Guesses: " << targAdd.getQueries() << endl;
			outfile << "Number of Low Guesses: " << targAdd.getLow() << endl;
			outfile << "Number of High Guesses: " << targAdd.getHigh() << endl;
			outfile << "Average Guess: " << targAdd.getAverage() << endl;
			outfile << "Known: " << targAdd.getKnown() << endl;
			outfile << endl;

			//Guess until hit target
			num = 0;
			while (!targAdd.getKnown())
			{
				outfile << "Guess " << num << " gets: " << targAdd.guess(num) << endl;
				num++;
			}
			outfile << endl;



			//Assignment Operator testing
			outfile << "targetInt 1 = targetInt 2 produces the following stats: "
				<< endl;
			targetsArr[0] = targetsArr[1];

			outfile << endl << "Number of Guesses: " << targetsArr[0].getQueries() << endl;
			outfile << "Number of Low Guesses: " << targetsArr[0].getLow() << endl;
			outfile << "Number of High Guesses: " << targetsArr[0].getHigh() << endl;
			outfile << "Average Guess: " << targetsArr[0].getAverage() << endl;
			outfile << "Known: " << targetsArr[0].getKnown() << endl;
			outfile << endl << endl;

			
			outfile << "Note: targetInt 1 now = targetInt 2 for all further testing" <<
				endl << endl;

			//Test Overloaded Comparison Operators
			bool tester = targetsArr[0] == targetsArr[3];
			outfile << "targetInt 1 == targetInt 4 produces: " << tester << endl;

			tester = targetsArr[0] != targetsArr[3];
			outfile << "targetInt 1 != targetInt 4 produces: " << tester << endl;

			tester = targetsArr[0] == targetsArr[1];
			outfile << "targetInt 1 == targetInt 2 produces: " << tester << endl;

			tester = targetsArr[0] < targetsArr[2];
			outfile << "targetInt 1 < targetInt 3 produces: " << tester << endl;

			tester = targetsArr[0] > targetsArr[2];
			outfile << "targetInt 1 > targetInt 3 produces: " << tester << endl;

			tester = targetsArr[0] >= targetsArr[1];
			outfile << "targetInt 1 >= targetInt 2 produces: " << tester << endl;

			tester = targetsArr[0] <= targetsArr[3];
			outfile << "targetInt 1 <= targetInt 4 produces: " << tester << endl << endl;


			//End targetInt testing- Begin randomTargets testing


			outfile << "Begin testing randomTargets: " << endl << endl;
			//Instantiate randomTargets array
			randomTargets randArr[TESTNUM];
			for (a = 0; a < TESTNUM; a++)
			{
				randomTargets randomTemp(RANDSIZE);
				outfile << "randomTargets " << a + 1 << " encapsulates the following: ";


				//fill the randomTargets' encapsulated int with the given numbers
				for (int z = 0; z < RANDSIZE; z++)
				{
					infile >> num;
					outfile << num << ", ";
					randomTemp.setTargets(z, num);	
				}

				randArr[a] = randomTemp;
				outfile << endl;
			}

			//Testing Overloaded Addition Operators
			outfile << "Testing randomTargets 1 + randomTargets 2" << endl << endl;
			randomTargets randTemp;
			randTemp = randArr[0] + randArr[1];

			num = 0;
			while (randTemp.getSize() > 0)
			{
				outfile << "Guess " << num << " returns " << 
					randTemp.checkGuess(num) << " correct values" << endl;
				
				randTemp.deleteKnown();
				num++;
			}
			
			outfile << endl << "Testing randomTargets 1 + 8" << endl << endl;
			randTemp = randArr[0] + 8;

			num = 0;
			while (randTemp.getSize() > 0)
			{
				outfile << "Guess " << num << " returns " <<
					randTemp.checkGuess(num) << " correct values" << endl;

				randTemp.deleteKnown();
				num++;
			}


			outfile << endl << "Testing 5 + randomTargets 1" << endl << endl;
			randTemp = 5 + randArr[0];

			num = 0;
			while (randTemp.getSize() > 0)
			{
				outfile << "Guess " << num << " returns " <<
					randTemp.checkGuess(num) << " correct values" << endl;

				randTemp.deleteKnown();
				num++;
			}

			outfile << endl << "Testing randomTargets 1 += randomTargets 2" << endl;
			randTemp = randArr[0];
			randTemp += randArr[1];

			num = 0;
			while (randTemp.getSize() > 0)
			{
				outfile << "Guess " << num << " returns " <<
					randTemp.checkGuess(num) << " correct values" << endl;

				randTemp.deleteKnown();
				num++;
			}


			outfile << endl << "Testing randomTargets 1 += 4" << endl;
			randTemp = randArr[0];
			randTemp += 4;

			num = 0;
			while (randTemp.getSize() > 0)
			{
				outfile << "Guess " << num << " returns " <<
					randTemp.checkGuess(num) << " correct values" << endl;

				randTemp.deleteKnown();
				num++;
			}

			//Testing Overloaded Comparison Operators
			tester = randArr[0] == randArr[1];
			outfile << endl << "randomTargets 1 == randomTargets 2 produces: " << 
				tester << endl;

			tester = randArr[0] == randArr[3];
			outfile << endl << "randomTargets 1 == randomTargets 4 produces: " << 
				tester << endl;

			tester = randArr[0] != randArr[1];
			outfile << endl << "randomTargets 1 != randomTargets 2 produces: " <<
				tester << endl;

			tester = randArr[0] != randArr[3];
			outfile << endl << "randomTargets 1 != randomTargets 4 produces: " <<
				tester << endl;

			tester = randArr[0] < randArr[1];
			outfile << endl << "randomTargets 1 < randomTargets 2 produces: " <<
				tester << endl;

			tester = randArr[0] <= randArr[1];
			outfile << endl << "randomTargets 1 <= randomTargets 2 produces: " <<
				tester << endl;

			tester = randArr[0] > randArr[1];
			outfile << endl << "randomTargets 1 > randomTargets 2 produces: " <<
				tester << endl;

			tester = randArr[0] >= randArr[1];
			outfile << endl << "randomTargets 1 >= randomTargets 2 produces: " <<
				tester << endl;


			//End by testing the statistics functionality of randomTargets
			outfile << endl << "Testing randomTargets 3" << endl;
			num = 0;
			while (randArr[2].getSize() > 0)
			{
				outfile << "Guess " << num << " returns " <<
					randArr[2].checkGuess(num) << " correct values" << endl;
				outfile << "Stats before deletion of known" << endl;
				outfile << "Average Guess: " << randArr[2].getAverage() << endl;
				outfile << "Highest high Guesses: " << randArr[2].getHighestHigh() << endl;
				outfile << "Highest low Guesses: " << randArr[2].getHighestLow() << endl;
				outfile << "Size: " << randArr[2].getSize() << endl << endl;
				randArr[2].deleteKnown();
				num++;
			}

			infile.close();
		}

		outfile.close();
	}

}
