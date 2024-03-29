

#include "Cache.h"



using namespace std;

//vetor de sets � uma matriz de blocos


Cache::Cache(int nSets, int ass,int escolhaSubstituicao){
    numeroSets = nSets;
    conj = ass;
    for(int i=0;i<ass;i++){
        CacheSet temp(nSets,escolhaSubstituicao);
        sets.push_back(temp);
    }
}

list<Answer> Cache::getAllHits(AddressList lista){
    int i,j = lista.getSize();
    list <Answer> result;
    for(i = 0; i<j; i++){
        result.push_back(getHit(lista.getElement(i)));
    }
    return result;
}



Answer Cache::getHit(Address address){ //pode receber answer como ponteiro e dai j� mantem o numero do programa total

    if(conj == 1){//direto
        if(sets.at(0).getValidade(address.getIndex()%numeroSets) == 1){ //dado valido
            if(sets.at(0).getValidade(address.getIndex()%numeroSets) == 1){ //dado valido
                if(sets.at(0).getTag(address.getIndex()%numeroSets) == address.getTag()) { //mesmo tag
                    return Answer(false); //HIT
                }
                else{   //tag diferente         CONFLITO
                    MissType missType = conflict;
                    sets.at(0).setTag(address.getIndex()%numeroSets,address.getTag());
                    return Answer(missType);
                }
            }
        }
        else{ //dado inv�lido       COMPULSORIO
            MissType missType = compulsory;
            sets.at(0).setTag(address.getIndex()%numeroSets,address.getTag()); // MUITO IMPORTANTE: SET TAG SEMPRE ANTES DE SETVALIDADE!
            sets.at(0).setValidade(address.getIndex()%numeroSets);
            return Answer(missType);
        }
    }
    else{//conj/total associativo
        int set_destino = address.getIndex()%conj;
        int i=0;
        while( sets.at(set_destino).getValidade(i) != false && i<numeroSets){ //se achar um tag nao valido significa que n tem como dar hit, se chgar em numeroSets ta cheio E deu miss
            if(sets.at(set_destino).getTag(i) == address.getTag()){
                return Answer(false); //HIT
            }
            i++;
        }
        if(i == numeroSets){//miss de CAPACIDADE
            MissType missType = capacity;
            int proximoLivre = sets.at(set_destino).proximoLivre(numeroSets); //proximo livre retorna um valor rand/fifo/lru se esta cheia a cache
            sets.at(set_destino).setTag(proximoLivre,address.getTag());
            return Answer(missType);
        }
        else{//miss         COMPULSORIO
            MissType missType = compulsory;
            int proximoLivre = sets.at(set_destino).proximoLivre(numeroSets);
            sets.at(set_destino).setTag(proximoLivre,address.getTag());
            sets.at(set_destino).setValidade(proximoLivre);
            return Answer(missType);
        }
    }
}
