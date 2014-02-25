//
//  MuleNode.h
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#ifndef __MANET__MuleNode__
#define __MANET__MuleNode__

#include <iostream>
#include "queue.h"
#include "Event.h"

class MuleNode {
public:
    /*
     * Constructor: MuleNode
     * ----------------------
     * Constructs an empty MuleNode
     */
    MuleNode();
    
    /*
     * Method: add
     * -----------
     * Adds an event to the MuleNode
     */
    void add(Event newEvent);
    
    /*
     * Method: sendEvent
     * -----------------
     * Sends the first event in the MuleNode
     */
    Event sendEvent();
    
    /*
     * Method: isEmpty
     * ---------------
     * Returns true if the mule has no events.
     */
    bool isEmpty() const;
    
/* Private section */
private:
    Queue<Event> events;
};

#endif /* defined(__MANET__MuleNode__) */
