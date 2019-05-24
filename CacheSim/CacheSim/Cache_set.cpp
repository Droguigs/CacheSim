#include <iostream>
#include "Cache_set.h"
#include "Cache_block.h"
#include <vector>

using namespace std;

/*set
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
*/

//gaurdar numero de lugares abertos e qual o próximo
//função pra procurar dentro dos blocos
Cache_set::Cache_set(int nSets){
    livre = 0;
    numeroBlocos = nSets;
    for(int i=0;i<nSets;i++){
        Cache_block bloco;
        blocos.push_back( bloco );
    }
}

bool Cache_set::getValidade(int numeroDoBloco){
    return blocos.at(numeroDoBloco).getValidade();
}
long int Cache_set::getTag(int numeroDoBloco){
    return blocos.at(numeroDoBloco).getTag();
}

void Cache_set::setValidade(int numeroDoBloco){
    blocos.at(numeroDoBloco).setValidade();
}

int Cache_set::proximoLivre(){
    if(livre <= numeroBlocos){
        return livre;
    }
    else{
        //FUNÇÃO RAND() PRA VOLTAR UM
    }
}
void Cache_set::setTag(int numeroDoBloco,long int tag){
    if(!(getValidade(numeroDoBloco)))
        livre++;

    blocos.at(numeroDoBloco).setTag(tag);
}

