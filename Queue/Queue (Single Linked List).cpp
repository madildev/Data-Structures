#include<iostream>
using namespace std;

//This is the structure for the node of the linked list 
struct Node{
	int value;
	Node* link;
};


//This is the implementation of Queue using single linked list
class Queue
{
	Node* Front;
	Node* Rear;
	public:
		//Null Constructor
		Queue()
		{
			Front = NULL;
			Rear = NULL;
		}
		
		//This function adds a node at the rare of the queue
		void Enqueue()
		{
			Node* temp = new Node();
			cout<<"\nEnter the value you want to add ";
			cin>> temp->value ;
			temp->link = NULL;
			if(Front == NULL)
			{
				Front = temp;
				Rear = temp;
			}
			else
			{
				Rear->link = temp;
				Rear = temp;
			}
		}
		
		//This function removes the node from the front of the queue
		void Dequeue()
		{
			if(Front == NULL)
			{
				cout<<"\nThe Queue is Empty ";
			}
			else
			{
				Node* temp = Front;
				Front = Front->link;
				cout<<"The value "<< temp->value <<" is removed from the queue ";
		        delete temp;
		        temp = NULL;
			}
		}
		
		//This function displays the queue
		void Display()
		{
			Node* ptr = Front;
			cout<<"\nQueue: "
			while(ptr != NULL)
			{
				cout<<ptr->value << " ";
				ptr = ptr->link;
			}
			cout<<" NULL ";
		}
};

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
