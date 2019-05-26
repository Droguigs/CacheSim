#ifndef CACHE_SET_H_INCLUDED
#define CACHE_SET_H_INCLUDED

#include <iostream>
#include "CacheBlock.h"
#include <vector>
#include <list>

using namespace std;

class CacheSet{
private:
    vector<CacheBlock> blocos;
    list<int> ordemSubs;
    int livre,numeroBlocos,escolhaSubstituicao,nUltimo;

public:
    CacheSet(int nSets,int escolhaSub);

    bool getValidade(int numeroDoBloco);
    unsigned long int getTag(int numeroDoBloco);

    void setValidade(int numeroDoBloco);
    int proximoLivre(int tamanhoSet);
    void setTag(int numeroDoBloco,unsigned long int tag);
};

#endif // CACHE_SET_H_INCLUDED
