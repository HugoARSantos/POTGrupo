/* 
 * File:   Comandos.h
 * Authors: Alheirium & Pepe
 */

#ifndef COMANDOS_H
#define COMANDOS_H

class Comandos {
public:
    Comandos();
    Comandos(const Comandos& orig);
    virtual ~Comandos();
    void defMundo(int i){}
    void defEN(int i){}
    void defPC(int i){}
    void defVT(int i){}
    void defMI(int i){}
    void defME(int i){}
    void defNM(int i){}
    void executa(string ficheiro){}
    void inicio(){}
    
    void criaNinho(int i,int j){}
    void criaFormigas(int i, int j, int k){}
    void criaFor(int i, int j, int k, int l){}
    void criaMigalha(int i, int j){}
    void foca(int i, int j){}
    void tempo(){}
    void tempo(int i){}
    void addEnergiaNinho(int i, int j){}
    void addEnergiaNinho(int i, int j, int k){}
    void mataFormiga(int i, int j){}
    void insecticida(int i){}
    void listaMundo(){}
    void listaNinho(int i){}
    void listaPosicao(int i,int j){}
    void guardaMundo(string nome);
    void mudaMundo(string nome);
    void apagaMundo(string nome);
    void sair();
};

#endif /* COMANDOS_H */

