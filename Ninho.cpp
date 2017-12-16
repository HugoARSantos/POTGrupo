/* 
 * File:   Ninho.cpp
 * Authors: Alheirium & Pepe
 */

#include "Ninho.h"
#include <sstream>
using namespace std;
int Ninho::sequencia=1;
Ninho::Ninho() {
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

Ninho::~Ninho() {
}
void Ninho::retiraEnergia(){
    energia--;
}

