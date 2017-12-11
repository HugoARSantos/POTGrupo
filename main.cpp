/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hugo
 *
 * Created on 7 de Dezembro de 2017, 23:46
 */

#include <cstdlib>
#include "Mundo.h"
#include "Formiga.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main() {
    Formiga a(1,2,10);
    cout << a.getAsString();
}

