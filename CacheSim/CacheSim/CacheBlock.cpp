#include "CacheBlock.h"

CacheBlock::CacheBlock(){
    validade = false;
}

bool CacheBlock::getValidade(){
    return validade;
}
unsigned long int CacheBlock::getTag(){
    return tag;
}

void CacheBlock::setValidade(){
    validade = true;
}

void CacheBlock::setTag(long int tag){
    this->tag = tag;
}
