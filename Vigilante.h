/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vigilante.h
 * Author: marti
 *
 * Created on 10 de Janeiro de 2018, 21:53
 */

#ifndef VIGILANTE_H
#define VIGILANTE_H
#include "Formiga.h"
class Vigilante :public Formiga{
   private:
        
public:
    Vigilante(int posxx,int posyy, Ninho * nn);
    Vigilante(int posxx,int posyy);
    void regraComeMigalha();
    Formiga * duplica()const;
    //Exploradora(const Exploradora& orig);
    virtual ~Vigilante();


};



#endif /* VIGILANTE_H */

