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
    int **tab = new int*[dim];

public:
    
    Mundo(int x);
    void MostraMundo();
    Mundo(const Mundo& orig);
    void preencheMatriz();
    int getNninhos(){return ninhos.size();};
    virtual ~Mundo();
    int VerificaPosicao(int xx,int yy);
    string getAsString()const;


};

#endif /* MUNDO_H */

