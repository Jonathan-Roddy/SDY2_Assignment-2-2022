
#include "PriorityQueue.h"
#include <iostream>
#include <string>

#include <windows.h>

using namespace std;


struct Patient {
	string name;
	int priority;

	bool operator < (Patient  p1)
	{
		return p1.priority > priority;
	}
	bool operator <= (Patient  p1)
	{
		return p1.priority >= priority;
	}
	bool operator > (Patient  p1)
	{
		return p1.priority < priority;
	}
	bool operator >= (Patient  p1)
	{
		return p1.priority <= priority;
	}
	bool operator == (Patient  p1)
	{
		return p1.priority == priority;
	}
};


int main()
{
	// colour options
	system("color 70");

	string x = "2";
	int y = 0;

	Patient p1 = { "Tom",3 };
	Patient p2 = { "Mary",4 };
	Patient p3 = { "Fred",3 };
	Patient p4 = { "Sarah",1 };
	Patient p5 = { "Ann",5 };
	Patient p6 = { "Mike",4 };
	Patient pUser{ x , y };

	PQType<Patient> pQueue(100); // have to enter a max int

	pQueue.Enqueue(p1);
	pQueue.Enqueue(p2);
	pQueue.Enqueue(p3);
	pQueue.Enqueue(p4);
	pQueue.Enqueue(p5);
	pQueue.Enqueue(p6);

	int option = 0;
	do
	{
		system("CLS");
		cout << " #=====================================#\n"
			 << " #             Assignment 2            #\n"
			 << " #=====================================#\n"
			 << " 1. Add Patient to queue.\n"
			 << " 2. Call Patient to appointment\n"
			 << " 3. Display all patients\n"
			 << " 4. Exit\n"
			 << " #=====================================#\n"
			 << " Please pick an option :  \n";

		cin >> option;
		cout << "You have chosen option: " << option << endl;

		switch (option) {
		case 1:

			system("CLS");

			cout << "\nPlease enter the patients name: \n";
			cin >> x;

			cout << "\nPlease enter the patients A & E priority:\n";
			cin >> y;

			pUser.name = x;
			pUser.priority = y;

			pQueue.Enqueue(pUser); // adds the new user to the priority queue

			break;
		case 2:
			system("CLS");
			pQueue.Dequeue(pUser); //Removes top item from the queue
			break;

		case 3:
			system("CLS");
			pQueue.Print(); // prints contents of entire queue.
			break;

		case 4:
			system("CLS");
			break; // exits program

		default:
			cout << "Invalid Option. Please choose again.\n";
			break;
		}
	} while (option != 4);
}

