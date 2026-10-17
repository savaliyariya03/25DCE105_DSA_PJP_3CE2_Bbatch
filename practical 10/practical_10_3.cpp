#include <iostream>
using namespace std;
int main()
{
    int table[10];
    int n, id;
    for(int i=0;i<10;i++)
    {
        table[i] = -1;
    }
    cout<<"Enter number of students: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter student ID: ";
        cin>>id;
        int h1=id%10;
        int steps[4] = {1, 3, 7, 9};
        int h2 = steps[id%4];
        int count = 0;
        int slot;
        while(count < 10)
        {
            slot = (h1+count*h2)%10;
            if(table[slot] == -1)
                break;
            count++;
        }
        if(count == 10)
            cout<<"Hash table is full.\n";
        else
            table[slot] = id;
    }
    cout<<"\nHash Table:\n";
    for(int i=0;i<10;i++)
    {
        if(table[i] == -1)
            cout<<i<<" : Empty\n";
        else
            cout<<i<<" : "<<table[i]<<endl;
    }
    return 0;
}
