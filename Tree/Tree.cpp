#include<iostream>
using namespace std;

//This is the Structure of the tree node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

//This function creates a new node
Node* CreateNode(int value)
{
	Node* node = new Node;
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//This function adds the node to the tree
Node* InsertNode(Node* root,int value)
{
	if(root == NULL)
	{
		root = CreateNode(value);
		return root;
	}
	else if(value < root->data)
	{
		root->left = InsertNode(root,value);
	}
	else if(value > root->data)
	{
		root->right = InsertNode(root,value);
	}
	return root;
}


//This function prints the tree in inorder
void Inorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data<< " ";
	Inorder(root->right);
}

//This function prints the tree in PreOrder
void Preorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<< " ";
	Preorder(root->left);
	Preorder(root->right);
}

//This function prints the tree in Postorder
void Postorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<< " ";
}

//This function is used to find a node from the tree
Node* SearchNode(Node* root,int value)
{
	if(root == NULL)
	{
		return root;
	}
	else if( root->data == value)
	{
		return root;
	}
	else if( value < root->data)
	{
		root->left = SeacrhNode(root,value);
	}
	else if(value > root->data)
	{
		root->right = SeacrhNode(root,value);
	}
	return root;
}


//This function is used to change the value of a tree node 
Node* UpdateNode(Node* root,int oldvalue,int newvalue)
{
	if(root == NULL)
	{
		return root;
	}
	Node* temp = SearchNode(root,oldvalue);
	temp->data = newvalue;
	return temp;
}
