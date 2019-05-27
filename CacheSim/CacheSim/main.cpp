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
#include <sstream>
#include <math.h>
#include "Cache.h"
#include "CacheTxtGenerator.h"
#include "AddressList.h"
#include "AnswerList.h"

using namespace std;

void printAnswers(AnswerList answers){

    cout << "Resultado da simulação:" <<endl;
    cout << "Número acessos: 131000" << endl;
    cout << "Número de Hits: " << answers.getHits() << " Hit Ratio: "<< answers.getHits()/131000.0 << endl;
    cout << "Número de Misses: " << answers.getMisses() << " Miss Ratio: "<< answers.getMisses()/131000.0<< endl;
    cout << "Número de Misses de conflito: " << answers.getConflictMisses() << endl;
    cout << "Número de misses compulsórios: "<< answers.getCompulsoryMisses() << endl;
    cout << "Número de misses de capacidade: "<< answers.getCapacityMisses() << endl;


}

vector<string> split(const string& s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main(int argc, char *argv[]){

    switch (argc) {
        case 1:{

            //run cache bench on default
            CacheTxtGenerator cacheDefaultI;
            cacheDefaultI.createTxt("default");

            AddressList addressListIns("default",log2(256),log2(4));

            Cache L1(255,1,0);
            list<Answer> L1Misses = L1.getAllHits(addressListIns);

            AnswerList answerList(L1Misses);

            printAnswers(answerList);


            break;
        }
        case 2:{
            if (!(strcmp(argv[0], "default"))) {
                //run cache on default configuration

                CacheTxtGenerator cacheDefaultI;
                cacheDefaultI.createTxt("default");

                AddressList addressListIns("default",log2(256),log2(4));

                Cache L1(255,1,0);
                list<Answer> L1Misses = L1.getAllHits(addressListIns);

                AnswerList answerList(L1Misses);

                printAnswers(answerList);


            } else if (!strcmp(argv[1], "generate")){
                CacheTxtGenerator cache;
                cache.createTxt("arquivo_de_entrada");
                cout << "arquivo 'arquivo_de_entrada' criado com sucesso \n";
            } else {
                cout << "Favor escrever um conjunto de comandos v�lido\n";
            }
            break;
        }

        case 3:{
            if (!(strcmp(argv[1], "generate"))) {
                CacheTxtGenerator cache;
                cache.createTxt(argv[2]);
                string message = "arquivo '";
                message.append(argv[2]);
                message.append("' criado com sucesso \n");
                cout << message;
            } else {
                //dividir o argv[1] e checar se ta certo
                vector<string> argumentos;

                argumentos = split(argv[1],':');

                if(argumentos.size()!= 4){
                    cout << "Favor escrever um conjunto de comandos valido\n";
                    break;
                }
                //stringstream stream(argumentos.at(0));
                //stream >> nSets;

                int nSets = stoi(argumentos.at(0));
                int bSize = stoi(argumentos.at(1));
                int ass = stoi(argumentos.at(2));
                int escolhaSub = stoi(argumentos.at(3));


                //checar se tem arquivo
                ifstream source;
                source.open(argv[2],ios::binary);
                if(source.fail()){
                    cout << "Favor escrever um conjunto de comandos valido\n";
                    break;
                }
                source.close();

                AddressList addressList(argv[2],(int)log2(nSets),(int)log2(bSize));


                Cache L1(nSets,ass,escolhaSub);

                list<Answer> L1Misses = L1.getAllHits(addressList);
                AnswerList answerList(L1Misses);

                printAnswers(answerList);


            }
            break;
        }

        default:{
            cout << "Favor escrever um conjunto de comandos valido\n";
            break;
        }

    }
    return 0;

}
