//
//  Event.h
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#ifndef __MANET__Event__
#define __MANET__Event__

#include <iostream>
#include <string>

using std::string;

class Event {
public:
    
    /*
     * Default constructor: Event
     * --------------------------
     * Constructs a new event
     */
    Event();
    
    /*
     * Constructor: Event
     * ------------------
     * Constructs a new event with given information
     */
     Event(int aTime, int s);
   
    /*
     * Method: setResponseTime
     * -----------------------
     * Sets the response time to the given time
     */
     void setResponseTime(int time);
     
    /*
     * Method: toString
     * ----------------
     * Returns a string summerizing the information of the event
     * Format: [ arrival time, response time, source ]
     */
    string toString() const;
    
    
/* Private section */
private:
    int arrivalTime;
    int responseTime;
    int source;
};

#endif /* defined(__MANET__Event__) */
