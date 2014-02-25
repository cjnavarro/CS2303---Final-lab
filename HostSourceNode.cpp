//
//  HostSourceNode.cpp
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#include "HostSourceNode.h"
#include <iostream>
HostSourceNode::HostSourceNode() {
    
}

void HostSourceNode::add(Event newEvent) {
    events.add(newEvent);
}

Event HostSourceNode::sendEvent() {
    Event result = events.get(0);
    events.remove(0);
    return result;
}

bool HostSourceNode::isEmpty() const {
    return events.isEmpty();
}
