// C++ program to merge two sorted arrays

#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	while (i<n1 && j <n2)
	{
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		}			
		else {
			arr3[k++] = arr2[j++];
		}			
	}

	while (i < n1) {
		arr3[k++] = arr1[i++];
	}

	while (j < n2) {
		arr3[k++] = arr2[j++];
	}
}

void printArray(int arr[], int size) {
	for(int i=0;i<size;++i) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	int arr1[] = {2,5,8,13};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	cout<<"Array 1 is\n";
	printArray(arr1, n1);

	int arr2[] = {1,4,9,10,15};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	cout<<"Array 2 is\n";
	printArray(arr2, n2);

	int arr3[n1+n2];
	mergeArrays(arr1, n1, arr2, n2, arr3);

	cout << "Merged array is\n";
	printArray(arr3, n1+n2);

	return 0;
}
