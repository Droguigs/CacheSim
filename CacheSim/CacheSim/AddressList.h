//
//  AddressList.hpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#ifndef AddressList_h
#define AddressList_h

#include <iostream>
#include <string.h>
#include <list>
#include <fstream>

#include "Address.h"

using namespace std;

class AddressList {

    list<Address> addressList;

public:
    AddressList(string myFile,long unsigned int nBitsIndex,long unsigned int nOffset);
    long unsigned int ulipow( int base, long unsigned int exp );
    Address getElement(int nPos);
    int getSize();
};

#endif /* AddressList_hpp */
