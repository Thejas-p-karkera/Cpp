#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node* insertBST(Node* root,  int val)
{
	if (root == NULL)
	{
		return new Node(val);
	}

	if (val < root->data)
	{
		root->left = insertBST(root->left, val);
	}
	else
	{
		root->right = insertBST(root->right, val);
	}
	return root;
}

void search(Node* root,int key)
{
	if (root == NULL)
	{
		cout << "\nThe search element is not found.";
		return;
	}

	if (key < root->data)
	{
		return search(root->left, key);
	}
	else if (key > root->data)
	{
		return search(root->right, key);
	}
	else
	{
		cout << "\nThe search element found in thee tree.";
		return;
	}	
}

Node* inorderSucc(Node* root)
{
	Node* curr = root;
	while (curr && curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

Node* deleteBST(Node* root, int key)
{
	if (root == NULL)
	{
		cout << "\nThe element is not found to delete.";
		return NULL;
	}

	if (key < root->data)
	{
		root->left = deleteBST(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = deleteBST(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete(root);
			return temp;
		}
		else
		{
			Node* temp = inorderSucc(root->right);
			root->data = temp->data;
			root->right = deleteBST(root->right, temp->data);
		}
	}
	return root;
}

void inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{
	Node* root = NULL;

	int n,ele;
	cout << "How many elements you want to store?: ";
	cin >> n;
	cout << "Enter " << n << " elements: " << endl;

	for (int i = 0; i < n;i++)
	{
		cin >> ele;
		root = insertBST(root, ele);
	}

	cout << "The elements in the BST: ";
	inorder(root);

	cout << "\nEnter the search element: ";
	cin >> ele;
	search(root, ele);

	cout << "\nEnter the element you want to delete: ";
	cin >> ele;
	deleteBST(root, ele);
	cout << "The elements in the BST after deleting: ";
	inorder(root);

	
}
