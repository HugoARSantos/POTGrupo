/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"

Ninho::Ninho() {
}
int Ninho::pesquisa(int idd) const{
    
    for (unsigned int i = 0; i < formigas.size(); i++)
        if (formigas[i]->getId() == idd){
            return i; 
        }
    return -1;
}


    
Ninho::Ninho(const Ninho& orig) {
}

Ninho::~Ninho() {
}

