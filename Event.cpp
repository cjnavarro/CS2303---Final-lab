//
//  Event.cpp
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#include "Event.h"
#include <sstream>

#define INIT_RESPONSE_TIME 0;

Event::Event() {
    arrivalTime = 0;
    responseTime = 0;
    source = 0;
}

Event::Event(int aTime, int s) {
    arrivalTime = aTime;
    responseTime = INIT_RESPONSE_TIME;
    source = s;
}

void Event::setResponseTime(int time) {
    responseTime = time;
}

string Event::toString() const {
    std::ostringstream stringstream;
    stringstream << "[ " << arrivalTime
                 << ", " << responseTime
                 << ", " << source
                 << " ]";
    
    return stringstream.str();
}
