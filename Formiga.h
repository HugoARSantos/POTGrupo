/* 
 * File:   Formiga.h
 * Authors: Alheirium & Pepe
 */

#ifndef FORMIGA_H
#define FORMIGA_H
#include <string>

using namespace std;
class Ninho;
class Formiga {
    private:
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        const Ninho * ninho;
        int raio_visao;
        int raio_movimento;
     
public:
    Formiga(int i,int posx,int posy,const Ninho & n):id(i),ninho(&n){};
    int getX(){return x;}
    int getY(){return y;}
    int getEnergiaInicial(){return energia_inicial;}
    int getEnergia(){return energia;}
    int getId()const{return id;};
    virtual string getAsString()const;
    int Movformiga();
    
    
        void SetXY(int x,int y);
        void SetEnergia(int e);
    
   
    Formiga(const Formiga& orig);
    virtual ~Formiga();


};

#endif /* FORMIGA_H */

