/*
Tanner Cox
CS255
P04: Merge Sort
Description: This program impliments user-defined sorting algorithms to sort a randomly seeded array of a user-defined size
			 It outputs the time taken to perform the sorting operation as well as the sorted or unsorted array of integers.
			 SortDiff.cpp contains prompts and menus for the user to implement, it also handles the implementation of a chosen
			 algorithm.
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include "Random.h"
#include "Sort.h"

using namespace std;

//Pre: User interface/ menu for sorting algorith choice
//Post: Based on selection, array will be sorted by algorithm
int menu()
{
	int val;
	do {
		cout << "Chose the sorting algorithm or operation : " << endl;
		cout << "\t1. Bubble Sort" << endl;
		cout << "\t2. Selection Sort" << endl;
		cout << "\t3. Insertion Sort" << endl;
		cout << "\t4. Quick Sort" << endl;
		cout << "\t5. Merge Sort" << endl;
		//cout << "\t6. Bubble Parallel" << endl;
		cout << "\t6. Print Array" << endl;
		//cout << "\t8. Exit program" << endl;
		cout << "Enter selection : ";
		cin >> val;
	} while (val < 1 || val > 8);
	return val;
}

//Pre: Print array is chosen by the user
//Post: A sorted or unsorted variant of the array will be displayed
int displayArray(Sort* s, int* sorted)
{
	int val, item;
	cout << "Chose the array to display : " << endl;
	cout << "\t1. Unsorted Array" << endl;
	cout << "\t2. Sorted Array" << endl;
	cout << "Enter selection : ";
	cin >> val;
	int sz = s->getSize();
	for (int i = 0; i < sz; i++)
	{
		if (val == 1)
		{
			item = s->getData(i);
			cout << item << endl;
		}
		else
		{
			cout << sorted[i] << endl;
		}
	}
	return 0;
}

int main()
{
	int size, val;
	time_t start, end;
	double totalTime;

	seedRandomizer();
	cout << "How big of an array do you want to work with? : ";
	cin >> size;

	Sort* s = new Sort(size);
	int* sorted = new int[size];
	for (int i = 0; i < size; i++)
	{
		val = generateRandomInt(1, 50000);
		s->addData(i, val);
	}
	do {
		val = menu();
		start = time(NULL);
		switch (val)
		{
		case 1: sorted = s->bubbleSort();
			break;
		case 2: sorted = s->selectionSort();
			break;
		case 3: sorted = s->insertionSort();
			break;
		case 4: sorted = s->quickSort();
			break;
		case 5: sorted = s->mergeSort();
			break;
		//case 6 : sorted = s->bubbleParallel();
		  //break;
		case 6: displayArray(s, sorted);

		}

		if (val < 7)
		{
			totalTime = difftime(start, time(&end));
			totalTime = fabs(totalTime);
			cout << "Total time to sort the array using the specified algorithm is : ";
			cout << totalTime << " seconds." << endl;
		}
	} while (val != 7);

	cout << "Have a great day..." << endl;
	delete[] sorted;
	return 0;
}