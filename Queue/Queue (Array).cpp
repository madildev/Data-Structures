#include<iostream>
using namespace std;

//This is the implementation of the Queue using array 
class Queue
{
	int arr[10];
	int front;
	int rear;
	public:
		//Null Constructor
		Queue()
		{
			front = -1;
			rear = -1;
		}
		
		//This function add the value to the rear of the Queue
		void Enqueue()
		{
			int value;
			cout<<"\nEnter the value you want to add to the queue ";
			cin>>value;
			if(front == -1 && rear == -1)
			{
				front++;
				rear++;
				arr[rear] = value;
			}
			else if(rear == 10)
			{
		        cout<<"\n The Queue is full ";	        
			}
			else if(rear <= 10)
			{
				rear++;
				arr[rear] = value;
			}
			else
			{
				front = -1;
				rear = -1;
			}
		}
		
		//This function removes the value from the from the front of the Queue
		void Dequeue()
		{
			if(front == -1)
			{
				cout<<"\nThe Queue is empty ";
			}
			else
			{
				cout<<"The value "<< arr[front] <<" is removed from the queue ";
				front++;
			}
		}
		
		//This function displays the queue
		void Display()
		{
			cout<<"\nQueue: ";
			for(int i = this->front; i<=this->rear; i++)
			{
				cout<<arr[i] <<" ";
			}
		}
}; 

//This is the main function
int main()
{
	Queue Q ;
	int choice;
	do
	{
		cout<<"\n1. Enqueue ";
		cout<<"\n2. Dequeue ";
		cout<<"\n3. Display ";
		cout<<"\n4. Exit    ";
		cout<<"\nEnter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Q.Enqueue();
				break;
			case 2:
			    Q.Dequeue();
				break;
			case 3:
			    Q.Display();
			case 4:
			    break;			
		}
	}
	while(choice!= 4);
}
