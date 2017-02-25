#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Classes.h"

using namespace std;

class ConfigManager{
    public:
        ListaRutasCosto listaRutas;

        void leerArchivo()
        {
            //string nombreArchivo="ArchivoRutas.txt";
            ifstream infile( "ArchivoRutas.txt" );
            while (infile)
            {
                string fila;
                string filaDelimitada[3];
                float costo;

                if (!getline( infile, fila )) break;
                istringstream ss( fila );
                int i=0;
                while (ss)
                {
                  string dato;
                  if (!getline( ss, dato, ',' )) break;
                  filaDelimitada[i]=dato;
                  i++;
                }

                costo = ::atof(filaDelimitada[2].c_str());
                listaRutas.InsertarRuta(filaDelimitada[0],filaDelimitada[1],costo);
            }
            if (!infile.eof())
            {
            cerr << "Terminado!\n";
            }
        }

};



