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
    cout<<"Enter Number OF Nodes: ";
    int n;
    cin>>n;
    vector<pair<int,int>>Adjacency_List[n];
    int Edge;
    cout<<"Enter the number of Edges: ";
    cin>>Edge;
    cout<<"Enter the value for graph representation: "<<endl;
    for(int i=1; i<=Edge; i++)
    {
       int u,v,weight;
       cin>>u>>v>>weight;
       Adjacency_List[u].push_back(make_pair(v,weight));
       Adjacency_List[v].push_back(make_pair(u,weight));
    }
    int i=0;
    for(auto u:Adjacency_List)
    {   cout<<i<<"->";
        for(auto g:u)
        {
            cout<<"("<<g.first<<","<<g.second<<")";
        }
        i++;
        cout<<endl;
    }
    return 0;
}

/*
input is given for weighted and undirected graph
input:
4 4
0 1 5
1 2 3
1 3 4
2 3 2
output:
0->(1,5)
1->(0,5)(2,3)(3,4)
2->(1,3)(3,2)
3->(1,4)(2,2)
*/

