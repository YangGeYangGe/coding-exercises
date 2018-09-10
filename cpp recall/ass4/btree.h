//
// Created by GeYang on 27/9/17.
//
#include <iostream>
using namespace std;

#ifndef ASS4_BTREE_H
#define ASS4_BTREE_H
template <typename T>
class btree {
public:
    btree(size_t maxNodeElems = 40);
    btree(const btree<T>&);
    btree(btree<T>&&);
    btree<T>& operator=(const btree<T>&);
    btree<T>& operator=(btree<T>&&);
    friend ostream& operator<< <> (ostream&, const btree<T>&);
    // typedef’s for iterators and declarations
    // for begin(), end(), rbegin(), rend() and
    // cbegin(), cend(), crbegin() and crend() go here
    iterator find(const T&);
    const_iterator find(const T&) const;
    pair<iterator, bool> insert(const T&);
    // make sure your destructor does not leak memory
    // (if raw pointers are used)
    ~btree();
    private:
// your internal representation goes here

};
#endif //ASS4_BTREE_H
