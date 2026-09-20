#include <iostream>
using namespace std;
struct Node
{
    string name;
    Node* next;
    Node* prev;
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
        newNode->prev = head;
        return;
    }
    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}
void remove(string name)
{
    if (head == NULL)
        return;
    Node* temp = head;
    do
    {
        if (temp->name == name)
        {
            if (temp->next == temp)
            {
                delete temp;
                head = NULL;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            delete temp;
            return;
        }
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
        cout << temp->name << " <-> ";
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
