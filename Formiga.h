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
        char tipo;
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        const Ninho * ninho;
        int raio_visao;
        int raio_movimento;
        static int sequencia;
public:
    Formiga(int i,int posx,int posy,char t,const Ninho & n,int e=0,int rv=0,int rm=0)
    :ninho(&n),energia_inicial(e),energia(e),raio_visao(rv),raio_movimento(rm),tipo(t){
             id=sequencia;
        sequencia++;}
        
    
    Formiga(const Formiga & orig);
    int getX(){return x;}
    int getY(){return y;}
    int getEnergiaInicial(){return energia_inicial;}
    int getEnergia(){return energia;}
    int getId()const{return id;};
    virtual string getAsString()const;
    
    
    void Settipo(const char  c);
        void SetXY(int x,int y);
        void SetEnergia(int e);
        void removeEnergia(int mv);
      
        int regraPasseia();
    
    virtual ~Formiga();


};

#endif /* FORMIGA_H */

