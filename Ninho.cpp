/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"
#include "Mundo.h"
#include "Formiga.h"
#include <sstream>
#include <iostream>
#include "Exploradora.h"
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
int Ninho::pesquisa(int x, int y){
    for(int i=0;i<formigas.size();i++){
        if(formigas[i]->getX()==x && formigas[i]->getY()==y)
            return formigas[i]->getId();
    }
    return -1;
}
int Ninho::verificaenergia(int ener){
    if(energia > energia_inicial+(energia_inicial*ener/100)){
//        energia=energia_inicial*ener/100;
       
    criaFormiga((energia-energia_inicial));
}
}
int Ninho::criaFormiga(int ee){
    Exploradora *e=0;
    e= new Exploradora(x+1,y+1,this);
    e->SetEnergia(ee);
    formigas.push_back(e);
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
    //delete formigas[aux];
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
char Ninho::retornaTipo(int x, int y){
    for (int i=0;i<formigas.size();i++){
        if(formigas[i]->getX()==x && formigas[i]->getY()==y)
            return formigas[i]->geTipo();
    }
}
Ninho::~Ninho() {
    
}
void Ninho::retiraEnergia(){
    energia--;
}
int Ninho::getEnergiaMigalha(int x, int y, int per){
    int aux;
    
    aux=mundo->getEnergiaMigalha(x,y,per);
   
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

void Ninho::mexeFormiga(){
    for (int i = 0; i < formigas.size();i++){
        formigas[i]->verificaRegras();
    }
}

string Ninho::guardaFormiga(){
    ostringstream oss;
    for(int k=0;k<formigas.size();k++){
        oss << "Formiga " <<formigas[k]->getId() << " " <<formigas[k]->geTipo() << " " 
        <<formigas[k]->getX() << " " <<formigas[k]->getY() 
        << " " <<formigas[k]->getEnergia() 
        << " " <<formigas[k]->getEnergiaInicial()
        << " " <<getId() << endl;
    }
    return oss.str();
}
bool Ninho::verificaFormiga(int x,int y){
    
    if(mundo->verificaFormigaDiferente(x,y,id)==true)
        return true;
    return false;
}