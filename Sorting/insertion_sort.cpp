// Insertion Sort

/*
Best Time complexity: Ω(n)
Average Time Complexity: θ(n^2)
Worst Time complexity: O(n^2)
Auxiliary Space: O(1)
Stability: stable
Sorting In Place: Yes
Online Algorithm: Yes 
(Online algorithm is one that can process its input piece-by-piece in a serial fashion, 
i.e., in the order that the input is fed to the algorithm, 
without having the entire input available from the start)
Important Point: Useful if array is almost sorted or number of elements are small
*/


#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
	for(int i=0;i<size;++i) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main() {
	int arr[] = {432,41,23,8,186,789,26};
	int n= sizeof(arr)/sizeof(int);
	printArray(arr, n);
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}
