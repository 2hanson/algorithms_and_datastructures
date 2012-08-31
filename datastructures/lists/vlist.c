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
