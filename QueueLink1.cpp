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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(2);
    q.display();
    q.enqueue(1);
    q.display();
    q.enqueue(3);
    q.display();
    cout << "Front element is " << q.peek() << endl;
    q.dequeue();
    q.display();
    cout << "Front element is " << q.peek() << endl;
    q.dequeue();
    q.display();
    cout << "Front element is " << q.peek() << endl;
    q.dequeue();
    q.display();
    cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
