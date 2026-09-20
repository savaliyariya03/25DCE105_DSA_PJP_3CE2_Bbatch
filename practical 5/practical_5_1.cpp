#include <iostream>
using namespace std;
struct Node
{
    string song;
    Node* prev;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;
void addBeginning(string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
}
void addEnd(string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
}
void insertAfter(string currentSong, string newSong)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->song == currentSong)
        {
            Node* newNode = new Node;
            newNode->song = newSong;
            newNode->prev = temp;
            newNode->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = newNode;
            else
                tail = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}
void removeFirst()
{
    if (head == NULL)
        return;
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    delete temp;
}
int countSongs()
{
    int count = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void display()
{
    Node* temp = head;
    cout << "Playlist: ";
    while (temp != NULL)
    {
        cout << temp->song;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
    }
    cout << endl;
    cout << "Count: " << countSongs() << endl;
}
int main()
{
    addBeginning("SongA");
    display();
    addEnd("SongB");
    display();
    addEnd("SongC");
    display();
    insertAfter("SongB", "SongD");
    display();
    removeFirst();
    display();
    return 0;
}
