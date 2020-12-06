#include<iostream>
using namespace std;

//This is the structure of the node of the linked list
struct Node
{
	int value;
	Node* link;
};

//This is the implementation of th queue using circular linked list 
class Queue
{
    Node* front;
	Node* rear;
	public:
	
	//Null Constructor
	Queue()
	{
		front = NULL;
		rear = NULL;
	}	
	
	//This function add the value to  queue
	void Enqueue()
	{
		int value;
		Node* temp = new Node();
		cout<<"\nEnter the value you want to add ";
		cin>>temp->value;
		if(front == NULL)
		{
			front = temp;
			rear = temp;
			rear->link = front;
		}
		else
		{
			rear->link = temp;
			rear = temp;
			temp->link = front;
		}
	}
	
	//This function removes the value from the front of the queue
	void Dequeue()
	{
		if(front == NULL)
		{
			cout<<"\nThe Queue is Empty ";
		}
		else
		{
			Node* temp = front;
			cout<<"\nThe value "<<front->value <<" is removed from the queue ";
			front = front->link;
			delete temp;
			temp = NULL;
		}
	}
	
	//This function displays the circular queue using linked list 
	void Display()
	{
		cout<<"\nCircular Queue: ";
		Node* ptr = front;
		while(ptr->link != front)
		{
			cout<<ptr->value<<" ";
			ptr = ptr->link; 
		}
		cout<<ptr->value;
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
