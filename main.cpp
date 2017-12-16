/* 
 * File:   main.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"


int main() {
    Comandos consola;
    if (consola.configuracao() == 1)
        consola.simulacao();
    
}

