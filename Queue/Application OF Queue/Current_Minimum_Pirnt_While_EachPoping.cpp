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

int main()
{
    //optimize();
    stack <int> st1,st2;
    cout<<"How many elements do you want to give as input in array: ";
    int n;
    cin>>n;
    cout<<"Enter The Elements: ";
    for(int i=1; i<=n; i++)
    {
       cin>>arr[i];
    }
    int minimum=INT_MAX;
    for(int i=1; i<=n; i++)
    {
       st1.push(arr[i]);
       if(arr[i]<=minimum)
       {
          minimum=arr[i];
          st2.push(minimum);
       }
    }
    cout<<endl;
    while(!st1.empty())
    {
        cout<<st2.top()<<" ";
        int value=st1.top();
        st1.pop();
        if(value==st2.top())
        {
            st2.pop();
        }
    }

    return 0;
}


