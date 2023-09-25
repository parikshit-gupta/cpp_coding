#include<iostream>
#include<cstdio>
using namespace std;

class node 
{
    public:
    int data;
    //when delete obj is called only the pointer next gets deallocated and not the object that it points to.
    node * next;

    node (int data)
    {
        this -> data =data;
        next=NULL;
    }

    ~node()
    {
        // we will always have to delete dynamically allocated variables insdie a class in its destructor
        if (next!=NULL)
        {
            delete next;
        }
        cout<<data<<" : object destroyed."<<endl;
    }
};

node *input()
{
    int data;
    cout << "enter the first element of the linked list: ";
    cin >> data;
    //node n1(data);
    node * n1= new node(data);
    node *head = n1;
    node *temp = head;
    while (true)
    {
        cout << "do you want to enter more elements? [Y/N]: ";
        char check;
        cin >> check;
        if (check == 'Y' || check == 'y')
        {
            cout << "enter the next element of the linked list: ";
            cin >> data;
            // node n(data);//scope of every variable created inside the loop is only for one iteration.
            // after every iteration the previous memory gets deallocated.
            node *n = new node(data); // we know that memory in heap doesnt get deallocated untill explicity deleted
            temp->next = n;
            temp = n;
        }

        else
        {
            break;
        }
    }

    return head;
}

//printing the linked list
void print(node *head)
{
    node *temp = head;
    cout << temp->data << endl;
    if (temp->next == NULL)
    {
        return;
    }
    temp = temp->next;
    print(temp);
}

//deallocating memory from heap
void del_LinkList(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        delete temp;
        cout << "linked list deleted." << endl;
        return;
    }

    temp = temp->next;
    //delete calls the destructor of the object;
    delete head;
    head = temp;
    del_LinkList(head);
    return;
}

int main()
{
    /*
    node n1(10);
    node n2(20);
    n1.next=&n2;
    //n1.~node();
    //cout<<n1.data<<endl;

    node * n3=new node(30);
    node *n4=new node (40);
    n3->next=n4;
    delete n3;
    //delete n4;*/

    node *head =input();
    print(head);
    delete head;
    return 0;
}