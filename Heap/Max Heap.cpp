#include<iostream>
using namespace std;

//This function swap the values
void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//This function creates the max-heap
void heapify(int arr[],int size,int i)
{
	int largest = i;
	int left = 2 * i + 1; //The left child
	int right = 2 * i + 2;  //The right child
	
	//This checks the left child
	if(left < size && arr[left] < arr[i])
	{
		largest = left;
	}
	
	//This checks the right child
	if(right < size && arr[right] < arr[i])
	{
		largest = right;
	}
	
	if(largest != i)
	{
		swap(arr[largest],arr[i]);
		heapify(arr,size,largest);
	}
}

//This function arranges the array into heap
void maxHeap(int arr[],int size)
{
	for(int i = size-1; i>0;i--)
	{
		heapify(arr,size,i);
	}
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

//This function deletes node from the heap
void DeleteNode(int arr[],int &size)
{
	swap(arr[0],arr[size-1]);
	size--;
	heapify(arr,size,0);
}

int main()
{
	int arr[] = { 1, 5, 6, 8, 9, 7, 3};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	maxHeap(arr,arr_size);

	cout << "\nThe Max Heap formed is \n";
	printArray(arr, arr_size);
	DeleteNode(arr,arr_size);
	cout << "\nThe Heap formed after deletion is \n";
	printArray(arr, arr_size);
	return 0;
}
