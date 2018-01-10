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

Vigilante::Vigilante(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,150,7,5,'V'){
    
};
Vigilante::Vigilante(int posxx,int posyy):Formiga(posxx,posyy,150,7,5,'V'){
    
};

Vigilante::~Vigilante() {
}
Formiga * Vigilante::duplica() const{
return new Vigilante(*this);    
}
void Vigilante::regraComeMigalha(){
//    
//    Ninho *n;
//    int e;
//    
//    n=getNinho();
//    
//    e=n->getEnergiaMigalha(getX(),getY());
//   
//    SetEnergia(e);

}


