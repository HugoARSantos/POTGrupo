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
    void executa(string ficheiro);
    int inicio();

    int simulacao();
    void criaNinho(int i,int j);
    void criaFormigas(int i, char a, int j);
    void criaFor(int i, int j, int k, int l);
    void criaMigalha(int i, int j);
    void foca(int i, int j);
    void tempo();
    void tempo(int i);
    void addEnergiaNinho(int i, int j);
    void addEnergiaNinho(int i, int j, int k);
    void mataFormiga(int i, int j);
    void insecticida(int i);
    void listaMundo();
    void listaNinho(int i);
    void listaPosicao(int i,int j);
    void guardaMundo(string nome);
    void mudaMundo(string nome);
    void apagaMundo(string nome);
    void sair();
};

#endif /* COMANDOS_H */

