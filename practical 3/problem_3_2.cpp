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
    int small_indax;
    int temp;
    for(int i=0;i<4;i++)
    {
        small_indax = i;
        for(int j=i+1;j<5;j++)
        {
            if(a[j] < a[small_indax])
            {
                small_indax =j;
            }
        }
        temp = a[i];
        a[i] = a[small_indax];
        a[small_indax] = temp;
    }

    cout<<endl<<"---after sorting---"<<endl;
    cout<<"array a = ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
