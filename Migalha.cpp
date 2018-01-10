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
#include <sstream>
#include <iostream>
using namespace std;

Migalha::Migalha(const Migalha& orig) {
    *this=orig;
}

Migalha::~Migalha() {
   
    delete this;
}
bool Migalha::verificaEnergia(){
    int x;
    x=energia/energia_inicial;
    
    
    if((energia/energia_inicial)< 0.1){
        
        return true;
       
    }
    return false;
}


string Migalha::getAsString(){
    ostringstream oss;
    oss << "Migalha: PosX:" << posx << " PosY:" << posy << endl;
    return oss.str();
}
void Migalha::setEnergia(int x){
    energia+=x;
   
}