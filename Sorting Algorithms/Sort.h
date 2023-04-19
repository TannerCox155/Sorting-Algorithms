/*
Tanner Cox
CS255
P04: Merge Sort
Description: This program impliments user-defined sorting algorithms to sort a randomly seeded array of a user-defined size
			 It outputs the time taken to perform the sorting operation as well as the sorted or unsorted array of integers.
			 Sort.h declares necessary array variables, constructor and destructor for array, convienence functions, and functions
			 for sorting algorithms.
*/

#if !defined SORT_H
#define SORT_H

class Sort
{
private:
	int* items; //pointer to array items
	int size; //total size of array

	//Pre: Array is constructed and populated with values
	int* clone();
	//Post: Array is cloned and returned to where function was called

	//Pre: bubblesort is selected as sorting algorithm
	void _bubbleSort(int* sorted);
	//Post: Swaps adjacent elements if they are in wrong order

	//Pre: selectionsort is selected as sorting algorithm
	void _selectionSort(int* sorted);
	//Post: Treats input as two parts, sorted and unsorted, repeatedly selects proper next value to move from unsorted to end of sorted part

	//Pre: insertionsort is selected as sorting algorithm
	void _insertionSort(int* sorted);
	//Post: Treats input as two parts, sorted and unsorted, inserts next value from unsorted part to correct location of sorted part

	//Pre: quicksort is selected as sorting algorithm
	void _quickSort(int* sorted, int left, int right);
	//Post: Creates pivot using lumuto partition, repeatedly partitions input into low and high parts(unsorted) then recursivly sorts each part.

	//Pre: mergesort is selected as sorting algorithm
	void _mergeSort(int* sorted, int left, int right);
	//Post: Divides list into two halves and recursivly sorts each half until a list of 1 element is remaining

	//Pre: Called by _mergeSort
	void merge(int* sorted, int left, int mid, int right);
	//Post: Sorts left and right partions into ordered temp array that is copied into original array

	//Functions for Quick Sort
	void choosePivot(int* sorted, int left, int right);
	int lamutoPartition(int* sorted, int left, int right);
public:
	//Pre: Array constructor
	Sort(int sz);
	//Post: Creates default array

	//Pre: Array destructor
	~Sort();
	//Post: Deletes array from heap

	//Pre: User is prompted to choose a sorting algorithm
	int* bubbleSort();
	//Post: Creates and passes clone to _bubbleSort function, returns clone of array 

	//Pre: User is prompted to choose a sorting algorithm
	int* selectionSort();
	//Post: Creates and passes clone to _quickSort, returns clone

	//Pre: User is prompted to choose a sorting algorithm
	int* insertionSort();
	//Post: Creates and passes clone to _insertionSort, returns clone

	//Pre: User is prompted to choose a sorting algorithm
	int* quickSort();
	//Post: Creates and passes clone to _quickSort, returns clone

	//Pre: User is prompted to choose a sorting algorithm
	int* mergeSort();
	//Post: Creates and passes clone to _mergeSort, returns clone

	//Pre: Index and value passed
	void addData(int index, int data);
	//Post: Array at index passed is assigned that value/data

	//Pre: Index is passed as parameter for data retrieval
	int getData(int index);
	//Post: Data at index is returned 

	//Pre: Function is called 
	int getSize();
	//Post: Returns size of  items array
};

#endif
