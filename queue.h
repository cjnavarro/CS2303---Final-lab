//
//  File: queue.h
//  --------------
//
//  Created by Hoang Minh Ngo on 2/24/14.
//
//

#ifndef _queue_h
#define _queue_h

#include <iostream>

/* A single node's single internal structure representation */
template <typename ValueType>
struct Node {
    ValueType data;         // Data in node
    Node* nextNodePtr;      // Pointer to the next node (NULL if none)
    
    Node<ValueType>(ValueType d, Node* n) {
        data = d;
        nextNodePtr = n;
    }
};

template <typename ValueType>
class Queue {
public:
    
    /*
     * Constructor: Queue
     * ------------------
     * Constructs a new empty queue.
     */
    
    Queue();
    
    /*
     * Destructor: ~Queue
     * ------------------
     * Frees any heap storage associated with this queue
     */
    
    ~Queue();
    
    /*
     * Method: size
     * ---------------
     * Returns the number of values in the queue.
     */
    
    int size() const;
    
    /*
     * Method: isEmpty
     * --------------------
     * Returns true if the queue contains no elements.
     */
    
    bool isEmpty() const;
    
    /*
     * Method: clear
     * -----------------
     * Removes all elements from the queue.
     *
     */
    
    void clear();
    
    /*
     * Method: enqueue
     * -----------------
     * Adds value to the end of the queue
     */
    
    void enqueue(ValueType value);
    
    /*
     * Method: dequeue
     * -----------------
     * Removes and return the first item in the queue
     */
    
    ValueType dequeue();
    
    /* Private section */
private:
    Node<ValueType>* frontNodePtr;
    Node<ValueType>* backNodePtr;
    int count;
};

template <typename ValueType>
Queue<ValueType>::Queue() {
    frontNodePtr = NULL;
    backNodePtr = NULL;
    count = 0;
}

template <typename ValueType>
Queue<ValueType>::~Queue() {
    clear();
}

template <typename ValueType>
int Queue<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool Queue<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void Queue<ValueType>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value) {
    if (frontNodePtr == NULL) {
        frontNodePtr = new Node<ValueType>(value, NULL);
	backNodePtr = frontNodePtr;
    } else {
        backNodePtr->nextNodePtr = new Node<ValueType>(value, NULL);
	backNodePtr = backNodePtr->nextNodePtr; 
    }

    count++;
}

template <typename ValueType>
ValueType Queue<ValueType>::dequeue() {
   if (frontNodePtr == NULL) throw "dequeue: Attempting to dequeue an empty queue.";
    Node<ValueType>* temp = frontNodePtr;
    ValueType value = frontNodePtr->data;
    
    frontNodePtr = frontNodePtr->nextNodePtr;
        
    if (frontNodePtr == NULL) {
        backNodePtr = NULL;
    }
        
    delete temp;
    count--;
    return value;
}

#endif
