/* 
 * File:   Mundo.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"
#include "Exploradora.h"
#include "Formiga.h"
#include "Ninho.h"
#include <sstream>
#include <iostream>
using namespace std;

Mundo::Mundo(int x ){
    dim=x;
    for (int i = 0; i< dim; ++i) { tab[i] = new int[dim];
    }
    tab={0};
}
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
string Mundo::getAsString() const{
    ostringstream oss;
    for(int i=0;i<dim;i++){
        oss<<"\n";
        for(int j=0;j<dim;j++)
            oss<<tab[i][j]<<endl;
    }
    oss<<"Elementos\n";
    for(int k=0;k<ninhos.size();k++){
        oss<<ninhos[k]->getAsString();
     
    }
    return oss.str();
}
Mundo::~Mundo() {
    for(int i=0;i<dim;i++){
       
        for(int j=0;j<dim;j++){
            delete &(tab[i][j]);
        }
    }
    
    delete tab;
}


