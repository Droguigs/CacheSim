//
//  main.cpp
//  CacheSim
//
//  Created by Douglas Schiavi and Giorgio Rossa
//  Copyright © 2019 Douglas Schiavi. All rights reserved.
//


#include <iostream>
#include "Cache.h"
using namespace std;


int main()
{
    /*Cache(5);
    NOffset = log2(bSize);//essas duas variáveis guardam os bits necessários pra achar o tag e o indice
    Nbits_indice = log2(nSets);*/
    cout << "Hello world!" << endl;
    return 0;
}
/*ler como parametro:
    Nsets;Bsize;Assoc;

estrutura da cache precisa:

    cache_validade[tamanho de sets(Nsets)];(inicia com 0)
    cache_tag[tamanho de sets];

    n_offset = log2 Bsize;
    Nbits_indice = log2 NSets;
    Nbits_tag = 32 - N_offset - Nbits_indice;

    abrir o arquivo binário de endereços

    while(!eof){
        endereço = endereço do arquivo binario gerado pelo gerador
        tag = endereço >> (Nbits_indice + N_offset);
        indice = endereço >> n_offset && (2^Nbits_indice -1)

        if(cache_validade[indice] = 0){
            missCompulsorio++;
            cache_validade[indice] = 1;
            cache_tag[indice] = tag;
        }
        else{
            if(cache_tag[indice] == tag)
                Hit++;
            else{
                trata os outros misses
            }
        }
    }
*/
