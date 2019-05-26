#ifndef CACHE_H_INCLUDED
#define CACHE_H_INCLUDED

#include <iostream>
#include "Answer.h"
#include "CacheSet.h"
#include <list>
#include <vector>
#include "MissType.h"
#include "Address.h"
#include "AddressList.h"

using namespace std;

//vetor de sets eh uma matriz de blocos

class Cache{
private:
     vector<CacheSet> sets;
     int conj, numeroSets;

public:
    Cache(int nSets, int ass, int escolhaSubstituicao);
    Answer getHit(Address address); //pode receber answer como ponteiro e dai já mantem o numero do programa total
    list<Answer> getAllHits(AddressList lista);
};
#endif // CACHE_H_INCLUDED
