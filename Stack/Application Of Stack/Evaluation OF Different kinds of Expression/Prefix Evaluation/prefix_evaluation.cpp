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

int prefix_Evaluation(string s)
{
    for(int i=s.size()-1; i>=0; i--)
    {
        int a,b,result;
        char ch=s[i];
        //cout<<ch<<endl;
        switch(ch)
        {
        case ' ':
            break;
        case '^':
            a=st.top()-'0';
            st.pop();
            b=st.top()-'0';
            st.pop();
            result=pow(a,b);
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
        case '+':
            a=st.top()-'0';
            st.pop();
            b=st.top()-'0';
            st.pop();
            result=a+b;
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
        case '-':
            a=st.top()-'0';
            st.pop();
            b=st.top()-'0';
            st.pop();
            result=a-b;
            st.push(result+'0');
            break;
        default:
            int val=0;
            while(!isspace(s[i]))
            {
               val=(val)
            }
            st.push(ch);
            break;
        }
    }
    return st.top()-'0';
}


int main()
{
    //optimize();
    string s;
    cout<<"Enter the prefix Expression: ";
    cin>>s;
    int result=prefix_Evaluation(s);
    cout<<"The prefix evaluation is: "<<result<<endl;
    return 0;
}

/*
input: -+7*45+20 //This input format not valid. it will valid if here is used only 1 digit number.
input: - + 7 * 4 5 + 2 0
output: 25
*/
