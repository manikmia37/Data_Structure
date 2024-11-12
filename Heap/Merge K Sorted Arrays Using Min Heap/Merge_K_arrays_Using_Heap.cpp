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
int main()
{
    //optimize();
    int vector_size; //Array Size;
    cin>>vector_size;
    vector<vector<int>>V(vector_size);
    for(int i=0; i<vector_size; i++)
    {
        int Size;
        cin>>Size;
        for(int j=0; j<Size; j++)
        {
            int value;
            cin>>value;
            V[i].push_back(value);
        }
    }
    vector<int>IndexTracker(vector_size,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=0; i<vector_size; i++)
    {
        pq.push(make_pair(V[i][0],i));
    }
    while(!pq.empty())
    {
        pair<int,int>current=pq.top();
        pq.pop();
        cout<<current.first<<" ";
        if(IndexTracker[current.second]+1<V[current.second].size())
        {
            int index=IndexTracker[current.second]+1;
            IndexTracker[current.second]=index;
            pq.push(make_pair(V[current.second][index],current.second));
        }
    }
    return 0;
}

/*
input:
3 //Total number of arrays
3 //Indivisual Array Size
1 4 7 //Array Elements
2  //Indivisual Array Size
3 5 //Array Elements
3   //Indivisual Array Size
2 6 7 //Array Elements
Output: 1 2 3 4 5 6 7 7
*/
