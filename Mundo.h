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
#include "Ninho.h"
class Formiga;
class Ninho;
class Mundo {
    
    int dim;
    vector<Ninho *> ninhos;
    char **tab;
    int pesquisa(int idd)const;
public:
    
    Mundo(int x);
    void MostraMundo();
    Mundo(const Mundo& orig);
    void preencheMatriz();
    bool acrescentaNinho(Ninho * ninho);
    bool acrescentaFormiga(Formiga *f,int id);
    int getDim()const{return dim;}
    int getNninhos(){return ninhos.size();};
    virtual ~Mundo();
    int VerificaPosicao(int xx,int yy);
    string getAsString()const;
    string listaPosicao(int x,int y)const;

};
ostream & operator<<(ostream & saida, const Mundo & x);

#endif /* MUNDO_H */

