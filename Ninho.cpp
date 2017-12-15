/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"

Ninho::Ninho() {
}
Ninho::pesquisa(int idd) const{
    
    for (unsigned int i = 0; i < formigas.size(); i++)
        if (formigas[i]->getId() == idd){
            return i; // indice do primeiro livro com este isbn
        }
    return -1;// nao se encontra livro com este isbn
}


    
Ninho::Ninho(const Ninho& orig) {
}

Ninho::~Ninho() {
}

