#include<iostream>
using namespace std;


//This is the implementation of Queue using Circular Array 
class Queue
{
	int Q[10];
	int front;
	int rear;
	public:
		//Null Constructor
		Queue()
		{
			front = -1;
			rear = -1;
		}
		//This function adds the value to queue
		void Enqueue()
		{
			int value;
			cout<<"\nEnter the value you want to add ";
			cin>>value;
			if(front == -1 && rear == -1)
			{
				front++;
				rear = (rear+1)%10;
				Q[rear] = value;
			}
			else if((rear+1)%10 == front)
			{
				cout<<"\nThe Queue is Full ";
			}
			else if((rear+1)%10 > front)
			{
				rear = (rear+1)%10;
				Q[rear] = value;
			}
			else
			{
				front = -1;
				rear = -1;
			}
		}
		
		//This function removes the value from the queue
		void Dequeue()
		{
			if(front == -1)
			{
				cout<<"\nThe Queue is Empty ";
			}
			else
			{
				front = (front+1)%10;
			}
		}
		
		//This function displays the queue
		void Display()
		{
			cout<<"Circular Queue: ";
			for(int i= front; i<=rear;i++)
			{
				cout<<Q[i]<<" ";
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
