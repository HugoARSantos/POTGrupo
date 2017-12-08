/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ninho.h
 * Author: marti
 *
 * Created on 7 de Dezembro de 2017, 23:59
 */

#ifndef NINHO_H
#define NINHO_H
#include <vector>
class Formiga;
class Ninho {
    private:
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        vector<Formiga *>formiga;
        
        static int sequencia;
public:
    Ninho();
    Ninho(const Ninho& orig);
    virtual ~Ninho();


};

#endif /* NINHO_H */

