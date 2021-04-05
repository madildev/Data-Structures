#include<iostream>
using namespace std;

void quickSort(int list[],int first,int last)
{
    int pivot,i,j,temp;

    if(first < last)
	{
        pivot = first;
        i = first;
        j = last;

        while(i < j)
		{
            while(list[i] <= list[pivot] && i < last)
                i++;
            while(list[j] > list[pivot])
                j--;
            if(i<j)
			{
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        quickSort(list,first,j-1);
        quickSort(list,j+1,last);
    }
}


int main()
{
  int arr[5]={2,9,6,3,1};
  int size=5,i;
  
  printf("List before sorting is: \n");
  for(i = 0; i < size; i++)
  {
  	cout<<arr[i]<<" ";
  }
  
  quickSort(list,0,size-1); 

  printf("\nList after sorting is: \n");
  for(i = 0; i < size; i++)
  {
  	cout<<arr[i]<<" ";
  }

}


