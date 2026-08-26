#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

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

    cout << "Enter your choice:\n";
    cout << "1. Insert patient at front\n";
    cout << "2. Insert patient at end\n";
    cout << "3. Insert patient at specific position\n";
    cout<<"4.exit\n";
    do{
    cout << "Enter: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
            cout << "Enter patient ID: ";
            cin >> NewNode->data;
            NewNode->next = head;
            head = NewNode;
            cout << "\nAfter inserting, Linked List = ";
            struct Node* travel = head;
            while (travel != nullptr)
            {
                cout << travel->data << " -> ";
                travel = travel->next;
            }
            cout << "NULL\n";
            break;
        }

        case 2: {
            struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
            cout << "Enter patient ID: ";
            cin >> NewNode->data;
            NewNode->next = nullptr;
            struct Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = NewNode;
            cout << "\nAfter inserting, Linked List = ";
            struct Node* travel = head;
            while (travel != nullptr)
            {
                cout << travel->data << " -> ";
                travel = travel->next;
            }
            cout << "NULL\n";
            break;
        }

        case 3:
        {
            int pos;
            struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
            cout << "Enter patient ID: ";
            cin >> NewNode->data;
            cout << "Enter position (1-based index): ";
            cin >> pos;
            if (pos == 1)
            {
                NewNode->next = head;
                head = NewNode;
            }
            if(pos < 0)
            {
                cout<<"invalide position\n";
            }
            else
            {
                struct Node* temp = head;
                for (int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }
                NewNode->next = temp->next;
                temp->next = NewNode;
            }
            cout << "\nAfter inserting, Linked List = ";
            struct Node* travel = head;
            while (travel != nullptr)
            {
                cout << travel->data << " -> ";
                travel = travel->next;
            }
            cout << "NULL\n";
            break;
        }
        case 4:
        {
            break;
        }
        default:
            cout << "Invalid choice!\n";
            return 0;
    }
    }while(choice != 4);
    return 0;
}
