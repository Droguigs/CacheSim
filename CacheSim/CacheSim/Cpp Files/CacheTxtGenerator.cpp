//
//  CacheTxtGenerator.cpp
//  CacheSim
//
//  Created by Douglas Schiavi on 26/05/19.
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//

#include "CacheTxtGenerator.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CacheTxtGenerator:: createTxt (string name) {
    ofstream myFile(name, ios::binary);
    unsigned long int randGenerated = 0;
    
    for(int i = 0; i < 131000; ++i) {
        randGenerated = rand() % 4294967296;
        myFile.write((char*)&randGenerated,sizeof(randGenerated));
    }
    
    myFile.close();
    return ;
}
