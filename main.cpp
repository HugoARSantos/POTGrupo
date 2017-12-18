/* 
 * File:   main.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"
#include "Mundo.h"
#include "Simulacao.h"
#include "Ninho.h"
#include "Exploradora.h"
#include "Formiga.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Comandos consola;
    
    Mundo m(15);
    Ninho n(5,5,10,&m);
    Exploradora a(2,2,&n);
    Exploradora b(4,4,&n);
    Exploradora c(6,6,&n);
    n.acrescentaFormiga(&a);
    n.acrescentaFormiga(&b);
    n.acrescentaFormiga(&c);
    cout << n.getAsString();
    
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

