
#pragma once

#include "bintree.h"

template <typename T> 
BinNode<T> *BinTree<T>::insertAsRoot ( T const& e )
{
    _size = 1;
    return _root = new BinNode<T> ( e );
} //将e当作根节点插入空的二叉树

template <typename T> 
BinNode<T> *BinTree<T>::insertAsLC ( BinNode<T> * x, T const& e )
{ 
    _size++; x->insertAsLC ( e ); 
    updateHeightAbove ( x ); 
    return x->lc; 
} //e插入为x的左孩子

template <typename T> 
BinNode<T> *BinTree<T>::insertAsRC ( BinNode<T> * x, T const& e )
{ 
    _size++; x->insertAsRC ( e ); 
    updateHeightAbove ( x ); 
    return x->rc; 
} //e插入为x的右孩子

template <typename T>
BinNode<T> *BinTree<T>::attachAsLC(BinNode<T> *x, BinTree<T> * &T)//T作为x左子树接入
{
    if( x->lc = T->_root) {
        x->lc->parent = x;
    }
    this->_size += S->_size;
    updatenHeightAbove(x);
}
template <typename T>
BinNode<T> *BinTree<T>::attachAsRC(BinNode<T> *x, BinTree<T> * &T)
{
    if( x->rc = T->_root) {
        x->rc->parent = x;
    }
    this->_size += S->_size;
    updatenHeightAbove(x);
}
template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x)
{
    return x->height = 1 + 
    (x->lc->height > x->rc->height ? x->lc->height : x->rc->height);
}

template <typename T>
void BinTree<T>::updatenHeightAbove (BinNode<T> *x)
{
    while(x)
    {
        updateHeight(x);
        x = x->parent;
    }
} 
