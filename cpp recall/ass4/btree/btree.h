/**
 * The btree is a linked structure which operates much like
 * a binary search tree, save the fact that multiple client
 * elements are stored in a single node.  Whereas a single element
 * would partition the tree into two ordered subtrees, a node
 * that stores m client elements partition the tree
 * into m + 1 sorted subtrees.
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstddef>
#include <utility>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
// we better include the iterator
#include "btree_iterator.h"

template <typename T> 
std::ostream& operator<<(std::ostream& os, const btree<T>& tree);

template <typename T>
class btree {
public:
    friend class btree_iterator<T>;
    friend class const_btree_iterator<T>;

  

  /**
   * Constructs an empty btree.  Note that
   * the elements stored in your btree must
   * have a well-defined zero-arg constructor,
   * copy constructor, operator=, and destructor.
   * The elements must also know how to order themselves
   * relative to each other by implementing operator<
   * and operator==. (These are already implemented on
   * behalf of all built-ins: ints, doubles, strings, etc.)
   *
   * @param maxNodeElems the maximum number of elements
   *        that can be stored in each B-Tree node
   */
    btree(size_t maxNodeElems = 40) : maxE{maxNodeElems}, root(Node()) {};

  /**
   * Copy constructor
   * Creates a new B-Tree as a copy of original.
   *
   * @param original a const lvalue reference to a B-Tree object
   */
    btree(const btree<T>& original);

  /**
   * Move constructor
   * Creates a new B-Tree by "stealing" from original.
   *
   * @param original an rvalue reference to a B-Tree object
   */
    btree(btree<T>&& original);


  /**
   * Copy assignment
   * Replaces the contents of this object with a copy of rhs.
   *
   * @param rhs a const lvalue reference to a B-Tree object
   */
    btree<T>& operator=(const btree<T>& rhs);

  /**
   * Move assignment
   * Replaces the contents of this object with the "stolen"
   * contents of original.
   *
   * @param rhs a const reference to a B-Tree object
   */
    btree<T>& operator=(btree<T>&& rhs);

  /**
   * Puts a breadth-first traversal of the B-Tree onto the output
   * stream os. Elements must, in turn, support the output operator.
   * Elements are separated by space. Should not output any newlines.
   *
   * @param os a reference to a C++ output stream
   * @param tree a const reference to a B-Tree object
   * @return a reference to os
   */
    friend std::ostream& operator<< <T> (std::ostream& os, const btree<T>& tree);

    typedef btree_iterator<T> iterator;
    typedef const_btree_iterator<T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const{return begin();};
    const_iterator cend() const{return end();};

    reverse_iterator rbegin() { return reverse_iterator(end()); } 
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); } 
    const_reverse_iterator crbegin() const { return rbegin(); } 
  
    reverse_iterator rend() { return reverse_iterator(begin()); } 
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); } 
    const_reverse_iterator crend() const { return rend(); } 


  /**
    * Returns an iterator to the matching element, or whatever
    * the non-const end() returns if the element could
    * not be found.
    *
    * @param elem the client element we are trying to match.  The elem,
    *        if an instance of a true class, relies on the operator< and
    *        and operator== methods to compare elem to elements already
    *        in the btree.  You must ensure that your class implements
    *        these things, else code making use of btree<T>::find will
    *        not compile.
    * @return an iterator to the matching element, or whatever the
    *         non-const end() returns if no such match was ever found.
    */
    iterator find(const T& elem);

  /**
    * Identical in functionality to the non-const version of find,
    * save the fact that what's pointed to by the returned iterator
    * is deemed as const and immutable.
    *
    * @param elem the client element we are trying to match.
    * @return an iterator to the matching element, or whatever the
    *         const end() returns if no such match was ever found.
    */
    const_iterator find(const T& elem) const;

  /**
    * Operation which inserts the specified element
    * into the btree if a matching element isn't already
    * present.  In the event where the element truly needs
    * to be inserted, the size of the btree is effectively
    * increases by one, and the pair that gets returned contains
    * an iterator to the inserted element and true in its first and
    * second fields.
    *
    * If a matching element already exists in the btree, nothing
    * is added at all, and the size of the btree stays the same.  The
    * returned pair still returns an iterator to the matching element, but
    * the second field of the returned pair will store false.  This
    * second value can be checked to after an insertion to decide whether
    * or not the btree got bigger.
    *
    * The insert method makes use of T's zero-arg constructor and
    * operator= method, and if these things aren't available,
    * then the call to btree<T>::insert will not compile.  The implementation
    * also makes use of the class's operator== and operator< as well.
    *
    * @param elem the element to be inserted.
    * @return a pair whose first field is an iterator positioned at
    *         the matching element in the btree, and whose second field
    *         stores true if and only if the element needed to be added
    *         because no matching element was there prior to the insert call.
    */
    std::pair<iterator, bool> insert(const T& elem);

  /**
    * Disposes of all internal resources, which includes
    * the disposal of any client objects previously
    * inserted using the insert operation.
    * Check that your implementation does not leak memory!
    */
    ~btree();

    
private:
  // The details of your implementation go here

    struct Element;
    struct Node {
        
        Node(Node* p = nullptr) : parent(p), elements(std::vector<Element>()) {}
        
        Node* parent;
        std::vector<Element> elements;
    };

    struct Element {
        
        Element(T value, Node *left = nullptr, Node *right = nullptr) : value(value), leftChild(left), rightChild(right) {}
        
        T value;
        Node *leftChild;
        Node *rightChild;

    };


    size_t maxE;  //stores the max number of elements each node may contain
    Node root;


    static void printNode(std::ostream& os, const Node *node);
    static void printChildren(std::ostream& os, std::vector<Node*> &children);
    std::pair<iterator, bool> resursiveInsert(Node* node, const T& element);
    iterator resursiveFind(Node* node, const T& element);
    const_iterator const_recursiveFind(const Node* node, const T& element) const;
    void resursiveCopy(const Node* target, Node* node, Node* parent);
    void resursiveDelete(Element &e, bool lastelement);
};



//copy constructor
template <typename T>
btree<T>::btree(const btree<T>& original){
    maxE = original.maxE;
    root = original.root;

    resursiveCopy(&original.root, &root, nullptr);
}

//
template <typename T>
void btree<T>::resursiveCopy(const Node *target, Node *node, Node *parent) {
    //assign parent, elements except childs
    node->elements = target->elements;
    node->parent = parent;

    for(size_t index = 0 ; index < node->elements.size(); ++index){
        if(target->elements[index].leftChild != nullptr){
            //create a new node for node leftChild
            Node *newNode = new Node(node);
            node->elements[index].leftChild = newNode;
            resursiveCopy(target->elements[index].leftChild, node->elements[index].leftChild, node);

        }

        if(target->elements[index].rightChild != nullptr){
            //create a new node for node rightChild
            Node *newNode = new Node(node);
            node->elements[index].rightChild = newNode;
            resursiveCopy(target->elements[index].rightChild, node->elements[index].rightChild, node);

        }

    }

}
//move constructor
template <typename T>
btree<T>::btree(btree<T>&& original){
    maxE = std::move(original.maxE);
    root = std::move(original.root);

    //childs' parent is not root now
    for (auto it = root.elements.begin(); it != root.elements.end(); ++it) {
        //For each valid child, update the parent node to newely moved node
        if (it->leftChild != nullptr) {
            it->leftChild->parent = &root;
        }

        if (it->rightChild != nullptr) {
            it->rightChild->parent = &root;
        }
    }

    // for (auto it = original.root.elements.begin(); it != original.root.elements.end(); ++it) {
    //     std::cout << "testing move !! \n";
    //     it->leftChild = nullptr;
    //     it->rightChild = nullptr;
    // }
}

//copy assignment
template <typename T>
btree<T>& btree<T>::operator=(const btree<T>& rhs){
    maxE = rhs.maxE;
    root = rhs.root;

    resursiveCopy(&rhs.root,&root, nullptr);

    return *this;
}

// move assignment
template <typename T>
btree<T>& btree<T>::operator=(btree<T>&& rhs){
    maxE = std::move(rhs.maxE);
    root = std::move(rhs.root);

    for (auto it = root.elements.begin(); it != root.elements.end(); ++it) {
        //For each valid child, update the parent node to newely moved node
        if (it->leftChild != nullptr) {
            it->leftChild->parent = &root;
        }

        if (it->rightChild != nullptr) {
            it->rightChild->parent = &root;
        }
    }

    // for (auto it = rhs.root.elements.begin(); it != rhs.root.elements.end(); ++it) {
    //     it->leftChild = nullptr;
    //     it->rightChild = nullptr;
    // }
    return *this;
}





template <typename T>
typename btree<T>::iterator btree<T>::begin() {
    typename std::vector<btree<T>::Element>::iterator it = root.elements.begin();

    //root elements size = 0 || no left child
    if(root.elements.size() == 0 || it->leftChild == nullptr){
        return btree_iterator<T> (&root, it);
    } else {
        //find the most left element
        Node *temp_node = it->leftChild;
        while(it->leftChild != nullptr){
            temp_node = it->leftChild;
            it = temp_node->elements.begin();
        }
        return iterator(temp_node, it);
    }
}

template <typename T>
typename btree<T>::iterator btree<T>::end() {
    return iterator(&root,root.elements.end());

}



template <typename T>
std::pair<typename btree<T>::iterator, bool> btree<T>::insert(const T &elem) {
    return resursiveInsert(&root, elem);
}

template <typename T>
std::pair<typename btree<T>::iterator, bool> btree<T>::resursiveInsert(Node* node, const T& element){

    for(size_t index = 0; index < node->elements.size(); ++index){

        if(element == node->elements[index].value){
            //already in tree
            

            iterator i(node, node->elements.begin()+index);
            return std::pair<btree<T>::iterator, bool>(i, false);

        }else if(element < node->elements[index].value && node->elements.size() < maxE){

            Element new_element(element);
            node->elements.insert(node->elements.begin()+index, new_element);
            return std::pair<typename btree<T>::iterator, bool>(btree<T>::iterator(node, node->elements.begin()+index), true);
        } else if(index == (node->elements.size() - 1) && node->elements.size() < maxE){
//            std::cout << element<<"test\n";
            // element > current last element
//            std::cout <<element<<"  hello\n";
            Element new_element(element);
            node->elements.insert(node->elements.begin()+index+1, new_element);
            return std::pair<typename btree<T>::iterator, bool>(btree<T>::iterator(node, node->elements.end()-1), true);
        }else if(element < node->elements[index].value && node->elements.size() == maxE){
            //if child is empty

            Node *child = node->elements[index].leftChild;
            if(child == nullptr){
                //create new node and set parent
                child = new Node(node);

                node->elements[index].leftChild = child;
                //also set right child of previous element
                if(index > 0){
                    node->elements[--index].rightChild = child;
                }


            }

            return resursiveInsert(child, element);
        }else if(index == (node->elements.size() - 1) && node->elements.size() == maxE){

            //reach last element and current size == max size

            Node *child = node->elements[index].rightChild;
            if(child == nullptr){
                
                child = new Node(node);
                node->elements[index].rightChild = child;
              
               
            }

            return resursiveInsert(child, element);

        }else{
            continue;
        }

    }
        
    //for vector of size 0
    Element e(element);
    node->elements.push_back(e);
    return std::pair<typename btree<T>::iterator, bool>(btree<T>::iterator(node, node->elements.begin()), true);


}

template <typename T>
typename btree<T>::iterator btree<T>::find(const T& elem){
    return resursiveFind(&root, elem);
}


template <typename T>
typename btree<T>::const_iterator btree<T>::find(const T& elem) const{
    return const_recursiveFind(&root, elem);
}



template <typename T>
typename btree<T>::iterator btree<T>::resursiveFind(Node *node, const T &element) {
    if(node != nullptr){
        for(size_t index = 0; index < node->elements.size(); ++index){
            if(element == node->elements[index].value){

                return iterator(node, (node->elements.begin()+index));
            }else if(element < node->elements[index].value){

                return resursiveFind(node->elements[index].leftChild, element);
            }else if(index == node->elements.size()-1){
                //std::cout <<element<<"  \n";
                return resursiveFind(node->elements[index].rightChild, element);
            } else{

                continue;
            }
        }

    }

    return end();
}



template <typename T>
typename btree<T>::const_iterator btree<T>::const_recursiveFind(const Node* node, const T& element) const {
    if(node != nullptr){
        for(size_t index = 0; index < node->elements.size(); ++index){
            if(element == node->elements[index].value){

                return const_iterator(node, (node->elements.cbegin()+index));
            }else if(element < node->elements[index].value){

                return const_recursiveFind(node->elements[index].leftChild, element);
            }else if(index == node->elements.size()-1){
                //std::cout <<element<<"  \n";
                return const_recursiveFind(node->elements[index].rightChild, element);
            } else{

                continue;
            }
        }
        
    } 
    return cend();
}



template <typename T>
typename btree<T>::const_iterator btree<T>::begin() const{
    typename std::vector<btree<T>::Element>::const_iterator it = root.elements.begin();
    if(root.elements.size() == 0 || it->leftChild == nullptr){
//       
        return const_iterator(&root, it);
    } else {

        Node *temp_node = it->leftChild;
        while(it->leftChild != nullptr){
            temp_node = it->leftChild;
            it = temp_node->elements.begin();
        }
        return const_iterator(temp_node, it);
    }
}




template <typename T>
typename btree<T>::const_iterator btree<T>::end() const{
    typename std::vector<btree<T>::Element>::const_iterator it = root.elements.end();
    return const_iterator(&root,it);

}


template <typename T>
std::ostream& operator<<(std::ostream& os, const btree<T>& tree) {
    btree<T>::printNode(os, &tree.root);
    std::vector<typename btree<T>::Node*> allc;

    for(auto i = tree.root.elements.begin(); i != tree.root.elements.end(); ++i){
        
        if(i->leftChild != nullptr){
            allc.push_back(i->leftChild);
        }
        
        if(i == --tree.root.elements.end()){
            if(i->rightChild != nullptr){
                allc.push_back(i->rightChild);
            }
        }
    }

    btree<T>::printChildren(os, allc);
    return os;
}


template <typename T>
void btree<T>::printNode(std::ostream& os, const Node *node) {
    auto it = node->elements.begin();
    for(; it != node->elements.end(); ++it){
        os << it->value;
        os << " ";        
    }

}


template <typename T>
void btree<T>::printChildren(std::ostream& os, std::vector<Node*> &children){
    //print node in children, then make new vector to store new children, resursively call this function    
    if(children.size() != 0){
        std::vector<Node*> newallc;
        int child_flag = 0;
        for(auto n = children.begin(); n != children.end(); ++n){
            btree<T>::printNode(os, *n);
            for(auto i = (*n)->elements.begin(); i != (*n)->elements.end(); ++i){
                if(i->leftChild != nullptr){
                    child_flag = 1;
                    newallc.push_back(i->leftChild);
                }
                if(i == --(*n)->elements.end()){
                    if(i->rightChild != nullptr){
                        child_flag = 1;
                        newallc.push_back(i->rightChild);
                    }
                }    
                
            }

        }

        btree<T>::printChildren(os, newallc);
    }


}

template <typename T>
btree<T>::~btree() {
    for(auto it = root.elements.begin(); it != root.elements.end(); ++it){
    
        if(it != --root.elements.end()){
            resursiveDelete(*it,false);
        }else{
            resursiveDelete(*it,true);
        }
    }
}  
template <typename T>
void btree<T>::resursiveDelete(Element &e, bool lastelement){

    if(e.leftChild != nullptr){
        for(auto it = e.leftChild->elements.begin(); it != e.leftChild->elements.end(); ++it){
    // for(size_t i = 0; i < root.elements.size){
            //resursiveDelete(*it);
            if(it != --e.leftChild->elements.end()){
                resursiveDelete(*it,false);
            }else{
                resursiveDelete(*it,true);
            }

        }

        delete e.leftChild;
        e.leftChild = nullptr;
    }

    if(e.rightChild != nullptr){
        for(auto it = e.rightChild->elements.begin(); it != e.rightChild->elements.end(); ++it){
            //resursiveDelete(*it);
            if(it != --e.rightChild->elements.end()){
                resursiveDelete(*it,false);
            }else{
                resursiveDelete(*it,true);
            }            
        }

        if(lastelement){
            delete e.rightChild;
        }        
        e.rightChild = nullptr;
    }
}
#endif
