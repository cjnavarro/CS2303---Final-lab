//
//  Manet.cpp
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#include "Manet.h"

Manet::Manet() {
    
}

void Manet::addToSource(int source, Event newEvent) {
    if (source == 1) {
        source1.add(newEvent);
    } else if (source == 2) {
        source2.add(newEvent);
    } else {
        throw "addToSource: Attempting to add new event to non-existed source!";
    }
}

void Manet::sendFromSourceToFirstMule(int source) {
    if (source == 1) {
        if (source1.isEmpty()) throw "sendFromSourceToFirstMule: Attemping to send event from an empty source";
        mule1.add(source1.sendEvent());
    } else if (source == 2) {
        if (source2.isEmpty()) throw "sendFromSourceToFirstMule: Attemping to send event from an empty source";
        mule1.add(source2.sendEvent());
    } else {
        throw "sendFromSourceToFirstMule: Attemping to send an event from a non-existed source";
    }
}

void Manet::processToNextMule() {
    if (mule1.isEmpty()) throw "processToNextMule: Attempting to process event from an empty mule.";
    mule2.add(mule1.sendEvent());
}

void Manet::sendFromMuleToReceiver() {
    if (mule2.isEmpty()) throw "sendFromMuleToReceiver: Attempting to send event from an empty mule!";
    receiver.add(mule2.sendEvent());
}

Event Manet::getCompletedEvent() {
    if (receiver.isEmpty()) throw "getCompletedEvent: Attempting to get event from an empty receiver";
    Event result = receiver.sendEvent();
    
    return result;
}
