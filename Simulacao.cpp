/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulacao.cpp
 * Author: Hugo
 * 
 * Created on 17 de Dezembro de 2017, 17:36
 */

#include "Simulacao.h"

Simulacao::Simulacao(int l, int n, int me, int e, int t, int p ,int nm):m(l,p,me){
    it = 0;
    lim = l;
    nenergia = n;                //Energia inicial dos ninhos
    menergia = me;               //Energia inicial das migalhas
    energianovaformiga = e;      //Percentagem de energia(vezes a inicial) que o ninho precisa para criar uma nova formiga
    transferir = t;              //Unidade de energia transferida entre ninho e formiga por iteração
    percentagem = p;             //Posiçoes vazias ocupadas por migalhas ao inicio
    nmigalhas = nm;              //maximo de migalhas criadas a cada instance
}

Simulacao::~Simulacao(){
 }

int Simulacao::simula(){
    string op,nficheiro;
    string a,b,c;
    int i, j, k, l ;
    bool run = true;
    
    ofstream ofs;
    ofs.open("default.txt");
    ofs << lim;
    ofs <<"\n";
    ofs << nenergia;
    ofs <<"\n";
    ofs << menergia;
    ofs <<"\n";
    ofs << energianovaformiga;
    ofs <<"\n";
    ofs << transferir;
    ofs <<"\n";
    ofs << percentagem;
    ofs <<"\n";
    ofs << nmigalhas;

    ofs.close();
    
//    Ninho n(5,5,10,&m);
//    Exploradora fa(2,2,&n);
//    Exploradora fb(4,4,&n);
//    n.acrescentaFormiga(&fa);
//    n.acrescentaFormiga(&fb);    
//    m.acrescentaNinho(&n);
    do{
//    fa.regraPasseia();
//    fb.regraPasseia();
    m.preencheMatriz();
    system("cls");
    cout <<"\b" << m.MostraMundo();
    cout << "Introduza um comando: ";
    getline(cin, op);
    i=-1;
    k=-1;
    j=-1;
    l=-1;
    a="";
    b="";
    c="";
    nficheiro="";
    istringstream iss(op);
    iss >> op;        
    if (op == "defen"){
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
    
    /*else if (op == "executa"){
        iss >> nficheiro;
        executa(nficheiro);
    }*/
    
    else if (op == "sair"){
        return 1;
    }  
    
    else if (op == "ninho"){
        iss >> i;
        iss >> j;
        criaNinho(i,j);
    }
    
    else if (op == "criaf"){
        iss >> i;
        iss >> a;
        iss >> j;
        criaFormigas(i,a,j);
    }
        else if (op == "cria1"){
        iss >> i;
        iss >> a;
        iss >> j;
        iss >> k;
        criaFor(1,a,j,k);
    }
    else if (op == "tempo"){
        iss >> i;
        tempo(i);
    }
    else if (op == "listamundo"){
        listaMundo();
    }
    else if (op == "listaninho"){
        iss >> i;
        listaNinho(i);
    }
    
    else if (op == "listaposicao"){
        iss >> i;
        iss >> j;
        listaPosicao(i,j);
    }
    
    else if (op=="energninho"){
        iss >> i;
        iss >> j;
        addEnergiaNinho(i,j);
    }
    
    else if (op=="migalha"){
        iss >> i;
        iss >> j;
        criaMigalha(i,j);
    }
//    else if (op=="energformiga")
//    else if (op=="mata")
//    else if (op=="inseticida")
    else if (op=="guarda"){
        iss >> nficheiro;
        guardaMundo(nficheiro);
    }
    else if (op=="muda"){
        iss >> nficheiro;
        //mudaMundo(nficheiro);
    }
        
    
    else if (op=="apaga"){
        iss >> nficheiro;
        if (apagaMundo(nficheiro)==1){
            cout << "O programa ira agora regressar a configuracao, prima qualquer tecla para continuar";
            getch();
            system("cls");
            return 0;
        }
    }
    
    else {
        cout<< "Por favor use um comando correcto.\nPressione qualquer tecla para continuar";
        getch();
    }
    
    }while (run == true);
    return 0;
}

void Simulacao::criaNinho(int i, int j){
    if (i<1 || i > lim)
        cout << "Linha invalida" << endl;
    if (j<1 || j > lim)
        cout << "Coluna invalida" << endl;
    if (i>0 && i <= lim && j>0 && j <= lim)
    {
        Ninho *n = nullptr;
        n= new Ninho(i,j,nenergia,&m);
        m.acrescentaNinho(n);
    }
}

void Simulacao::criaFormigas(int i, string a, int j){
    int nninhos = m.getNninhos();
    if (i<1)
        cout << "Introduza um numero de formigas valido" << endl;
    if (a != "E"||a != "E"||a != "E"||a != "E"||a != "E"||a != "E")
        cout << "Introduza um tipo valido" << endl;
    if (j > nninhos || j < 1)
        cout << "O ninho que indicou nao existe" << endl;
    if (i>=1 && a== "E" && j <= nninhos && j>0)
        cout << i << " formigas do tipo " << a << " foram acrescentadas ao ninho " << j << endl;
}

void Simulacao::criaFor(int i, string a, int j, int k){
    
};

void Simulacao::tempo(int i){
    if (i==0){
        cout << "Nao podes ficar parado no tempo, segue em frente" << endl;
    }
    else if (i<0)
    {
        int novas = rand()% nmigalhas;
        
        for (int aux=0;aux<novas;aux++){
            int j=rand()%lim+1;
            int k=rand()%lim+1;
            m.acrescentaMigalha(menergia,j,k);
        }

    }
    else if (i>1)
    {
    
    }
}

void Simulacao::listaMundo(){
    system("cls");
    cout << m.getAsString();
    cout << endl << "Pressione qualquer tecla para continuar";
    getch();
}

void Simulacao::listaNinho(int i){
    int nninhos = m.getNninhos();
    if (i > nninhos || i < 1){
       cout << "O ninho que indicou nao existe" << endl;
       getch();
    }
    if (i <= nninhos && i>0)
    {
        system("cls");
        cout << m.ListaNinho(i);
        cout << endl << "Pressione qualquer tecla para continuar";
        getch();
    }
 }

void Simulacao::listaPosicao(int i, int j){
    if (i<0 || i >= lim)
        cout << "Linha invalida" << endl;
    if (j<0 || j >= lim)
        cout << "Coluna invalida" << endl;
    if (i>=0 && i < lim && j>=0 && j < lim)
        //Cria ninho nesta posicao
        cout << "Na posicao X:" << i << " Y:" <<j << " existe: "<< endl;
}

void Simulacao::defEnergia(int i){   //defen Energia dos ninhos quando são criados pode
    if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia dos ninhos (Acima de 0)." << endl;
    else{                            //ser alterado durante a simulação por isso
        nenergia = i;    
        cout << "A energia dos novos ninhos e: " << nenergia << "." << endl;
    }
}                                   //é diferente de energia inicial dos ninhos

void Simulacao::defPercentagemCriarFormiga(int i){   //defpc
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
void Simulacao::defValorTransferencia(int i){   //defvt
        if (i < 1) 
        cout << "Introduza um valor apropiado "
                "para a energia transferida do ninho para a formiga." << endl;
    else{                            
        transferir = i;    
        cout << "Os ninhos vao transferir: " << transferir << " unidades de energia por iteracao." << endl;
    }
}                                             
                               
void Simulacao::defMigalhasIniciais(int i){   //defmi 0 a 100
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
void Simulacao::defEnergiaMigalhas(int i){   //defme
    if (i<1)
        cout << "Introduza a energiad das migalhas(Acima de 0)." << endl;
    else{
        menergia = i;
        cout << "A energia de novas migalhas e: " << menergia << "." << endl;              
        }
}

void Simulacao::defNumeroMigalhas(int i){   //defnm
     if (i<1)
        cout << "Introduza um valor apropiado maximo de migalhas criadas a cada instante.(Acima de 0)" << endl;
    else{
        nmigalhas = i;
        cout << "A cada interacao serao criadas entre 0 a " << nmigalhas << " migalhas." << endl;              
    }                              //valor de migalhas criadas a cada 
} //instance varia entre 0 e este valor
void Simulacao::addEnergiaNinho(int i, int j){
    int nninhos = m.getNninhos();
    if (i > nninhos || i < 1){
       cout << "O ninho que indicou nao existe" << endl;
       getch();
    }
    else
        m.acrescentaEnergiaNinho(i,j);
}

void Simulacao::criaMigalha(int i, int j){
    if (i<1 || i > lim)
        cout << "Linha invalida" << endl;
    if (j<1 || j > lim)
        cout << "Coluna invalida" << endl;
    if (i>0 && i <= lim && j>0 && j <= lim)
    {
        m.acrescentaMigalha(menergia,i,j);
    }
}
//void mataFormiga(int i, int j){
//};
//void insecticida(int i){
//};
//void listaMundo(){
//    
//};
//void listaNinho(int i){
//    
//};
//void listaPosicao(int i,int j){
//    
//};
void Simulacao::guardaMundo(string nome){
    ofstream ofs;
    ofs.open(nome+".txt");
    ofs << lim;
    ofs <<"\n";
    ofs << nenergia;
    ofs <<"\n";
    ofs << menergia;
    ofs <<"\n";
    ofs << energianovaformiga;
    ofs <<"\n";
    ofs << transferir;
    ofs <<"\n";
    ofs << percentagem;
    ofs <<"\n";
    ofs << nmigalhas;
    ofs << m.guardaMundo();
    ofs.close();
};
void Simulacao::mudaMundo(string nome){
//        ifstream ifs;
//        ifs.open(nome+".txt");
//        if(ifs.is_open()){
//        ifs >> lim;
//        ifs >> nenergia;
//        ifs >> menergia;
//        ifs >> energianovaformiga;
//        ifs >> transferir;
//        ifs >> percentagem;
//        ifs >> nmigalhas;
//        m = (lim,percentagem,menergia);
//        ifs.close();
//        }
//        else 
//        {
//            cout << "O ficheiro nao existe" << endl;
//                    //return 0;
//        }
    
};

int Simulacao::apagaMundo(string nome){
    if (remove((nome+".txt").c_str()) !=0){
            cout << "Nao existe nenhum ficheiro com este nome";
            getch();
    }
        else {
            cout << nome << " foi apagado com sucesso" << endl;
            getch();
    }

    if (nome=="default")
        return 1;
    return 0;
};

