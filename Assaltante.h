/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assaltante.h
 * Author: marti
 *
 * Created on 10 de Janeiro de 2018, 22:05
 */

#ifndef ASSALTANTE_H
#define ASSALTANTE_H
#include "Formiga.h"
class Assaltante :public Formiga{
   private:
        
public:
    Assaltante(int posxx,int posyy, Ninho * nn);
   Assaltante(int posxx,int posyy);
    void regraComeMigalha();
    Formiga * duplica()const;
    //Exploradora(const Exploradora& orig);
    virtual ~Assaltante();


};
#endif /* ASSALTANTE_H */

