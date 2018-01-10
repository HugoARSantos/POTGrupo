/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Migalha.h
 * Author: marti
 *
 * Created on 8 de Janeiro de 2018, 22:44
 */

#ifndef MIGALHA_H
#define MIGALHA_H
#include <string>
#include <iostream>

using namespace std;

class Migalha {
    int energia_incial;
    int energia;
    int posx;
    int posy;
public:
    Migalha(int e,int x,int y){
        energia=e;
        energia_incial=e;
        posx=x;
        posy=y;
        //cout << "Migalha construida" << endl;
    }
    Migalha(const Migalha& orig);
    void setPosx(int x);
    void setPosy(int y);
    int getEnergia(){return energia;}
    int getPosX(){return posx;}
    int getPosY(){return posy;}
    bool verificaEnergia();
    bool removeEnergia(int x);
    virtual ~Migalha();
    string getAsString();

};

#endif /* MIGALHA_H */

