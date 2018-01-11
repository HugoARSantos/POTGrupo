/* 
 * File:   Ninho.h
 * Authors: Alheirium & Pepe
 */

#ifndef NINHO_H
#define NINHO_H
#include "Formiga.h"
#include <vector>


using namespace std;
class Formiga;
class Mundo;
class Ninho {
    private:
        int id;
        int x;
        int y;
        int energia_inicial;
        int energia;
        vector<Formiga *>formigas;
          Mundo * mundo;
        static int sequencia;
        int pesquisa(int idd)const;
        
public:
    Ninho(int xx, int yy,int e, Mundo *m);
    bool acrescentaFormiga(Formiga * formiga);
    bool removerFormiga(int idd);
    int pesquisa(int x,int y);
    int getX(){return x;}
    int getDimMundo()const ;
    int getY(){return y;}
    int getEnergiaInicial(){return energia_inicial;}
    int getId()const{return id;}
    int gettamanhoVetor()const{return formigas.size();}
    Ninho * getPonteiro(){return this;}
    int  retornaPosxy(int z,int j);
    Ninho(const Ninho& orig);
    virtual ~Ninho();
    string getAsString()const;
    string getAsStringTwo() const;
    void retiraEnergia();
    char retornaTipo(int x,int y);
    Ninho * duplica()const{return new Ninho(*this);}
    int getEnergia(){return energia;};
    void setEnergia(int j){energia+=j;};
    int getEnergiaMigalha(int x,int y,int per);
    bool verificaMigalha(int x,int y);
    void mexeFormiga();
    string guardaFormiga();
};
ostream & operator<<(ostream & saida, const Ninho & x);

#endif /* NINHO_H */

