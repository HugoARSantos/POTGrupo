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
extern int nmigalhas;               //Maximo de migalhas migalhas que aparecem a cada interação(entre 0 e este valor)

int main() {
    Formiga a(1,2,10);
    cout << a.getAsString();
}

