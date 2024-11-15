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

const int number_OF_nodes=101;
int Adjacency_Matrix[number_OF_nodes][number_OF_nodes];
int main()
{
    //optimize();
    //For undirected and unweighted graph
    cout<<"Enter The number of Nodes: ";
    int n;
    cin>>n;
    int Edge;
    cout<<"Enter the number of edges: ";
    cin>>Edge;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            Adjacency_Matrix[i][j]=0;
        }
    }
    cout<<"Enter the value for Graph Representation: "<<endl;
    int i,j;
    while(Edge--)
    {
        cin>>i>>j;
        Adjacency_Matrix[i][j]=1;
        Adjacency_Matrix[j][i]=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<Adjacency_Matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
input is given for single edge but not for self loop and multi edge about undirected and unweighted graph
input:
4 4
0 1
1 2
1 3
2 3
output:
0 1 0 0
1 0 1 1
0 1 0 1
0 1 1 0

*/

