/* 
 * File:   main.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"
#include "Mundo.h"
#include "Simulacao.h"

int main() {
    Comandos consola;
//    Mundo m(15);
//    Ninho n(5,7,3,m);
//    Formiga()
    bool run = true;
    do{
    if (consola.configuracao() == 1)
    {
        Simulacao s(consola.lim,consola.nenergia,consola.menergia, consola.energianovaformiga,consola.transferir,consola.percentagem, consola.nmigalhas);
        if(s.simula() == 1)
            run = false;
    }
    else
        run = false;
    }while (run == true);
}

