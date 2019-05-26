//
//  Address.cpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#include "Address.h"

Address::Address(unsigned long int tag, unsigned long int index) {
    this->tag = tag;
    this->index = index;
}

unsigned long int Address::getTag() {
    return tag;
}

unsigned long int Address::getIndex() {
    return index;
}
