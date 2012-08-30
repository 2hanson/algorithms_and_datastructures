/*
 * circular buffer implementation in C
 * copyright (c) 2012 Hanson Yu
 *
 * This implemenatation always keep a slot open 
 * to distinguish full/empty buffer.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//circular buffer element type.
typedef struct 
{
    int value; 
} ElemType;

//circular buffer object.
typedef struct
{
    int size; //maximum number of elements
    int start; //index of start elements
    int end; //index of end elements
    ElemType *elems; //vector of elements
} circularBuffer;

int cbufferInit(circularBuffer *cb, int size)
{
    cb->size = size + 1; //include the empty slot
    cb->start = 0;
    cb->end = 0;
    cb->elems = (ElemType *)calloc(cb->size, sizeof(ElemType));
    if (cb->elems == null)
        return 0;

    return 1;
}

void cbufferFree(circularBuffer *cb)
{
    free( cb->elems );
}

int cbufferIsFull(circularBuffer *cb)
{
    if (cb->start == (cb->end + 1) % (cb->size))
        return 1;

    return 0;
}

int cbufferIsEmpty(circularBuffer *cb)
{
    if (cb->start == cb->end)
        return 1;

    return 0;
}

//write an element, if buffer is full, overwrite the oldest
//element. one also can avoid overwrite by check isfull.
void cbufferWrite(circularBuffer *cb, ElemType *elem)
{
    cb->elems[cb->end] = *elem;
    cb->end = (cb->end + 1)%cb->size;
    if (cb->end == cb->start)
    {
        cb->start = (cb->start + 1) % cb->size; // full, overwrite
    }
}

//read the olders element, one must check not isempty() first.
void cbufferRead(circularBuffer *cb, ElemType *elem)
{
    *elem = cb->elems[cb->start];
    cb->start = (cb->start + 1) % cb->size;
}

int main()
{
    circularBuffer cb;
    ElemType elem = {0};

    int testBufferSize = 10; // test
    if (cbufferInit(&cb, testBufferSize) == 0)
        return -1;

    //fill buffer with elements.
    for (elem.value = 0; elem.value < 3 * testBufferSize; ++elem.value)
    {
        cbufferWrite(&cb, &elem);
    }

    //remove and print all elements.
    while (!cbufferIsEmpty(&cb))
    {
        cbufferRead(&cb, &elem);
        printf("%d\n", elem.value);
    }

    cbufferFree(&cb);

    return 0;
}

