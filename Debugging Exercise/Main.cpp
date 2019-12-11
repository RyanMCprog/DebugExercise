// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}
//keeps track of how many marines are alive
size_t squadSize(Marine * squadArr, size_t arrSize)
{
	size_t aliveMember = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			aliveMember++;
		}
	}
	return aliveMember;
}
//keeps track of how many zerglings are alive
size_t swarmSize(Zergling * swarmArr, size_t arrSize)
{
	size_t aliveMember = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			aliveMember++;
		}
	}
	return aliveMember;
}

void squadStrike(Zergling * swarmArr, size_t swarmArrSize, int pain)
{
	// each marine will attack the first alive zergling in the swarm
	for (size_t i = 0; i < swarmArrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			swarmArr[i].takeDamage(pain);
			if (!swarmArr[i].isAlive()) // if the zergling dies, it is marked as such
			{
				cout << "The zergling target dies" << endl;
			}
			return;
		}
	}

}
//each alive zergling will attack the first alive marine that is alive
void swarmStrike(Marine * squadArr, size_t squadArrSize, int pain)
{
	for (size_t i = 0; i < squadArrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			squadArr[i].takeDamage(pain);
			if (squadArr[i].isAlive())
			{
				cout << "The marine is wounded but is still standing" << endl;
			}
			else //if they die it is marked and said how many are left
				cout << "The marine succumbs to his wounds." << endl;
			cout << "There are "<< squadSize(squadArr, 10) << " marines left." << endl;
			return;
		}
	}
	
	
}

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, 10) && zerglingAlive(swarm, 20)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad,10)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize(squad,10); i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				squadStrike(swarm, 20, damage);
			}
		}
		if (zerglingAlive(swarm,20)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize(swarm,20); i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
				int damage = swarm[i].attack();

				swarmStrike(squad, 10, damage);
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad,10))
	{
		int finalthoughts;
		cout << "The Marines win." << endl;
		std::cin >> finalthoughts;
	} 
	else if(zerglingAlive(swarm, 10))
	{
		int finalthoughts;
		cout << "The Zerg win." << endl;
		std::cin >> finalthoughts;
	}
	else
	{
		int finalthoughts;
		cout << "Draw" << endl;
		std::cin >> finalthoughts;
	}
}


