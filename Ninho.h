/* 
 * File:   Ninho.h
 * Authors: Alheirium & Pepe
 */

#ifndef NINHO_H
#define NINHO_H
#include <vector>
using namespace std;
class Formiga;
class Ninho {
    private:
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        vector<Formiga *>formiga;
        
        static int sequencia;
public:
    Ninho();
    Ninho(const Ninho& orig);
    virtual ~Ninho();


};

#endif /* NINHO_H */

