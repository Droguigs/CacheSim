//
//  main.cpp
//  CacheSim
//
//  Created by Douglas Schiavi and Giorgio Rossa
//  Copyright � 2019 Douglas Schiavi. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <fstream>

#include "Cache.h"
#include "CacheTxtGenerator.h"
#include "AddressList.h"

using namespace std;

int main(int argc, char *argv[]){

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



                //checar se tem arquivo
                ifstream source;
                source.open(myFile,ios::binary);
                if(source.fail()){
                    cout << "Favor escrever um conjunto de comandos valido\n" <<endl;
                    break;
                }
                source.close();

                AddressList addressList(argv[2]);


            }
            break;
        default:
            cout << "Favor escrever um conjunto de comandos v�lido\n";
            break;
    }
    return 0;

}
