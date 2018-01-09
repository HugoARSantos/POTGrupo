/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Migalha.cpp
 * Author: marti
 * 
 * Created on 8 de Janeiro de 2018, 22:44
 */

#include "Migalha.h"



Migalha::Migalha(const Migalha& orig) {
    *this=orig;
}

Migalha::~Migalha() {
}
bool Migalha::verificaEnergia(){
    if(energia_incial/energia<10)
        return true;
    return false;
}
bool Migalha::removeEnergia(int x){
    energia-=(1+x);
    if(this->verificaEnergia()==true)
    {
        return true;
    }
    return false;
}