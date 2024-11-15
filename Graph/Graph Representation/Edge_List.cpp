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
    int node;
    cin>>node;
    int Edge;
    cout<<"Enter the number of Edges: ";
    cin>>Edge;
    vector<vector<int>>Edge_List;
    for(int i=1; i<=Edge; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        Edge_List.push_back({u,v,weight});
    }
    for(int i=0; i<Edge_List.size(); i++)
    {
        cout<<"["<<Edge_List[i][0]<<" "<<Edge_List[i][1]<<" "<<Edge_List[i][2]<<"]"<<endl;
    }
    return 0;
}

/*
input is given for undirected and unweighted graph
input:
4 4
0 1 5
1 2 10
1 3 5
2 3 15
output:
[0 1 5]
[1 2 10]
[1 3 5]
[2 3 15]
*/
