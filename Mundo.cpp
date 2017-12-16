/* 
 * File:   Mundo.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"
#include "Exploradora.h"
#include "Formiga.h"
#include "Ninho.h"

#include <iostream>


Mundo::Mundo(const Mundo& orig) {
}
void Mundo::MostraMundo(){

}
int Mundo::VerificaPosicao(int xx, int yy){

    if(tab[xx][yy]==0){
        return 1;}
    else
        
    return -1;
}
void Mundo::preencheMatriz(){
    //1- Ninho
    //2-Exploradora
    int auxx;
    int auxy;
    int auxF;
    for(unsigned int i =0;i<ninhos.size();i++){
        auxx=ninhos[i]->getX();
        
        auxy=ninhos[i]->getY();
        tab[auxx][auxy]=1;
        auxF=ninhos[i]->gettamanhoVetor();
        for(int j=0;j<auxF;j++){
           auxx = ninhos[j]->retornaPosxy(j,0);
           auxx=ninhos[j]->retornaPosxy(j,1);
           tab[auxx][auxy]=2;

        }
    }
   
    
    //}
}
Mundo::~Mundo() {
}


