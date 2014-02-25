//
//  HostSourceNode.h
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#ifndef __MANET__HostSourceNode__
#define __MANET__HostSourceNode__

#include <iostream>
#include "linkedlist.h"
#include "Event.h"

class HostSourceNode {
public:
    /*
     * Constructor: Source
     * -------------------
     * Constructs an empty host source node
     */
    HostSourceNode();
    
    /*
     * Method: add
     * -----------
     * Adds an event to the host source node
     */
    void add(Event newEvent);
    
    /*
     * Method: sendEvent
     * -----------------
     * Returns first event in the node and removes it
     */
    Event sendEvent();
    
    /*
     * Method: isEmpty
     * ---------------
     * Returns true if the host source node has no events
     */
    bool isEmpty() const;
    
    /* Private section */
private:
    LinkedList<Event> events;
};


#endif /* defined(__MANET__HostSourceNode__) */
