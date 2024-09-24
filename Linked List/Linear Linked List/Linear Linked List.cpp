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


class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};


struct Test
{
    int position[1000];
};

void insertAtTail(Node *&Head, int val)
{
    Node *newnode= new Node(val);
    if(Head==NULL)
    {
        Head=newnode;
        return;
    }
    Node *temp=Head;
    while(temp->Next != NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newnode;
    return;
}

void insertAtHead(Node *&head, int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    newnode->Next=head;
    head=newnode;
}

int searchValue(Node *&head, int val)
{
    if(head==NULL) return 0;
    Node *temp=head;
    int position=1;
    while(temp->value != val)
    {
        if(temp->Next != NULL)
        {
            temp=temp->Next;
            position++;
        }
        else
        {
            return 0;
        }
    }
    return position;
}

int find_length(Node *&head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return 0;
    }
    int cnt=0;
    while(temp != NULL)
    {
        cnt++;
        temp=temp->Next;
    }
    return cnt;
}

Test SearchValueDuplicate(Node *&head,int val)
{
    Node *temp=head;
    Test T;
    int k=1;
    int cnt=1;
    while(temp != NULL)
    {
        if(temp->value==val)
        {
            T.position[k]=cnt;
            k++;
        }
        temp=temp->Next;
        if(temp != NULL)
        {
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    T.position[0]=k-1;
    return T;
}

void display(Node* &n)
{
    if(n==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    Node *temp=n;
    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->Next != NULL) cout<<"->";
        temp=temp->Next;
    }
    cout<<endl;
}

void insertAtspecificPosition(Node *&head, int val, int pos)
{
    Node *newnode=new Node(val);
    Node *temp=head;
    if(pos<1)
    {
        cout<<"Please Enter Valid Position"<<endl;
        return;
    }
    else if(pos==1)
    {
        newnode->Next=temp;
        head=newnode;
        return;
    }
    int cnt=1;
    while(cnt != pos-1)
    {
        temp=temp->Next;
        cnt++;
    }
    newnode->Next=temp->Next;
    temp->Next=newnode;
}


void insertAt_after_specific_value(Node *&head, int prefered_value, int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        cout<<"Since the list is empty, your given element is inserted"
            <<endl<<"as the first element in the List"<<endl;
        insertAtHead(head,val);
        return;
    }
    bool flag=true;
    Node *temp=head;
    while(temp->value != prefered_value)
    {
        temp=temp->Next;
        if(temp == NULL)
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
        cout<<"Your preference value does not exist in the list"
            <<endl<<"Your given value is inserted as the last element in the list"<<endl;
        insertAtTail(head,val);
    }
    else
    {
        newnode->Next=temp->Next;
        temp->Next=newnode;
    }
}


void insertAt_after_specific_value_in_Alternate_Way(Node *&head, int prefered_value, int value)
{
    int position = searchValue(head,prefered_value);
    if(!position)
    {
        if(head==NULL)
        {
            cout<<"Since The is Empty"<<endl
                <<"Your given value is inserted as The first Element"<<endl;
            insertAtHead(head,value);
        }
        else
        {
            cout<<"Your preferred value does not exist in the List"<<endl
                <<"Your given value is inserted as the last element of the List"<<endl;
            insertAtTail(head,value);
        }
    }
    else
    {
        insertAtspecificPosition(head,value,position+1);
    }
}

void insertAt_after_specific_value_in_duplicate_list(Node *&head, int prefered_value, int value)
{
    Test S=SearchValueDuplicate(head,prefered_value);
    int Size=S.position[0];
    if(Size==0)
    {
        if(head==NULL)
        {
            cout<<"Since The List is Empty"<<endl
                <<"Your given value is inserted as The first Element"<<endl;
            insertAtHead(head,value);
        }
        else
        {
            cout<<"Your preferred value does not exist in the List"<<endl
                <<"Your given value is inserted as the last element of the List"<<endl;
            insertAtTail(head,value);
        }
    }
    else
    {
        for(int i=1; i<=Size; i++)
        {
            int position=S.position[i]+i;
            insertAtspecificPosition(head,value,position);
        }
    }
}

void deleteAtHead(Node *&head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"The list is Empty"<<endl;
        return;
    }
    else if(temp->Next == NULL)
    {
        delete temp;
        head=NULL;
        return;
    }
    head=head->Next;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    else if(temp->Next == NULL)
    {
        deleteAtHead(temp);
        head=NULL;
        return;
    }
    while(temp->Next->Next != NULL)
    {
        temp=temp->Next;
    }
    Node *delnode=temp->Next;
    temp->Next=NULL;
    delete delnode;
}

void deleteAtspecificPosition(Node *&head, int position)
{
    Node *temp=head;
    if(temp != NULL && (position>=1 && position<=find_length(temp)))
    {
        if(position==1)
        {
            deleteAtHead(head);
            return;
        }
        else if(position==find_length(temp))
        {
            deleteAtTail(temp);
            return;
        }
        int cnt=1;
        while(cnt != position-1)
        {
            temp=temp->Next;
            cnt++;
        }
        Node *delnode=temp->Next;
        temp->Next=delnode->Next;
        delete delnode;
    }
    else
    {
        if(temp==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Please Enter Valid Position"<<endl;
        }
    }
}

void deletebyspecificvalue(Node *&head, int val)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    int position=searchValue(head,val);
    if(position)
    {
        deleteAtspecificPosition(head,position);
    }
    else
    {
        cout<<"Entered Value does not Exist in List"<<endl;
    }
}

void deletebyspecificvalue_in_duplicate_List(Node *&head, int value)
{
    Test S=SearchValueDuplicate(head,value);
    int Size=S.position[0];
    if(Size==0)
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Entered value does not exist in the List"<<endl;

        }
    }
    else
    {
       int cnt=0;
       for(int i=1; i<=Size; i++)
       {
           int pos = S.position[i]-cnt;
           deleteAtspecificPosition(head,pos);
           cnt++;
       }
    }
}


void reverse_Linked_List_in_Non_RecuresiveWay(Node* &head)
{
    Node *prev=NULL;
    Node *current=head;
    if(head==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    Node *next=head->Next;
    while(1)
    {
       current->Next=prev;
       prev=current;
       current=next;
       if(next == NULL)
       {
          break;
       }
       next=next->Next;
    }
    head=prev;
    return;
}

Node* reverse_Linked_List_In_Recursive_Way(Node *&head)
{
   if(head->Next==NULL)
   {
       return head;
   }
   Node *newnode=reverse_Linked_List_In_Recursive_Way(head->Next);
   head->Next->Next=head;
   head->Next=NULL;
   return newnode;
}

int main()
{
    //optimize();
    Node *head=NULL;

    cout<<"Choose 1: Insertion at Tail"<<endl;
    cout<<"Choose 2: Insertion at Head"<<endl;
    cout<<"Choose 3: Insertion at specific position"<<endl;
    cout<<"Choose 4: Searching A value in Unique Linked List"<<endl;
    cout<<"Choose 5: Display The Linked List"<<endl;
    cout<<"Choose 6: Find Length of List"<<endl;
    cout<<"Choose 7: Search a value in Duplicate valued Linked List"<<endl;
    cout<<"Choose 8: Insertion After specific Value (in Unique List)"<<endl;
    cout<<"Choose 9: Insertion After specific Value in Alternative Way ( in Unique List)"<<endl;
    cout<<"Choose 10: Insertion After specific Value (in Duplicate Valued List)"<<endl;
    cout<<"Choose 11: Deletion At Head"<<endl;
    cout<<"Choose 12: Deletion At Tail"<<endl;
    cout<<"Choose 13: Deletion At specific Position"<<endl;
    cout<<"Choose 14: Deletion specific Value in List(unique list)"<<endl;
    cout<<"Choose 15: Deletion specific Value in List(Duplicate List)"<<endl;
    cout<<"Choose 16: Reverse Linked List(In Non Recursive Way)"<<endl;
    cout<<"Choose 17: Reverse Linked List (In Recursive Way)"<<endl;
    cout<<"Choose 0: to Exit"<<endl;
    cout<<"Choose The Option from Option menu: ";
    int choose;
    cin>>choose;
    int value;
    while(choose)
    {
        switch(choose)
        {
        case 1:
            cout<<"Enter The Value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 2:
            cout<<"Enter The Value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 3:
            cout<<"Enter The Value: ";
            cin>>value;
            cout<<"Enter a position: ";
            int position;
            cin>>position;
            insertAtspecificPosition(head,value,position);
            break;
        case 4:
            int pos;
            cout<<"Enter The value which You want to search: ";
            cin>>value;
            pos=searchValue(head,value);
            if(pos==0)
                cout<<"Your Searching Value does not exist in the list"<<endl;
            else
                cout<<"Your searching value is found at position: "<<pos<<endl;
            break;
        case 5:
            display(head);
            break;
        case 6:
            int len;
            len=find_length(head);
            cout<<"The length is: "<<len<<endl;
            break;
        case 7:
            cout<<"Enter The value which you want to search: ";
            cin>>value;
            //SearchValueDuplicate(head,value);
            Test S;
            S=SearchValueDuplicate(head,value);
            if(S.position[0]==0)
            {
                cout<<"Your Searching Value does not exist Yet in the List"<<endl;
            }
            else
            {
                int Size=S.position[0];
                cout<<"Your Searching Value is found at position: ";
                for(int i=1; i<=Size; i++)
                {
                    cout<<S.position[i];
                    if(i<Size) cout<<",";
                }
            }
            break;
        case 8:
            int prefered_value;
            cout<<"Enter the value which after you want to insert new value: ";
            cin>>prefered_value;
            cout<<"Enter The Value which want to insert: ";
            cin>>value;
            insertAt_after_specific_value(head,prefered_value,value);
            break;
        case 9:
            cout<<"Enter the value which after you want to insert new value: ";
            cin>>prefered_value;
            cout<<"Enter The Value which want to insert: ";
            cin>>value;
            insertAt_after_specific_value_in_Alternate_Way(head,prefered_value,value);
            break;
        case 10:
            cout<<"Enter the value which after you want to insert new value: ";
            cin>>prefered_value;
            cout<<"Enter The Value which want to insert: ";
            cin>>value;
            insertAt_after_specific_value_in_duplicate_list(head,prefered_value,value);
            break;
        case 11:
            deleteAtHead(head);
            break;
        case 12:
            deleteAtTail(head);
            break;
        case 13:
            cout<<"Enter The Position: "<<endl;
            cin>>position;
            deleteAtspecificPosition(head,position);
            break;
        case 14:
            cout<<"Enter The Value Which you want to delete: ";
            cin>>value;
            deletebyspecificvalue(head,value);
            break;
        case 15:
            cout<<"Enter The Value which You want to delete: ";
            cin>>value;
            deletebyspecificvalue_in_duplicate_List(head,value);
            break;
        case 16:
            reverse_Linked_List_in_Non_RecuresiveWay(head);
            break;
        case 17:
            head=reverse_Linked_List_In_Recursive_Way(head);
            break;
        default:
            break;
        }
        cout<<endl;
        cout<<"Choose The Option from Option menu: ";
        cin>>choose;
    }

    return 0;
}














