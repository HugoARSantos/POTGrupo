/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hugo
 *
 * Created on 7 de Dezembro de 2017, 23:46
 */

#include <cstdlib>
#include "Mundo.h"
#include "Formiga.h"
#include <iostream>
#include "Comandos.h"
using namespace std;
extern int lim;                     //Limite do mundo, não pode ser alterado durante a simulação
extern int nenergia;                //Energia inicial dos ninhos
extern int menergia;                //Energia inicial das migalhas
extern int percentagem;             //Posiçoes vazias ocupadas por migalhas ao inicio
extern int transferencia;           //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
extern int nmigalhas;               //Novas migalhas que aparecem a cada interação

int main() {
    Formiga a(1,2,10);
    cout << a.getAsString();
}

