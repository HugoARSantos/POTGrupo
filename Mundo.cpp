/* 
 * File:   Mundo.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"


#include <iostream>
Mundo::Mundo(int dim) {
    x=dim;
    
}

Mundo::Mundo(const Mundo& orig) {
}
void Mundo::MostraMundo(){

}
int Mundo::VerificaPosicao(int x, int y){
    if(matriz[x][y]==0){
        return 1;
    }
    return 0;
    }

Mundo::~Mundo() {
}
