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

Cuidadora::Cuidadora(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,100,5,3,'C'){
    
};
Cuidadora::Cuidadora(int posxx,int posyy):Formiga(posxx,posyy,100,5,3,'C'){
    
};

Cuidadora::~Cuidadora() {
}
Formiga * Cuidadora::duplica() const{
return new Cuidadora(*this);    
}
void Cuidadora::regraComeMigalha(){
    
//    Ninho *n;
//    int e;
//    
//    n=getNinho();
//    
//    e=n->getEnergiaMigalha(getX(),getY());
//   
//    SetEnergia(e);

}

