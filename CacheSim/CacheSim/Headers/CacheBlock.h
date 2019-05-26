#ifndef CACHE_BLOCK_H_INCLUDED
#define CACHE_BLOCK_H_INCLUDED

#include <iostream>

/*
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
*/

using namespace std;

class CacheBlock{

private:
    bool validade;
    long int tag;

public:
    CacheBlock();
    bool getValidade();
    long int getTag();
    void setValidade();
    void setTag(long int tag);

};

#endif // CACHE_BLOCK_H_INCLUDED
