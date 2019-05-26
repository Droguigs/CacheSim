//
//  main.cpp
//  CacheSim
//
//  Created by Douglas Schiavi and Giorgio Rossa
//  Copyright � 2019 Douglas Schiavi. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

#include "Cache.h"
#include "CacheTxtGenerator.h"
#include "AddressList.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*Cache(5);
    NOffset = log2(bSize);//essas duas vari�veis guardam os bits necess�rios pra achar o tag e o indice
    Nbits_indice = log2(nSets);*/
    
    switch (argc) {
        case 1:
            //run cache bench on default
            break;
        case 2:
            if (strcmp(argv[1], "default")) {
                //run cache on default configuration
            } else if (strcmp(argv[1], "generate")){
                CacheTxtGenerator cache;
                cache.createTxt("arquivo_de_entrada");
                cout << "arquivo 'arquivo_de_entrada' criado com sucesso \n";
            } else {
                cout << "Favor escrever um conjunto de comandos v�lido\n";
            }
            break;
        case 3:
            if (strcmp(argv[1], "generate")) {
                CacheTxtGenerator cache;
                cache.createTxt(argv[2]);
                string message = "arquivo '";
                message.append(argv[2]);
                message.append("' criado com sucesso \n");
                cout << message;
            } else {
                //dividir o argv[1] e checar se ta certo
                
                
                ifstream myFile(argv[2], ios::binary);
                //checar se tem arquivo
                AddressList addressList(myFile);
                cout << "Favor escrever um conjunto de comandos v�lido\n";
            }
            break;
        default:
            cout << "Favor escrever um conjunto de comandos v�lido\n";
            break;
    }
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

    abrir o arquivo bin�rio de endere�os

    while(!eof){
        endere�o = endere�o do arquivo binario gerado pelo gerador
        tag = endere�o >> (Nbits_indice + N_offset);
        indice = endere�o >> n_offset && (2^Nbits_indice -1)

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
