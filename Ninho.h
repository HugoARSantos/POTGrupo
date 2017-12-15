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
    
    Ninho(const Ninho& orig);
    virtual ~Ninho();


};

#endif /* NINHO_H */

