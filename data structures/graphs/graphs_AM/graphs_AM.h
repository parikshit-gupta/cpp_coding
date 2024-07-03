#include <vector>
#include <queue>
#include<stack>
using namespace std;

class graph
{
    int n; // number of nodes
    int m; // number of edges
    vector<vector<bool>> v;

public:
    /*
    1) contructor
    2) display_AM
    3) DFS_traversal
    4) get_path_DFS
    5) BFS_traversal
    6) has_path_BFS
    ...and some self implemented fucntionalities

    TO DO:
    1)has_path_DFS()
    2)get_path_BFS()
    */
   
   //1) constructor
    graph(int n, int m) : n(n), m(m)
    {
        // inputting the graph from the user in the form of an adjucency matrix
        for (int i = 0; i < n; i++)
        {
            vector<bool> v1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    v1.push_back(0);
                    continue;
                }
                bool b = 0;
                cout << "edge from " << i << " to " << j << " [0/1]: ";
                cin >> b;
                v1.push_back(b);
            }

            v.push_back(v1);
        }
    }

    // 2) displaying the adjucency matrix
    void display_AM()
    {
        cout << "   ";
        for (int i = 0; i < n; i++)
        {
            cout << i << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << ',';
            }
            cout << endl;
        }
    }

    
    // 3) the below code for DFS traversal is only valid for graphs with no seperate components.
    bool *DFS_traversal(int next, bool *arr, int next1)
    {
        // this checking if 'arr' is all 1 or not is useless because the graph might be disconnected also
        /*int i = 0;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                break;
            }
        }
        if (i == n)
        {
            return arr;
        }*/

        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (v[next][i] == 1 && arr[i] == 0)
            {
                arr[i] = 1;
                cout << i << ',';
                DFS_traversal(i, arr, 1);
            }
        }
        // program counter wil enter this block only when all possible traversals in the current component are done
        if (next1 == 0)
        {
            // check if array is all one or not
            // if all one then return
            // if there are 0's in the array then the graph has multiple components
            int c = 0;
            for (i = 0; i < n; i++)
            {
                if (arr[i] == 0)
                {
                    c = i;
                    break;
                }
            }
            if (i == n)
            {
                return arr;
            }
            else
            {
                // since c is less than n thus, there exists a node 'c' but that part is isolated from the current part
                // the below code explores this isolated nodes
                cout << endl;
                arr[c] = 1;
                cout << c << ',';
                DFS_traversal(c, arr, 0);
            }
        }
        return arr;
    }
    // helper funtion of DFS_traversal
    void DFS_traversal(int start)
    {
        bool *arr = new bool[n];
        cout << start << ',';
        for (int i = 0; i < n; i++)
        {
            if (i == start)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
        DFS_traversal(start, arr, 0);
        delete[] arr;
    }

    //4) prints the path between two givens node of the graph using the DFS algo
    bool get_path_DFS(int curr_node, int v2, bool *arr)
    {
        // returns if path found or not aswell
        bool path_exists = 0;
        if (curr_node == v2)
        {
            cout << curr_node <<", ";
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 && v[curr_node][i] == 1)
            {
                arr[i] = 1;
                path_exists = get_path_DFS(i, v2, arr);
                if(path_exists)
                {
                    cout<<curr_node<<", ";
                    break;
                }
            }
        }
        return path_exists;
    }
    // helper function of get_path_DFS()
    void get_path_DFS(int start, int v2)
    {
        bool *arr = new bool[n];
        for (int i = 0; i < n; i++)
        {
            if (i == start)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
        bool path_exists = get_path_DFS(start, v2, arr);
        if (path_exists == 0)
        {
            cout << "no path exists between the given nodes." << endl;
        }
        delete[] arr;
    }

    //5) BFS traversal
    void BFS_traversal(int start)
    {
        queue<int> q;
        q.push(start);
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            if (i == start)
            {
                cout << start << ',';
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
        while (!q.empty())
        {
            int front_ele = q.front();
            for (int i = 0; i < n; i++)
            {
                if (v[front_ele][i] == 1 && arr[i] == 0)
                {
                    q.push(i);
                }
            }

            if (arr[front_ele] == 0)
            {
                cout << front_ele << ',';
                arr[front_ele] = 1;
            }

            q.pop();
        }
        delete[] arr;
    }

    //6) checking existence of a path between two given nodes in graph
    bool has_path_BFS(int start, int v2)
    {
        queue<int> q;
        q.push(start);
        int *arr = new int[n];
        arr[start] = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == start)
            {
                continue;
            }
            else
            {
                arr[i] = 0;
            }
        }
        while (!q.empty())
        {
            int front_ele = q.front();
            for (int i = 0; i < n; i++)
            {
                if (v[front_ele][i] == 1 && arr[i] == 0)
                {
                    q.push(i);
                }
            }
            if (arr[front_ele] == 0)
            {
                arr[front_ele] = 1;
            }
            if (arr[v2] == 1)
            {
                return true;
            }
            q.pop();
        }
        delete[] arr;
        return false;
    }

    //7) prints the path between two givens node of the graph using the BFS algo
    bool get_path_BFS(int start, int end)
    {
        /*
        q1: for the BFS traversal
        s1: for maintaining a link between the elements to calculate the shortest 
        s1.first: neighbour which called/inserted s1.second
        */
        queue<int> q1;
        q1.push(start);

        stack<pair<int,int>> s1;
        pair<int,int> p1(start,start);
        s1.push(p1);

        bool path_exists=0;
        int *arr=new int[n];
        for (int i = 0; i < n; i++)
        {
            if (i == start)
            {
                arr[i]=1;
            }
            else
            {
                arr[i] = 0;
            }
        }

        while(!q1.empty())
        {
            int front=q1.front();
            q1.pop();
            for(int i=0;i<n;i++)
            {
                if(v[front][i]==1&&arr[i]==0)
                {
                    q1.push(i);
                    arr[i]=1;
                    pair<int,int> p2(front, i);
                    s1.push(p2);
                    if(i==end)
                    {
                        path_exists=1;
                        break;
                    }
                }
            }
            if(path_exists==true)
            {
                break;
            }
        }
        if(path_exists==true)
        {
            int parent=s1.top().first;
            int node =s1.top().second;
            s1.pop();
            cout<<node<<", ";
            while(!s1.empty())
            {
                if(s1.top().second==parent)
                {
                    cout<<parent<<", ";
                    parent=s1.top().first;
                    node =s1.top().second;
                }                
                s1.pop();
            }
        }
        else 
        {
            cout<<"no path exists between given nodes."<<endl;
        }
        delete []arr;
        return path_exists;
    }

    // some self implemented functionalities
    // checking for presence of node
    bool nodeIsPresent(int node)
    {
        if (node >= n)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i][node] == 1)
                {
                    return 1;
                }
            }
            vector<bool> v1 = {0};
            if (v[node] == v1)
            {
                return 0;
            }
        }
    }

    // checking for presence of edge FROM A TO B
    bool edgeIsPresent(int a, int b)
    {
        if (v[a][b] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // inserting a new node or updating a previously existing node
    void insert(int node, vector<bool> v1)
    {
        if (node == n)
        {
            // v1 is the vector denoting connections from the new node TO other nodes
            v.push_back(v1);
            n++;
            // for connections FROM other nodes TO the node inserted
            for (int i = 0; i < n; i++)
            {
                bool b;
                cout << "edge from " << i << " to " << n - 1 << " [0/1]: ";
                cin >> b;
                v[i].push_back(b);
                // incrementing the number of edges if it exists FROM any one of the 2 nodes TO the other
                if (b == 1 || v[n - 1][i] == 1)
                {
                    m++;
                }
            }
        }
        else if (node < n)
        {
            v[node] = v1;
            for (int i = 0; i < n; i++)
            {
                bool b;
                cout << "edge from " << i << " to " << node << " [0/1]: ";
                cin >> b;
                v[i][node] = b;

                // incrementing the number of edges if it exists FROM any one of the 2 nodes TO the other
                if (b == 1 || v[node][i] == 1)
                {
                    m++;
                }
            }
        }
    }

    // deleting a node form the graph
    void delNode(int node)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][node] == 1)
            {
                v[i][node] = 0;
                m--; // decrementing the number of edges
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (v[node][i] == 1)
            {
                v[node][i] = 0;
                m--;
            }
        }
    }
};