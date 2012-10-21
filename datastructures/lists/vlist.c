/*
 * An implementation of vlist, it combines the fast indexing of arrays 
 * with the easy extension of singly linked lists.
 * for example. here is one possible VList holding six elements.
 *
 *      +------+    +------+     +------+
 *      | next | -->| next | --> | next | --> nil
 *      +------+    +------+     +------+
 * nil<-| pre  | <--| pre  | <-- | pre  |
 *      +------+    +------+     +------+
 *      | null |    |   2  |     |  0   |
 *      +------+    +------+     +------+
 *      |   5  |    |   1  |
 *      +------+    +------+
 *      |   4  |
 *      +------+
 *      |   3  |
 *      +------+
 *
 * each column represents a linked list cell containing a fix size of array.
 * the size of array in the nth column from the end is 2^n. in this manner.
 * for a uniformly-randomly chosen position, the expected time to look up that
 * element is O(1), though in the worst case is O(log n). this random access is
 * significantly better than linked list, but in the worst cast is not good as
 * dynamic array.
 *
 * @author Hanson Yu (hangzhong.yu@gmail.com)
 * */
#include <stdlib.h>
#include <stdio.h>

const int INF = 2147483647 /* maximum (signed) int value */;

//vlist column
typedef struct BLOCK
{
    struct BLOCK *pre;
    struct BLOCK *next;
    int *elems;
    int index;
    int size;
}vlistBlock;

void vlistInit(vlistBlock *head, int size)
{
    vlistBlock *cur;
    int cursize = 1;
    while (size > 0)
    {
        cur = (vlistBlock *)malloc(sizeof(vlistBlock));
        cur->elems = (int *)malloc(sizeof(cursize));
        
        cur->pre = NULL;
        cur->next = NULL;
        if (size == 1)
        {
            head = cur;
        }
        else
        {
            head->pre = cur;
            cur->next = head;

            head = cur;
        }

        cur->index = cur->size = cursize;
        size -= cursize;
        cursize *= 2;
    }

    //size if negtive num, as an example, size is -1, curcize is 4.
    //they should set index to -1 + 4,
    cur->index = curzise + size; 
}

/* Locate the kth element (O(1) average, O(log n) worst-case)
 * @param elem
 *      the index at which to look up the element.
 * @param elem
 *      the element at the position.
 * */
int locate(vlistBlock *head, int index)
{
    //here is a bug!!!
    if (head == NULL)
        return -INF;
    
    int curIndex = index;

    while (head != NULL)
    {
        if (curIndex > head.index)
        {
            curIndex -= head.index;
        }
        else
        {
            return head->elems[curindex];
        }
        head = head->next;
    }

    return -INF;
}

/*
 * Compute the length of the list (O(log n)).
 */
int computeLen(vlistBlock *head)
{
    if (head == NULL)
    {
        return 0;
    }
    
    int len = 0;
    while (head != NULL)
    {
        ++len;
        head = head->next;
    }

    return len;
}

vlistBlock* allocBlock(int size)
{    
        vlistBlock *cur;
        int cursize = size;
        cur = (vlistBlock *)malloc(sizeof(vlistBlock));
        cur->elems = (int *)malloc(sizeof(cursize));
        
        cur->size = size;
}

/* Add an element to the front of the VList (O(1) average, with an occasional allocation)
 * @param elem
 *      the element to add.
 * */
void add(vlistBlock *head, int value)
{
    if (head == NULL)
    {
        
        vlistBlock *cur;
        int cursize = 1;
        cur = allocBlock(cursize);
        cur->pre = NULL;
        cur->next = NULL;
        head = cur;

        cur->index = 1;
    }
    else if (head->index > head->size)
    {
        vlistBlock *cur;
        int cursize = 2*head->size;
        cur = allocBlock(cursize);

        cur->pre = NULL;
        cur->next = head->next;
        head->pre = cur;
        head = cur;

        cur->index = 1;
    }

    head->elems[index] = value;
    ++head->index;
}

int main()
{
    vlistBlock head;

    vlistInit(&head, 1);
    return 0;
}

