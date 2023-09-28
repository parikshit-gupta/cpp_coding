#include <iostream>
#include <cstdio>
using namespace std;

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
        cout << data << " : object destroyed." << endl;
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

// lenght of a LL recursively
int len_ll(node *head)
{
    node *temp = head;
    if (temp->next == NULL)
    {
        return 1;
    }

    temp = temp->next;
    return 1 + len_ll(temp);
}

node *append_from_last(node *head, int N)
{
    cout<<"hello"<<endl;
    node *temp = head;
    node *temp1;
    int len = len_ll(temp);
    cout<< len<<endl;
    int c = 0;
    while (c <= len)
    {
        if (c==len-1)
        {
            temp->next = head;
            temp=temp->next;
            c++;
        }

        if (c == len - N-1)
        {
            temp1 = temp->next;
            temp->next = NULL;
            temp=temp1;
            c++;
        }
        else
        {
            temp = temp->next;
            c++;
        }
    }

    return temp1;
}

int main()
{
    node *head =input();
    cout<<"before appending: "<<endl;
    print(head);
    node *new_head=append_from_last(head, 2);
    cout<<"after appending: "<< endl;
    print(new_head);

    delete new_head;
    
    return 0;
}