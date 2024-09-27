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


int precedence_calculation(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_to_postfix(string s)
{
    stack<char>st;
    string result;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            result+=s[i];
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            result+=s[i];
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            result+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top() != '(')
            {
                result+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && precedence_calculation(s[i])<=precedence_calculation(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
               st.pop();
               st.push(s[i]);
            }
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter the infix expression: ";
    cin>>s;
    s=infix_to_postfix(s);
    cout<<s<<endl;
    return 0;
}

/*
input: ((4*(3+5))-(2+0))
output: 435+*20+-
input: ((a*b)+c)
output: ab*c+
*/
