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

int perform_operation(int val1, int val2,char ch)
{
    int result;
    if(ch=='^')
    {
        result=pow(val2,val1);
        return result;
    }
    else if(ch=='/')
    {
        result=val2/val1;
        return result;
    }
    else if(ch=='*')
    {
        result=val2*val1;
        return result;
    }
    else if(ch=='+')
    {
        result=val2+val1;
        return result;
    }
    else if(ch=='-')
    {
        result=val2-val1;
        return result;
    }
}

int precedence_calculation(char ch)
{
    if(ch=='^') return 3;
    else if(ch=='/' || ch=='*') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

int infix_evaluation(string s)
{
    //cout<<s.size()<<endl;
    stack<int>value;
    stack<char>o_and_p;
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
           value.push(val);
           i--;
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            value.push(s[i]-'0');
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            value.push(s[i]-'0');
        }
        else if(s[i]=='(')
        {
            o_and_p.push(s[i]);
        }
        else if(s[i]=='^'||s[i]=='/'||s[i]=='*'||s[i]=='+'||s[i]=='-')
        {
            while(!o_and_p.empty() && o_and_p.top() != '(' && precedence_calculation(s[i])<precedence_calculation(o_and_p.top()))
            {
                int val1=value.top();
                value.pop();
                int val2=value.top();
                value.pop();
                char Operator=o_and_p.top();
                o_and_p.pop();
                int result=perform_operation(val1,val2,Operator);
                //cout<<result<<endl;
                value.push(result);
            }
            if(o_and_p.empty())
            {
                o_and_p.push(s[i]);
            }
            else if(o_and_p.top() == '(')
            {
                o_and_p.push(s[i]);
            }
            else if(precedence_calculation(s[i])>=precedence_calculation(o_and_p.top()))
            {
                o_and_p.push(s[i]);
            }
        }
        else if(s[i]==')')
        {
            while(!o_and_p.empty() && o_and_p.top() != '(')
            {
                int val1=value.top();
                value.pop();
                int val2=value.top();
                value.pop();
                char Operator=o_and_p.top();
                o_and_p.pop();
                int result=perform_operation(val1,val2,Operator);
                value.push(result);

            }
            if(!o_and_p.empty())
            {
                o_and_p.pop();
            }
        }
    }
    while(!o_and_p.empty())
    {
        int val1=value.top();
        value.pop();
        int val2=value.top();
        value.pop();
        char Operator=o_and_p.top();
        o_and_p.pop();
        int result=perform_operation(val1,val2,Operator);
        value.push(result);
    }
    return value.top();
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter The infix expression: ";
    getline(cin,s);
    int result=infix_evaluation(s);
    cout<<result<<endl;
    return 0;
}

/*
input: 2*(5*(3+6))/15-2 //This input format not valid. it will valid if here is used only 1 digit number.
output: 4
input: 100 * 2 + 12
output: 212
input: 100 * ( 2 + 12 )
output: 1400
*/
