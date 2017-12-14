/* 
 * File:   main.cpp
 * Authors: Alheirium & Pepe
 */

#include "Mundo.h"
#include "Ninho.h"
#include "Formiga.h"
#include "Comandos.h"

#include <cstdlib>
#include <iostream>

using namespace std;


extern int lim;                     //Limite do mundo, não pode ser alterado durante a simulação
extern int nenergia;                //Energia inicial dos ninhos
extern int menergia;                //Energia inicial das migalhas
extern int percentagem;             //Posiçoes vazias ocupadas por migalhas ao inicio
extern int transferencia;           //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
extern int transferir = 1;          //Unidade de energia transferida entre ninho e formiga por iteração
extern int mmigalhas;               //maximo de migalhas criadas a cada instance
extern int idNinho = 1;             

int main() {
    Formiga a(1,2,10);
    cout << a.getAsString();
}

