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

bool check_matching(char ch1, char ch2)
{
   if(ch1=='(' && ch2==')') return true;
   else if(ch1=='{' && ch2=='}') return true;
   else if(ch1=='[' && ch2==']') return true;
   else return false;
}

int main()
{
    //optimize();
    cout<<"Enter a string: ";
    string s;
    getline(cin,s);
    int top = -1;
    for(int i=0; i<s.size(); i++)
    {
        if(top<0 || !check_matching(s[top],s[i]))
        {
           top++;
           s[top]=s[i];
        }
        else{
            top--;
        }
    }
    if(top == -1)
    {
        cout<<"Yes, Balance Parenthesis"<<endl;
    }
    else{
        cout<<"No, imbalance Parenthesis"<<endl;
    }
    return 0;
}


