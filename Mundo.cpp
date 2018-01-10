/* 
 * File:   Mundo.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"
#include "Exploradora.h"
#include "Cuidadora.h"
#include "Formiga.h"
#include "Ninho.h"
#include "Migalha.h"
#include "Assaltante.h"
#include "Surpresa.h"
#include "Vigilante.h"
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
    

int Mundo::nEspacosVazios(){
    int cont=0;
    for(int i=0;i<dim;++i){
        for(int j=0;j<dim;++j){
            if(tab[i][j]== '-')
                cont++;
        }}
    return cont;
}
Mundo::Mundo(const Mundo& orig) {
}
string Mundo::MostraMundo(){
    ostringstream oss;
     for(int i=0;i<dim;i++){
        oss<<"\n";
        for (int j=0;j<dim;j++){
            oss<< tab[i][j];
        }
     }
    oss << endl;
    return oss.str();
        
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
char Mundo::listaPosicao(int x, int y) {
    char i=tab[x-1][y-1];
    return i;
    
}
int Mundo::VerificaPosicao(int xx, int yy){

    if(tab[xx-1][yy-1]=='-'){
        return 1;}
    else
        
    return -1;
}
void Mundo::preencheMatriz(){
   
    int auxx;
    int auxy;
    int auxF;
    char auxC;
     for(int i=0;i<dim;++i){
        for(int j=0;j<dim;++j){
            tab[i][j]='-';
        }
    
    for(int i=0;i<migalhas.size();i++){
           auxx = migalhas[i]->getPosX();
           auxy = migalhas[i]->getPosY();
           tab[auxx-1][auxy-1]='m';
    }
       
    for(int i =0;i<ninhos.size();i++){
         auxF=ninhos[i]->gettamanhoVetor();
         
        for(int j=0;j<auxF;j++){
           
           auxx = ninhos[i]->retornaPosxy(j,0);
           auxy = ninhos[i]->retornaPosxy(j,1);
           auxC=ninhos[i]->retornaTipo(auxx,auxy);
           tab[auxx-1][auxy-1]=auxC;

        
      }}
        
    for( int i =0;i<ninhos.size();i++){
        auxx=ninhos[i]->getX();
        
        auxy=ninhos[i]->getY();
       
        tab[auxx-1][auxy-1]='N';
    }
      
  
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
    if (ninho == nullptr || pesquisa(ninho->getId()) != -1 ){
        return false;}
     
    ninhos.push_back(ninho);
    return true;
}
    
    

string Mundo::getAsString() const{
    ostringstream oss;
    
     /*for(int i=0;i<dim;i++){
         oss<<"\n";
        for (int j=0;j<dim;j++){
        
            oss<< tab[i][j];}
     }*/
      
    oss<<"\nElementos\n";
    for(int k=0;k<ninhos.size();k++){
        oss<<ninhos[k]->getAsString();
    }
    
        for(int k=0;k<migalhas.size();k++){
        oss<<migalhas[k]->getAsString();
     
    }
    oss << endl << migalhas.size() << endl;
    return oss.str();
}

string Mundo::ListaNinho(int i){
    ostringstream oss;
    oss << ninhos[i-1]->getAsStringTwo();
    return oss.str();
}

void Mundo::acrescentaEnergiaNinho(int i, int j){
    if (ninhos[i-1]->getEnergia()+j<=0){
        cout << "Nao pode tornar a energia do ninho nula ou negativa" << endl;
        getch();
    }
    else 
        ninhos[i-1]->setEnergia(j);
}


Mundo::~Mundo() {
    for(int i=0;i<dim;i++){
        delete tab[i];
       
        }
    
    
    delete tab;
}


void Mundo::adicionaMigalhas(int ee,int xx){
   
//    int aux=calculaQuantasMigalhas(xx);
    int aux = dim*dim*xx/100;

    int auxx,auxy;
    for (int i=0;i<aux;i++){
       
        do{
            preencheMatriz();
            auxx=rand()%dim+1;
            auxy=rand()%dim+1;
        }while(VerificaPosicao(auxx,auxy)==-1);
         Migalha *m= nullptr;
         m =new Migalha(ee,auxx,auxy);        
        migalhas.push_back(m);
    
    }
   preencheMatriz();   
}
int Mundo::getEnergiaMigalha(int x, int y){
    int aux;
   // cout<<"yolo";
    for(int i=0;i<migalhas.size();i++){
        
        if(migalhas[i]->getPosX()==x && migalhas[i]->getPosY()==y){
            aux=migalhas[i]->getEnergia();
            
            migalhas[i]->setEnergia(-aux);
//            cout<<i<<"yolo\n";
             verificaMigalhas();
            return aux;
        }
    }
   
}
void Mundo::verificaMigalhas(){
    bool x;
    for(int i=0;i<migalhas.size();++i){
        x=migalhas[i]->verificaEnergia();
    if(x==true){
//        cout<<"yolo";
//        delete migalhas[i];
////        cout<<"yolo";
        migalhas.erase(migalhas.begin()+i);
          //cout<<migalhas.size()<<"\n";//Para concluiur que quando se cria alguma coisa no mundo tem que se remover as migalhas.
    }
    
    }
    preencheMatriz();
}

string Mundo::guardaMundo(){
    ostringstream oss;
    for(int k=0;k<ninhos.size();k++){
        oss << "Ninho " <<ninhos[k]->getId() << " " <<ninhos[k]->getX() 
                << " " <<ninhos[k]->getY() << " " <<ninhos[k]->getEnergia() 
                << " " <<ninhos[k]->getEnergiaInicial() << endl;
        oss << ninhos[k]->guardaFormiga();
    }
    
        for(int k=0;k<migalhas.size();k++){
        oss<<"Migalha " << migalhas[k]->getPosX() << " " << migalhas[k]->getPosY() << " " 
                << migalhas[k]->getEnergia() <<" " << migalhas[k]->getEnergiaInicial()<< endl ;
     
    }
    return oss.str();
}

ostream & operator<<(ostream & saida, const Mundo & x) {
    saida << x.getAsString();
    return saida;
}

void Mundo::acrescentaMigalha(int e,int x,int y){
        Migalha *m= nullptr;
        m =new Migalha(e,x,y);        
        migalhas.push_back(m);
}

void Mundo::acrescentaFormigas(int idn,char t,int q){
    int x, y;
//    Ninho *n = nullptr;
//    for(int k=0;k<ninhos.size();k++){
//        if (ninhos[k]->getId() == idn)
//            Ninho *n = ninhos[k]->getPonteiro();
//    }
    
    for (int i =0; i < q; i++){
        if (t=='E'){
            x = rand()% dim+1;
            y = rand()% dim+1;
            Exploradora *e= nullptr;
            e = new Exploradora (x,y);        
            acrescentaFormiga(e,idn);
       }
    }
    
    for (int i =0; i < q; i++){
        if (t=='C'){
            x = rand()% dim+1;
            y = rand()% dim+1;
            Cuidadora *c= nullptr;
            c = new Cuidadora (x,y);        
            acrescentaFormiga(c,idn);
       }
    }
    
        for (int i =0; i < q; i++){
        if (t=='V'){
            x = rand()% dim+1;
            y = rand()% dim+1;
            Vigilante *v= nullptr;
            v = new Vigilante (x,y);        
            acrescentaFormiga(v,idn);
       }
    }
    
        for (int i =0; i < q; i++){
        if (t=='A'){
            x = rand()% dim+1;
            y = rand()% dim+1;
            Assaltante *a= nullptr;
            a = new Assaltante (x,y);        
            acrescentaFormiga(a,idn);
       }
    }
    
        for (int i =0; i < q; i++){
        if (t=='S'){
            x = rand()% dim+1;
            y = rand()% dim+1;
            Surpresa *s= nullptr;
            s = new Surpresa (x,y);        
            acrescentaFormiga(s,idn);
       }
    }
}

void Mundo::acrescentaForm(int idn,char tipo, int l,int c){
    Ninho *n = nullptr;
    for(int k=0;k<ninhos.size();k++){
        if (ninhos[k]->getId() == idn)
            Ninho *n = ninhos[k]->getPonteiro();
    }
        
        if (tipo=='E'){
            Exploradora *e= nullptr;
            e = new Exploradora (l,c,n);
            acrescentaFormiga(e,idn);
        }
    
        if (tipo=='C'){
            Cuidadora *cui= nullptr;
            cui = new Cuidadora(l,c,n);
            acrescentaFormiga(cui,idn);
        }
    
        if (tipo=='A'){
            Assaltante *a= nullptr;
            a = new Assaltante(l,c,n);
            acrescentaFormiga(a,idn);
        }
    
        if (tipo=='V'){
            Vigilante *v= nullptr;
            v = new Vigilante(l,c,n);
            acrescentaFormiga(v,idn);
        }
    
        if (tipo=='S'){
            Surpresa *s= nullptr;
            s = new Surpresa (l,c,n);        
            acrescentaFormiga(s,idn);
        }
}

void Mundo::avanca(){

        
    for( int i =0;i<ninhos.size();i++){
        ninhos[i]->mexeFormiga();
    }
    
    for(int i=0;i<migalhas.size();i++){
        migalhas[i]->setEnergia(- 1);
        verificaMigalhas();
    }

    
}