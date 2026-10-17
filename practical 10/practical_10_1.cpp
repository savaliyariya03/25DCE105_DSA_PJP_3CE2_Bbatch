#include <iostream>
using namespace std;
int main()
{
    int table[10];
    int n, reg;
    for(int i=0;i<10;i++)
    {
        table[i]=-1;
    }
    cout<<"Enter number of vehicles: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter registration number: ";
        cin>>reg;
        int slot=reg % 10;
        int count=0;
        while(table[slot]!=-1 && count<10)
        {
            slot=(slot+1)%10;
            count++;
        }
        if(count == 10)
            cout << "Parking is full. Vehicle not parked.\n";
        else
            table[slot] = reg;
    }
    cout<<"\nParking Slots:\n";
    for(int i=0;i<10;i++)
    {
        if(table[i] == -1)
            cout<<i<<" : Empty\n";
        else
            cout<<i<<" : "<<table[i]<<endl;
    }
    return 0;
}
