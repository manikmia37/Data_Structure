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
    vector<int>Adjacency_List[n];
    int Edge;
    cout<<"Enter the number of Edges: ";
    cin>>Edge;
    cout<<"Enter the value for graph representation: "<<endl;
    for(int i=1; i<=Edge; i++)
    {
       int u,v;
       cin>>u>>v;
       Adjacency_List[u].push_back(v);
       Adjacency_List[v].push_back(u);
    }
    int i=0;
    for(auto u:Adjacency_List)
    {   cout<<i<<"->";
        for(auto g:u)
        {
            cout<<g<<" ";
        }
        i++;
        cout<<endl;
    }
    return 0;
}
/*
input is given for unweighted and undirected graph
input:
6 6
0 1
1 2
1 5
2 3
2 4
5 4
output:
0->1
1->0 2 5
2->1 3 4
3->2
4->2 5
5->1 4
*/

