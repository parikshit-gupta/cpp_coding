#include <vector>
using namespace std;

class graph
{
    int n; // number of nodes
    int m; // number of edges
    vector<vector<bool>> v;

public:
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

    //displaying the adjucency matrix
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

    //checking for presence of node
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

    //inserting a new node or updating a previously existing node
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
                cout << "edge from " << i << " to " << n-1 << " [0/1]: ";
                cin >> b;
                v[i].push_back(b);
                // incrementing the number of edges if it exists FROM any one of the 2 nodes TO the other
                if (b == 1 || v[n - 1][i] == 1)
                {
                    m++;
                }
            }
        }
        else if (node<n)
        {
            v[node] = v1;
            for (int i = 0; i < n; i++)
            {
                bool b;
                cout << "edge from " << i << " to " << node << " [0/1]: ";
                cin >> b;
                v[i][node]=b;
                
                // incrementing the number of edges if it exists FROM any one of the 2 nodes TO the other
                if (b == 1 || v[node][i] == 1)
                {
                    m++;
                }

            }
        }
    }

    //deleting a node form the graph
    void delNode(int node)
    {
        for (int i = 0; i < n; i++)
        {
            if(v[i][node]==1)
            {
                v[i][node] = 0;
                m--;//decrementing the number of edges
            }
        }

        for (int i=0;i<n;i++)
        {
            if(v[node][i]==1)
            {
                v[node][i]=0;
                m--;
            }
        }
    }
};