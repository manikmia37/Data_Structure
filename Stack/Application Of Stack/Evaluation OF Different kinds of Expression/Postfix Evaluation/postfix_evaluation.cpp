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

void make_some_operation(char ch)
{
    int a,b,result;
    switch(ch)
    {
    case '^':
        a=st.top()-'0';
        st.pop();
        b=st.top()-'0';
        st.pop();
        result=pow(b,a);
        st.push(result+'0');
        break;
    case '*':
        a=st.top()-'0';
        st.pop();
        b=st.top()-'0';
        st.pop();
        result=a*b;
        st.push(result+'0');
        break;
    case '/':
        a=st.top()-'0';
        st.pop();
        b=st.top()-'0';
        st.pop();
        result=a/b;
        st.push(result+'0');
        break;
    case '+':
        a=st.top()-'0';
        st.pop();
        b=st.top()-'0';
        st.pop();
        result=a+b;
        st.push(result+'0');
        break;
    case '-':
        a=st.top()-'0';
        st.pop();
        b=st.top()-'0';
        st.pop();
        result=b-a;
        st.push(result+'0');
        break;
    default:
        break;
    }
}

void PostfixEvaluation(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(isspace(s[i]))
        {
            continue;
        }
        else if(isdigit(s[i]))
        {
            int val=0;
            while(isdigit(s[i]) && i<s.size())
            {
                val=(val*10)+(s[i]-'0');
                i++;
            }
            st.push(val+'0');
            i--;
        }
        else
        {
            make_some_operation(s[i]);
        }
    }
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter the postfix notation: ";
    getline(cin,s);
    PostfixEvaluation(s);
    cout<<"The postfix evaluation is: "<<st.top()-'0'<<endl;
    return 0;
}

/*
input: 4 3 5 + * 2 0 + -
output: 30

input: 435+*20+- //this input format not valid. it will valid if here is used only 1 digit number.


input: 2 3 1 * + 9 -
output: -4
*/

