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
    bool a;
    Mundo m(15);
    Ninho n(5,7,3,&m);
    Exploradora ex(5,5,&n);
    a = n.acrescentaFormiga(&ex);
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

