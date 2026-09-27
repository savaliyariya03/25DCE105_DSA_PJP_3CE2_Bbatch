#include<iostream>
using namespace std;
struct Node
{
    string page;
    Node* next;
};
Node* top=NULL;
void visit(string page)
{
    Node* newNode=new Node;
    newNode->page=page;
    newNode->next=top;
    top=newNode;
    cout<<"You visited: "<<page<<endl;
    cout<<"Current Page: "<<top->page<<endl;
}
void back()
{
    if(top==NULL)
    {
        cout<<"Error: No history"<<endl;
        return;
    }
    cout<<"You backed from: "<<top->page<<endl;
    Node* temp=top;
    top=top->next;
    delete temp;
    if(top==NULL)
        cout<<"Current Page: None"<<endl;
    else
        cout<<"Current Page: "<<top->page<<endl;
}
int main()
{
    visit("Google");
    visit("YouTube");
    visit("Wikipedia");
    back();
    back();
    back();
    back();
    return 0;
}
