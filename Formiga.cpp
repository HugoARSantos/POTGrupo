/* 
 * File:   Formiga.cpp
 * Authors: Alheirium & Pepe
 */

#include "Formiga.h"
#include <string>
#include <sstream>
using namespace std;
Formiga::Formiga(int i,int posx,int posy,int e_inicial,int rv, int rm,const Ninho & n):ninho(n) {
//    SetXY(posx,posy);
    id=i;
    energia_inicial=e_inicial;
    energia=e_inicial;
    
}

Formiga::Formiga(const Formiga& orig) {
}

Formiga::~Formiga() {
}
string Formiga ::  getAsString()const{
    ostringstream oss;
    oss << "posX\n"<<x<<"\n"<<"posY\n"<<y<<"\n"<<"Energia inicial\n"<<energia_inicial<<"\n"<<"energia atual\n"<<energia;
    return oss.str();
}
int Formiga::Movformiga(){
    
}
