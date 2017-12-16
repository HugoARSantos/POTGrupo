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
        char c;
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        const Ninho * ninho;
        int raio_visao;
        int raio_movimento;
     
public:
    Formiga(int i,int posx,int posy,const Ninho & n,int e=0,int rv=0,int rm=0):id(i),ninho(&n),energia_inicial(e),energia(e),raio_visao(rv),raio_movimento(rm){};
    Formiga(const Formiga & orig);
    int getX(){return x;}
    int getY(){return y;}
    int getEnergiaInicial(){return energia_inicial;}
    int getEnergia(){return energia;}
    int getId()const{return id;};
    virtual string getAsString()const;
    int Movformiga();
    
    
        void SetXY(int x,int y);
        void SetEnergia(int e);
        void removeEnergia();
   
        void regraPasseia();
    
    virtual ~Formiga();


};

#endif /* FORMIGA_H */

