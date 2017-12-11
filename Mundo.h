/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mundo.h
 * Author: marti
 *
 * Created on 8 de Dezembro de 2017, 0:00
 */

#ifndef MUNDO_H
#define MUNDO_H

class Mundo {
    int x;
    int matriz[x][x]={0};
public:
    Mundo(int dim);
    void MostraMundo();
    Mundo(const Mundo& orig);
    virtual ~Mundo();
private:

};

#endif /* MUNDO_H */

