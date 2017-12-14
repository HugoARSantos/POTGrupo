/* 
 * File:   Comandos.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"

using namespace std;
        
        
Comandos::Comandos() {
}
Comandos::Comandos(const Comandos& orig) {
}
Comandos::~Comandos() {
}

void Comandos:: defMundo(int i){
    lim = i;
}
void Comandos:: defEN(int i){   //Energia dos ninhos quando são criados pode
    nenergia = i;               //ser alterado durante a simulação por isso
}                               //é diferente de energia inicial dos ninhos
void Comandos::defPC(int i){}
void defVT(int i){}
void defMI(int i){}
void defME(int i){}
void defNM(int i){}
void executa(string ficheiro){}
void inicio(){}