/* 
 * File:   Ninho.h
 * Authors: Alheirium & Pepe
 */

#ifndef NINHO_H
#define NINHO_H
#include <vector>
#include "Formiga.h"

using namespace std;

class Ninho {
    private:
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        vector<Formiga *>formigas;
        
        static int sequencia;
        int pesquisa(int idd)const;
public:
    Ninho();
    bool acrescentaFormiga(Formiga * formiga);
    bool removerFormiga(int idd);
    int getX(){return x;}
    int getY(){return y;}
    int gettamanhoVetor()const{return formigas.size();}
    int  retornaPosxy(int z,bool j);
    Ninho(const Ninho& orig);
    virtual ~Ninho();
    string getAsString()const;
    void retiraEnergia();
};

#endif /* NINHO_H */

