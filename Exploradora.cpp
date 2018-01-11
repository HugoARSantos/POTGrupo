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
#include <iostream>
using namespace std;

Exploradora::Exploradora(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,200,10,8,'E',100){
    
};
Exploradora::Exploradora(int posxx,int posyy):Formiga(posxx,posyy,200,10,8,'E',100){
    
};

Exploradora::~Exploradora() {
}
Formiga * Exploradora::duplica() const{
return new Exploradora(*this);    
}


