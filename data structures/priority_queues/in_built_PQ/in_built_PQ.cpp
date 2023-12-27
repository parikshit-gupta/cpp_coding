#include<iostream>
#include<queue>
using namespace std;

//the compare class on what basis the elements of the priority queue are compared/arranged
class compare
{
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    priority_queue<int> pq;//creates an in-built max priority queue object
    priority_queue<int, vector<int> ,greater<int>> pq2;//creates an in-built min PQ
    //all other operations demonstrated in k smallest and k largest questions

    
    //min priority queue consisting of pairs, compared on the basis of their first element
    priority_queue<pair<int,char>, vector<pair<int,char>>,greater<pair<int,char>>> pq1;
    
    //min priority queue consisting of pairs, compared on the basis of their second element
    priority_queue<pair<char,int>, vector<pair<char,int>>,compare> pq2;

    pair<int,char> p(1, 'a');
    pq1.push(p);
    p=pair<int,char>(2, 'b');
    pq1.push(p);
    p=pair<int,char>(3, 'c');
    pq1.push(p);
    p=pair<int,char>(4, 'd');
    pq1.push(p);
    p=pair<int,char>(5, 'e');
    pq1.push(p);
    p=pair<int,char>(6, 'f');
    pq1.push(p);

    p=pq1.top();
    cout<<p.first<<": "<<p.second<<endl;
}

