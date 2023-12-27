#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
class BST
{
    binaryTree_node<int> *root;

public:
    BST()
    {
        this->root = input_binTree1();
    }
    ~BST()
    {
        delete root;
    }

    // bool search_node(int k, binaryTree_node<int>*root1=root)
    /*we can not pass member variables as deafult arguments to memeber functions, and thats why we need to
    create a chained funciton as shown below*/

    // searching for a node
    bool search_node(int k)
    {
        return search_node(root, k);
    }
    bool search_node(binaryTree_node<int> *root1, int k)
    {
        if (root1 == NULL)
        {
            return false;
        }
        if (root1->data == k)
        {
            return true;
        }
        if (root1->data > k)
        {
            return search_node(root1->left, k);
        }
        if (root1->data < k)
        {
            return search_node(root1->right, k);
        }
    }

    // insertion to a BST
    void insert(int k)
    {
        insert(root, k);
    }
    void insert(binaryTree_node<int> *root, int k)
    {
        if (k < root->data)
        {
            if (root->left == NULL)
            {
                binaryTree_node<int> *node = new binaryTree_node<int>(k);
                root->left = node;
                return;
            }
            insert(root->left, k);
        }
        else if (k > root->data)
        {
            if (root->right == NULL)
            {
                binaryTree_node<int> *node = new binaryTree_node<int>(k);
                root->right = node;
                return;
            }
            insert(root->right, k);
        }
    }

    // deletion of node;
    int min_node(binaryTree_node<int> *root1)
    {
        //finding and deleting min_node from the right tree
        if (root1->left == NULL)
        {
            int root1_data = root1->data;
            delete_node(root1_data);
            return root1_data;
        }
        return min_node(root1->left);
    }
    void delete_node(int k)
    {
        // speacial case: if root is intended to be deleted
        if (root->data == k)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
                return;
            }
            if (root->left == NULL && root->right != NULL)
            {
                binaryTree_node<int> *root2 = root->right;
                root->right = NULL;
                delete root;
                root = root2;
                return;
            }
            if (root->left != NULL && root->right == NULL)
            {
                binaryTree_node<int> *root2 = root->left;
                root->left = NULL;
                delete root;
                root = root2;
                return;
            }
            if (root->left != NULL && root->right != NULL)
            {
                int minimum = min_node(root->right);
                cout << "minimum: " << minimum << endl;
                root->data = minimum;
                return;
            }
        }
        else if (root->data > k)
        {
            delete_node(root->left, k, root, 0);
        }
        else if (root->data < k)
        {
            delete_node(root->right, k, root, 1);
        }
    }
    void delete_node(binaryTree_node<int> *root1, int k, binaryTree_node<int> *parent, int c)
    {
        if (root1 == NULL)
        {
            return;
        }
        /*
        if c==0, then root is left child of parent
        if c==1, then root is right child of parent
        */

        // different cases if required node is found
        if (root1->data == k)
        {
            // leaf node
            if (root1->left == NULL && root1->right == NULL)
            {
                if (c == 0)
                {
                    parent->left = NULL;
                }
                if (c == 1)
                {
                    parent->right = NULL;
                }
                delete root1;
                return;
            }

            // one of the node is NULL
            if (root1->left == NULL && root1->right != NULL)
            {
                if (c == 0)
                {
                    parent->left = root1->right;
                    root1->right = NULL;
                    delete root1;
                    return;
                }

                if (c == 1)
                {
                    parent->right = root1->right;
                    root1->right = NULL;
                    delete root1;
                    return;
                }
            }

            if (root1->left != NULL && root1->right == NULL)
            {
                if (c == 0)
                {
                    parent->left = root1->left;
                    root1->left = NULL;
                    delete root1;
                    return;
                }

                if (c == 1)
                {
                    parent->right = root1->left;
                    root1->left = NULL;
                    delete root1;
                    return;
                }
            }

            // when both nodes are not NULL
            if (root1->left != NULL && root1->right != NULL)
            {
                int minimum = min_node(root1->right);
                cout << "minimum: " << minimum << endl;
                root1->data = minimum;
                return;
            }
        }

        if (root1->data > k)
        {
            delete_node(root1->left, k, root1, 0);
        }

        if (root1->data < k)
        {
            delete_node(root1->right, k, root1, 1);
        }
    }

    // printing bin_tree
    void print_binTree1()
    {
        if (root == NULL)
        {
            return;
        }

        queue<binaryTree_node<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            binaryTree_node<int> *front = q.front();
            q.pop();
            cout << front->data << ": ";
            if (front->left != NULL)
            {
                cout << "L: " << front->left->data << " ";
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                cout << "R: " << front->right->data;
                q.push(front->right);
            }
            cout << endl;
        }
    }
};