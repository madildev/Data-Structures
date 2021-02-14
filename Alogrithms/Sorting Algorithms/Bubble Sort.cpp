#include<iostream>
using namespace std;

int* BubbleSort(int arr[],int l)
{
	int temp;
	for(int i = 0; i<l ;i++)
	{	
		for(int j= i+1; j<l ;j++)
		{
			if(arr[i] > arr[j])
			{
			   temp = arr[j];
		       arr[j] = arr[i];
		       arr[i] = temp; 
			}
		}
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
	
	int *p = BubbleSort(arr,l);
	cout<<"\nThe Array after sorting is: ";
	cout<<"[";
	for(int i=0;i<=l;i++)
	{
		cout<<*(p+i) <<" , ";
	}
	cout<<"]";
}
