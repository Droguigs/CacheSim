//
//  AddressList.cpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#include "AddressList.h"

using namespace std;

long unsigned int AddressList::ulipow( int base, long unsigned int exp ){
   long unsigned int result = 1;
    while( exp )
    {
        if ( exp & 1 )
        {
            result *= (long unsigned int)base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

AddressList::AddressList(string myFile, long unsigned int nBitsIndex,long unsigned  int nOffset) {
    long unsigned int temp;
    ifstream source;
    source.open(myFile,ios::binary);

    while(source.read((char *)&temp, sizeof(long unsigned int))){
        //tmp to array
        long unsigned int tag,index;
        tag = temp >> (nBitsIndex + nOffset);
        index = temp >> nOffset & (ulipow(2,nBitsIndex) - 1);
        Address address(tag,index);

        addressList.push_back(Address(address));
    }
    source.close();
}

Address AddressList::getElement(int nPos){
    if(nPos <= addressList.size()){
        list<Address>::iterator it;
        it = addressList.begin();
        for(int i=0;i<nPos;i++)
            it++;
        return *it;
    }
    return NULL;
}

int AddressList::getSize(){
    return addressList.size();
}



