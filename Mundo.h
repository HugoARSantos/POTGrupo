/* 
 * File:   Mundo.h
 * Authors: Alheirium & Pepe
 */

#ifndef MUNDO_H
#define MUNDO_H
#include "Ninho.h"
#include <vector>

class Formiga;
class Mundo {
    
    int dim;
    vector<Ninho *> ninhos;
    int tab[10][10];
    int pesquisa(int idd)const;
public:
    
    Mundo(int x);
    void MostraMundo();
    Mundo(const Mundo& orig);
    void preencheMatriz();
    bool acrescentaFormiga(Ninho * ninho);
    int getNninhos(){return ninhos.size();};
    virtual ~Mundo();
    int VerificaPosicao(int xx,int yy);
    string getAsString()const;


};
ostream & operator<<(ostream & saida, const Mundo & x);

#endif /* MUNDO_H */

