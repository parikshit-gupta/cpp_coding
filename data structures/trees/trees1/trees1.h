#include<vector>
#include<queue>
using namespace std;

template <typename T>
class tree_node
{
    public:
    T data;
    //vector which stores the adresses of all child nodes
    vector<tree_node<T>*> children;

    
    tree_node()
    {
    }

    tree_node(T data)
    {
        this->data=data;
    }

    ~tree_node()
    {
        for (int i=0; i<children.size();i++)
        {
            int child_data=children[i]->data;
            delete children[i];
            cout<<"child: "<< child_data<<" of node: "<<data<<" deleted."<<endl;
        }
    }
};

tree_node<int>* tree_input1()
{
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    tree_node<int>*root=new tree_node<int>(rootData);

    queue <tree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        tree_node<int>*front=q.front();
        q.pop();
        int numChild;
        cout<<"enter the number of children for node "<<front->data<<": ";
        cin>>numChild;
        for (int i=0; i<numChild;i++)
        {
            int data;
            cout<<"enter the data of child"<<i+1<<" of node "<<front->data<<": ";
            cin>>data;
            tree_node<int>*child=new tree_node<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void print_tree(tree_node<int>*root)
{
    queue<tree_node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        tree_node<int> *front=q.front();
        q.pop();
        cout<<front->data<<": ";
        for (int i=0; i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<", ";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}