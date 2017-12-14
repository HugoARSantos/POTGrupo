/* 
 * File:   Comandos.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"

using namespace std;
        
        
Comandos::Comandos() {
}
Comandos::Comandos(const Comandos& orig) {
}
Comandos::~Comandos() {
}

void Comandos:: defMundo(int i){
    lim = i;
}

void Comandos:: defEnergia(int i){   //defen Energia dos ninhos quando são criados pode
    nenergia = i;                     //ser alterado durante a simulação por isso
}                                     //é diferente de energia inicial dos ninhos

void Comandos::defPercentagemCriarFormiga(int i){   //defpc
    transferencia = i;               
}                               
void defValorTransferencia(int i){   //defvt
    transferir = i;               
}                               
void defMigalhasIniciais(int i){   //defmi 0 a 100
    if (i>= && i <=100)
        percentagem = i;
}                               
void defEnergiaMigalhas(int i){   //defme
    menergia = i;              
}                               
void defNunmeroMigalhas(int i){   //defNM
    mmigalhas = i;                //valor de migalhas criadas a cada 
}                                 //instance varia entre 0 e este valor

void executa(string ficheiro){}

void inicio(){}