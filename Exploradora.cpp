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

Exploradora::Exploradora(int i,int posx,int posy,const Ninho & n):Formiga(i,posx,posy,200,10,8,n){
}

Exploradora::Exploradora(const Exploradora& orig) {
}

Exploradora::~Exploradora() {
}

