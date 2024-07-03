#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class graph
{
    

public:
    unordered_map<int, vector<int>> map;
    int n; // number of nodes
    int m; // number of edges

    graph(int n, int m) : n(n), m(m)
    {
        cout << "give three parameters for edge v1,v2,[1/0](directed/undirected edge from v1 to v2): ";
        for (int i = 0; i < m; i++)
        {
            
            int v1;
            int v2;
            bool v3; // 1 if edge should be directed
            cout<< "enter edge "<<i<<": ";
            cin >> v1 >> v2 >> v3;
            map[v1].push_back(v2);
            if (v1 == v2)
            {
                continue;
            }
            if (v3 == 0)
            {
                map[v2].push_back(v1);
            }
        }
    }

    // 1)BFS traversal
    void BFS_traversal(int start, bool *arr)
    {
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout<<front<<", ";
            vector<int> v = map[front];
            vector<int>::iterator Vit = v.begin();
            while (Vit != v.end())
            {
                if (arr[*Vit] == 0)
                {
                    q.push(*Vit);
                }
            }
        }
    }
    // helper function
    void BFS_traversal(int start)
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
        cout << start << ", ";
        BFS_traversal(start, arr);
        int count=1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                count++;
                BFS_traversal(i, arr);
            }
        }
    }

    //2) DFS traversal
    void DFS_traversal(int start, bool*arr)
    {
        vector<int>v=map[start];
        int len=v.size();
        for(int i=0;i<len;i++)
        {
            if(arr[v[i]]==0)
            {
                cout<<v[i]<<", ";
                arr[v[i]]=1;
                DFS_traversal(v[i],arr);
            }
        }
    }
    //helper function
    void DFS_traversal(int start)
    {
        if(map.count(start)==0)
        {
            cout<<"node not found"<<endl;
            return;
        }
        bool *arr=new bool[n];
        for(int i=0;i<n;i++)
        {
            if(i==start)
            {
                arr[i]=1;
            }
            else
            {
                arr[i]=0;
            }
        }

        cout<<start<<", ";
        DFS_traversal(start, arr);
        for (int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                DFS_traversal(i,arr);
            }
        }

    }


    void addEdge(int u, int v, bool direction)
    {
        // direction==0: undirected graph
        // direction==1: directed graph
        map[u].push_back(v);
        /*map[u] refers to the vector corresponding to the node 'u', we are inserting a new node into
        that vector, thus creating a node directed from u to v*/

        if (direction == 0)
        {
            map[v].push_back(u);
        }
    }

    void display()
    {
        unordered_map<int, vector<int>>::iterator it;
        it = map.begin();
        while (it != map.end())
        {
            cout << it->first << ": ";
            for (int i = 0; i < (it->second).size(); i++)
            {
                cout << (it->second)[i] << ',';
            }
            cout << endl;
            it++;
        }
    }
};