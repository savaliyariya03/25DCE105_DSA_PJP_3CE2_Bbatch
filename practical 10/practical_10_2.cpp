#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> shelf[10];
    int n, code;
    cout<<"Enter number of books: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter book code: ";
        cin>>code;
        int slot=code%10;
        shelf[slot].push_back(code);
    }
    cout<<"\nLibrary Shelves:\n";
    for(int i=0;i<10;i++)
    {
        cout<<i<<" : ";
        if(shelf[i].empty())
        {
            cout<<"Empty";
        }
        for(int j=0;j<shelf[i].size();j++)
        {
            cout<<shelf[i][j]<<" -> ";
        }
        cout<<endl;
    }
    return 0;
}
