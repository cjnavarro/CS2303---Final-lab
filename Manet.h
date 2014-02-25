//
//  Manet.h
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#ifndef __MANET__Manet__
#define __MANET__Manet__

#include <iostream>
#include "HostSourceNode.h"
#include "MuleNode.h"
#include "Event.h"

class Manet {
public:
    /*
     * Constructor: Manet
     * ------------------
     * Constructs a new MANET simulation
     */
    Manet();
    
    /*
     * Method: addToSource
     * Usage: manet.addToSource(source, event);
     * ----------------------------------------
     * Adds an event to the given source
     */
    void addToSource(int source, Event newEvent);
    
    /*
     * Method: sendFromSourceToFirstMule
     * Usage: manet.sendFromSourceToFirstMule(source);
     * ------------------------------------
     * Sends an event from a source to the mule node 1
     * and removes it from the source
     */
    void sendFromSourceToFirstMule(int source);
    
    /*
     * Method: processToNextMule
     * Usage: manet.processToNextMule();
     * ---------------------------------
     * Sends an event from mule node 1 to mule node 2
     * and removes it from mule node 1
     */
    void processToNextMule();
    
    /*
     * Method: sendFromMuleToReceiver
     * Usage: manet.sendFromMuleToReceiver();
     * --------------------------------------
     * Sends an event from last mule to the receiver and
     * removes it from the last mule
     */
    void sendFromMuleToReceiver();
    
    /*
     * Method: getCompletedEvent
     * Usage: Event event = manet.getCompletedEvent();
     * ------------------------------------------------
     * Gets the completed event from the receiver and
     * removes it from the receiver
     */
    Event getCompletedEvent();
    
    
/* Private section */
private:
    HostSourceNode source1;      // Source node
    HostSourceNode source2;
    MuleNode mule1;              // Intermediate mule
    MuleNode mule2;
    HostSourceNode receiver;     // Receiver node
};
#endif /* defined(__MANET__Manet__) */
