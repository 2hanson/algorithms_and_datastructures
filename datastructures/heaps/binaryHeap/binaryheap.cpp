#include "binaryheap.h"

BinaryHeap::BinaryHeap(int first, int last)
{
    if (last < first)
        return;

    _heap.reserve((last-first+1));
    for (int val = frist; val <= last; ++val)
    {
        _heap.push_back(val);    
    }

    _BuildHeap();
}

void BinaryHeap::Insert(int val)
{
    _heap.push_back(val);

    _ShiftUp(_heap.size()-1);
}

int BinaryHeap::PopMax()
{
    int ret = _heap.front();
    _heap.front = _heap.back();
    _heap.pop_back();
    _ShiftDown(0);

    return ret;
}

int BinaryHeap::Max()
{
    int ret = _heap.front();

    return ret;
}

void BinaryHeap::_BuildHeap()
{
    //The number of internal nodes (non-leaf nodes) in a Complete Binary Tree of n nodes is floor(n/2)
    for (int index = _heap.size()/2 - 1/*minus 1 because index from 0*/; index>=0; --index)
    {
        _ShiftDown(index);
    }
}

void BinaryHeap::_ShiftDown(int index)
{
    int leftChild = index*2 + 1;
    int rightChild = index*2 + 2;
    int replaceIndex = index;

    if (rightChild < _heap.size())
    {
        bool isLeft = _heap[rightChild] < _heap[leftChild];

        if (isLeft && _heap[replaceIndex] < _heap[leftChild])
        {
            replaceIndex = leftChild;
        }
        else if (!isLeft && _heap[replaceIndex] < _heap[rightChild])
        {
            replaceIndex = rightChild;
        }
    }
    else if (leftChild < _heap.size())
    {
        if (_heap[replaceIndex] < _heap[leftChild])
        {
            replaceIndex = leftChild;
        }
    }

    if (replaceIndex == index)
        return;

   std::swap(_heap[replaceIndex], _heap[index]);
   _ShiftDown(replaceIndex);
}

void BinaryHeap::_ShiftUp(int index)
{
   if (0 == index)
       return;
    
   int parent = (index-1)/2;
   if (_heap[parent] > _heap[index])
       return;

   std::swap(_heap[parent], _heap[index]);
   _ShiftUp(parent);
}

