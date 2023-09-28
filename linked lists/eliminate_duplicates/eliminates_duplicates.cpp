#include <iostream>
#include <cstdio>
using namespace std;
// eliminating duplicates from a sorted linked list

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
        cout << data << " : object destroyed."<<endl;
    }
};

node *input()
{
    int data;
    cout << "enter the first element of the linked list: ";
    cin >> data;
    // node n1(data);
    node *n1 = new node(data);
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

// printing the linked list
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

// eliminating duplicates from a LL
void eliminate_duplicates(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp ->next!= NULL)
    {
        if ((temp->data == (temp->next)->data))
        {
            node *temp1 = temp->next;
            temp->next = temp->next->next;
            temp1->next = NULL;
            delete temp1;
        }

        if ((temp->data == (temp->next)->data)&&(temp->next)->next==NULL)
        {
            delete temp->next;
            temp->next =NULL;
            break;
        }

        temp=temp->next;
        c++;
    }
    return;
}

int main()
{
    node *head=input();
    cout<<"linked list before elimination: "<<endl;
    print(head);
    eliminate_duplicates(head);
    cout<<"linked list after elimination: "<<endl;
    print(head);
    delete head;
    return 0;
}