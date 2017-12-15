/* 
 * File:   Mundo.h
 * Authors: Alheirium & Pepe
 */

#ifndef MUNDO_H
#define MUNDO_H
#include "Ninho.h"
#include <vector>
class Mundo {
 
    vector<Ninho *> ninhos;

public:
    Mundo(int dim);
    void MostraMundo();
    Mundo(const Mundo& orig);
    virtual ~Mundo();
    int VerificaPosicao(int x,int y);
private:

};

#endif /* MUNDO_H */

