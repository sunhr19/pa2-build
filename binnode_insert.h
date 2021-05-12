#ifndef BINNODE_INSERT_H
#define BINNODE_INSERT_H
#include "binnode.h"

template <typename T>
BinNode<T> *BinNode<T>::insertAsLC(T const& d)
{
    return lc = new BinNode(d, this);
}

template <typename T>
BinNode<T> *BinNode<T>::insertAsRC(T const& d)
{
    return rc = new BinNode(d, this);
}

#endif