#ifndef BINNODE_H
#define BINNODE_H

template <typename T> struct BinNode
{
    T data;
    BinNode<T> *parent;
    BinNode<T> *lc;
    BinNode<T> *rc;
    int height;
    BinNode():
        parent(nullptr), lc(nullptr), rc(nullptr), height(0) {}
    BinNode(T d, BinNode<T> *p = nullptr, BinNode<T> *l = nullptr,
        BinNode<T> *r = nullptr,
        int h = 0):
        data(d), parent(p), lc(l), rc(r), h(h) {}
    int size();
    BinNode<T> *insertAsLC(T const&);
    BinNode<T> *insertAsRC(T const&);
    BinNode<T> *succ();//get succ (in order traversal)
    /*
        subtree traversal
    */
   bool operator< (BinNode const& bn){
       return data < bn.data;
   }
   bool operator==(BinNode<T> const& bn){
       return data == bn.data;
   }
//    BinNode<T> *zig();
//    BinNode<T> *zag();
//    BinNode<T> *balance();
//    BinNode<T> *imitate(const BinNode<T> *);
};
#endif