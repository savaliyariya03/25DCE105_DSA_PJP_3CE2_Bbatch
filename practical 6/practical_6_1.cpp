#include<iostream>
using namespace std;
class Stack
{
    int arr[100];
    int top;
    int size;
public:
    Stack(int n)
    {
        size=n;
        top=-1;
    }
void place(int tray)
{
    if(top==size-1)
    {
        cout<<"Error: Stack is full"<<endl;
        return;
    }
    top++;
    arr[top]=tray;
    cout<<"insert: "<<arr[top]<<endl;
    cout<<"Top: "<<arr[top]<<endl;
}
void take()
{
    if(top==-1)
    {
    cout<<"Error: Stack is empty"<<endl;
    return;
    }
    cout<<"Taken: "<<arr[top]<<endl;
    top--;
    if(top==-1)
        cout<<"Top: Empty"<<endl;
    else
        cout<<"Top: "<<arr[top]<<endl;
}
};
int main()
{
    int n;
    cout<<"Enter capacity: ";
    cin>>n;
    Stack s(n);
    s.place(10);
    s.place(20);
    s.place(30);
    s.take();
    s.take();
    s.take();
    s.take();
    return 0;
}
