#include<iostream>
using namespace std;
struct node{
	int data;
	node* prev;
	node* next;
};
class LinkedList{
	    node* head;
	public:
		LinkedList()
		{
			head=NULL;
		}
		node* get_head()
		{
			return head;
		}
		void Add_At_End(int value)
		{
			node* tail,
			*temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				temp->prev=NULL;
				head=temp;
			}
			else
			{
				tail = head;
				while(tail->next!=NULL)
				{
					tail = tail->next;
				}
				tail->next=temp;
				temp->prev=tail;
			}
			cout<<"\nNode Added Successfully\n";
		}
		void Add_At_Any(int value,int pos)
		{
			node* temp1 = head;
			node* temp2 = new node;
			for(int i=0;i<pos-1;i++)
		    {
				temp1=temp1->next;
			}
			if(pos==0)
			{
				cout<<"\nAdd Node At Start First\n";
			}
			else
			{
				temp2->data = value;
		    	temp2->next = temp1->next;
			    temp1->next->prev=temp2;
		    	temp1->next=temp2;
			    temp2->prev=temp1;
			    cout<<"\nNode Added Successfully After Given Position\n";
			}
			
		}
		void Add_At_Start(int value)
		{
			node* temp=new node;
			temp->data=value;
			temp->prev=NULL;
			temp->next=head;
			head->prev=temp;
			head=temp;
			cout<<"\nNode Added Successfully At Start\n";
		}
		void Delete(int pos)
		{
			node* temp=head;
			for(int i=0;i<pos-1;i++)
		    {
				temp=temp->next;
			}
			if(temp == head)
			{
				head=head->next;
				head->prev=NULL;
				delete temp;
				cout<<"\nFirst Node Deleted Successfully\n";
			}
			else if(temp->next==NULL)
			{
				temp->prev->next=NULL;
				delete temp;
				cout<<"\nLast Node Deleted Successfully\n";
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
				cout<<"\nNode Deleted Successfully\n";
			}
		}
		void display()
		{
			node* temp=head;
            cout<<"NULL <--> ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" <--> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
		}
};
int main()
{
	int choice,value,position;
	LinkedList list,list2;
	do{
	    cout<<"Press 0: Add Node At End\n";
	    cout<<"Press 1: Add Node At Start\n";
	    cout<<"Press 2: Add Node At Any Location\n";
	    cout<<"Press 3: Delete Node\n";
	    cout<<"Press 4: Display Linked List\n";
	    cout<<"Press 5: Exit\n";
	    cout<<"\nEnter Choice: ";
	    cin>>choice;
	    switch(choice)
	    {
		    case 0:
			    cout<<"\nEnter Value: ";
			    cin>>value;
			    list.Add_At_End(value);
			    break;
			case 1:
				cout<<"Enter Value: ";
		    	cin>>value;
				list.Add_At_Start(value);
				break;
		    case 2:
		    	cout<<"Enter Value: ";
		    	cin>>value;
		    	cout<<"Enter Position: ";
		    	cin>>position;
		    	list.Add_At_Any(value,position);
			    break;
		    case 3:
		    	cout<<"Enter Position: ";
		    	cin>>position;
				list.Delete(position);
			    break;
				
		    case 4:
		    	list.display();
		    	cout<<endl;
			    break;			
		    case 5:
		    	cout<<"\nThank You";
			    break;
			default:
				cout<<"\nInvalid Input\n";
	   }
	   cout<<endl;
	}while(choice!=5);	
}

