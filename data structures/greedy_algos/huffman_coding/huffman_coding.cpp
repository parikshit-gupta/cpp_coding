#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "D:\Development\cpp_coding\data structures\binary_trees\binary_trees1\binary_trees1.h"
using namespace std;

/*
right now we will convert strings containing only lowercase charecters to their respective huffman code
TODO later on:
1) extend this function to operate on a text file
2) create a seperate class which creates an object that operates on the file
*/

class triplet
{
public:
    pair<char, int> tp;
    binaryTree_node<pair<char, int>> *node;

    triplet(pair<char, int> p)
    {
        tp = p;
        node = NULL;
    }

    triplet(pair<char, int> p, binaryTree_node<pair<char, int>> *node)
    {
        tp = p;
        this->node = node;
    }
};

// comparison class for min priority queue
class compare
{
public:
    bool operator()(triplet a, triplet b)
    {
        return a.tp.second >= b.tp.second;
    }
};

void print_binTree12(binaryTree_node<pair<char,int>> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<binaryTree_node<pair<char,int>> *> q;
    q.push(root);
    while (!q.empty())
    {
        binaryTree_node<pair<char,int>> *front = q.front();
        q.pop();
        cout << "char: "<<front->data.first <<", int: "<<front->data.second<< ": ";
        if (front->left != NULL)
        {
            cout << "L: " << "char: "<<front->left->data.first <<", int: "<<front->left->data.second<< " ";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R: " << "char: "<<front->right->data.first <<", int: "<<front->right->data.second;
            q.push(front->right);
        }
        cout << endl;
    }
}


// 1)count frequency
unordered_map<char, int> frequency_table(string s)
{
    unordered_map<char, int> freq_map;
    for (int i = 0; i < s.length(); i++)
    {
        if (freq_map.count(s[i]) == 0)
        {
            pair<char, int> p1(s[i], 1);
            freq_map.insert(p1);
        }
        else if (freq_map.count(s[i]) == 1)
        {
            pair<char, int> p1(s[i], ++freq_map.at(s[i]));
            freq_map.insert(p1);
        }
    }
    return freq_map;
}

// 3)creating the binary prefix tree
binaryTree_node<pair<char, int>> *convert_to_tree(priority_queue<triplet, vector<triplet>, compare> pq)
{
    while (pq.size() > 1)
    {
        triplet t1 = pq.top();
        pq.pop();
        triplet t2 = pq.top();
        pq.pop();
        /*clearly t2>t1, we will create intermediate nodes such that to their left is the pair with
        the lower value of frequency*/
        if (t1.tp.first != '\0' && t2.tp.first != '\0')
        {
            binaryTree_node<pair<char, int>> *node1 = new binaryTree_node<pair<char, int>>(t1.tp);
            binaryTree_node<pair<char, int>> *node2 = new binaryTree_node<pair<char, int>>(t2.tp);
            pair<char, int> p3 = {'\0', (t1.tp.second + t2.tp.second)};
            binaryTree_node<pair<char, int>> *node3 = new binaryTree_node<pair<char, int>>(p3);
            node3->left = node1;
            node3->right = node2;
            triplet t3(p3, node3);
            pq.push(t3);
        }

        /*first element popped is an intermediate node
        second element poped is a leaf node*/
        else if (t1.tp.first == '\0' && t2.tp.first != '\0')
        {
            binaryTree_node<pair<char, int>> *node2 = new binaryTree_node<pair<char, int>>(t2.tp);
            pair<char, int> p3 = {'\0', (t1.tp.second + t2.tp.second)};
            binaryTree_node<pair<char, int>> *node3 = new binaryTree_node<pair<char, int>>(p3);
            node3->left = t1.node;
            node3->right = node2;
            triplet t3(p3, node3);
            pq.push(t3);
        }

        else if (t1.tp.first != '\0' && t2.tp.first == '\0')
        {
            binaryTree_node<pair<char, int>> *node1 = new binaryTree_node<pair<char, int>>(t1.tp);
            pair<char, int> p3 = {'\0', (t1.tp.second + t2.tp.second)};
            binaryTree_node<pair<char, int>> *node3 = new binaryTree_node<pair<char, int>>(p3);
            node3->left = node1;
            node3->right = t2.node;
            triplet t3(p3, node3);
            pq.push(t3);
        }

        else if (t1.tp.first == '\0' && t2.tp.first == '\0')
        {
            pair<char, int> p3 = {'\0', (t1.tp.second + t2.tp.second)};
            binaryTree_node<pair<char, int>> *node3 = new binaryTree_node<pair<char, int>>(p3);
            node3->left = t1.node;
            node3->right = t2.node;
            triplet t3(p3, node3);
            pq.push(t3);
        }
    }

    binaryTree_node<pair<char, int>> *root = pq.top().node;
    pq.pop();
    return root;
}

// 4) creating the prefix table by traversing the binary tree
void prefix_table(binaryTree_node<pair<char, int>> *root, string s, unordered_map<char, string> &prefix_map)
{
    /*
    left: 0
    right: 1
    */
    if (root->left == NULL && root->right == NULL)
    {
        prefix_map.insert({(root->data.first), s});
        return;
    }

    s.push_back('0');
    prefix_table(root->left, s, prefix_map);
    s.pop_back();

    s.push_back('1');
    prefix_table(root->right, s, prefix_map);
    s.pop_back();
}


// main function which returns the compressed code along with the prefix code table
pair<string, unordered_map<char, string>> compressed_code(string s)
{
    /*
    1) count frequency
    2) create min PQ according to the frequency table
    3) create a binary prefix tree
    4) trqaverse the binary tree from root to each leaf node
    5) create a hashmap to store the code for each charecter
    6) replace charecters in the original string

    ISSUES(fixed):
    1) extracting values from PQ and inserting to binary tree:
    -there will be two types of values in the priority queue at any given instant, first those corresponding to a
     charecter and second the sum of frequencies of two charecters
    -first ones will be leaf nodes, and second ones will be intermediate nodes
    -these two nodes need to be distinguished
    */

    // this freq_map stores the occurence frequency of every charecter
    unordered_map<char, int> freq_map = frequency_table(s);

    // 2)create min priority queue
    //  min priority queue which compares the elements on basis of the second element of its pairs
    priority_queue<triplet, vector<triplet>, compare> pq;
    unordered_map<char, int>::iterator it = freq_map.begin();
    for (it; it != freq_map.end(); it++)
    {
        //cout<<"char: "<<it->first<<", frequency: "<<it->second<<endl;
        pair<char, int> p1 = *it;
        triplet t1(p1);
        pq.push(t1);
    }

    // creating the binary tree
    binaryTree_node<pair<char, int>> *root = convert_to_tree(pq);
    //print_binTree12(root);
    // traversing the tree, simultaneously creating a hashmap to store the new bit codes of charecters
    unordered_map<char, string> prefix_map;
    string s1 = "o";
    s1.pop_back();
    prefix_table(root, s1, prefix_map);
    delete root; // deleting the prefix_tree

    for (int i = 0; i < s.length(); i++)
    {
        string s2 = prefix_map.at(s[i]);
        s1 = s1 + s2;
    }
    pair<string, unordered_map<char, string>> final_pair = {s1, prefix_map};
    return final_pair;
}

int main()
{
    string s = "ccccfffggjsfnfsjn!!sdkjnvdkggeii";
    pair<string, unordered_map<char, string>> p1 = compressed_code(s);
    cout << p1.first << endl;
    unordered_map<char, string>::iterator it = p1.second.begin();
    for (it; it != p1.second.end(); it++)
    {
        cout << "char: " << it->first << ", code: " << it->second << endl;
    }
    return 0;
}