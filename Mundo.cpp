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
    tab =new char *[dim];
    for(int i=0;i<dim;++i){
        
        tab[i]=new char [dim];}
    for(int i=0;i<dim;++i)
        for(int j= 0;j<dim;++j){
            tab[i][j]='-';
        }
    }
    

Mundo::Mundo(const Mundo& orig) {
}
void Mundo::MostraMundo(){

}
bool Mundo::acrescentaFormiga(Formiga* f, int id){
    int aux=pesquisa(id);
    if(aux==-1)
    {
            
  return false;
    }
    Ninho * n=ninhos[aux]->getPonteiro();
    f->setNinho(n);
    ninhos[aux]->acrescentaFormiga(f);
    return true;
          
}
string Mundo::listaPosicao(int x, int y) const{
    char i=tab[x][y];
    if(i=='-')
        return "Vazia";   
        return "yolo";
    
}
int Mundo::VerificaPosicao(int xx, int yy){

    if(tab[xx][yy]=='-'){
        return 1;}
    else
        
    return -1;
}
void Mundo::preencheMatriz(){
   
    int auxx;
    int auxy;
    int auxF;
     for(int i=0;i<dim;++i)
        for(int j= 0;j<dim;++j){
            tab[i][j]='-';
        }
    for( int i =0;i<ninhos.size();i++){
        auxx=ninhos[i]->getX();
        
        auxy=ninhos[i]->getY();
       
        tab[auxx-1][auxy-1]='N';
    }
      for(int i =0;i<ninhos.size();i++){
         auxF=ninhos[i]->gettamanhoVetor();
        for(int j=0;j<auxF;j++){
           
           auxx = ninhos[i]->retornaPosxy(j,0);
           auxy=ninhos[i]->retornaPosxy(j,1);
           tab[auxx-1][auxy-1]='E';

        
      }}
}
    
    //}}

int Mundo::pesquisa(int idd) const{
    
    for (unsigned int i = 0; i < ninhos.size(); i++)
        if (ninhos[i]->getId() == idd){
            return i; 
        }
    return -1;
}
bool Mundo::acrescentaNinho(Ninho* ninho){
    if (ninho == nullptr || pesquisa(ninho->getId()) != -1){
        return false;}
     
    ninhos.push_back(ninho);
    return true;
}
    
    

string Mundo::getAsString() const{
    ostringstream oss;
    
     for(int i=0;i<dim;i++){
         oss<<"\n";
        for (int j=0;j<dim;j++){
        
            oss<< tab[i][j];}
     }
      
    oss<<"\nElementos\n";
    for(int k=0;k<ninhos.size();k++){
        oss<<ninhos[k]->getAsString();
     
    }
    return oss.str();
}
Mundo::~Mundo() {
    for(int i=0;i<dim;i++){
        delete tab[i];
       
        }
    
    
    delete tab;
}
ostream & operator<<(ostream & saida, const Mundo & x) {
    saida << x.getAsString();
    return saida;
}

