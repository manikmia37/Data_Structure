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

bool checK_left_prarenthesis(char ch)
{
    if(ch=='[' || ch=='{' || ch=='(')
    {
        return true;
    }
    else return false;
}

int main()
{
    //optimize();
    stack <char> st;
    string s;
    cin>>s;
    bool balance_parenthesis=true;
    for(int i=0; i<s.size(); i++)
    {
        if(checK_left_prarenthesis(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    balance_parenthesis=false;
                    break;
                }
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    balance_parenthesis=false;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    balance_parenthesis=false;
                    break;
                }
            }
        }
    }
    if(balance_parenthesis==true && st.empty()) cout<<"Yes, Balance Parenthesis"<<endl;
    else cout<<"No, imbalance Parenthesis"<<endl;

    return 0;
}


