#include<iostream>
#include<cstdio>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
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

class node_pair
{
    public:
    node*head;
    node *tail;
    node_pair()
    {
        head=NULL;
        tail=NULL;
    }

    bool isNULL()
    {
        if (head==NULL&&tail==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

// printing linked list
void print_LL(node *head)
{
    node *temp = head;
    cout << temp->data << endl;
    if (temp->next == NULL)
    {
        return;
    }
    temp = temp->next;
    print_LL(temp);
}

node_pair BSTtoLL(binaryTree_node<int>*root)
{
    if (root==NULL)
    {
        node_pair np;
        return np;
    }

    node *root_node=new node(root->data);
    node_pair np;
    node_pair npl=BSTtoLL(root->left);
    node_pair npr=BSTtoLL(root->right);
    
    if(npl.isNULL()&&!npr.isNULL())
    {
        np.head=root_node;
        root_node->next=npr.head;
        np.tail=npr.tail;
    }

    if(!npl.isNULL()&&npr.isNULL())
    {
        npl.tail->next=root_node;
        np.head=npl.head;
        np.tail=root_node;
    }

    if (npl.isNULL()&&npr.isNULL())
    {
        np.head=root_node;
        np.tail=root_node;
    }

    if (!npl.isNULL()&&!npr.isNULL())
    {
        npl.tail->next=root_node;
        root_node->next=npr.head;
        np.head=npl.head;
        np.tail=npr.tail;
    }
    return np;
}

int main()
{
    binaryTree_node<int>*root=input_binTree1();
    cout<<"BST: "<<endl;
    print_binTree1(root);
    node_pair np=BSTtoLL(root);
    cout<<"LL: "<<endl;
    print_LL(np.head);
    delete root;
    delete np.head;
    return 0;
}