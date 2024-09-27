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

string postfix_into_infix(string s)
{
    stack<string>st;
    for(int i=0; i<s.size(); i++)
    {
       string ch;
       if(s[i]>='0' && s[i]<='9')
       {
          ch+=s[i];
          st.push(ch);
       }
       else if(s[i]>='A' && s[i]<='Z')
       {
          ch+=s[i];
          st.push(ch);
       }
       else if(s[i]>='a' && s[i]<='z')
       {
          ch+=s[i];
          st.push(ch);
          //cout<<st.top()<<endl;
       }
       else{
        string ch1=st.top();
        st.pop();
        string ch2=st.top();
        st.pop();
        string result="("+ch2+s[i]+ch1+")";
        st.push(result);
       }
    }
    return st.top();
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter The Postfix Expression: ";
    cin>>s;
    s=postfix_into_infix(s);
    cout<<s<<endl;
    return 0;
}
/*
ab*c+
output: ((a*b)+c)

435+*20+-
output: ((4*(3+5))-(2+0))
*/


