//
//  AnswerList.hpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#ifndef AnswerList_h
#define AnswerList_h

#include <iostream>
#include <list>

#include "Answer.h"

using namespace std;

class AnswerList {
    
    int hits, misses, compulsoryMisses, capacityMisses, conflictMisses;
    
public:
    AnswerList(list<Answer> myList);
    int getHits();
    int getMisses();
    int getCompulsoryMisses();
    int getCapacityMisses();
    int getConflictMisses();
    
};

#endif /* AnswerList_hpp */
