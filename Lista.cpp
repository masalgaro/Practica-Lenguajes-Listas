#include "Lista.h"
#include "Nodo.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

void Lista::crearLista() { //Crear lista de 22 nodos
    srand(time(NULL));
    int proseguir;
    primero = NULL;
    anterior = NULL;
    int i;
    for(i = 0; i<22; i++){
        int x = rand() % 100 + 1;
        int y = rand() % 2 + 1;
        anterior = primero;
        primero = new Nodo(x, y, primero, anterior);
        if(i >= 2){
            cout << "Ya se han generado "<< i+1 << " eventos. Desea proseguir con la generacion de eventos? (Si = 1 | No = 2)" << endl;
            cin >> proseguir;
            if(proseguir == 2){
                cout << "Has generado "<< i+1 << " nodos." << endl;
                break;
            }
            if(proseguir != 1 && proseguir != 2){
                cout << "Valor incorrecto, se generara otro nodo" << endl;
                continue;
            }
            else { continue; }
        }
    }
    if(i == 22){
        cout << "Has alcanzado el limite de nodos." << endl;
    }

}

Lista::Lista() {
    primero = NULL;
    anterior = NULL;
}

void Lista::insertarCabezaLista(int datos, int cientifico) {
    Nodo *nuevo;
    nuevo = new Nodo(datos, cientifico);
    nuevo->ponerEnlaces(primero, anterior); // enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

void Lista::visualizar() {
    Nodo *n;
    Nodo *m;
    string cient;
    string tipoEvento;
    int k = 0;
    n = primero;
    m = anterior;
    cout << "Los eventos generados fueron los siguientes" << endl;
    while (n != NULL) {
        if (n->getCientNodo() == 1){
            cient = "Einstein";
        }
        else{
            cient = "Rosen";
        }
        char c;
        k++;
        c = (k % 15 != 0 ? ' ' : '\n');
        cout << n->getDataNodo() << "|" << cient << " -" << c;
        n = n->getEnlaceAdelanteNodo();
        m = m->getEnlaceAtrasNodo();
    }
    cout << endl;
}

void Lista::buscaEventos(){
    Nodo *n;
    Nodo *m;
    m = anterior;
    n = primero;
    if (n == NULL){
        while(m != NULL){ //Por si acaso para asegurar que estemos al inicio de la lista
            n = m;
            m->getEnlaceAtrasNodo();
        }
    }
    string cientifico;
    int contadorA = 0;
    int contadorB = 0;
    int contadorC = 0;
    int datosA = 0;
    int cientA = 0;
    int datosB = 0;
    while(n != NULL){
        int datos = n->getDataNodo();
        int cient = n->getCientNodo();
        if (cient == 1){
            cientifico = "Einstein";
        }
        else{
            cientifico = "Rosen";
        }
        if(EventoA(datos, cient)){
            contadorA++; //Así sabemos cuantas veces pasó un Evento A
            datosA = n->getDataNodo();
            cientA = n->getCientNodo();
            cout << "Einstein inicia su investigacion en viajes temporales" << endl;
            cout << "El Evento A sucedio con los datos " << datos << " y el cientifico " << cientifico << endl;
            cout << "---------------------" << endl; //Hacer un separador para que se vea más bonito
        }
        if(EventoB(datos) && EventoA(datosA, cientA)){
            contadorB++;
            datosB = n->getDataNodo();
            cout << "Se ha desarrollado una maquina del tiempo c:" << endl;
            cout << "El Evento B sucedio con los datos " << datos << " y el cientifico " << cientifico << endl;
            cout << "---------------------" << endl; //Hacer un separador para que se vea más bonito
        }
        if(EventoC(datos, datosA, cient) && EventoB(datosB)){
            contadorC++;
            if(esPrimo(datos)) {
                cout << "Ha ocurrido una singularidad!" << endl; //Esto se podría cambiar a un condicional aparte fuera de la función
                cout << "El cientifico " << cientifico << " logro viajar pero solo a ver..." << endl;
                cout << "---------------------" << endl; //Hacer un separador para que se vea más bonito
                n = n->getEnlaceAdelanteNodo();
                break;
            }
            cout << "El cientifico " << cientifico << " le entrego la informacion " << datos << " a Einstein c:" << endl;
            cout << "---------------------" << endl; //Hacer un separador para que se vea más bonito
        }
        n = n->getEnlaceAdelanteNodo();
    }
    cout << "El Evento A ha sucedido " << contadorA << " veces." << endl;
    cout << "El Evento B ha sucedido " << contadorB << " veces." << endl;
    cout << "El Evento C ha sucedido " << contadorC << " veces." << endl;
}

bool Lista::esPrimo(int x){
    int contador = 0;
    for(int i=2; i<x; i++){
        if (x % i == 0) { contador++; }
    }
    if(contador != 0) return false;
    else return true;
}


bool Lista::sonCoprimos(int datosA, int datosC){
    if(gcd(datosA, datosC) == 1){ //gcd es de la librería numeric de c++ que halla el común divisor más alto entre dos números
        return true; //dos números coprimos entre sí deberian solo tener al 1 como el divisor común.
    }
    else return false;
}

bool Lista::EventoA(int datos, int cientifico){
    if(cientifico != 1){ //Solo puede ser Einstein
        return false;
    }
    else{
        if(esPrimo(datos)){
            return true;
        }
        else return false;
    }
}

bool Lista::EventoB(int datos){ //El EventoB solo se debería activar si un el Evento A se ha ejecutado al menos una vez.
    if (esPrimo(datos)){
        return true;
    }
    else return false;
}

bool Lista::EventoC(int datosC, int datosA, int cientifico){ //Solo se activa si EventoB se ha ejecutado al menos una vez.
    if(sonCoprimos(datosA, datosC)){ //Se cumple el EventoC
        return true;
    }
    return false;
}
