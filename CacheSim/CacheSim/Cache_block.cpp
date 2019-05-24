#include <iostream>
#include "Cache_block.h"
/*
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
*/



Cache_block::Cache_block(){
    validade = false;
}

bool Cache_block::getValidade(){
    return validade;
}
long int Cache_block::getTag(){
    return tag;
}

void Cache_block::setValidade(){
    validade = true;
}

void Cache_block::setTag(long int tag){
    this->tag = tag;
}
