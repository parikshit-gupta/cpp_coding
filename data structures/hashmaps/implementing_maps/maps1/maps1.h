#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T val;
    node *next;

    node()
    {
        next = NULL;
    }
    node(string key, T val)
    {
        next = NULL;
        this->key = key;
        this->val = val;
    }

    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class pair1
{
public:
    node<T> *head;
    node<T> *tail;

    pair1()
    {
        head = NULL;
        tail = NULL;
    }

    ~pair1()
    {
        delete head;
    }
};

template <typename T>
class map
{
    /*since we are to implement rehashing now we will have to create our bucket array on heap memory
    pair1<T> arr[20];
    int size;
    */  

    pair1<T>* arr;
    int size;//total number of elements
    int bucket_size;//size of the underlying array
    float load_factor;

    // hash function
    int hash(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum = sum + ((97 + key[i]) * pow(31, i));
        }
        int index = sum % bucket_size;
        return index;
    }

    void rehash()
    {
        int old_bucket_size=bucket_size;
        bucket_size=bucket_size*2;
        pair1<T>*re_arr=new pair1<T>[bucket_size];
        for (int i=0; i<old_bucket_size;i++)
        {
            if (arr[i].head==NULL)
            {
                continue;
            }
            else
            {
                node<T>* temp=arr[i].head;
                while(temp!=NULL)
                {
                    int index=hash(temp->key);
                    if (re_arr[index].head==NULL)
                    {
                        node<T>*new_node=new node<T>(temp->key,temp->val);
                        re_arr[index].head=new_node;
                        re_arr[index].tail=new_node;
                    }
                    if (re_arr[index].head!=NULL)
                    {
                        node<T>*new_node=new node<T>(temp->key,temp->val);
                        re_arr[index].tail->next=new_node;
                        re_arr[index].tail=new_node;
                    }
                }
            }
        }
        delete[] arr;
        arr=re_arr;
        //TODO modify the insert function of the map
        //TODO destructor of map;
    }

public:
    map()
    {
        size=0;
        bucket_size=5;
        arr=new pair1<T>[bucket_size];
        load_factor=(float)size/bucket_size;
        /*
        for (int i = 0; i < 20; i++)
        {
            pair1<T> p1;
            arr[i] = p1;
            size = 0;
        }
        */
    }

    // inserting a key
    void insert(string key, T val)
    {
        if(load_factor>0.7)
        {
            rehash();
        }
        int index = hash(key);
        node<T>*temp=arr[index].head;
        if (arr[index].head == NULL)
        {
            node<T> *new_node = new node<T>(key, val);
            arr[index].head = new_node;
            arr[index].tail = new_node;
            size++;
            cout<<key<< " : key inserted succesfully."<<endl;
            return;
        }

        while(temp!=NULL)
        {
            if (temp->key==key)
            {
                temp->val=val;
                cout<<key<<" : key updated succesfully."<<endl;
                return;
            }
            temp=temp->next;
        }

        if (arr[index].head != NULL)
        {
            node<T> *new_node = new node<T>(key, val);
            arr[index].tail->next = new_node;
            arr[index].tail = new_node;
            size++;
            cout<<key<<" : key inserted succesfully."<<endl;
            return;
        }
    }

    // searching for a key
    T search(string key)
    {
        // the compiler detects the datatype at runtime using the auto keyword
        int index = hash(key);
        auto x = 0;
        if (arr[index].head == NULL)
        {
            return x;
        }
        if (arr[index].head != NULL)
        {
            node<T> *temp = arr[index].head;
            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    return temp->val;
                }
                temp = temp->next;
            }
            return x;
        }
    }

    // deleting a key
    void del(string key)
    {
        int index = hash(key);
        if (arr[index].head == NULL)
        {
            cout << "key not found." << endl;
            return;
        }
        if (arr[index].head != NULL)
        {
            node<T> *temp = arr[index].head;
            node<T> *temp_next = temp;
            while (temp_next != NULL)
            {
                if (temp_next->key == key)
                {
                    if (temp_next == arr[index].head)
                    {
                        if (temp_next->next == NULL)
                        {
                            arr[index].head = NULL;
                            arr[index].tail = NULL;
                            delete temp_next;
                            size--;
                        }
                        else
                        {
                            arr[index].head = temp_next->next;
                            temp_next->next = NULL;
                            delete temp_next;
                            size--;
                        }
                        cout<<key<<" : key deleted succesfully."<<endl;
                        return;
                    }

                    if (temp_next == arr[index].tail)
                    {
                        arr[index].tail = temp;
                        temp->next = NULL;
                        delete temp_next;
                        size--;
                        cout<<key<<" : key deleted succesfully."<<endl;
                        return;
                    }
                    else
                    {
                        temp->next = temp_next->next;
                        temp_next->next = NULL;
                        delete temp_next;
                        size--;
                        cout<<key<< " : key deleted succesfully."<<endl;
                        return;
                    }
                }
                temp = temp_next;
                temp_next = temp_next->next;
            }
            cout << "key not found." << endl;
        }
    }

    ~map()
    {
        delete[] arr;
    }
};