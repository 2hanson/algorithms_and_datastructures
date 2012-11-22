#include "trie.h"

void Trie::Insert(char* word)
{
    if ('\0' == word[0])
        return;

    TrieNode* cur = root;
    for (int index = 0; ; ++index)
    {
        if ('\0' == word[index])
            break;

        if (NULL == cur->next[ word[index] ])
        {
            TrieNode* newNode = new TrieNode();

            cur->next[ word[index] ] = newNode;
        }

        cur = cur->next[ word[index] ];
    }

    ++cur->count;
}

void Trie::Travel()
{
    char* word = (char*)malloc(1000*sizeof(char));
    word[0] = '\0';
    //DoTravel(root, word, index);
    DoTravel(root, word, 0);
}

void Trie::DoTravel(TrieNode* cur, char* word, int index)
{
    if (NULL == cur)
        return;
    
    if (0 != cur->count)
    {
        PrintWord(word, cur->count);
    }
    //#define TREEWIDTH 256
    for (int i = 0; i < TREEWIDTH; ++i)
    {
        word[index] = i;
        ++index;
        word[index] = '\0';

        DoTravel(cur->next[i], word, index);
        --index;
        word[index] = '\0';
    }
}

void Trie::PrintWord(char* word, int count)
{
    printf("%s\t%d\n", word, count);
}

int main()
{}
