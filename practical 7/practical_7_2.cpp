#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node *front=NULL, *rear=NULL;
int main()
{
    int operations;
    cout<<"enter no. of operations: ";
    cin>>operations;
    for(int i=0;i<operations;i++)
    {
        string operation;
        cin>>operation;
        if(operation == "arrive" || operation == "ARRIVE")
        {
            int token;
            cin>>token;
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = token;
            newNode->next = NULL;
            if(rear == NULL)
            {
                front = rear = newNode;
            }
            rear->next = newNode;
            rear = newNode;
            cout<<"Front patient: "<<front->data<<endl<<endl;
        }
        else if(operation == "attend" || operation == "ATTEND")
        {
            if(front == NULL)
            {
                cout<<"Queue is underflow"<<endl<<endl;
            }
            struct Node* temp = front;
            int item = temp->data;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            free(temp);
            cout<<"Front patient: "<<front->data<<endl<<endl;
        }
        else
        {
            cout<<"Not a valid operation"<<endl;
        }
    }
    return 0;
}
