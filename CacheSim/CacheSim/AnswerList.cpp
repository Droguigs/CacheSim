//
//  AnswerList.cpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#include "AnswerList.h"
#include "Address.h"

AnswerList::AnswerList(list<Answer> myList) {
    hits = misses = compulsoryMisses = capacityMisses = conflictMisses = 0;
    list <Answer>::iterator it;
    for(it = myList.begin(); it != myList.end(); it++){
        bool isMiss = (*it).getMiss();
        if (isMiss) {
            hits++;
        } else {
            //capacity, compulsory, conflict
            misses ++;
            MissType missType = (*it).getMissType();
            if (missType == capacity) {
                capacityMisses++;
            } else if (missType == compulsory) {
                compulsoryMisses++;
            } else {
                conflictMisses++;
            }
        }
    }
}
int AnswerList::getHits() {
    return hits;
}
int AnswerList::getMisses() {
    return misses;
}
int AnswerList::getCompulsoryMisses() {
    return compulsoryMisses;
}
int AnswerList::getCapacityMisses() {
    return capacityMisses;
}
int AnswerList::getConflictMisses() {
    return conflictMisses;
}
