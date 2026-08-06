#include<iostream>
using namespace std;
int main()
{
    int a[5]={8, 5, 1, 3, 7};
    cout<<"---befor sorting---"<<endl;
    cout<<"array a = ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int j=0;j<5;j++)
    {
        for(int i=0;i<5;i++)
        {
            int temp = a[i];
            if(a[i] > a[i+1])
            {
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    cout<<endl<<"---after sorting---"<<endl;
    cout<<"array a = ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
