/* 
 * File:   Formiga.h
 * Authors: Alheirium & Pepe
 */

#ifndef FORMIGA_H
#define FORMIGA_H
#include <string>

#include "Ninho.h"

using namespace std;
class Ninho;
class Formiga {
    private:
        char tipo;
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        int pEnergia;
         Ninho * ninho;
        int raio_visao;
        int raio_movimento;
        static int sequencia;
public:
    Formiga(int posx,int posy, Ninho * n,int e=0,int rv=0,int rm=0,char c='F',int pe=0)
    :ninho(n),x(posx),y(posy),energia_inicial(e),energia(e),raio_visao(rv),raio_movimento(rm),tipo(c),pEnergia(pe){
        id=sequencia;
        sequencia++;}
        
    Formiga(int posx,int posy,int e=0,int rv=0,int rm=0,char c='F',int pe=0)
    :x(posx),y(posy),energia_inicial(e),energia(e),raio_visao(rv),raio_movimento(rm),tipo(c),pEnergia(pe){
        id=sequencia;
        sequencia++;}
        
    Formiga(const Formiga & orig);
    int move(int xx,int yy);
    int getX(){return x;}
    int getY(){return y;}
    char geTipo(){return tipo;}
    int getEnergiaInicial(){return energia_inicial;}
    int getEnergia(){return energia;}
    int getId()const{return id;};
    int getRVisao(){return raio_visao;}
    virtual bool verificaRegras(){}
    virtual string getAsString()const;
    
    
    void Settipo(const char  c);
        void SetXY(int x,int y);
        void SetEnergia(int e){energia+=e;}
        void removeEnergia(int mv);
        void setNinho(Ninho * n){ninho=n;}
         void regraComeMigalha();
        int regraPasseia();
        virtual bool regraProcuraMigalha(){};
        virtual bool regrafoge(){};
        Ninho * getNinho(){return ninho;}
       
    virtual ~Formiga();
    virtual Formiga * duplica()const=0;

};

#endif /* FORMIGA_H */

