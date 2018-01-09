/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulacao.h
 * Author: Hugo
 *
 * Created on 17 de Dezembro de 2017, 17:36
 */

#ifndef SIMULACAO_H
#define SIMULACAO_H

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
#include <stdio.h>


class Simulacao {
public:
    Mundo m;
    int it;
    int lim;
    int nenergia;                //Energia inicial dos ninhos
    int menergia;                //Energia inicial das migalhas
    int energianovaformiga;      //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
    int transferir;              //Unidade de energia transferida entre ninho e formiga por iteração
    int percentagem;             //Posiçoes vazias ocupadas por migalhas ao inicio
    int nmigalhas;               //maximo de migalhas criadas a cada instance  
    
    Simulacao(int l, int n, int menergia, int e, int t, int p ,int nm);

    virtual ~Simulacao();
    void defEnergia(int i);
    void defPercentagemCriarFormiga(int i);
    void defValorTransferencia(int i);
    void defMigalhasIniciais(int i);
    void defEnergiaMigalhas(int i);
    void defNumeroMigalhas(int i);
    //void executa(string ficheiro);
    
    int simula();
    void criaNinho(int i,int j);
    void criaFormigas(int i, string a, int j);
    void criaFor(int i, int j, int k, int l);
    void criaMigalha(int i, int j);
    void foca(int i, int j);
    void tempo(int i);
    void addEnergiaNinho(int i, int j);
    void addEnergiaFormiga(int i, int j, int k);
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

#endif /* SIMULACAO_H */

