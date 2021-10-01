// Selection Sort

/*
Best Time complexity: Ω(n^2)
Average Time Complexity: θ(n^2)
Worst Time complexity: O(n^2)
Auxiliary Space: O(1)
Stability: unstable (by default unstable but modified stable selection sort exist)
Sorting In Place: Yes
Important Point: Never make more than O(n) swaps. 
						  Useful when memory write is a costly operation. 
*/


#include <iostream>
#include <cstdlib> // For rand function
#include <time.h> // For seeding rand function
using namespace std;

void swap (int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

void selectionSort(int arr[], int n) {
	// [0, ..., i-1] (sorted sub-array)
	// [i, ..., min_idx, ..., n-1] (unsorted sub-array)
	// Remember i goes from 0 to N-2
	for(int i=0;i<n-1;++i) {
		int min_idx = i;
		for(int j=i+1;j<n;++j) {
			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]); // or use swap(arr, min_idx, i);
	}
}

void printArray(int arr[], int size) {
	for(int i=0;i<size;++i) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main() {
	srand(time(0)); // It ensure every time new random values are generated
	const int MAX = 1000; // Maximum range of array element's value
	int n; // Size of array
	cin >> n;
	int arr[n];
	for(int i=0;i<n;++i) {
		arr[i] = rand()%MAX;
	}
	// int arr[] = {432,41,23,8,186,789,26};
	// int n= sizeof(arr)/sizeof(int);
	printArray(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
}
