#ifndef CACHE_H_INCLUDED
#define CACHE_H_INCLUDED

#include <iostream>
#include "Answer.h"
#include <math.h>       /* log2 */
#include "CacheSet.h"
#include <vector>
#include "MissType.h"

using namespace std;

//vetor de sets eh uma matriz de blocos

class Cache{
private:
     vector<CacheSet> sets;
     int conj, numeroSets;

public:
    Cache(int nSets, int ass, int escolhaSubstituicao);
    Answer getHit(int endereco, long int tag); //pode receber answer como ponteiro e dai já mantem o numero do programa total
};
#endif // CACHE_H_INCLUDED
