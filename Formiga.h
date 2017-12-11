/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Formiga.h
 * Author: marti
 *
 * Created on 7 de Dezembro de 2017, 23:59
 */

#ifndef FORMIGA_H
#define FORMIGA_H
#include <string>

using namespace std;
class Ninho;
class Formiga {
    private:
        int x;
        int y;
        int energia_inicial;
        int energia;
        const Ninho *n;
public:
    Formiga(int posx,int posy,int e_inicial);
    int getX(){return x;}
    int getY(){return y;}
    int getEnergiaInicial(){return energia_inicial;}
    int getEnergia(){return energia;}
    string getAsString();
    int Movformiga();
    
    
        void SetXY(int x,int y);
        void SetEnergia(int e);
    
   
    Formiga(const Formiga& orig);
    virtual ~Formiga();


};

#endif /* FORMIGA_H */

