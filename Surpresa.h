/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Surpresa.h
 * Author: marti
 *
 * Created on 10 de Janeiro de 2018, 22:09
 */

#ifndef SURPRESA_H
#define SURPRESA_H
#include "Formiga.h"
class Surpresa :public Formiga{
   private:
        
public:
    Surpresa(int posxx,int posyy, Ninho * nn);
    Surpresa(int posxx,int posyy);
    bool regraProcuraMigalha(){;}
    Formiga * duplica()const;
    //Exploradora(const Exploradora& orig);
    virtual ~Surpresa();


};

#endif /* SURPRESA_H */

