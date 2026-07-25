#include<iostream>
using namespace std;
int binarySearchRecursive(int a[], int start, int end1, int target) {
    if (start > end1) 
    {
        return -1;
    }
    int mid = start + (end1 - start) / 2;
    if (a[mid] == target) 
    {
        return mid;
    }
    if (a[mid] < target) 
    {
        return binarySearchRecursive(a, mid + 1, end1, target);
    }
    return binarySearchRecursive(a, start, mid - 1, target);
}
int main()
{
    int a[10]={101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int start=0;
    int end1=9;
    int target=102;
    cout<<"using binary search"<<endl;
    while(start <= end1)
    {
        int mid = (start+end1)/2;
        if(a[mid] == target)
        {
            cout<<"found at: "<<mid+1;
            break;
        }
        else if(a[mid] <= target)
        {
            start=mid+1;
        }
        else
        {
            end1=mid-1;
        }
    }
    cout<<endl<<"using recursive"<<endl;
    int resultIndex = binarySearchRecursive(a, start, end1, target);
    if (resultIndex != -1) 
    {
        cout << "found at: " << resultIndex + 1 << endl;
    } 
    else 
    {
        cout << "not found" << endl;
    }
}
