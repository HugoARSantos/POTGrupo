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
    
    
    vector<Ninho *> ninhos;
    int tab[10][10]={0};
    
public:
    
    Mundo(int dim){};
    void MostraMundo();
    Mundo(const Mundo& orig);
    void preencheMatriz();
    virtual ~Mundo();
    int VerificaPosicao(int xx,int yy);
private:

};

#endif /* MUNDO_H */

