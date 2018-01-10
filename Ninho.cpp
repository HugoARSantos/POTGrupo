/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"
#include "Mundo.h"
#include <sstream>
#include <iostream>
using namespace std;
int Ninho::sequencia=1;
Ninho::Ninho(int xx,int yy,int e, Mundo * m):mundo(m) {
    x=xx;
    y=yy;
    energia_inicial=e;
    energia = e;
    id=sequencia;
    sequencia++;
}
int Ninho::getDimMundo() const{
    return mundo->getDim();
}
int Ninho::pesquisa(int idd) const{
    
    for (unsigned int i = 0; i < formigas.size(); i++)
        if (formigas[i]->getId() == idd){
            return i; 
        }
    return -1;
}
bool Ninho::acrescentaFormiga(Formiga * formiga) {
    if (formiga == nullptr || pesquisa(formiga->getId()) != -1){
        return false;}
    
    formigas.push_back(formiga);
    return true;
}
bool Ninho::removerFormiga(int idd) {
    int aux = pesquisa(idd);
    if (aux == -1)
        return false;
    // liberta o objecto apontado por formigas[i]
    delete formigas[aux];
    //retira o ponteiro do vetor
    formigas.erase(formigas.begin() + aux);
    return true;
}
    
Ninho::Ninho(const Ninho& orig) {
}
string Ninho::getAsString() const {
    ostringstream oss;
    oss << "\nId Ninho: " << id << "\nNa posicao X:" << x <<" Y: " << y
            <<"\nEnergia:" << energia
            <<"\nTem "<<formigas.size()<<" Formigas"<<endl;
    return oss.str();
}

string Ninho::getAsStringTwo() const{
        ostringstream oss;
        oss << "\nId Ninho: " << id << "\nNa posicao X:" << x <<" Y: " << y << endl<<"Energia:"<<energia<<endl;
            for (unsigned int i = 0; i < formigas.size(); i++)
                oss << formigas[i]->getAsString();
        
        return oss.str();
}
int Ninho ::retornaPosxy(int z, int j){
    for( int i=0;i<formigas.size();i++){
        if(i==z && j==0)
            return formigas[i]->getX();
        if(i==z && j==1)
            return formigas[i]->getY();
    }
}
Ninho::~Ninho() {
    
}
void Ninho::retiraEnergia(){
    energia--;
}
int Ninho::getEnergiaMigalha(int x, int y){
    int aux;
    
    aux=mundo->getEnergiaMigalha(x,y);
   
    return aux;
    
}
bool Ninho::verificaMigalha(int x, int y){
    char c;
    c=mundo->listaPosicao(x,y);
    if(c=='m')
        return true;
    return false;
}

ostream & operator<<(ostream & saida, const Ninho & x) {
    saida << x.getAsString();
    return saida;
}