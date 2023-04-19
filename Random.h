/*
Tanner Cox
CS255
P04: Merge Sort
Description: This program impliments user-defined sorting algorithms to sort a randomly seeded array of a user-defined size
			 It outputs the time taken to perform the sorting operation as well as the sorted or unsorted array of integers.
			 Random.h declares the functions used to generate random integers.
*/
#if !defined NULL
#define NULL = 0;
#endif

#if !defined RANDOM_H
#define RANDOM_H

//Pre : None
void seedRandomizer();
//Post: Randomizer is seeded with the current time

//Pre : low and high are ints that define the range of random 
//		numbers. low is less than high
int generateRandomInt(int low, int high);
//Post: returns an integer that is between low (inclusive) 
//		and high (exclusive)

//Pre : low and high are floats that define the range of random 
//		numbers. low is less than high
float generateRandomInt(float low, float high);
//Post: returns a float that is between low (inclusive) 
//		and high (exclusive)

#endif
