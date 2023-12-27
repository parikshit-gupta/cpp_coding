#include <string>
using namespace std;
class trieNode
{
public:
    char data;
    trieNode **children; // child array
    bool val;

public:
    trieNode()
    {
        data = '\0';
        val = 0;
        children = new trieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
    trieNode(char data, bool val)
    {
        children = new trieNode *[26];
        this->data = data;
        this->val = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
    ~trieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != NULL)
            {
                delete children[i];
            }
        }
        delete[] children;
    }

    // fucntion to check if the current trie node is a leaf node or not
    bool isLeafNode()
    {
        int c = 0;
        while (children[c] == NULL)
        {
            c++;
        }
        if (c == 26)
        {
            return true;
        }
        if (c < 26)
        {
            return false;
        }
    }
};

// inserting a word to a given root
void insert_word(trieNode *root, string s)
{
    if (root->val == 0)
    {
        root->val = 1;
    }
    int index = 0;
    trieNode *temp = root;
    for (int i = 0; i < s.length(); i++)
    {
        index = s[i] - 97; // calculating the index corresponding to every charecter of the string

        if (temp->children[index] != NULL)
        {
            // checking if the charecter is aldready a child of the current node or not
            temp = temp->children[index];
        }

        else if (temp->children[index] == NULL)
        {
            trieNode *new_node = new trieNode(s[i], 0);
            temp->children[index] = new_node;
            if (i == s.length() - 1)
            {
                new_node->val = 1;
            }
            temp = new_node;
        }
    }
}

bool search_word(trieNode *root, string s)
{
    trieNode *temp = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 97;
        if (temp->children[index] == NULL)
        {
            return false;
        }
        else if (temp->children[index] != NULL)
        {
            if ((i == s.length() - 1) && temp->children[index]->val == 1)
            {
                return true;
            }
        }
        temp = temp->children[index];
    }
    return false;
}

void del_word1(trieNode *root, string s)
{
    trieNode *temp = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 97;
        if (temp->children[index] == NULL)
        {
            cout << "word not found" << endl;
            cout << "index: " << char(index + 97) << endl;
            break;
        }

        if (temp->children[index] != NULL)
        {
            if (i == s.length() - 1) // we have reached the last letter of the given word
            {
                /*
                1)it is a leaf node
                    -deallocate the node
                    -update is parent's children array(place NULL at the index corresponding to that node)
                2)it is not a leaf node
                    -assign val=0
                */

                temp->children[index]->val = 0;
                int c = 1;
                // checking if the last letter of the given word is leaf node in the given trie
                // if it is a leaf node we deallocate its emory
                // if it is not a leaf node we just change the value of val to 0
                for (int j = 0; j < 26; j++)
                {
                    if (temp->children[index]->children[j] == NULL)
                    {
                        c++;
                        continue;
                    }
                    if (temp->children[index]->children[j] != NULL)
                    {
                        break;
                    }
                }
                if (c == 26)
                {
                    delete temp->children[index];
                }
            }
        }
        temp = temp->children[index];
    }
}

/*recursive deletion becomes imperitive because of the fact that once a leaf node is deallocated
there is a possibility that its parent node becomes a leaf ndoe aswell, and this chain could continue.
to improve memory efficiency we need to deallocate all those nodes, which is not possible iteratively
but can be easily implemented recursively*/

// recursive deletion of a word from a trie
void del_word(trieNode *root, string s)
{
    int index = s[0] - 97;
    // base case
    if (s.length() == 1)
    {
        if (root->children[index] == NULL)
        {
            cout << "word not found." << endl;
            cout << "index: " << char(index+97) << endl;
            return;
        }
        if (root->children[index] != NULL)
        {
            // checking if that child is a leaf node or not
            trieNode *temp = root->children[index];
            // temp is a leaf node
            if (temp->isLeafNode())
            {
                root->children[index] = NULL;
                delete temp;
            }
            if (!temp->isLeafNode())
            {
                temp->val = 0;
            }
        }
        return;
    }

    if (root->children[index] == NULL)
    {
        cout << "word not found." << endl;
        cout << "index: " << char(index+97) << endl;
        return;
    }

    if (root->children[index] != NULL)
    {
        string s1=s.substr(1);
        del_word(root->children[index], s1);
        if (root->children[index]->isLeafNode())
        {
            root->children[index] = NULL;
            delete root->children[index];
        }
    }
}

// printing the trie