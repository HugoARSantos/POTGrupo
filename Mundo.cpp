/* 
 * File:   Mundo.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"
#include "Exploradora.h"
#include "Formiga.h"
#include "Ninho.h"
#include "Migalha.h"
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

Mundo::Mundo(int x,int pMigalhas,int e ){
    dim=x;
    tab =new char *[dim];
    for(int i=0;i<dim;++i){
        
        tab[i]=new char [dim];}
    for(int i=0;i<dim;++i)
        for(int j= 0;j<dim;++j){
            tab[i][j]='-';
        }
    adicionaMigalhas(e,pMigalhas);
    preencheMatriz();
    }
    
int Mundo::calculaQuantasMigalhas(int x){
    int aux=x*nEspacosVazios()/100;
    cout << "Espacos vazios:" << aux << endl;
    return aux;
}
int Mundo::nEspacosVazios(){
    int cont=0;
    for(int i=0;i<dim;++i)
        for(int j=0;j<dim;++j){
            if(tab[i][j]== '-')
                cont++;
                     }
    return cont;
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
        for(int j=0;j<dim;++j){
            tab[i][j]='-';
        }
      for(int i=0;i<migalhas.size();++i){
           auxx = migalhas[i]->getPosX();
           auxy = migalhas[i]->getPosY();
           tab[auxx][auxy]='c';
    }
    for(int i =0;i<ninhos.size();i++){
         auxF=ninhos[i]->gettamanhoVetor();
        for(int j=0;j<auxF;j++){
           
           auxx = ninhos[i]->retornaPosxy(j,0);
           auxy=ninhos[i]->retornaPosxy(j,1);
           tab[auxx][auxy]='E';

        
      }}
    for( int i =0;i<ninhos.size();i++){
        auxx=ninhos[i]->getX();
        
        auxy=ninhos[i]->getY();
       
        tab[auxx][auxy]='N';
    }
      
  
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
    
        /*for(int k=0;k<migalhas.size();k++){
        oss<<migalhas[k]->getAsString();
     
    }*/
    return oss.str();
}
Mundo::~Mundo() {
    for(int i=0;i<dim;i++){
        delete tab[i];
       
        }
    
    
    delete tab;
}
void Mundo::adicionaMigalhas(int ee,int xx){
   
    int aux=calculaQuantasMigalhas(xx);
    int auxx,auxy;
    //cout << "yo";
    for (int i=0;i<aux;i++){
        do{
            auxx=rand()%dim;
            auxy=rand()%dim;
        }while(VerificaPosicao(auxx,auxy)==-1);
         Migalha *m= nullptr;
         //cout << i;
         m =new Migalha(ee,auxx,auxy);
         //cout << i*10;
        
        
        migalhas.push_back(m);
        //cout << "WHY HAVE YOU FORSAKEN ME";
    
    }
//    prencheMatriz();   
}

void Mundo::verificaMigalhas(){
    for(int i=0;i<migalhas.size();++i){
    if(migalhas[i]->verificaEnergia()==true){
        delete migalhas[i];
        migalhas.erase(migalhas.begin()+i);
    }
    }
}
ostream & operator<<(ostream & saida, const Mundo & x) {
    saida << x.getAsString();
    return saida;
}

