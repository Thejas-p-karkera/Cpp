#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
};

void print(node *head) 
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node *head = NULL; // Initialize head to NULL
    int n, value;

    cout << "Enter the number of nodes in the list: ";
    cin >> n;

    // Create the initial linked list
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        node *newN = new node();
        newN->data = value;
        newN->next = head; // Insert at the beginning
        head = newN;       
    }

    cout << "Original list: ";
    print(head);

    int choice;
    do {
        cout << "Choose where to insert new data:\n";
        cout << "1. Beginning\n";
        cout << "2. Middle\n";
        cout << "3. End\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Insert at the beginning
                int newData;
                cout << "Enter data to insert: ";
                cin >> newData;

                node *newN = new node();
                newN->data = newData;
                newN->next = head;
                head = newN;

                cout << "List after insertion: ";
                print(head);
                break;
            }
            case 2: { // Insert in the middle
                int position, newData;
                cout << "Enter position to insert new data: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> newData;

                if (position < 0) {
                    cout << "Invalid position" << endl;
                    break;
                }

                node *newN = new node();
                newN->data = newData;

                if (head == NULL || position == 0) {
                    newN->next = head;
                    head = newN;
                } else {
                    node *current = head;
                    for (int i = 0; i < position - 1; i++) {
                        if (current->next == NULL) {
                            cout << "Position exceeds list length, inserting at the end" << endl;
                            break;
                        }
                        current = current->next;
                    }
                    newN->next = current->next;
                    current->next = newN;
                }

                cout << "List after insertion: ";
                print(head);
                break;
            }
            case 3: { // Insert at the end
                int newData;
                cout << "Enter data to insert: ";
                cin >> newData;

                node *newN = new node();
                newN->data = newData;
                newN->next = NULL;

                if (head == NULL) {
                    head = newN; // If the list is empty, new node becomes the head
                } else {
                    node *current = head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newN; // Insert new node at the end
                }

                cout << "List after insertion: ";
                print(head);
                break;
            }
            case 4: // Exit
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}
