#include<iostream>
using namespace std;
int main()
{
    int capacity;
    cout<<"enter capacity of queue: ";
    cin>>capacity;
    int Queue[100];
    int rear = -1;
    int front = -1;
    int count = 0;
    int operations;
    cout<<"enter no. of operations: ";
    cin>>operations;
    cout<<"eneter operations like join or serve: "<<endl;
    for(int i=0;i<operations;i++)
    {
        string operation;
        cin>>operation;
        if(operation == "join" || operation == "JOIN")
        {
            int token;
            cin>>token;
            if(count == capacity)
            {
                cout<<"Queue is overflow";
            }
            else
            {
                if(front == -1)
                {
                    front = 0;
                }
                rear++;
                Queue[rear] = token;
                count++;
                cout<<"Front token: "<<Queue[front]<<endl<<endl;
            }
        }
        else if(operation == "serve" || operation == "SERVE")
        {
            if(count == 0 || front == -1 || front > rear)
            {
                cout<<"Queue is underflow";
            }
            else
            {
                front++;
                count--;
                if(count == 0)
                {
                    front = -1;
                    rear = -1;
                }
                if(count > 0)
                {
                    cout<<"Front token: "<<Queue[front]<<endl<<endl;
                }
                else
                {
                    cout<<"Queue is empty"<<endl<<endl;
                }
            }
        }
        else
        {
            cout<<"not a valid operation"<<endl;
        }
    }
    return 0;
}
