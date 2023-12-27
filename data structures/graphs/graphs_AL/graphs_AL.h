#include<unordered_map>
#include<vector>
using namespace std;

template<typename T>
class graph
{
    unordered_map<T, vector<T>> map;
    public:

    void addEdge(T u, T v, bool direction)
    {
        //direction==0: undirected graph
        //direction==1: directed graph
        map[u].push_back(v);
        /*map[u] refers to the vector corresponding to the node 'u', we are inserting a new node into
        that vector, thus creating a node directed from u to v*/

        if(direction==0)
        {
            map[v].push_back(u);
        }
    }
    
    void display()
    {
        unordered_map<int, vector<int>>::iterator it;
        it=map.begin();
        while(it!=map.end())
        {
            cout<<it->first<<": ";
            for (int i=0; i< (it->second).size();i++)
            {
                cout<< (it->second)[i]<<',';
            }
            cout<<endl;
            it++;
        }
    }
};