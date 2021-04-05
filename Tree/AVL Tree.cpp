#include <iostream>
using namespace std;

class Node 
{
   public:
  int data;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int data) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(data));
  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (data < node->left->data) {
      return rightRotate(node);
    } else if (data > node->left->data) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (data > node->right->data) {
      return leftRotate(node);
    } else if (data < node->right->data) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int data) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else 
  {
    if ((root->left == NULL) ||
      (root->right == NULL)) 
	{
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) 
	  {
        temp = root;
        root = NULL;
      } 
	  else
        *root = *temp;
         delete temp;
    } 
	else 
	{
      Node *temp = nodeWithMimumValue(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right,
                   temp->data);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(Node *root) {
  if (root == NULL) 
  {
  	 return;
  }
  else
  {
    printTree(root->left);
    cout << root->data <<" ";
    printTree(root->right);
  }
}

int main() 
{
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  cout<<"The Tree is: \n";
  printTree(root);
  root = deleteNode(root, 13);
  cout <<"\nAfter deleting " << endl;
  printTree(root);
}
