#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define MOD 1000000007
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(5); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

const int mx=101;
int arr[mx];

void heapify(int arr[], int n, int current_index)
{
    int largest=current_index;
    int leftchild_index=2*current_index+1;
    int rightchild_index=2*current_index+2;
    if(leftchild_index<n && arr[leftchild_index]>arr[largest])
    {
        largest=leftchild_index;
    }
    if(rightchild_index<n && arr[rightchild_index]>arr[largest])
    {
        largest=rightchild_index;
    }
    if(largest != current_index)
    {
        swap(arr[largest],arr[current_index]);
        heapify(arr,n,largest);
    }
    return;
}

void print_Array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    //optimize();
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Heapify The Tree is (complete Binary Tree): ";
    print_Array(arr,n);
    int EndLeafs = (n/2)-1; // taking floor as 0 based index
    for(int index=EndLeafs; index>=0; index--)
    {
        heapify(arr,n,index);
    }
    cout<<endl;
    cout<<"After Heapify The Tree is (complete Binary Tree and Max Heap): ";
    print_Array(arr,n);
    return 0;
}

/*
input
9
2 10 1 5 4 8 3 8 7
output
Before: 2 10 1 5 4 8 3 8 7
After: 10 8 8 7 4 1 3 5 2
*/

