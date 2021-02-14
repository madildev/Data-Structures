#include<iostream>
using namespace std;

int* SelectionSort(int arr[],int l)
{
	int temp;
	int min;
	for(int i=0;i<l;i++)
	{
		min = i;
		for(int j= i+1;j<l;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp; 
	}
	return arr;
}

int main()
{
	int arr[5];
	int l = sizeof(arr)/sizeof(arr[0])-1;
	cout<<"\nEnter the values into the array: ";
	for(int i=0;i<=l;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nThe Array before sorting is: ";
	cout<<"[";
	for(int i=0;i<=l;i++)
	{
		cout<<arr[i]<<" , ";
	}
	cout<<"]";
	
	int *p = SelectionSort(arr,l);
	cout<<"\nThe Array after sorting is: ";
	cout<<"[";
	for(int i=0;i<=l;i++)
	{
		cout<<*(p+i) <<" , ";
	}
	cout<<"]";
}
