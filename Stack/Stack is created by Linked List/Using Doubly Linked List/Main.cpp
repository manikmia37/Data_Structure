#include<bits/stdc++.h>
#include "myStack_using_Doubly_List.h";
using namespace std;
int main()
{
    Stack<string>ST;
    cout<<"Choose 1: Push into stack"<<endl;
    cout<<"Choose 2: Pop from stack"<<endl;
    cout<<"Choose 3: Display the elements"<<endl;
    cout<<"Choose 4: Display the top Element"<<endl;
    cout<<"Choose 5: Check the stack is either full or not"<<endl;
    cout<<"Choose 6: Find out the size of stack"<<endl;
    cout<<"Choose 7: Check the stack is either empty or not"<<endl;
    cout<<"Choose 0: To exist"<<endl;
    cout<<"Select the option from option menu: ";
    int choose;
    cin>>choose;

    while(choose)
    {
        switch(choose)
        {
        case 1:
            int n;
            cout<<"Enter the how many elements you want to add in stack: ";
            cin>>n;
            cout<<"Ok...that's good! Now enter the values: ";
            for(int i=1; i<=n; i++)
            {
                string element;
                cin>>element;
                ST.push(element);
            }
            break;
        case 2:
            ST.pop();
            break;
        case 3:
            ST.display();
            break;
        case 4:
            ST.Peek_element();
            break;
        case 5:
            bool full;
            full=ST.isFull(n);
            if(full) cout<<"The stack is Full"<<endl;
            else cout<<"The stack is not full"<<endl;
            break;
        case 6:
            int length;
            length=ST.Size();
            cout<<"The size of stack is: "<<length<<endl;
            break;
        case 7:
            bool Empty;
            Empty=ST.isEmpty();
            if(Empty) cout<<"The stack is empty"<<endl;
            else{
                cout<<"The stack is not empty"<<endl;
            }
            break;
        default:
            break;
        }
        cout<<endl;
        cout<<"Select the option from option menu: ";
        cin>>choose;
    }

    return 0;
}
