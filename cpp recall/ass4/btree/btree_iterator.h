#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

#include <iterator>
#include <algorithm>
#include <iostream>
#include "btree.h"

/**
 * btree_iterator and const_btree_iterator implementations.
 *
 * Will allow in-order (from lowest to highest) traversal through a btree.
 * Internally, the iterator uses a map<T, Element> iterator in addition with a currend 'node' and didTraverse bool to indicate an upwards traversal.
 *
*/

template <typename T> class btree;
template <typename T> class const_btree_iterator;
//asdasd
 
template <typename T>
class btree_iterator {
public:
    friend class const_btree_iterator<T>;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;

    typedef ptrdiff_t difference_type;

    btree_iterator(typename btree<T>::Node* node, typename std::vector<typename btree<T>::Element>::iterator it):node(node), it(it){};

    btree_iterator<T>& operator=(const btree_iterator<T>&);

    reference operator*() const;
    pointer operator->() const {
        return &(operator*());
    }

    bool operator==(const btree_iterator<T>& it) const;
    bool operator!=(const btree_iterator<T>& it) const {
        return !operator==(it);
    };


    //
    // current < rightchild node < current right < parent
    btree_iterator<T>& operator++();//pre
    btree_iterator<T>& operator++(int);//post

    //current > leftchild node > current left > parent
    btree_iterator<T>& operator--();//pre
    btree_iterator<T>& operator--(int);//post


private:
    //Store a current node as well as a map iterator
    //This will be the underlying implementation of our iterator
    typename btree<T>::Node *node;
    typename std::vector<typename btree<T>::Element>::iterator it;

    void firstgreaterthan(typename btree<T>::Node *&current, typename std::vector<typename btree<T>::Element>::iterator& i);

};

template <typename T>
class const_btree_iterator{
public:
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef const T* pointer;
    typedef const T& reference;
    //btree_iterator -> const_btree_iterator
    const_btree_iterator(btree_iterator<T>& i) : const_btree_iterator(i.node, i.it) {};
    const_btree_iterator(const typename btree<T>::Node* node, typename std::vector<typename btree<T>::Element>::const_iterator it):node(node), it(it){};

    const_btree_iterator& operator=(const const_btree_iterator<T>&);
    reference operator*() const;
    pointer operator->() const {
        return &(operator*());
    }

    bool operator==(const const_btree_iterator<T>& it) const;
    bool operator!=(const const_btree_iterator<T>& it) const {
        return !operator==(it);
    };

    //
    // current < rightchild node < current right < parent
    const_btree_iterator<T>& operator++();//pre
    const_btree_iterator<T>& operator++(int);//post

    //current > leftchild node > current left > parent
    const_btree_iterator<T>& operator--();//pre
    const_btree_iterator<T>& operator--(int);//post


private:
    //Store a current node as well as a map iterator
    //This will be the underlying implementation of our iterator
    const typename btree<T>::Node *node;
    typename std::vector<typename btree<T>::Element>::const_iterator it;

    void firstgreaterthan(const typename btree<T>::Node *&current, typename std::vector<typename btree<T>::Element>::const_iterator& i);
};



template <typename T>
btree_iterator<T>& btree_iterator<T>::operator=(const btree_iterator<T>& other) {
    node = other.node;
    it = other.it;
    return *this;

}

template <typename T>
const_btree_iterator<T>& const_btree_iterator<T>::operator=(const const_btree_iterator<T>& other) {
    //Set iterator fields
    node = other.node;
    it = other.it;
    return *this;
}

template <typename T>
T& btree_iterator<T>::operator*() const {
    //return node->elements[0].value;
    return it->value;
}

template <typename T>
bool btree_iterator<T>::operator==(const btree_iterator<T>& it) const {


    return (this->node == it.node && this->it == it.it);
}

template <typename T>
btree_iterator<T>& btree_iterator<T>::operator++() {
    //current 'node', current 'it'
    if(it->rightChild != nullptr){
        // node = it->rightChild;
        // it = node->elements.begin();
        typename btree<T>::Node *temp_node = it->rightChild;
        while(temp_node->elements.begin()->leftChild != nullptr){
            temp_node = temp_node->elements.begin()->leftChild;            
        }

        node = temp_node;
        it = node->elements.begin();

    } else{
        firstgreaterthan(node, it);
    }
    return *this;
}


template <typename T>
btree_iterator<T>& btree_iterator<T>::operator++(int) {
    btree_iterator<T> *temp = new btree_iterator<T>(node, it);
    ++(*this);
    return *temp;

}
template <typename T>
void btree_iterator<T>::firstgreaterthan(typename btree<T>::Node *&current,
                                      typename std::vector<typename btree<T>::Element>::iterator& i) {
    auto up = current->elements.begin();
    for(; up != current->elements.end(); ++up){
        if(up->value > i->value){
            break;
        }
    }
    //std::cout << current->elements[0].value <<"testing current \n";
    if(up == current->elements.end()){
        //std::cout << current->elements[0].value <<"testing current \n";
        if(current->parent != nullptr){
            current = current->parent;
            firstgreaterthan(current, i);
        } else {
            i = current->elements.end();
        }
    } else {
       // std::cout << up->value <<"in function \n";
        i = up;
    }

}


template <typename T>
btree_iterator<T>& btree_iterator<T>::operator--() {
    //current 'node', current 'it'
    //end()
    if(node->parent == nullptr && it == node->elements.end()){
        --it;
        while(it->rightChild != nullptr){
            node = it->rightChild;
            it = --(node->elements.end());
        }
    }else if(it->leftChild != nullptr){
        // //has leftchild
        // node = it->leftChild;
        // it = --(node->elements.end());


        typename btree<T>::Node *temp_node = it->leftChild;
        while( ( --(temp_node->elements.end()) )->rightChild != nullptr){
            temp_node = ( --(temp_node->elements.end()) )->rightChild;            
        }

        node = temp_node;
        it = --(node->elements.end());

    }else if(it != node->elements.begin()){
        //no leftchild, but has left element in node
        --it;

    } else if(node->parent != nullptr){
        //
        if(node->parent->elements[0].value < it->value){
            node = node->parent;

            auto temp_it = --(node->elements.end());
            for(;temp_it >= node->elements.begin(); --temp_it){
                if(temp_it->value < it->value){
                    it = temp_it;
                    break;
                }
            }
        }
    }
    return *this;
}

template <typename T>
btree_iterator<T>& btree_iterator<T>::operator--(int) {
    btree_iterator<T> *temp = new btree_iterator<T>(node, it);
    --(*this);
    return *temp;
}




/////////////////////////////////////////////////////
template <typename T>
const T& const_btree_iterator<T>::operator*() const {
    //return node->elements[0].value;
    return it->value;
}


template <typename T>
bool const_btree_iterator<T>::operator==(const const_btree_iterator<T>& it) const {
    return (this->node == it.node && this->it == it.it);
}



template <typename T>
const_btree_iterator<T>& const_btree_iterator<T>::operator++() {
    //current 'node', current 'it'
    if(it->rightChild != nullptr){

        // node = it->rightChild;
        // it = node->elements.begin();

        const typename btree<T>::Node *temp_node = it->rightChild;

        while(temp_node->elements.begin()->leftChild != nullptr){
            temp_node = temp_node->elements.begin()->leftChild;            
        }

        node = temp_node;
        it = node->elements.begin();

    } else{
        firstgreaterthan(node, it);
    }
    return *this;
}

template <typename T>
void const_btree_iterator<T>::firstgreaterthan(const typename btree<T>::Node *&current,
                                         typename std::vector<typename btree<T>::Element>::const_iterator& i) {
    auto up = current->elements.begin();
    for(; up != current->elements.end(); ++up){
        if(up->value > i->value){
            break;
        }
    }
    //std::cout << current->elements[0].value <<"testing current \n";
    if(up == current->elements.end()){
        //std::cout << current->elements[0].value <<"testing current \n";
        if(current->parent != nullptr){
            current = current->parent;
            firstgreaterthan(current, i);
        } else {
            i = current->elements.end();
        }
    } else {
        // std::cout << up->value <<"in function \n";
        i = up;
    }

}

template <typename T>
const_btree_iterator<T>& const_btree_iterator<T>::operator++(int) {
    const_btree_iterator<T> *temp = new const_btree_iterator<T>(node, it);
    ++(*this);
    return *temp;

}

template <typename T>
const_btree_iterator<T>& const_btree_iterator<T>::operator--() {
    //current 'node', current 'it'
    //end()
    if(node->parent == nullptr && it == node->elements.end()){
        --it;
        while(it->rightChild != nullptr){
            node = it->rightChild;
            it = --(node->elements.end());
        }
    }else if(it->leftChild != nullptr){
        //has leftchild
        // node = it->leftChild;
        // it = --(node->elements.end());

        const typename btree<T>::Node *temp_node = it->leftChild;
        while( ( --(temp_node->elements.end()) )->rightChild != nullptr){
            temp_node = ( --(temp_node->elements.end()) )->rightChild;            
        }

        node = temp_node;
        it = --(node->elements.end());

    }else if(it != node->elements.begin()){
        //no leftchild, but has left element in node
        --it;

    } else if(node->parent != nullptr){
        //
        if(node->parent->elements[0].value < it->value){
            node = node->parent;

            auto temp_it = --(node->elements.end());
            for(;temp_it >= node->elements.begin(); --temp_it){
                if(temp_it->value < it->value){
                    it = temp_it;
                    break;
                }
            }
        }
    }
    return *this;
}

template <typename T>
const_btree_iterator<T>& const_btree_iterator<T>::operator--(int) {
    const_btree_iterator<T> *temp = new const_btree_iterator<T>(node, it);
    --(*this);
    return *temp;
}

#endif
