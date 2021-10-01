// Bubble Sort

/*
Best Time complexity: Ω(n)
Average Time Complexity: θ(n^2)
Worst Time complexity: O(n^2)
Auxiliary Space: O(1)
Stability: stable
Sorting In Place: Yes
Important Point: Useful if array is almost sorted
*/


#include <iostream>
using namespace std;

void swap (int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bubbleSort(int arr[], int n) 
{ 
    for (int i=0;i<n-1;++i) {
    	// Last i elements are already in place 
    	for(int j=0;j<n-i-1;++j) {
    		if(arr[j] > arr[j+1]) {
    			swap(&arr[j], &arr[j+1]);
    		}
    	}
    }  
} 

// An optimized version of Bubble Sort
void optimizedBubbleSort(int arr[], int n)
{
   bool swapped;
   for (int i = 0; i < n-1; i++)
   {
     swapped = false;
     for (int j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
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
	optimizedBubbleSort(arr, n);
	printArray(arr, n);
	return 0;
}
