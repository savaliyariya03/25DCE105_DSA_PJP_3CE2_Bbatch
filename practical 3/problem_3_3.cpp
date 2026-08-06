#include <iostream>
using namespace std;
int main() {
    int a[] = {8, 5, 1, 3, 7};
    cout<<"---befor sorting---"<<endl;
    cout<<"array a = ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=1;i<5;i++)
    {
        int temp=a[i];
        int j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    cout<<"\n---after sorting---\n";
    cout<<"array a = ";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
