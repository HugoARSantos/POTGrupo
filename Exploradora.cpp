/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exploradora.cpp
 * Author: marti
 * 
 * Created on 15 de Dezembro de 2017, 17:01
 */

#include "Exploradora.h"


Exploradora::Exploradora(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,200,10,8,'E'){
    
};
Exploradora::Exploradora(int posxx,int posyy):Formiga(posxx,posyy,200,10,8,'E'){
    
};

Exploradora::~Exploradora() {
}
Formiga * Exploradora::duplica() const{
return new Exploradora(*this);    
}
void Exploradora::regraComeMigalha(){
    Ninho *n;
    int e;
    n=getNinho();
    
    e=n->getEnergiaMigalha(getX(),getY());
    SetEnergia(e);
}

