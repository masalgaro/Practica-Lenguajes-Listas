#ifndef LISTAS_ENLAZADAS_LENGUAJES_LISTA_H
#define LISTAS_ENLAZADAS_LENGUAJES_LISTA_H
#include "Nodo.h"

using namespace std;

class Lista {
protected:
    Nodo *primero; //primero es un atributo. Es un puntero de tipo Nodo
    Nodo *anterior; //para representar el nodo anterior
public:

    Lista();//Constructor de la lista. Al crearse la lista se debe inicializar el puntero *primero (head)  de modo que apunte a NULL

    void crearLista();

    void insertarCabezaLista(int datos, int cientifico);

    void visualizar();

    void buscaEventos();

    bool esPrimo(int x);

    bool sonCoprimos(int datosA, int datosC);

    bool EventoA(int datos, int cientifico);

    bool EventoB(int datos);

    bool EventoC(int datosC, int datosA, int cientifico);
};

#endif //LISTAS_ENLAZADAS_LENGUAJES_LISTA_H
