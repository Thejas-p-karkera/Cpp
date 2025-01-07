#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) 
	{
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node* node) 
{
    if (node == NULL)
	{
		return 0;
	}

    return node->height;
}

int getBalance(Node* node) 
{
    if (node == NULL)
	{
		return 0;
	}

    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    y->left = x->right;

    x->right = y;
    //y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    x->right = y->left;

    y->left = x;
    //x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key)
{
    if (node == NULL)
		{
			return new Node(key);
		}
        

    if (key < node->data)
		{
			node->left = insert(node->left, key);
		}
        
    else if (key > node->data)
		{
			node->right = insert(node->right, key);
		}
        
    else
		{
			return node;
		}
        

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
		{
			return rightRotate(node);
		}
        

    if (balance < -1 && key > node->right->data)
	{
		return leftRotate(node);
	}
        

    if (balance > 1 && key > node->left->data)
	{
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data)
	{
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inOrderPrint(Node* root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    Node* root = NULL;

    int keys[] = {10, 30, 20, 50, 40, 25};

    for (int i = 0; i < 6 ; i++)
	{
		root = insert(root, keys[i]);
	}


    inOrderPrint(root);

    return 0;
}
