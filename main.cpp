/* 
 * File:   main.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"


int main() {
    Comandos consola;
    bool run = true;
    do{
    if (consola.configuracao() == 1)
    {
        if(consola.simulacao() == 1)
            run = false;
    }
    else
        run = false;
    }while (run == true);
}

