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

class Minimum_Priority_Queue
{
private:
    vector<int>v;
    int leftchild(int parent_index)
    {
        return (2*parent_index)+1;
    }
    int rightchild(int parent_index)
    {
        return (2*parent_index)+2;
    }
    int parent(int child_index)
    {
        return (child_index-1)/2;
    }
    void heapify(int parent_index)
    {
       int smallest=parent_index;
       int leftchild_index=leftchild(smallest);
       int rightchild_index=rightchild(smallest);
       if(leftchild_index<v.size() && v[leftchild_index]<v[smallest])
       {
           smallest=leftchild_index;
       }
       if(rightchild_index<v.size() && v[rightchild_index]<v[smallest])
       {
           smallest=rightchild_index;
       }
       if(smallest != parent_index)
       {
           swap(v[smallest],v[parent_index]);
           heapify(smallest);
       }
    }
public:
    void push(int val)
    {
        v.push_back(val);
        int insert_index=v.size()-1;
        if(insert_index==0)
        {
            return;
        }
        while(v[insert_index]<v[parent(insert_index)])
        {
            swap(v[insert_index],v[parent(insert_index)]);
            insert_index=parent(insert_index);
            if(insert_index==0)
            {
                break; //stop condition
            }
        }
        return;
    }
    int Top()
    {
        return v[0];
    }
    int pop()
    {
        v[0]=v[v.size()-1];
        v.pop_back();
        heapify(0);
    }
    bool empty()
    {
        return  v.size()==0;
    }
};
int main()
{
    //optimize();
    Minimum_Priority_Queue pq;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      int val;
      cin>>val;
      pq.push(val);
    }
    while(!pq.empty())
    {
        int number=pq.Top();
        pq.pop();
        cout<<number<<" ";
    }
    return 0;
}
/*
input
5
4 1 2 3 5
output: 1 2 3 4 5
*/

