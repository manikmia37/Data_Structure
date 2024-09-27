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

stack<char>st;
string new_string;

int precedence_calculation(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}


void push_operation(char ch)
{
    while(!st.empty() && precedence_calculation(ch)<=precedence_calculation(st.top()))
    {
        new_string+=st.top();
        st.pop();
    }
    st.push(ch);
}


void pop_operation()
{
    while(!st.empty() && st.top() != ')')
    {
        new_string+=st.top();
        st.pop();
    }
    if(!st.empty())
    {
        st.pop();
    }
}

void infix_convert_to_prefix(string s)
{
    reverse(s.begin(),s.end());
    //cout<<s<<endl;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            new_string+=s[i];
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            new_string+=s[i];
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            new_string+=s[i];
        }
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            pop_operation();
        }
        else
        {
            push_operation(s[i]);
        }
    }
    while(!st.empty())
    {
        new_string+=st.top();
        st.pop();
    }
    reverse(new_string.begin(),new_string.end());
}


int main()
{
    //optimize();
    string s;
    cout<<"Enter infix notation: ";
    cin>>s;
    infix_convert_to_prefix(s);
    cout<<"The converted Prefix notation is: "<<new_string<<endl;
    return 0;
}

/*
input: (7+(4*5))-(2+0)
output: -+7*45+20
input: (7+(4*5))-(2+0)+(3+0)
output: -+7*45++20+30
input: ((7+(4*5))-(2+0)+(3+0)+5)
output: -+7*45++20++305
*/

