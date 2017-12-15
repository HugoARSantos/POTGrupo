/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exploradora.h
 * Author: marti
 *
 * Created on 15 de Dezembro de 2017, 17:00
 */

#ifndef EXPLORADORA_H
#define EXPLORADORA_H
#include "Formiga.h"
class Exploradora: public Formiga {
    private:
        
public:
   // Exploradora(int ii,int posxx,int posyy,const Ninho & nn):Formiga(ii,posxx,posyy,&nn){};
    Exploradora(const Exploradora& orig);
    virtual ~Exploradora();


};

#endif /* EXPLORADORA_H */

