#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"enter no. of article: ";
    cin>>n;
    string article[n];
    cout<<"enter article words:";
    for(i=0;i<n;i++)
    {
        cin>>article[i];
    }
    int temp=article[0].length();
    string win;
    for(i=1;i<n;i++)
    {
        if(temp<article[i].length())
        {
            win=article[i];
        }
    }
    cout<<"winning word is: "<<win;
    return 0;
}
