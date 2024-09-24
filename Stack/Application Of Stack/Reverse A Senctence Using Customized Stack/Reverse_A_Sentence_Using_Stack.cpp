#include<bits/stdc++.h>
#include "myStack_using_Doubly_List.h"
using namespace std;
int main()
{
    //optimize();
    Stack<string>ST;
    string s;
    getline(cin,s);
    //cout<<s.size()<<endl;
    string word;
    for(int i=0; i<s.size(); i++)
    {
        if(isspace(s[i]))
        {
           ST.push(word);
           word.clear();
        }
        else{
            word+=s[i];
        }
    }
    ST.push(word);
    while(!ST.isEmpty())
    {
        ST.Peek_element();
        ST.pop();
    }
    return 0;
}


