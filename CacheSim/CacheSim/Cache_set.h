#ifndef CACHE_SET_H_INCLUDED
#define CACHE_SET_H_INCLUDED

#include <iostream>
#include "cache_block.h"
#include <vector>

using namespace std;

class Cache_set{
private:
vector<Cache_block> blocos;
int livre,numeroBlocos;

public:


    Cache_set(int nSets);

    bool getValidade(int numeroDoBloco);
    long int getTag(int numeroDoBloco);

    void setValidade(int numeroDoBloco);
    int proximoLivre();
    void setTag(int numeroDoBloco,long int tag);
};

#endif // CACHE_SET_H_INCLUDED
