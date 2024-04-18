#include<iostream>
using namespace std;

const int ALP_SIZE=26;

struct TrieNode{
    struct TrieNode * child[ALP_SIZE];
    bool endOfword;
};

// new trie node 

typedef struct TrieNode * trie;

trie getNode(void)
{
    trie pNode = new TrieNode;

    pNode->endOfword=false;

    for(int i=0;i<ALP_SIZE;i++)
    {
        pNode->child[i]=NULL;
    }

    return pNode;
}

// insert 
trie insert(trie root,string key)
{
    trie trav=root;
    for(int i=0;i<key.length();i++)
    {
        int idx=key[i]-'a';
        if(!trav->child[idx])
        trav->child[idx]= getNode();
        trav=trav->child[idx];
    }
    trav->endOfword=true;
}
bool search(trie root,string key)
{
    trie trav=root;
    for(int i=0;i<key.length();i++)
    {
        int idx=key[i]-'a';
        if(!trav->child[idx])
        return false;
        trav=trav->child[idx];
    }
    return (trav->endOfword);
}

int main()
{
    string keys[]={"hello","hey","hi","heya","hola"};

    int n=sizeof(keys)/sizeof(keys[0]);

    trie root=getNode();

    for(int i=0;i<n;i++)
    {
        insert(root,keys[i]);
    }

    cout<<search(root,"Hello, World!");

    return 0;
}