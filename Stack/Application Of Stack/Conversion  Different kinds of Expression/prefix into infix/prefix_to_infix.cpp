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

string prefix_to_infix(string s)
{
    stack<string>st;
    string resultant_string;
    for(int i=s.size()-1; i>=0; i--)
    {
       string s1;
       if(s[i]>='0' && s[i]<='9')
       {
           s1.append(1,s[i]);
           st.push(s1);
       }
       else if(s[i]>='a' && s[i]<='z')
       {
           s1.append(1,s[i]);
           st.push(s1);
       }
       else if(s[i]>='A' && s[i]<='Z')
       {
           s1.append(1,s[i]);
           st.push(s1);
       }
       else{
           string ch1=st.top();
           st.pop();
           string ch2=st.top();
           st.pop();
           st.push('('+ch1+s[i]+ch2+')');
       }
    }
    return st.top();
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter the prefix Expression: ";
    cin>>s;
    s=prefix_to_infix(s);
    cout<<s<<endl;
    return 0;
}

/*
input:  *-A/BC-/AKL
output: ((A-(B/C))*((A/K)-L))
*/
