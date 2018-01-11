/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuidadora.h
 * Author: marti
 *
 * Created on 10 de Janeiro de 2018, 21:18
 */

#ifndef CUIDADORA_H
#define CUIDADORA_H
#include "Formiga.h"
class Cuidadora:public Formiga {
   private:
        
public:
    Cuidadora(int posxx,int posyy, Ninho * nn);
    Cuidadora(int posxx,int posyy);
    bool regraProcuraMigalha();
    bool verificaRegras();
    bool regrafoge();
    Formiga * duplica()const;
    //Exploradora(const Exploradora& orig);
    virtual ~Cuidadora();


};

#endif /* CUIDADORA_H */

