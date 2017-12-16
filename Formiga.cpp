/* 
 * File:   Formiga.cpp
 * Authors: Alheirium & Pepe
 */

#include "Formiga.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;





Formiga::~Formiga() {
}
string Formiga ::  getAsString()const{
    ostringstream oss;
    oss << "posX\n"<<x<<"\n"<<"posY\n"<<y<<"\n"<<"Energia inicial\n"<<energia_inicial<<"\n"<<"energia atual\n"<<energia;
    return oss.str();
}
int Formiga::Movformiga(){
    
}
Formiga :: Formiga(const Formiga & orig){
}
void Formiga :: removeEnergia(){
    energia--;
}
void Formiga :: regraPasseia(){
    x +=rand()% (raio_movimento*2+1) - raio_movimento;
    y += rand()%(raio_movimento*2+1) -raio_movimento;
}