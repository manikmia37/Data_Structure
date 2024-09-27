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


string postfix_to_prefix(string s)
{
    stack<string>st;

    for(int i=0; i<s.size(); i++)
    {
        string s1;
        if(s[i]>='0' && s[i]<='9')
        {
            s1+=s[i];
            st.push(s1);
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            s1+=s[i];
            st.push(s1);
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s1+=s[i];
            st.push(s1);
        }
        else
        {
            string ch1=st.top();
            st.pop();
            string ch2=st.top();
            st.pop();
            st.push(s[i]+ch2+ch1);
        }
    }
    return st.top();
}

int main()
{
    //optimize();
    string s;
    cout<<"Enter the postfix Expression: ";
    cin>>s;
    s=postfix_to_prefix(s);
    cout<<s<<endl;
    return 0;
}

/*
input: AB+CD-*
output: *+AB-CD
input: ABC/-AK/L-*
output: *-A/BC-/AKL
*/

