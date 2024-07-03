#include<iostream>
#include<cstdio>
using namespace std;

class disjoint_set
{
    int *parent;
    int *rank;
    int *size_arr;
    int size;

    public:
    disjoint_set(int size)
    {
        rank =new int[size];
        parent =new int[size];
        for(int i=0;i<size;i++)
        {
            rank[i]=0;
            size_arr[i]=0;
            parent[i]=i;
        }
        this->size =size;
    }

    int find_parent(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        int temp=find_parent(parent[node]);
        parent[node]=temp;
        return temp;
    }

    void Unionbyrank(int u, int v)
    {
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);

        if(ulp_v==ulp_u) return;
        if(rank[ulp_u]>rank[ulp_v]) 
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]==rank[ulp_v])
        {
           parent[ulp_u]=ulp_v;
           rank[ulp_v]++;
        }
        else if (rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
    }

    void Unionbyrsize(int u, int v)
    {
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);

        if(ulp_v==ulp_u) return;
        if(size_arr[ulp_u]>size_arr[ulp_v]) 
        {
            parent[ulp_v]=ulp_u;
        }
        else if(size_arr[ulp_u]==size_arr[ulp_v])
        {
           parent[ulp_u]=ulp_v;
           size_arr[ulp_v]++;
        }
        else if (size_arr[ulp_u]<size_arr[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
    }
    ~disjoint_set()
    {
        delete []rank;
        delete []size_arr;
        delete []parent;
    }

};

int main()
{
    cout<<"hello"<<endl;
    disjoint_set ds(8);
    ds.Unionbyrsize(1,2);
    ds.Unionbyrsize(2,3);
    ds.Unionbyrsize(4,5);
    ds.Unionbyrsize(6,7);
    ds.Unionbyrsize(5,6);
    if(ds.find_parent(3)==ds.find_parent(7))
    {
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    ds.Unionbyrsize(3,7);
    
    if(ds.find_parent(3)==ds.find_parent(7))
    {
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}

