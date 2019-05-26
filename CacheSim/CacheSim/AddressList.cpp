//
//  AddressList.cpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#include "AddressList.h"

using namespace std;

AddressList::AddressList(ifstream myFile) {
    Address temp;
    while(myFile.read((char *)&temp, sizeof(long unsigned int))){
        //tmp to array
        
        addressList.push_back(Address(temp));
    }
    myFile.close();
}

