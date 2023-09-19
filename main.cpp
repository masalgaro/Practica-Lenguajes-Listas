#include <stdlib.h>
#include <time.h>
#include "Lista.h"

using namespace std;

int main() {
    srand(time(NULL)); //Mide segundos del reloj del sistema desde el 1 de enero de 1970
    int headData = rand() % 100 + 1;
    int headCient = rand() % 2 + 1; //Para asegurar que el head también genere un evento válido
    Lista *l = new Lista();
    l->crearLista();
    l->insertarCabezaLista(headData, headCient);
    l->buscaEventos();
    l->visualizar();

    return 0;
}
