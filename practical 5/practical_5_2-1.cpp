#include <iostream>
using namespace std;
struct Node
{
    string name;
    Node* next;
};
Node* head = NULL;
void insert(string name)
{
    Node* newNode = new Node;
    newNode->name = name;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void remove(string name)
{
    if (head == NULL)
        return;
    Node* temp = head;
    Node* prev = NULL;
    do
    {
        if (temp->name == name)
        {
            if (temp == head)
            {
                if (head->next == head)
                {
                    delete head;
                    head = NULL;
                    return;
                }

                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                delete temp;
                return;
            }
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}
void display()
{
    if (head == NULL)
    {
        cout << "Circle is empty" << endl;
        return;
    }
    Node* temp = head;
    do
    {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}
int main()
{
    insert("A");
    display();
    insert("B");
    display();
    insert("C");
    display();
    remove("B");
    display();
    insert("D");
    display();
    return 0;
}
