#include <iostream>
#include "CacheSet.h"
#include "CacheBlock.h"
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
CacheSet::CacheSet(int nSets,int escolhaSub){
    livre = 0;
    nUltimo = 0;
    escolhaSubstituicao = escolhaSub;
    numeroBlocos = nSets;
    for(int i=0;i<nSets;i++){
        CacheBlock bloco;
        blocos.push_back( bloco );
    }
}

bool CacheSet::getValidade(int numeroDoBloco){
    return blocos.at(numeroDoBloco).getValidade();
}
long int CacheSet::getTag(int numeroDoBloco){
    //se for LRU tenho que pegar o valor com esse tag e jogar pro final
    int bloco;
    bloco = numeroDoBloco;
    if(escolhaSubstituicao == 2){
        list<int>::iterator it;

        for(it=ordemSubs.begin();it != ordemSubs.end();it++){
            if(*it == bloco){
                ordemSubs.splice(ordemSubs.end(),ordemSubs, it); //splice pega o elemento que it aponta do segundo parametro e joga no primeiro(ou seja no final)
                break;
            }
        }
    }

    return blocos.at(numeroDoBloco).getTag();;
}

void CacheSet::setValidade(int numeroDoBloco){
    blocos.at(numeroDoBloco).setValidade();
}

int CacheSet::proximoLivre(int tamanhoSet){// 0 - random  1- fifo 2 - LRU
    if(livre <= numeroBlocos){
        return livre;
    }
    else{//aqui depende da escolha de reposição rand, fifo, lru
        if(escolhaSubstituicao == 0){//random
            int random = rand()% tamanhoSet;
            return random;
        }
        else{ //FIFO E LRU usam a lista,então já estão no inicio
            int bloco = ordemSubs.front();
            ordemSubs.pop_front();
            return bloco;
        }
    }
}
void CacheSet::setTag(int numeroDoBloco,long int tag){
    if(!(getValidade(numeroDoBloco)))
        livre++;

    ordemSubs.push_back(numeroDoBloco);
    blocos.at(numeroDoBloco).setTag(tag);
}

