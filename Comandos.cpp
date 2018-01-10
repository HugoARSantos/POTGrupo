/* 
 * File:   Comandos.cpp
 * Authors: Alheirium & Pepe
 */

#include "Comandos.h"
        
Comandos::Comandos(){
}
Comandos::Comandos(const Comandos& orig){
};
Comandos::~Comandos(){
};

int Comandos :: configuracao(){
    string op,nficheiro;
    bool run = true;
    int i;
    lim = -1;                     
    nenergia = -1;                
    menergia = -1;                
    energianovaformiga = -1;          
    transferir = 1;              
    percentagem = -1;             
    nmigalhas = -1;  
    
    do{
    i = -1;
    cout << "Introduza um comando: ";
    getline(cin, op);   
    
    istringstream iss(op);
    iss >> op;
    
    if (op == "defmundo"){
        iss >> i;
            defMundo(i);
    }
    
    else if (op == "defen"){
        iss >> i;
        defEnergia(i);
    }
    
    else if (op == "defpc"){
        iss >> i;
        defPercentagemCriarFormiga(i);
    }
    else if (op == "defvt"){
        iss >> i;
        defValorTransferencia(i);
    }
    
    else if (op == "defmi"){
        iss >> i;
        defMigalhasIniciais(i);
    }
    
    else if (op == "defme"){
        iss >> i;
        defEnergiaMigalhas(i);
    }
    
    else if (op == "defnm"){
        iss >> i;
        defNumeroMigalhas(i);
    }
    
    else if (op == "executa"){
        iss >> nficheiro;
        if (nficheiro!="")
            if(executa(nficheiro)==1)
                return 1;
    }
    
    else if (op == "inicio"){
         if (inicio() == 1)
            return 1;
    }
    
    else if (op == "sair"){
        return 0;
    }
    
    else 
        cout << "Por favor introduza um comando valido" << endl;
    
    }while (run == true);
    return 0;
}



void Comandos ::defMundo(int i){
    if (i<10)
        cout << "Introduza um valor apropiado para o limite do mundo(Acima de 10)." << endl;
    else{
        lim = i;
        cout << "Limite do mundo definido com: " << lim << "." << endl;
    }
}

void Comandos::defEnergia(int i){   //defen Energia dos ninhos quando são criados pode
    if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia dos ninhos (Acima de 0)." << endl;
    else{                            //ser alterado durante a simulação por isso
        nenergia = i;    
        cout << "A energia dos novos ninhos e: " << nenergia << "." << endl;
    }
}                                   //é diferente de energia inicial dos ninhos

void Comandos::defPercentagemCriarFormiga(int i){   //defpc
    if (i >= 0 && i <= 100){
        energianovaformiga = i;  
        cout << "Os ninhos vao criar uma formiga assim que tiverem: " 
            << energianovaformiga << "% de energia acima do valor inicial." << endl;
    }
    else{
        cout << "Introduza um valor apropiado para a energia com a qual o ninho "
                "pode criar uma nova formiga(Entre 0 e 100)." << endl;
    }            
}                               
void Comandos::defValorTransferencia(int i){   //defvt
        if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia transferida do ninho para a formiga." << endl;
    else{                            
        transferir = i;    
        cout << "Os ninhos vao transferir: " << transferir << " unidades de energia por iteracao." << endl;
    }
}                                             
                               
void Comandos::defMigalhasIniciais(int i){   //defmi 0 a 100
    if (i >= 0 && i <=100){
        percentagem = i;
            cout << "No incio da simulacao as migalhas irao ocupar: " 
            << percentagem << "% das posicoes vazias." << endl;
    }
    else{
        cout << "Introduza um valor apropiado para a percentagem "
                "de celulas vazias ocupadas por migalhas(Entre 0 e 100)." << endl;
    }
}
void Comandos::defEnergiaMigalhas(int i){   //defme
    if (i<1)
        cout << "Introduza a energiad das migalhas(Acima de 0)." << endl;
    else{
        menergia = i;
        cout << "A energia de novas migalhas e: " << menergia << "." << endl;              
        }
}

void Comandos::defNumeroMigalhas(int i){   //defnm
     if (i<1)
        cout << "Introduza um valor apropiado maximo de migalhas criadas a cada instante.(Acima de 0)" << endl;
    else{
        nmigalhas = i;
        cout << "A cada interacao serao criadas entre 0 a " << nmigalhas << " migalhas." << endl;              
    }                              //valor de migalhas criadas a cada 
}                                 //instance varia entre 0 e este valor

int Comandos::executa(string ficheiro){
        ifstream ifs;
        ifs.open(ficheiro+".txt");
        ifs >> lim;
        ifs >> nenergia;
        ifs >> menergia;
        ifs >> energianovaformiga;
        ifs >> transferir;
        ifs >> percentagem;
        ifs >> nmigalhas;

        ifs.close();
    
    if (lim>=10 && nenergia>0 && menergia > 0 && energianovaformiga>=0 && energianovaformiga<=100 && transferir > 0
       && percentagem >=0 && percentagem <=100 && nmigalhas > 0)
    {
        return 1;
    }
    else{
        if (lim<10) cout <<"Limite do mundo nao definido" << endl;
        if (nenergia< 1) cout << "Energia dos ninhos nao definida" << endl;
        if (menergia < 1) cout << "Energia das migalhas nao definida" << endl;
        if (energianovaformiga < 0 || energianovaformiga > 100) cout << "Energia para criar uma nova formiga nao definida" << endl;
        if (transferir < 0) cout << "Energia transferida do ninho para a formiga nao definida" << endl;
        if (percentagem < 0 || percentagem > 100) cout << "Percentagem de posicoes iniciais vazias ocupadas por migalhas nao definida" << endl;
        if (nmigalhas < 1) cout << "Numero maximo de migalhas a ser criado a cada iteracao nao definido." << endl;
        return 0;
    }
}

int Comandos::inicio(){
    if (lim>=10 && nenergia>0 && menergia > 0 && energianovaformiga>=0 && energianovaformiga<=100 && transferir > 0
        && percentagem >=0 && percentagem <=100 && nmigalhas > 0)
        return 1;
    else{
        if (lim<10) cout <<"Limite do mundo nao definido" << endl;
        if (nenergia< 1) cout << "Energia dos ninhos nao definida" << endl;
        if (menergia < 1) cout << "Energia das migalhas nao definida" << endl;
        if (energianovaformiga < 0 || energianovaformiga > 100) cout << "Energia para criar uma nova formiga nao definida" << endl;
        if (transferir < 0) cout << "Energia transferida do ninho para a formiga nao definida" << endl;
        if (percentagem < 0 || percentagem > 100) cout << "Percentagem de posicoes iniciais vazias ocupadas por migalhas nao definida" << endl;
        if (nmigalhas < 1) cout << "Numero maximo de migalhas a ser criado a cada iteracao nao definido." << endl;
        return 0;
    }
}

