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
    //a regra passeia nao funciona para as formigas criados pelo
    //pelo ninho, pois elas nao tem um ponteiro para o ninho
    //lista posicao ??????????
    //migalhas nao desaparecem ??? fuck->ver verifica migalhas==not fucked, i mean, still fucked...
    Comandos consola;
//
//    int l = 10;
//    int me = 50;
//    int pm = 50;
//    Mundo m(l,pm,me);
//    Exploradora *c=0;
//    Ninho n(5,5,10,&m);
////////    Ninho n1(1,1,2,&m);
////    Exploradora a(2,2,&n);
////    Exploradora b(4,4,&n);
////    Exploradora c(6,6);
//   c= new Exploradora (6,6);
////    n.acrescentaFormiga(&a);
////    n.acrescentaFormiga(&b);    
//      m.acrescentaNinho(&n);
////////    m.acrescentaNinho(&n1);
//      m.acrescentaFormiga(c,1);
//////    m.preencheMatriz();
//////    n.removerFormiga(3);
//////    m.preencheMatriz();
////    //cout <<m.getAsString();
////    //cout <<m.listaPosicao(1,1);
////    
////      a.regraPasseia();
////    b.regraPasseia();
////    c.regraPasseia();
//    system("cls");
//    
//    m.preencheMatriz();
//    cout << m.MostraMundo();
////    cout<< m;
//    //cout << m.ListaNinho(1);
////    
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

