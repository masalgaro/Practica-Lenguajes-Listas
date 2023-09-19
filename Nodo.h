#ifndef LISTAS_ENLAZADAS_LENGUAJES_NODO_H
#define LISTAS_ENLAZADAS_LENGUAJES_NODO_H
#include <string>

using namespace std;

class Nodo {
protected:
    int datos;
    int cientifico;
    Nodo *siguiente;
    Nodo *anterior;

public:
    Nodo(int t, int u);

    Nodo(int d, int c, Nodo *n, Nodo *m);

    int getDataNodo() const; //const = no modifica la información que busca el método. Solo es consulta

    int getCientNodo() const;

    Nodo *getEnlaceAdelanteNodo() const;

    Nodo *getEnlaceAtrasNodo() const;

    void ponerEnlaces(Nodo *sgte, Nodo *ant);
};

#endif //LISTAS_ENLAZADAS_LENGUAJES_NODO_H
