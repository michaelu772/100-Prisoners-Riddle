// Author: Michael Urquiza
// Date: 6/30/22

#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
using namespace std;

vector<int> populateRoom();
void printRoom(vector<int> room);
bool checkBox(vector<int> room, int temp, int i);
bool game(vector<int> room);

int PRISONERS = 100;
int tries = PRISONERS / 2;

int main()
{
	vector<int> room;
	int loops = 100;
	int success = 0;
	int i = 0;

	while(i < loops)
	{
		if (game(room))
		{
			++success;
		}
		++i;
	}

	float successrate = 100.0f * ((float)success / (float)loops);
	printf("%f percent success rate.\n%d# of successes.", successrate, success);

	return 1;
}

////////////////////////////////////////////////////////////////////////
//
// populateRoom(): fills a vector of size PRISONERS from 1 - PRISONERS
//				   and then shuffles randomly.
//
// return type: vector<int>
// 
////////////////////////////////////////////////////////////////////////

vector<int> populateRoom()
{
	vector<int> room(PRISONERS);
	for (int i = 0; i < PRISONERS; ++i)
	{
		room[i] = i + 1;
	}

	random_device dev;
	mt19937 rng(dev());
	shuffle(begin(room), end(room), rng);
	return room;
}

////////////////////////////////////////////////////////////////////////
//
// printRoom(vector<int> room): Prints the 'room' vector in rows and columns
//								equal to the root of PRISONERS to the console.
//				  
// return type: void
// 
////////////////////////////////////////////////////////////////////////

void printRoom(vector<int> room)
{
	int x = sqrt(PRISONERS);
	for (int i = 1;i <= PRISONERS; ++i)
	{
		cout << "(" << i << ")" << room[i-1] << "\t";
		if (i % x == 0)
		{
			cout << endl;
		}
	}
}

////////////////////////////////////////////////////////////////////////
//
// checkBox(vector<int> room, int temp, int i): Given both the original
//					prisoners number(i) and the number that is currently 
//					being searched(temp), check if thecurrent number is 
//					the number that is being searched for. 
// 
// return type: bool
//
////////////////////////////////////////////////////////////////////////

bool checkBox(vector<int> room, int temp, int i)
{
	int index = temp - 1;
	printf("Checking if %d is equal to room[%d], which is %d\n", i, index + 1, room[index]);
	if (i == room[index])
	{
		cout << "\nSuccess!" << endl;
		return true;
	}
	cout << "\tFailure!" << endl;
	return false;
}

////////////////////////////////////////////////////////////////////////
//
// bool game(vector<int> room): Main game loop, populates the room, prints
//					to the console, then begins seaching for the prisoners
//					number, if the number of tries excedes the alloted amount
//					the iteration of the game ends.
//
// return type: bool
// 
////////////////////////////////////////////////////////////////////////

bool game(vector<int> room)
{
	int temp;
	room = populateRoom();
	printRoom(room);
	for (int currPrison = 1; currPrison <= PRISONERS; ++currPrison)
	{
		temp = currPrison;
		for (int attempt = 1; attempt <= tries; ++attempt)
		{
			if (checkBox(room, temp, currPrison))
			{
				printf("Prisoner #%d has found their number on their %dth try.\n", currPrison, attempt);
				printf("--------------------------------------------------------------------------------\n\n");
				return true;
			}
			else if (attempt == tries)
			{
				printf("Prisoner #%d has failed to escape.\n", currPrison);
				printf("********************************************************************************\n\n");
				return false;
			}
			temp = room[temp - 1];
		}
	}

	return false;
}