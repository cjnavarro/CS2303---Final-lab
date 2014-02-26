//
//  main.cpp
//  MANET
//
//  Created by Hoang Minh Ngo on 2/25/14.
//  Copyright (c) 2014 Hoang Ngo. All rights reserved.
//

#include <iostream>
#include "Manet.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //Manet newManetSimulation;
    LinkedList<Event> events;
    
    //string ans;
    int arrivalTime;
    int source;
    int counter = 0;
    
    for(int i = 0; i<200;i++){
        
        cout << "Enter the data as : Sender(1 or 2), Arrival Time"<< endl;
        cin >> source >> arrivalTime;
        
        Event newEvent(source, arrivalTime);
        
        events.addInOrder(newEvent);
    }
    
    while(true)
        
    
    
    
    
    
    
   /* while (true) {
        cout << "Add new event?: " << endl;
        getline(cin, ans);
        if (ans == " ") break;
        
        cout << "Enter arrival time: ";
        cin >> arrivalTime;
        
        cout << "Enter source: (1 or 2): ";
        cin >> source;
        
        Event newEvent(arrivalTime, source);
        newManetSimulation.addToSource(source, newEvent);
        
        newManetSimulation.sendFromSourceToFirstMule(source);
        newManetSimulation.processToNextMule();
        
        newManetSimulation.sendFromMuleToReceiver();
        
        Event final = newManetSimulation.getCompletedEvent();
        cout << final.toString() << endl;
    }*/
    
    return 0;
}

