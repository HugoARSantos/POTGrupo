/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comandos.h
 * Author: Hugo
 *
 * Created on 11 de Dezembro de 2017, 0:16
 */

#ifndef COMANDOS_H
#define COMANDOS_H

class Comandos {
public:
    Comandos();
    Comandos(const Comandos& orig);
    virtual ~Comandos();
    defMundo(int i){
        lim = i;
    }

};

#endif /* COMANDOS_H */

