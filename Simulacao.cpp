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

Simulacao::Simulacao(int l, int n, int me, int e, int t, int p ,int nm) {
    //Mundo m(l);
    lim = l;
    nenergia = n;                //Energia inicial dos ninhos
    menergia = me;         //Energia inicial das migalhas
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
    string op,nficheiro;
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
    
    /*else if (op == "executa"){
        iss >> nficheiro;
        executa(nficheiro);
    }*/
    
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
    
    }while (run == true);
    return 0;
}

void Simulacao::criaNinho(int i, int j){
    if (i<0 || i >= lim)
        cout << "Linha invalida" << endl;
    if (j<0 || j >= lim)
        cout << "Coluna invalida" << endl;
    if (i>=0 && i < lim && j>=0 && j < lim)
    {
        cout << "Ninho criado em X:" << i << " Y:" <<j << endl;
    }
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

void Simulacao::defEnergia(int i){   //defen Energia dos ninhos quando são criados pode
    if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia dos ninhos (Acima de 0)." << endl;
    else{                            //ser alterado durante a simulação por isso
        nenergia = i;    
        cout << "A energia dos novos ninhos e: " << nenergia << "." << endl;
    }
}                                   //é diferente de energia inicial dos ninhos

void Simulacao::defPercentagemCriarFormiga(int i){   //defpc
    if (i >= 0 && i <= 100){
        energianovaformiga = i;  
        cout << "Os ninhos vao criar uma formiga assim que tiverem: " 
            << energianovaformiga << "% de energia acima do valor inicial." << endl;
    }
    else{
        cout << "Introduza um valor apropiado para a energia com a qual o ninho "
                "pode criar uma nova formiga(Entre 0 e 100)." << endl;
    }            
}                               
void Simulacao::defValorTransferencia(int i){   //defvt
        if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia transferida do ninho para a formiga." << endl;
    else{                            
        transferir = i;    
        cout << "Os ninhos vao transferir: " << transferir << " unidades de energia por iteracao." << endl;
    }
}                                             
                               
void Simulacao::defMigalhasIniciais(int i){   //defmi 0 a 100
    if (i >= 0 && i <=100){
        percentagem = i;
            cout << "No incio da simulacao as migalhas irao ocupar: " 
            << percentagem << "% das posicoes vazias." << endl;
    }
    else{
        cout << "Introduza um valor apropiado para a percentagem "
                "de celulas vazias ocupadas por migalhas(Entre 0 e 100)." << endl;
    }
}
void Simulacao::defEnergiaMigalhas(int i){   //defme
    if (i<1)
        cout << "Introduza a energiad das migalhas(Acima de 0)." << endl;
    else{
        menergia = i;
        cout << "A energia de novas migalhas e: " << menergia << "." << endl;              
        }
}

void Simulacao::defNumeroMigalhas(int i){   //defnm
     if (i<1)
        cout << "Introduza um valor apropiado maximo de migalhas criadas a cada instante.(Acima de 0)" << endl;
    else{
        nmigalhas = i;
        cout << "A cada interacao serao criadas entre 0 a " << nmigalhas << " migalhas." << endl;              
    }                              //valor de migalhas criadas a cada 
}                                 //instance varia entre 0 e este valor