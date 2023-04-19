/*
Tanner Cox
CS255
P04: Merge Sort
Description: This program impliments user-defined sorting algorithms to sort a randomly seeded array of a user-defined size
			 It outputs the time taken to perform the sorting operation as well as the sorted or unsorted array of integers.
			 Random.cpp provides the user with the necessary operations to generate a random list of integers.
*/
#include <ctime>
#include <cstdlib>
#include "Random.h"
void seedRandomizer()
{
	srand(time(NULL));
}

int generateRandomInt(int low, int high)
{
	return rand() % high + low;
}

float generateRandomInt(float low, float high)
{
	return ((high - low) * ((float)rand() / RAND_MAX)) + low;
}