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

Assaltante::Assaltante(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,80,8,4,'A'){
    
};
Assaltante::Assaltante(int posxx,int posyy):Formiga(posxx,posyy,80,8,4,'A'){
    
};

Assaltante::~Assaltante() {
}
Formiga * Assaltante::duplica() const{
return new Assaltante(*this);    
}
void Assaltante::regraComeMigalha(){
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
