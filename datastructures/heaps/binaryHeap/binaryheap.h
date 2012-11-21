/* max-heaps implementation in c++
 * copyright(c) 2012 hanson Yu
 *
 * implemention is according to this wiki: http://en.wikipedia.org/wiki/Binary_heap
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

class BinaryHeap
{
    private:
        std::vector<int> _heap;
        void _BuildHeap();
        void _ShiftDown(int index);
        void _ShiftUp(int index);

    public:
        BinaryHeap()
        {
        }
        ~BinaryHeap()
        {
        }
        BinaryHeap(int first, int last);
        void Insert(int val);
        int PopMax();
        int Max() { return _heap.front(); }
        unsigned int Count() { return _heap.size(); }
};

