#include <iostream>
#include "CacheBlock.h"
/*
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
*/

CacheBlock::CacheBlock(){
    validade = false;
}

bool CacheBlock::getValidade(){
    return validade;
}
long int CacheBlock::getTag(){
    return tag;
}

void CacheBlock::setValidade(){
    validade = true;
}

void CacheBlock::setTag(long int tag){
    this->tag = tag;
}
