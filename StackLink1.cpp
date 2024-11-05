#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->val;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack s;
    s.push(2);
    s.display();
    s.push(1);
    s.display();
    s.push(3);
    s.display();
    cout << "Top element is " << s.peek() << endl;
    s.pop();
    s.display();
    cout << "Top element is " << s.peek() << endl;
    s.pop();
    s.display();
    cout << "Top element is " << s.peek() << endl;
    s.pop();
    s.display();
    cout << "Stack is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
