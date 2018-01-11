/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuidadora.cpp
 * Author: marti
 * 
 * Created on 10 de Janeiro de 2018, 21:18
 */

#include "Cuidadora.h"

Cuidadora::Cuidadora(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,100,5,3,'C',50){
    
};
Cuidadora::Cuidadora(int posxx,int posyy):Formiga(posxx,posyy,100,5,3,'C',50){
    
};
bool Cuidadora::regraProcuraMigalha(){
    Ninho * n=0;
    bool x;
    n=getNinho();
    int aux=getX();
    int auxy=getY();
    int rv=getRVisao();
    int auxx,auyy,ene=0;
    for (int i=(aux-rv);i<(aux+rv);i++)
        for(int j=(auxy-rv);j<(auxy-rv);j++){
            x=n->verificaMigalha(i,j);
            if(x==true){
                if(n->getEnergiaMigalha(i,j)>ene){
                ene=n->getEnergiaMigalha(i,j);
                auxx=i;
                auyy=j;}
            }
            
         
    
}
    if(ene>0){
        move(auxx,auyy);
    return true;
    }
    return false;
}

bool Cuidadora::verificaRegras() {
    if(regrafoge()==true){
          return true;
      }
    if(regraProcuraMigalha()==true)
        return true;
    regraPasseia();
    return true;
}
bool Cuidadora::regrafoge(){
    Ninho * n=0;
    bool x;
    n=getNinho();
    int aux=getX();
    int auxy=getY();
    int rv=getRVisao();
    int auxx=aux,auyy=auxy;
    for (int i=(aux-rv);i<(aux+rv);i++)
        for(int j=(auxy-rv);j<(auxy-rv);j++){
            x=n->verificaFormiga(i,j);
                    if(x==true){
                
                auxx=i;
                auyy=j;}
            }
            
    if(auxx!=aux){
        move(-auxx,-auyy);
    return true;
    }
    return false;
        
    
}
   

Cuidadora::~Cuidadora() {
}
Formiga * Cuidadora::duplica() const{
return new Cuidadora(*this);    
}


