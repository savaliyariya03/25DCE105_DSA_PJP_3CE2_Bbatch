#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"enter no. of items: ";
    cin>>n;
    string bakery[n];
    cout<<"enter item names: ";
    for(i=0;i<n;i++)
    {
        cin>>bakery[i];
    }
    int hour;
    cout<<"enter numbers of hour:";
    cin>>hour;
    string temp=bakery[0];
    for(int j=1;j<=hour;j++)
    {
        string temp=bakery[0];
        for(i=0;i<n-1;i++)
        {
            bakery[i]=bakery[i+1];
        }
        bakery[n-1]=temp;
    }
    cout<<"after "<<hour<<" hours display"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<bakery[i]<<" ";
    }
    cout<<endl<<"total no. of hours: "<<hour;
    return 0;
}
