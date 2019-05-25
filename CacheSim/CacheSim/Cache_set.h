#ifndef CACHE_SET_H_INCLUDED
#define CACHE_SET_H_INCLUDED

#include <iostream>
#include "cache_block.h"
#include <vector>
#include <list>

using namespace std;

class Cache_set{
private:
vector<Cache_block> blocos;
list<int> ordemSubs;
int livre,numeroBlocos,escolhaSubstituicao,nUltimo;

public:


    Cache_set(int nSets,int escolhaSub);

    bool getValidade(int numeroDoBloco);
    long int getTag(int numeroDoBloco);

    void setValidade(int numeroDoBloco);
    int proximoLivre(int tamanhoSet);
    void setTag(int numeroDoBloco,long int tag);
};

#endif // CACHE_SET_H_INCLUDED
