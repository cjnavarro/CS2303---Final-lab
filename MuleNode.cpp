//
//  MuleNode.cpp
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#include "MuleNode.h"

MuleNode::MuleNode() {
    
}

void MuleNode::add(Event newEvent) {
    events.enqueue(newEvent);
}

Event MuleNode::sendEvent() {
    return events.dequeue();
}

bool MuleNode::isEmpty() const {
    return events.isEmpty();
}
