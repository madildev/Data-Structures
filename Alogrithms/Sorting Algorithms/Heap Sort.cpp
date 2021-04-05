#include<iostream>
using namespace std;

//This function swaps the value
void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//This function creates the heap
void heapify(int arr[], int size, int i)
{
	int largest = i;
	int Left = 2 * i + 1;  //Left Child
	int Right = 2 *i + 2;  //Right Child

	//This compares the left child
	if (Left < size && arr[Left] < arr[i])
	{
	  largest = Left;
	} 
	//This compares the right child
	if (Right < size && arr[Right] < arr[largest]) 
	{
		largest = Right;
	}
	
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) 
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int arr[] = {12, 10, 13, 7, 4, 6};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	heapSort(arr,arr_size);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}
