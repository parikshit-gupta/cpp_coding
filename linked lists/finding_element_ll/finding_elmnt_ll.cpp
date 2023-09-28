#include<iostream>
#include<cstdio>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }

    ~node()
    {
        if (next!=NULL)
        {
            delete next;
        }
        cout<<data<<" : object destoyed."<<endl;
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

int find_elmnt(node*head, int elmnt, int c)
{
    node*temp=head;
    if (temp->data==elmnt)
    {
        return c;
    }

    if (temp==NULL)
    {
        return -1;
    }

    return find_elmnt(temp->next, elmnt, ++c);
}

int main()
{
    node *head =input();
    if (find_elmnt(head, 40, 0)==-1)
    {
        cout<< "element not found."<<endl;
    }

    else
    {
        cout<< "element found at index: "<< find_elmnt(head, 40, 0)<<endl;
    }

    delete head;
}