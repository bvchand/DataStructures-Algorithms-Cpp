//============================================================================
// Name        : Monty-Hall.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Version     : 2
// Description : Assignment #2 - Monty-Hall Problem in C++
//============================================================================


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;


/**
 * Simulate the door choices
 * @param i the iteration number
 * @param &win_first address of the win_first variable
   - number of first choice wins
 * @param &win_second address of the win_second variable
   - number of second choice wins
 */
void simulate(int i, int &win_first, int &win_second);

/**
 * Compute the door behind which the car is hid
 * @return door# where car is hid
 */
Door hideCar();

/**
 * Compute the door which Monty opens
 * @param car_position door# where car is hid
 * @param choice1 First choice of the contestant
 * @return door # which Monty opens
 */
Door openDoor(Door car_position, Door choice1);

/**
 * Compute the first choice of the contestant
 * @return first choice of door#
 */
Door makeFirstChoice();

/**
 * Compute the second choice of the contestant
 * @param opened_door door# which Monty opened previously
 * @param choice1 First choice of the contestant
 * @return second choice of door#
 */
Door makeSecondChoice(Door opened_door, Door choice1);

int main()
{
    int win1 = 0, win2 = 0;

    //print the header
	cout << "   #" << "     Car" << "   First" << "  Opened" << "  Second" << "    Win" << "     Win" << endl;
	cout << "        here" << "  choice" << "    door" << "  choice" << "  first" << "  second" << endl;

	//This generates a new pattern of random numbers everytime
	srand(time(0));

	//Run the simulations
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);

    return 0;
}

void simulate(int i, int &win_first, int &win_second)
{

	Door car_here = hideCar();
	Door first_choice = makeFirstChoice();
	Door open_door = openDoor(car_here, first_choice);
	Door second_choice = makeSecondChoice(open_door, first_choice);

	//print the Car here, First choice, Opened door and Second choice values
//	cout << "   " << i << "\t   " << car_here << "\t   " << first_choice  << "\t   " << open_door << "   \t   " << second_choice << "\t";
	cout << setw(4) << i << setw(8) << car_here << setw(8) << first_choice  << setw(8) << open_door << setw(8) << second_choice << setw(8);

	if(car_here == first_choice)
	{
		//number of wins by staying with the contenstant's first door choice
		win_first++;
		cout << "yes" << endl;
	}

	else
	{
		//number of wins when switched to the contestant's second door choice
		win_second++;
		cout << "\t" << "yes" << endl;
	}

	if(i == 100)
	{
	    cout << "\n" << "   " << win_first << " wins if stay with the first choice" << endl;
	    cout << "   " << win_second << " wins if switch to the second choice" << endl;

	    //print the switch over the stay winning ratio
	    cout <<  "Win ratio of switch over stay: " << static_cast<double> (win_second)/win_first;
	}

}

Door hideCar()
{
	//choose a random number between 1,2,3 for the door where the car is hid
	return rand()%3 + 1;
}


Door makeFirstChoice()
{
	//choose a random number between 1,2,3 for the contestant's first choice
	return rand()%3 + 1;
}

Door openDoor(Door car_position, Door choice1)
{
	Door open = rand()%3 + 1;

	//Compute a random number between 1,2,3 for the door to be opened
	//Opened door != door # where car is hid or the contestant's first choice
	while((car_position == open) || (choice1 == open))
	{
		open = rand()%3 + 1;
	}
	return open;
}

Door makeSecondChoice(Door opened_door, Door choice1)
{
	Door second = rand()%3 + 1;

   //Compute a random number between 1,2,3 for the door to be opened
   //Second door != door which Monty opened or the contestant's first choice
	while((opened_door == second) || (choice1 == second))
	{
		second = rand()%3 + 1;
	}
	return second;
}
