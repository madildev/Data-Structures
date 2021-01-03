#include<iostream>
using namespace std;

int BinarySearch(int arr[],int search,int start, int end)
{
    while(start<=end)
    {
    	int mid = (start+end)/2;
    	if(arr[mid] == search)
    	{
    		return mid;
		}
		else if(arr[mid] < search)
		{
			start = mid+1;
		}
		else if(arr[mid] > search)
		{
			end = mid-1;
		}
		else
		{
			return -1;
		}
	}
    
}

int main()
{
	int arr[10];
	int search;
	int start=0;
	int end = sizeof(arr)/sizeof(arr[0])-1;
	cout<<"\nEnter the values into array: ";
	for(int i=0;i<=end;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nEnter the number you want to search ";
	cin>>search;
	int value = BinarySearch(arr,search,start,end);
	if(value>0)
	{
		 cout<<"\nThe value is present at "<<value;
	}
	else
	{
		cout<<"\nThe Given was not found!!! ";
	}
	
}
