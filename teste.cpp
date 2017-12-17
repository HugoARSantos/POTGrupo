/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teste.cpp
 * Author: marti
 * 
 * Created on 17 de Dezembro de 2017, 23:36
 */
#include "Comandos.h"
#include "Mundo.h"
#include "Simulacao.h"
#include "Ninho.h"
#include "Exploradora.h"
#include "Formiga.h"
#include <string>
#include <iostream>
#include "teste.h"

teste::teste(){
    testar();
}
void teste::testar(){
    Mundo m(10);
    Ninho n (1,2,3,&m);
    cout<<n.getAsString();
    
}