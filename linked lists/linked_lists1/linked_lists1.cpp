#include <iostream>
#include <cstdio>
using namespace std;

// node class represents a single element of a linked list
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = 0;
    }

    ~node()
    {
        delete next;
        cout<<this->data <<" :object destroyed."<<endl;
    }
};

// inputting linked list, function returns the head pointer of the linked list
node *input()
{
    int data;
    cout << "enter the first element of the linked list: ";
    cin >> data;
    //node *n1=new node(data);
    node *n1=new node(data);
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

// printing linked list
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

void print2(node *head)
{
    while (true)
    {
        cout << head->data << endl;
        if (head->next == NULL)
        {
            return;
        }

        head = head->next;
    }
}

int len_LL(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

int find_node(node *head, int index)
{
    // assuming 0th index is first element
    int c = 0;
    node *temp = head;
    while (c != index)
    {
        c++;
        temp = temp->next;
    }
    return temp->data;
}

int main()
{
    // first element of a linked list is the head, whose adress is stored and used to access all other elements;
    /*node n1(1);
    node *head = &n1;

    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print2(head);

    cout << "n1_data: " << n1.data << endl;
    cout << "n2_data: " << head->next->data << endl;*/

    node *head1 = input();
    cout<<head1<<endl;
    print(head1);
    //cout << "lenght of the above linked list is: " << len_LL(head1) << endl;
    /*int x=find_node(head1, 3);
    cout<<x<<endl;
    cout<<head1<<endl;*/
    delete head1;
    //del_LinkList(head1);
    return 0;
}