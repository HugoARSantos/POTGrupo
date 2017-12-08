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


using namespace std;

class Formiga {
    private:
        int x;
        int y;
        int energia_inicial;
        int energia;
        
public:
    Formiga(int posx,int posy,int e_inicial);
    int getX(){return x;}
    int getY(){return y;}
    void getEnergiaInicial(){return energia_inicial;}
    void getEnergia(){return energia;}
    string getAsString();
    
    
        void SetXY(int posx,int posy);
        void SetEnergia(int e);
    
   
    Formiga(const Formiga& orig);
    virtual ~Formiga();


};

#endif /* FORMIGA_H */

