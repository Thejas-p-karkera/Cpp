#include <iostream>
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

Node* insertBST(Node* root, int val)
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

void findMin(Node* root)
{
    if (root == NULL) 
    {
        cout << "\nThe subtree is empty.";
        return;
    }

    Node* curr = root;
    while (curr->left != NULL)
    {                               // Traverse to the leftmost node
        curr = curr->left;
    }
    cout << "\nThe minimum value in the BST is: " << curr->data;
}

void findMax(Node* root)
{
    if (root == NULL) 
    {
        cout << "\nThe subtree is empty.";
        return;
    }

    Node* curr = root;
    while (curr->right != NULL)
    {                                         // Traverse to the rightmost node
        curr = curr->right;
    }
    cout << "\nThe maximum value in the BST is: " << curr->data;
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

void main()
{
    Node* root = NULL;

    int n, ele;
    cout << "How many elements you want to store?: ";
    cin >> n;
    cout << "Enter " << n << " elements: " << endl;

    for (int i = 0; i < n; i++) 
    {
        cin >> ele;
        root = insertBST(root, ele);
    }

    cout << "\nInorder traversal of the BST: ";
    inorder(root);

    findMin(root);

    findMax(root);
}
