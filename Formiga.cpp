/* 
 * File:   Formiga.cpp
 * Authors: Alheirium & Pepe
 */

#include "Formiga.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

int Formiga::sequencia=1;



Formiga::~Formiga() {
}
string Formiga ::  getAsString()const{
    ostringstream oss;
    oss << "posX\n"<<x<<"\n"<<"posY\n"<<y<<"\n"<<"Energia inicial\n"<<energia_inicial<<"\n"<<"energia atual\n"<<energia;
    return oss.str();
}

Formiga :: Formiga(const Formiga & orig){
}
void Formiga :: removeEnergia(int mv){
    energia=energia-(1+mv);
}
int Formiga :: regraPasseia(){
    int auxx=rand()% (raio_movimento*2+1) - raio_movimento;
    int auxy=rand()%(raio_movimento*2+1) -raio_movimento;
    int mv=abs(x-auxx)+abs(y-auxy);
    x +=auxx;
    y += auxy;
    return mv;
}
void Formiga::Settipo(char c){
    tipo=c;
}