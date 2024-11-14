#include <iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

        Node(int data)
        {
            val = data;
            next = NULL;
        }
};

class Stack 
{
    private:
        Node* top;

    public:
        Stack()
        {
            top = NULL;
        }

    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top element is " << top->val << endl;
        }
    }

    void isEmpty()
    {
        if (top == NULL) 
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }

    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;

        while (temp != NULL)
        {
            cout << "<-" << temp->val ;
            temp = temp->next;
        }
        //cout << "NULL" << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.isEmpty();
            break;

        case 5:
            s.display();
            break;

        case 6:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
