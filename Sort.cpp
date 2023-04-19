/*
Tanner Cox
CS255
P04: Merge Sort
Description: This program impliments user-defined sorting algorithms to sort a randomly seeded array of a user-defined size
			 It outputs the time taken to perform the sorting operation as well as the sorted or unsorted array of integers.
			 Sort.cpp performs the operations of a user implemented sorting algorithm, it also contains convienence functions.
*/

#include "Sort.h"
#include <omp.h>

Sort::Sort(int sz) { //constructor
	items = new int[sz]; 
	size = sz;
}

Sort::~Sort() { //destructor
	delete[] items;
}

int* Sort::clone() { //clone/copy array
	int* sorted = new int[size];
	for (int i = 0; i < size; ++i) {
		sorted[i] = items[i];
	}
	return sorted;
}

void Sort::_bubbleSort(int* sorted) {
	int swap;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (sorted[j] > sorted[j + 1]) {
				swap = sorted[i];
				sorted[i] = sorted[j + 1];
				sorted[j + 1] = swap;
			}
		}
	}
}

int* Sort::bubbleSort() {
	int* sorted = clone();
	_bubbleSort(sorted);
	return sorted;
}

void Sort::_selectionSort(int* sorted) {
	int min, swap;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (sorted[j] < sorted[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap = sorted[min];
			sorted[min] = sorted[i];
			sorted[i] = swap;
		}
	}
}

int* Sort::selectionSort() {
	int* sorted = clone();
	_selectionSort(sorted);
	return sorted;
}

void Sort::_insertionSort(int* sorted) {
	int curr;
	int swap;
	for (int i = 1; i < size; i++) {
		swap = sorted[i];
		curr = i;
		while ((curr > 0) && (sorted[curr - 1] > swap)) {
			sorted[curr] = sorted[curr - 1];
			curr--;
		}
		sorted[curr] = swap;
	}
}

int* Sort::insertionSort() {
	int* sorted = clone();
	_insertionSort(sorted);
	return sorted;
}

void Sort::_quickSort(int* sorted, int left, int right) {
	int pivot;
	//if left < right find pivot with lamutoPartiton, recursivly sort array
	if (left < right) {
		pivot = lamutoPartition(sorted, left, right);
		_quickSort(sorted, left, pivot - 1);
		_quickSort(sorted, pivot + 1, right);
	}
}

int* Sort::quickSort() {
	int* sorted = clone();
	_quickSort(sorted, 0, size - 1);
	return sorted;
}

void Sort::choosePivot(int* sorted, int left, int right) {
	int mid = (left + right) / 2; //mid point of array
	int swap = sorted[left]; //swap variable holds first element of array
	sorted[left] = sorted[mid]; //first/left element now holds value from mid point
	sorted[mid] = swap; // midpoint now holds value from left/first
}

int Sort::lamutoPartition(int* sorted, int left, int right) {
	int swap;
	choosePivot(sorted, left, right);	//Avoid the worst case

	int pivot = sorted[left]; //pivot is the left most value of array
	int lastS1 = left; // lastS1 holds element value of left/first value

	for (int unk = left + 1; unk <= right; unk++) { //unk equals element to right of first element, while <= right increment unk
		if (pivot > sorted[unk]) { //if pivot > array at unk current index, increment lastS1 and perform swap on unk and lastS1
			lastS1++;
			swap = sorted[unk];
			sorted[unk] = sorted[lastS1];
			sorted[lastS1] = swap;
		}
	}
	//swap left most value and lastS1
	swap = sorted[left];
	sorted[left] = sorted[lastS1];
	sorted[lastS1] = swap;

	return lastS1;
}

void Sort::_mergeSort(int* sorted, int left, int right) {
	if (left < right) {
		// Midpoint in the partition
		int mid = left + (right - left) / 2;
		
		// Recursively sort left and right partitions
		_mergeSort(sorted, left, mid);
		_mergeSort(sorted, mid + 1, right);

		// Merge left and right partition in sorted order
		merge(sorted, left, mid, right);
	}
}

int* Sort::mergeSort() {
	int* sorted = clone();
	_mergeSort(sorted, 0, size - 1);
	return sorted;
}

void Sort::merge(int* sorted, int left, int mid, int right) {
	int mergedSize = right - left + 1;// Size of merged partition
	int mergeInsert = 0;// Position to insert merged number
	
	int L1 = left; // left/first index of array
	int R1 = right; // right/last index of array
	int leftPart = left;// Position of elements in left partition
	int rightPart = mid + 1;// Position of elements in right partition
	
	int* mergedNums = new int[mergedSize]; // Dynamically allocates temporary array for merged numbers

	// Add smallest element from left or right partition to the merged array
	while (leftPart <= mid && rightPart <= R1) { // loop while left partition index <= mid index and right element partition <= right index
		if (sorted[leftPart] < sorted[rightPart]) { // if left index partition element less than right index partition element
			mergedNums[mergeInsert] = sorted[leftPart]; // while true, temp array will merge number at index of left partition
			++leftPart; // increment through left partition
		}
		else {
			mergedNums[mergeInsert] = sorted[rightPart]; // while true temp array will merge number at current index of right partition
			++rightPart; // increment through right partition
		}
		++mergeInsert; // increment position for the next merged number
	}

	// If left partition is not empty, add the remaining elements to the merged array
	while (leftPart <= mid) { // loop while left partition position index less than equal that of mid index
		mergedNums[mergeInsert] = sorted[leftPart]; // temp array merges numbers from current index of left partition
		++leftPart; // increment through left partition
		++mergeInsert; //increment position for the next merged number
	}

	// If right partition is not empty, add remaining elements to merged array
	while (rightPart <= R1) { // loop while right partition position is less than or equal to that of right/end index
		mergedNums[mergeInsert] = sorted[rightPart]; // temp array merges numbers from current index of right partition
		++rightPart; // increment through right partition 
		++mergeInsert; // increment position for the next merged number
	}

	// Copy mergeNums (temp array) back to numbers
	for (mergeInsert = 0; mergeInsert < mergedSize; ++mergeInsert) { //while merged position(0) is less than size of merged partition, position++
		sorted[L1 + mergeInsert] = mergedNums[mergeInsert]; //temp array is copied to the original array
	}
	delete[] mergedNums; //dynamically created temp array is deleted from heap
}

void Sort::addData(int index, int data) {
	items[index] = data;
}

int Sort::getData(int index) {
	return items[index];
}

int Sort::getSize() {
	return size;
}