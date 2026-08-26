#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printReverse(struct Node* head) {
    if (head == nullptr) {
        return;
    }
    printReverse(head->next);
    cout << head->data << " -> ";
}

int main() {
    int choice;
    struct Node* Node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* Node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* Node3 = (struct Node*)malloc(sizeof(struct Node));

    Node1->data = 101;
    Node1->next = Node2;

    Node2->data = 102;
    Node2->next = Node3;

    Node3->data = 103;
    Node3->next = nullptr;

    struct Node* head = Node1;

    cout << "1. Delete patient by Token ID\n";
    cout << "2. Forward Traversal (Front to Back)\n";
    cout << "3. Reverse Traversal (Last to First)\n";
    cout << "4. Exit\n";

    do {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                cout << "Enter patient ID to delete: ";
                cin >> key;

                if (head == nullptr) {
                    cout << "Queue is empty!\n";
                    break;
                }

                if (head->data == key) {
                    struct Node* toDelete = head;
                    head = head->next;
                    free(toDelete);
                    cout << "Patient " << key << " deleted.\n";
                } else {
                    struct Node* temp = head;
                    while (temp->next != nullptr && temp->next->data != key) {
                        temp = temp->next;
                    }

                    if (temp->next == nullptr) {
                        cout << "Patient ID not found!\n";
                    } else {
                        struct Node* toDelete = temp->next;
                        temp->next = temp->next->next;
                        free(toDelete);
                        cout << "Patient " << key << " deleted.\n";
                    }
                }
                break;
            }

            case 2: {
                cout << "Queue (Front to Back): ";
                struct Node* travel = head;
                while (travel != nullptr) {
                    cout << travel->data << " -> ";
                    travel = travel->next;
                }
                cout << "NULL\n";
                break;
            }

            case 3: {
                cout << "Queue (Last to First): ";
                printReverse(head);
                cout << "NULL\n";
                break;
            }

            case 4:
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
