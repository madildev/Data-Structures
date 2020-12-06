#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
class Stack{
		node* top;
	public:
		Stack()
		{
			top=NULL;
		}
		void push(int value)
		{
			node* temp=new node;
		    temp->data=value;
		    temp->prev=top;
		    temp->next=NULL;
		    top=temp;
		}
		void pop()
	    {
	    	node* temp=top;
	    	if(top==NULL)
	    	{
	    		cout<<"\nStack Underflow\n";
			}
			else
			{
				cout<<"\nPop Element: "<<top->data<<endl;
	    	    top=top->prev;
	    	    delete temp;
	        }
		}
		void display()
		{
			if(top==NULL)
			{
				cout<<"\nEmpty Stack\n";
			}
			else
			{
				node* temp=top;
			    cout<<"\nStack:\t";
			    while(temp!=NULL)
			    {
				    cout<<temp->data<<"\t";
				    temp=temp->prev;
			    }
			    cout<<endl;
		    }
		}
};
int main()
{
	Stack list;
	int choice,value;
	do{
	    cout<<"\nPress 0: Push";
	    cout<<"\nPress 1: Pop";
	    cout<<"\nPress 2: Display";
	    cout<<"\nPress 3: Exit";
	    cout<<"\nEnter Choice: ";
	    cin>>choice;
	    switch(choice)
	    {
		    case 0:
			    cout<<"\nEnter Value: ";
			    cin>>value;
			    list.push(value);
			    break;
		    case 1:
			    list.pop();
			    break;
		    case 2:
			    list.display();
			    break;
		    case 3:
			    cout<<"\nThank You\n";
			    break;
		    default:
			    cout<<"\nInvalid Input\n";
	    }
	}while(choice!=3);
}
