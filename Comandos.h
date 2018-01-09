/* 
 * File:   Comandos.h
 * Authors: Alheirium & Pepe
 */

#ifndef COMANDOS_H
#define COMANDOS_H

#include "Mundo.h"
#include "Ninho.h"
#include "Formiga.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<stdlib.h>
#include <conio.h>

using namespace std;

class Comandos {
public:
    int lim;                     //Limite do mundo, não pode ser alterado durante a simulação
    int nenergia;                //Energia inicial dos ninhos
    int menergia;                //Energia inicial das migalhas
    int energianovaformiga;      //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
    int transferir;              //Unidade de energia transferida entre ninho e formiga por iteração
    int percentagem;             //Posiçoes vazias ocupadas por migalhas ao inicio
    int nmigalhas;               //maximo de migalhas criadas a cada instance            

    Comandos();
    Comandos(const Comandos& orig);
    virtual ~Comandos();
    
    int configuracao();
    void defMundo(int i);
    void defEnergia(int i);
    void defPercentagemCriarFormiga(int i);
    void defValorTransferencia(int i);
    void defMigalhasIniciais(int i);
    void defEnergiaMigalhas(int i);
    void defNumeroMigalhas(int i);
    int executa(string ficheiro);
    int inicio();

    void sair();
};

#endif /* COMANDOS_H */

