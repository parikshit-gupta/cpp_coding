#include<queue>
using namespace std;
template <typename T>
class binaryTree_node
{
public:
    T data;
    binaryTree_node<T> *left;
    binaryTree_node<T> *right;

    binaryTree_node()
    {
        left = NULL;
        right = NULL;
    }

    binaryTree_node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTree_node()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

// printing a binary tree levelwise
void print_binTree1(binaryTree_node<int> *root)
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

// taking input to a binay tree levelwise
binaryTree_node<int> *input_binTree1()
{
    int rootData;
    cout << "enter root data: ";
    cin >> rootData;
    binaryTree_node<int> *root = new binaryTree_node<int>(rootData);
    queue<binaryTree_node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        binaryTree_node<int> *front = q.front();
        q.pop();
        int c;
        cout << front->data << ": do you want a left branch of this node[1/0]: ";
        cin >> c;
        if (c == 1)
        {
            int leftData;
            cout << "enter data for left node: ";
            cin >> leftData;
            binaryTree_node<int> *left_node = new binaryTree_node<int>(leftData);
            front->left = left_node;
            q.push(left_node);
        }
        cout << front->data << ": do you want a right branch of this node[1/0]: ";
        cin >> c;
        if (c == 1)
        {
            int rightData;
            cout << "enter data for right node: ";
            cin >> rightData;
            binaryTree_node<int> *right_node = new binaryTree_node<int>(rightData);
            front->right = right_node;
            q.push(right_node);
        }
    }
    return root;
}
