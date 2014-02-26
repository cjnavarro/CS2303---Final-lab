//
//  File: linkedlist.h
//  -------------------- 
//
//  Created by Hoang Minh Ngo on 2/21/14.
//
//

#ifndef _linkedlist_h
#define _linkedlist_h

#include <iostream>
#include <string>

using namespace std;

/* A single node's internal structure representation */
template <typename ValueType>
struct ListNode {
    ValueType data;             // Data in node
    ListNode* nextNodePtr;      // Pointer to the next node (NULL if none)

    ListNode<ValueType>(ValueType d, ListNode* n) {
        data = d;
        nextNodePtr = n;
    }
};

template <typename ValueType>
class LinkedList {
public:
    /*
     * Constructs a new empty list.
     */
    LinkedList();
    
    /*
     * Frees the memory that was allocated internally by the list
     */
    ~LinkedList();
    
    /*
     * Appends the given value to the end of the list
     */
    void add(ValueType value);
    
    /*
     * Appends the given value to the end of the list in a specific order
     */
    void addInOrder(ValueType value); 
     
    /*
     * Removes all elements from the list
     */
    void clear();
    
    /*
     * Returns the value at the given 0-based index of the list
     */
    ValueType get(int index) const;
    
    /*
     * Adds the given value at the given 0-based index in the list,
     * shifting the subsequent elements right as necessary to make room
     */
    void insert(ValueType value, int index);
    
    /*
     * Returns true if there are no elements in the list
     */
    bool isEmpty() const;
    
    /*
     * Removes the element at the given 0-based index in the list
     * shifting the subsequent elements left as necessary to cover its slot
     */
    void remove(int index);
    
    /*
     * Store value at the given 0-based index in the list
     */
    void set(ValueType value, int index);
    
    /*
     * Returns the number of elements in the list
     */
    int size() const;
    
    
/* Private section */
private:
    ListNode<ValueType>* frontNodePtr;
    
    /*
     * Throw a string exception if the given index is not between
     * the given min/max indice, inclusive
     */
    void checkIndex(int index, int min, int max) const;
};

template <typename ValueType>
LinkedList<ValueType>::LinkedList() {
    frontNodePtr = NULL;
}

template <typename ValueType>
LinkedList<ValueType>::~LinkedList() {
    clear();
}

template <typename ValueType>
void LinkedList<ValueType>::add(ValueType value) {
    if (frontNodePtr == NULL) {
        frontNodePtr = new ListNode<ValueType>(value, NULL);
    } else {
        ListNode<ValueType>* currentPtr = frontNodePtr;
        
        while (currentPtr->nextNodePtr) {
            currentPtr = currentPtr->nextNodePtr;
        }
        
        currentPtr->nextNodePtr = new ListNode<ValueType>(value, NULL);
    }
}

template<typename ValueType>
void LinkedList<ValueType>::addInOrder(ValueType value){
    if (frontNodePtr == NULL) {
        frontNodePtr = new ListNode<ValueType>(value, NULL);
    } else {
        ListNode<ValueType>* currentPtr = frontNodePtr;
        while(currentPtr->nextNodePtr && currentPtr->data < value) {
            currentPtr = currentPtr->nextNodePtr;
        }
        currentPtr->nextNodePtr = new ListNode<ValueType>(value, NULL);
       }   
}



template <typename ValueType>
void LinkedList<ValueType>::clear() {
    while (frontNodePtr) {
        ListNode<ValueType>* currentPtr = frontNodePtr;
        frontNodePtr = frontNodePtr->nextNodePtr;
        delete currentPtr;
    }
}

template <typename ValueType>
ValueType LinkedList<ValueType>::get(int index) const {
    checkIndex(index, 0, size() - 1);
    ListNode<ValueType>* currentPtr = frontNodePtr;
    for (int i = 0; i < index; i++) {
        currentPtr = currentPtr->nextNodePtr;
    }
    return currentPtr->data;
}

template <typename ValueType>
void LinkedList<ValueType>::insert(ValueType value, int index) {
    checkIndex(index, 0, size() - 1);
    
    if (index == 0) {
        ListNode<ValueType>* temp = frontNodePtr;
        frontNodePtr = new ListNode<ValueType>(value, temp);
    } else {
        ListNode<ValueType>* currentPtr = frontNodePtr;
        for (int i = 0; i < index; i++) {
            currentPtr = currentPtr->nextNodePtr;
        }
        
        ListNode<ValueType>* temp = currentPtr->nextNodePtr;
        currentPtr->nextNodePtr = new ListNode<ValueType>(value, temp);
    }
}

template <typename ValueType>
bool LinkedList<ValueType>::isEmpty() const {
    return size() == 0;
}

template <typename ValueType>
void LinkedList<ValueType>::remove(int index) {
    checkIndex(index, 0, size() - 1);
    ListNode<ValueType>* trash;
    
    // Point the trash pointer to the about-to-dead list node
    if (index == 0) {
        trash = frontNodePtr;
        frontNodePtr = frontNodePtr->nextNodePtr;
    } else {
        ListNode<ValueType>* currentPtr = frontNodePtr;
        for (int i = 0; i < index - 1; i++) {
            currentPtr = currentPtr->nextNodePtr;
        }
        trash = currentPtr->nextNodePtr;
        currentPtr->nextNodePtr = currentPtr->nextNodePtr->nextNodePtr;
    }
    
    delete trash;
}

template <typename ValueType>
void LinkedList<ValueType>::set(ValueType value, int index) {
    checkIndex(index, 0, size() - 1);
    ListNode<ValueType>* currentPtr = frontNodePtr;
    for (int i = 0; i < index; i++) {
        currentPtr = currentPtr->nextNodePtr;
    }
    currentPtr->data = value;
}

template <typename ValueType>
int LinkedList<ValueType>::size() const {
    int count = 0;
    ListNode<ValueType>* currentPtr = frontNodePtr;
    while(currentPtr) {
        count++;
        currentPtr = currentPtr->nextNodePtr;
    }
    return count;
}

template <typename ValueType>
void LinkedList<ValueType>::checkIndex(int index, int min, int max) const {
    if (index < min || index > max) {
        throw "Invalid index";
    }
}

#endif
