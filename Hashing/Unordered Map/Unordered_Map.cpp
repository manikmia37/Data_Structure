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
    unordered_map<int,string>m;
    m[3]="Manik";
    m[5]="Krisof";
    m[2]="Tourist";
    m.insert(make_pair(1,"Sundar Pichai"));
    m.insert(make_pair(4,"Jahid Sobur"));
    for(auto u:m)
    {
        cout<<u.first<<"->"<<u.second<<endl;
    }
    return 0;
}


