#include <iostream>
#include <stdlib.h>
#include "ClassConfigManager.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ConfigManager fmHandler;
    fmHandler.leerArchivo();
    fmHandler.listaRutas.imprimirListaRutas();
    system("pause");
    return 0;
}
