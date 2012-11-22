/* trie implementation in c++
 * copyright(c) 2012 hanson Yu
 *
 * implemention is according to this wiki: http://en.wikipedia.org/wiki/Trie 
 */
#ifndef TRIEH
#define TRIEH
#include "trienode.h"

class Trie
{
    private:
        TrieNode* root;
        void PrintWord(char* word, int count);

    public:
        Trie()
        {}
        void Insert(char* word);
        void DoTravel(TrieNode* cur, char* word, int index);
        void Travel();
};

#endif
