#include "Nodo.h"

Nodo::Nodo(int t, int u)
{
    datos = t;
    cientifico = u;
    siguiente = 0; // 0 es el puntero NULL en C++
    anterior = 0;
}

Nodo::Nodo(int d, int c, Nodo* n, Nodo *m) // crea el nodo y lo enlaza a n y m
{
    datos = d;
    cientifico = c;
    siguiente = n;
    anterior = m;
}

int Nodo::getDataNodo( ) const
{
    return datos;
}

int Nodo::getCientNodo( ) const
{
    return cientifico;
}

Nodo *Nodo::getEnlaceAdelanteNodo( ) const
{
    return siguiente;
}

Nodo *Nodo::getEnlaceAtrasNodo() const
{
    return anterior;
}

void Nodo:: ponerEnlaces(Nodo* sgte, Nodo* ant)
{
    siguiente = sgte;
    anterior = ant;
}
