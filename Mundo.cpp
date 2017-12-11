/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mundo.cpp
 * Author: marti
 * 
 * Created on 8 de Dezembro de 2017, 0:00
 */

#include "Mundo.h"


#include <iostream>
Mundo::Mundo(int dim) {
    x=dim;
    
}

Mundo::Mundo(const Mundo& orig) {
}
void Mundo::MostraMundo(){

}
int Mundo::VerificaPosicao(int x, int y){
    if(matriz[x][y]==0){
        return 1;
    }
    return 0;
    }

Mundo::~Mundo() {
}
