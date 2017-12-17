/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"
#include <sstream>
using namespace std;
int Ninho::sequencia=1;
Ninho::Ninho(int xx,int yy,int e) {
    x=xx;
    y=yy;
    energia_inicial=energia=e;
    id=sequencia;
    sequencia++;
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
    oss << "\nId Ninho: " << id << endl;
    for (unsigned int i = 0; i < formigas.size(); i++)
        oss << formigas[i]->getAsString();

    return oss.str();
}
int Ninho ::retornaPosxy(int z, bool j){
    for(unsigned int i=0;i<formigas.size();i++){
        if(i==z && j==0)
            return formigas[i]->getX();
        else if(i==z && j==1)
            return formigas[i]->getY();
    }
}
Ninho::~Ninho() {
    
}
void Ninho::retiraEnergia(){
    energia--;
}

