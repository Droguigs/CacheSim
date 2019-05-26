//
//  Address.hpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#ifndef Address_hpp
#define Address_hpp

#include <iostream>

using namespace std;

class Address {
    unsigned long int tag, index;
    
public:
    Address(unsigned long int tag = 0, unsigned long int index = 0);
    unsigned long int getTag();
    unsigned long int getIndex();
};

#endif /* Address_hpp */
