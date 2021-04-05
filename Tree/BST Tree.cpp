#include<iostream>
#include<queue>
using namespace std;

//This is the Structure of the tree node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

//This function creates a new node
Node* NewNode(int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//This function adds the node to the tree
Node* InsertNode(Node* root,int value)
{
	if(root == NULL)
	{
		return (NewNode(value));
	}
	else if(value <= root->data)
	{
		root->left = InsertNode(root->left,value);
	}
	else if(value > root->data)
	{
		root->right = InsertNode(root->right,value);
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
	cout<<root->data<<" ";
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

//This function prints the tree in the level order
void LevelOrder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		queue<Node*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			Node* current = Q.front();			
			cout<<current->data<<" "; 
			if(current->left != NULL)
			{
				Q.push(current->left);
		    }
		    if(current->right != NULL)
		    {
		    	Q.push(current->right);
			}
			Q.pop();
		}
	}
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
		root->left = SearchNode(root->left,value);
	}
	else if(value > root->data)
	{
		root->right = SearchNode(root->right,value);
	}
	return root;
}

//This function is used to change the value of a tree node 
void UpdateNode(Node* root,int oldvalue,int newvalue)
{
	if(root == NULL)
	{
		return;
	}
	Node* temp = SearchNode(root,oldvalue);
	temp->data = newvalue;
}

// This function finds the height of the tree
int FindHeight(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	int leftHeight = FindHeight(root->left);
	int rightHeight = FindHeight(root->right);
	return (max(leftHeight,rightHeight) + 1);
}

//This function find maximum value from the tree
int MaxmimunValue(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		Node* current = root->right;
		while(current != NULL)
		{
			current = current->right;
		}
		return current->data;
	}
}

//This function finds the minimum value from the tree
int MinimumValue(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		Node* current = root->left;
		while(current != NULL)
		{
			current = current->left;
		}
		return current->data;
	}
}

//This function deletes a node from the tree
Node* DeleteNode(Node* root,int value)
{
	if(root == NULL)
	{
		return root;
	}
	else if(value < root->data)
	{
		root->left = DeleteNode(root->left,value);
	}
	else if( value > root->data)
	{
		root->right = DeleteNode(root->right,value);
	}
	else
	{
	   //if the root has no child
	   if(root->left == NULL && root->right == NULL)
	   {
		  delete root;
		  root = NULL;
		  return root;
	   }
	   //if the root has one child
	   else if(root->left == NULL && root->right != NULL)
	   {
	     Node* temp = root;
		 root = root->right;
		 delete temp;
		 temp = NULL;	
		 return root;
	   }
	   //if the root has one child
	   else if(root->left != NULL && root->right == NULL)
	   {
	   	 Node* temp = root;
		 root = root->left;
		 delete temp;
		 temp = NULL;
		 return root;
	   }
	   //if the root has two childern
	   else
	   {
	   	 int min = MinimumValue(root->right);
	   	 root->data = min;
	   	 root->right = DeleteNode(root->right,min);
	   }
	}
	return root;
}

//This function if the subtree is lesser or not
bool isSubTreeLesser(Node* root,int value)
{
	if(root == NULL)
	{
		return true;
	}
	if(root->data <= value && 
	isSubTreeLesser(root->left,value) &&
	isSubTreeLesser(root->right,value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function if the subtree is greater or not
bool isSubTreeGreater(Node* root,int value)
{
	if(root == NULL)
	{
		return true;
	}
	if(root->data > value && 
	isSubTreeGreater(root->left,value) &&
	isSubTreeGreater(root->right,value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function checks whether tree is BST or Not
bool IsBST(Node* root)
{
	if(root == NULL)
	{
		return true;
	}
	if(isSubTreeLesser(root->left,root->data) &&
	  isSubTreeGreater(root->right,root->data) &&
	  IsBST(root->left) &&
	  IsBST(root->right))
	  return true;
	else
	  return false;
}
//This is the main function 
int main()
{
	Node* root = NULL;
	root = InsertNode(root,22);
	root = InsertNode(root,10);
	root = InsertNode(root,23);
	root = InsertNode(root,19);
	root = InsertNode(root,18);
	root = InsertNode(root,20);
	root = InsertNode(root,21);
	cout<<"The Tree is \n ";
	Inorder(root);
	int height = FindHeight(root);
	cout<<"\nThe Height of the tree is: "<<height;
	root = DeleteNode(root,10);
	cout<<"\nThe Tree after deletion is: \n";
	Inorder(root);
	cout<<"\nLevel Order Transversal is: \n";
	LevelOrder(root);
	bool valid = IsBST(root);
	if(valid)
	{
		cout<<"\nThe Given Tree is a Binary Search Tree \n";
	}
	else
	{
		cout<<"\nThe Given Tree is not a Binary Search Tree \n";
	}		
}

	
