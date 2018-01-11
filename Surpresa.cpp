/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Surpresa.cpp
 * Author: marti
 * 
 * Created on 10 de Janeiro de 2018, 22:09
 */

#include "Surpresa.h"

Surpresa::Surpresa(int posxx,int posyy, Ninho *nn):Formiga(posxx,posyy,nn,80,8,4,'S',100){
    
};
Surpresa::Surpresa(int posxx,int posyy):Formiga(posxx,posyy,80,8,4,'S',100){
    
};

Surpresa::~Surpresa() {
}
Formiga * Surpresa::duplica() const{
return new Surpresa(*this);    
}
