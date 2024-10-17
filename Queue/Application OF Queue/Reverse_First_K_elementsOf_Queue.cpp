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

queue<int>q,q1;
stack<int>st;

int main()
{
    //optimize();
    cout<<"How many elements do want to give as input: ";
    int n,k;
    cin>>n;
    cout<<"Enter Elements: ";

    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }

    cout<<"Enter The the number of First K elements which you want to reverse: ";
    cin>>k;

    for(int j=1; j<=k; j++)
    {
        int val=q.front(); //TC->O(K)
        q.pop();
        st.push(val);
    }

    while(!st.empty())
    {
        int val=st.top();
        st.pop();
        q1.push(val);
    }

    while(!q.empty())
    {
        q1.push(q.front());  //TC->O(N-K)
        q.pop();
    }

    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    return 0;
}
// so Final TC->O(N-K)+O(K)=o(N)
/*
input: 10 3
1 2 3 4 5 6 7 8 9 10
output: 3 2 1 4 5 6 7 8 9 10
*/


