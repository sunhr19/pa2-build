#ifndef BINTREE_H
#define BINTREE_H
#include "binnode.h"

template<typename T> class BinTree
{
protected:
    int _size;
    BinNode<T> *_root;
    virtual int updateHeight(BinNode<T> *x);
    void updatenHeightAbove(BinNode<T> *x);
public:
    BinTree():_size(0), _root(nullptr){}
    ~BinTree()
    {
        if(0 < _size){
            remove(_root);
        }
    }
    int size() const {return _size;}
    bool empty() const {return !_root;}
    BinNode<T> *root() const {return _root;}
    BinNode<T> *insertAsRoot(T const& e);
    BinNode<T> *insertAsLC(BinNode<T> *x, T const& e);
    BinNode<T> *insertAsRC(BinNode<T> *x, T const& e);
    BinNode<T> *attachAsLC(BinNode<T> *x, BinTree<T> * &T);//T作为x左子树接入
    BinNode<T> *attachAsRC(BinNode<T> *x, BinTree<T> * &T);
    int remove(BinNodePosi(T) x);
    // BinTree<T> *secede(BinNode<T> *x);
    // template <typename VST> //操作器
    // void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); } //层次遍历
    // template <typename VST> //操作器
    // void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); } //先序遍历
    // template <typename VST> //操作器
    // void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); } //中序遍历
    // template <typename VST> //操作器
    // void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); } //后序遍历
    bool operator< ( BinTree<T> const& t ) //比较器（其余自行补充）
    { return _root && t._root && lt ( _root, t._root ); }
    bool operator== ( BinTree<T> const& t ) //判等器
    { return _root && t._root && ( _root == t._root ); }

};

#endif