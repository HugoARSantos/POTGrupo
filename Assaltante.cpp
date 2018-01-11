/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assaltante.cpp
 * Author: marti
 * 
 * Created on 10 de Janeiro de 2018, 22:05
 */

#include "Assaltante.h"

Assaltante::Assaltante(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,80,8,4,'A',25){
    
};
Assaltante::Assaltante(int posxx,int posyy):Formiga(posxx,posyy,80,8,4,'A',25){
    
};
bool Assaltante::regraProcuraMigalha(){
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
bool Assaltante::verificaRegras() {
   
    if(regraProcuraMigalha()==true)
        return true;
    
    return false;
}

Assaltante::~Assaltante() {
}
Formiga * Assaltante::duplica() const{
return new Assaltante(*this);    
}
