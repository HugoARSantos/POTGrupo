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
#include <string>
using namespace std;

int main() {
    string op;
    int i,j,k,l;
    Comandos consola;
    cout << "Introduza um comando: ";
    getline(cin, op);   
    
    if (op == "defmundo")
        //if (i != NULL)
            consola.defMundo(i);

    if (op == "defen")
        //if (i != NULL)
            consola.defEnergia(i);
        
    if (op == "defpc")
        //if (i != NULL)
            consola.defPercentagemCriarFormiga(i);
    
    if (op == "defvt")
        //if (i != NULL)
            consola.defValorTransferencia(i);
}

