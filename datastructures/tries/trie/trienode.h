#ifndef TRIENODEH
#define TRIENODEH

#include <string>
#include <iostream>
#define TREEWIDTH 256

class TrieNode
{
    public:
        int count;
        TrieNode* next[TREEWIDTH];
        TrieNode()
        {   
            count = 0;
            memset(next, NULL, sizeof(next));
        } 
};
#endif

