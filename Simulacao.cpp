/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulacao.cpp
 * Author: Hugo
 * 
 * Created on 17 de Dezembro de 2017, 17:36
 */

#include "Simulacao.h"

Simulacao::Simulacao(int l, int n, int menergia, int e, int t, int p ,int nm) {
    Mundo m(l);
    lim = l;
    nenergia = n;                //Energia inicial dos ninhos
    menergia = menergia;                //Energia inicial das migalhas
    energianovaformiga = e;      //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
    transferir = t;              //Unidade de energia transferida entre ninho e formiga por iteração
    percentagem = p;             //Posiçoes vazias ocupadas por migalhas ao inicio
    nmigalhas = nm;               //maximo de migalhas criadas a cada instance
}

Simulacao::Simulacao(const Simulacao& orig) {
}

Simulacao::~Simulacao() {
}

int Simulacao::simula(){
   /* string op,nficheiro;
    string a,b,c;
    int i, j, k, l ;
    bool run = true;
    do{
    system("cls");
    cout << "Introduza um comando: ";
    getline(cin, op);
    
    istringstream iss(op);
    iss >> op;        
    if (op == "defen"){
        iss >> i;
        defEnergia(i);
    }
    
    else if (op == "defpc"){
        iss >> i;
        defPercentagemCriarFormiga(i);
    }
    else if (op == "defvt"){
        iss >> i;
        defValorTransferencia(i);
    }
    
    else if (op == "defmi"){
        iss >> i;
        defMigalhasIniciais(i);
    }
    
    else if (op == "defme"){
        iss >> i;
        defEnergiaMigalhas(i);
    }
    
    else if (op == "defnm"){
        iss >> i;
        defNumeroMigalhas(i);
    }
    
    else if (op == "executa"){
        iss >> nficheiro;
        executa(nficheiro);
    }
    
    else if (op == "sair"){
        return 0;
    }  
    
    else if (op == "ninho"){
        iss >> i;
        iss >> j;
        criaNinho(i,j);
    }
    
    else if (op == "criaf"){
        iss >> i;
        iss >> a;
        iss >> j;
        criaFormigas(i,a,j);
    }
    else if (op == "tempo"){
        tempo();
    }
    else if (op == "listamundo"){
        listaMundo();
    }
    else if (op == "listaninho"){
        iss >> i;
        listaNinho(i);
    }
    
    else if (op == "listaposicao"){
        iss >> i;
        iss >> j;
        listaPosicao(i,j);
    }
    
    }while (run == true);*/
    return 0;
}

void Simulacao::criaNinho(int i, int j){
    if (i<0 || i >= lim)
        cout << "Linha invalida" << endl;
    if (j<0 || j >= lim)
        cout << "Coluna invalida" << endl;
    if (i>=0 && i < lim && j>=0 && j < lim)
        //Cria ninho nesta posicao
        cout << "Ninho criado em X:" << i << " Y:" <<j << endl;
}

void Simulacao::criaFormigas(int i, string a, int j){
    int nninhos = 5;
    if (i<1)
        cout << "Introduza um numero de formigas valido" << endl;
    if (a != "E")
        cout << "Introduza um tipo valido" << endl;
    if (j > nninhos || j < 1)
        cout << "O ninho que indicou nao existe" << endl;
    if (i>=1 && a== "E" && j <= nninhos && j>0)
        cout << i << " formigas do tipo " << a << " foram acrescentadas ao ninho " << j << endl;
}

void Simulacao::tempo(){
    
}

void Simulacao::listaMundo(){
}

void Simulacao::listaNinho(int i){
    int nninhos = 5;
    if (i > nninhos || i < 1)
       cout << "O ninho que indicou nao existe" << endl;
    if (i <= nninhos && i>0)
        cout << "O ninho " << i << " tem:" << endl;
 }

void Simulacao::listaPosicao(int i, int j){
    if (i<0 || i >= lim)
        cout << "Linha invalida" << endl;
    if (j<0 || j >= lim)
        cout << "Coluna invalida" << endl;
    if (i>=0 && i < lim && j>=0 && j < lim)
        //Cria ninho nesta posicao
        cout << "Na posicao X:" << i << " Y:" <<j << " existe: "<< endl;
}