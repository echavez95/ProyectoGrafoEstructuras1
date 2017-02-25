#include <iostream>
#include <stdlib.h>
#include "ClassConfigManager.h"
using namespace std;

int main()
{
    cout << "Leer archivo y guardarlo en una lista de rutas" << endl;
    ConfigManager fmHandler;
    fmHandler.leerArchivo();
    fmHandler.listaRutas.imprimirListaRutas();
    cout << endl;
    cout << "Imprmir la pila de una ciudad: Ciudad SPS" << endl;
    Ciudad SPS("San Pedro Sula");
    SPS.pilaCiudad.Push(1);
    SPS.pilaCiudad.Push(2);
    SPS.pilaCiudad.Push(3);
    SPS.pilaCiudad.Push(4);
    SPS.pilaCiudad.VerPila();
    system("pause");
    return 0;
}
