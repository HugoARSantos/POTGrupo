/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formiga.cpp
 * Author: marti
 * 
 * Created on 7 de Dezembro de 2017, 23:59
 */

#include "Formiga.h"
#include <string>
#include <sstream>
using namespace std;
Formiga::Formiga(int posx,int posy,int e_inicial) {
//    SetXY(posx,posy);
    energia_inicial=e_inicial;
    energia=e_inicial;
}

Formiga::Formiga(const Formiga& orig) {
}

Formiga::~Formiga() {
}
string Formiga ::  getAsString(){
    ostringstream oss;
    oss << "posX\n"<<x<<"\n"<<"posY\n"<<y<<"\n"<<"Energia inicial\n"<<energia_inicial<<"\n"<<"energia atual\n"<<energia;
    return oss.str();
}
int Formiga::Movformiga(){
    
}