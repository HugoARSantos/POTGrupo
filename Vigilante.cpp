/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vigilante.cpp
 * Author: marti
 * 
 * Created on 10 de Janeiro de 2018, 21:53
 */

#include "Vigilante.h"

Vigilante::Vigilante(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,150,7,5,'V',75){
    
};
Vigilante::Vigilante(int posxx,int posyy):Formiga(posxx,posyy,150,7,5,'V',75){
    
};
bool Vigilante::regraProcuraMigalha(){
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
bool Vigilante::verificaRegras() {
    if(regraProcuraMigalha()==true)
        return true;
    regraPasseia();
    return true;
}

Vigilante::~Vigilante() {
}
Formiga * Vigilante::duplica() const{
return new Vigilante(*this);    
}
