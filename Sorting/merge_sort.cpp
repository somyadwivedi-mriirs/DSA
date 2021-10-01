// Merge Sort

/*
Best Time complexity: Ω(nlog(n))
Average Time Complexity: θ(nlog(n))
Worst Time complexity: O(nlog(n))
Auxiliary Space: O(n)
Stability: stable
Sorting In Place: No
Algorithmic Paradigm: Divide and Conquer
Important Point: 
- Useful for storting linked lists
- Used in external sorting (algorithms that can handle massive amounts of data)
(External sorting is required when the data being sorted 
do not fit into the main memory of a computing device (usually RAM) 
and instead they must reside in the slower external memory, usually a hard disk drive)

Drawbacks:
- Slower comparative to the other sort algorithms for smaller tasks.
- Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
- It goes through the whole process even if the array is sorted.
*/


#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int array[], int left, int mid, int right)
{
	// sz1 and sz2 are number of elements in 1st and 2nd subarray resp.
    int sz1 = mid - left + 1, sz2 = right - mid;
  
    // Create temp arrays
    int arr[sz1], brr[sz2];
  
    // Copy data to temp arrays arr[] and brr[]
    for (int i = 0; i < sz1; i++)
        arr[i] = array[left + i];
    for (int j = 0; j < sz2; j++)
        brr[j] = array[mid + 1 + j];
  
  	// i: index of 1st subarray, j of 2nd subarray, index of merged subarray
    int i = 0, j = 0, index = left;
  
    // Merge the temp arrays back into array[left..right]
    while (i < sz1 && j < sz2) {
        if (arr[i] <= brr[j]) {
            array[index] = arr[i];
            i++;
        }
        else {
            array[index] = brr[j];
            j++;
        }
        index++;
    }
    // Copy the remaining elements of left[], if there are any
    while (i < sz1) {
        array[index] = arr[i];
        i++;
        index++;
    }
    // Copy the remaining elements of right[], if there are any
    while (j < sz2) {
        array[index] = brr[j];
        j++;
        index++;
    }
}
  
// begin is for left index and end is right index of the sub-array of arr to be sorted 
void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
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
	mergeSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}
