/* 
 * File:   Mundo.h
 * Authors: Alheirium & Pepe
 */

#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <conio.h>
#include <stdio.h>
#include "Ninho.h"
class Formiga;
class Ninho;
class Migalha;
class Mundo {
    
    int dim;
    vector<Ninho *> ninhos;
    vector<Migalha *> migalhas;
    char **tab;
    int pesquisa(int idd)const;
    
    int calculaQuantasMigalhas(int x);
    int nEspacosVazios();
public:
    
    Mundo(int x,int pMigalhas,int e);
    Mundo(int x){x=dim;}
    string MostraMundo();
    string ListaNinho(int i);
    void acrescentaEnergiaNinho(int i, int j);
    void acrescentaFormigas(int idn, char tipo, int quant);
    void acrescentaForm(int idn, char tipo, int l,int c);
    Mundo(const Mundo& orig);
    void preencheMatriz();
    bool eliminaFormiga(int x,int y);
    void adicionaMigalhas(int e,int xx);
    void acrescentaMigalha(int e,int x, int y);
    void verificaMigalhas();
    bool acrescentaNinho(Ninho * ninho);
    bool inseticida(int idd);
    bool acrescentaFormiga(Formiga *f,int id);
    int getDim()const{return dim;}
    int getNninhos(){return ninhos.size();};
    virtual ~Mundo();
    int VerificaPosicao(int xx,int yy);
    string getAsString()const;
    char listaPosicao(int x,int y);
    bool verificaFormigaDiferente(int x,int y,int idd);
    int getEnergiaMigalha(int x,int y,int pper);
    string guardaMundo();
    void avanca();
};
ostream & operator<<(ostream & saida, const Mundo & x);

#endif /* MUNDO_H */

