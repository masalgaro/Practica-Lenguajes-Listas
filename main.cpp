#include <stdlib.h>
#include <time.h>
#include "Lista.h"

using namespace std;

int main() {
    srand(time(NULL));
    int headData = rand() % 100 + 1;
    int headCient = rand() % 2 + 1; //Para asegurar que el head también genere un evento valido
    Lista *l = new Lista();
    l->crearLista();
    l->insertarCabezaLista(headData, headCient);
    l->buscaEventos();
    l->visualizar();

    return 0;
}
