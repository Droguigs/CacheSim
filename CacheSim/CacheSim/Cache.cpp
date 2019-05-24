#include <iostream>
#include <math.h>       /* log2 */
#include "Cache_set.h"
#include "Answer.h"
#include <vector>
#include "Cache.h"

#include "MissType.h"

using namespace std;

//vetor de sets é uma matriz de blocos

/*
                        1                                                               2                                                       3
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|   BLOCO:: |NUMERO INDICE|BLOCO DE INFO|TAG|VALIDADE|OFFSET|
*/



Cache::Cache(int nSets, int ass){
    numeroSets = nSets;
    conj = ass;
    for(int i=0;i<ass;i++){
        Cache_set temp(nSets);
        sets.push_back(temp);
    }
}

Answer Cache::getHit(int endereco, long int tag){ //pode receber answer como ponteiro e dai já mantem o numero do programa total

    if(conj == 1){//direto
        if(sets.at(0).getValidade(endereco%conj) == 1){ //dado valido
            if(sets.at(0).getTag(endereco%conj) == tag) //mesmo tag
                return Answer(false); //HIT
            else{   //tag diferente         CONFLITO
                MissType missType = conflict;
                sets.at(0).setTag(endereco%conj,tag);
                return Answer(missType);
            }
        }
        else{ //dado inválido       COMPULSORIO
            MissType missType = compulsory;
            sets.at(0).setTag(endereco%conj,tag); // MUITO IMPORTANTE: SET TAG SEMPRE ANTES DE SETVALIDADE!
            sets.at(0).setValidade(endereco%conj);
            return Answer(missType);
        }
    }
    else{//conj/total associativo
        int set_destino = endereco%conj;
        int i=0;
        while( sets.at(set_destino).getValidade(i) != false && i<numeroSets){ //se achar um tag nao valido significa que n tem como dar hit, se chgar em numeroSets ta cheio E deu miss
            if(sets.at(set_destino).getTag(i) == tag){
                return Answer(false); //HIT
            }
        }
        if(i == numeroSets){//miss de CAPACIDADE
            MissType missType = capacity;
            int proximoLivre = sets.at(set_destino).proximoLivre(); //proximo livre retorna um valor randomico se esta cheia a cache
            sets.at(set_destino).setTag(proximoLivre,tag);
            return Answer(missType);
        }
        else{//miss         COMPULSORIO
            MissType missType = compulsory;
            int proximoLivre = sets.at(set_destino).proximoLivre();
            sets.at(set_destino).setTag(proximoLivre,tag);
            sets.at(set_destino).setValidade(proximoLivre);
            return Answer(missType);
        }
    }
}
