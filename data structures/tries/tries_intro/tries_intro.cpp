#include<iostream>
#include<cstdio>
#include"D:\Development\cpp_coding\data structures\tries\tries1\tries1.h"

using namespace std;

int main()
{
    trieNode*root=new trieNode();
    insert_word(root, "potty");
    insert_word(root, "ahemdabad");
    insert_word(root, "bikaner");
    insert_word(root, "haridwar");
    insert_word(root, "ayodhya");
    insert_word(root, "raipur");
    insert_word(root, "delhi");
    insert_word(root, "mandwi");
    insert_word(root, "tamilnadu");

    
    cout<<search_word(root, "ayodhyas")<<endl;
    cout<<search_word(root, "ahemdabad")<<endl;
    cout<<search_word(root, "haridwar")<<endl;
    cout<<search_word(root, "bizkaner")<<endl;
    cout<<search_word(root, "ahemdabad")<<endl;

    cout<<search_word(root, "ayodhya")<<endl;
    del_word(root, "ayop");
    del_word(root, "bikaner");
    cout<<search_word(root, "bikaner")<<endl;
    cout<<search_word(root, "ayodhya")<<endl;

    return 0;
}