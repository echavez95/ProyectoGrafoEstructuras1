#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Classes.h"

using namespace std;

class ConfigManager{
    public:
        ListaRutasCosto listaRutas;
        Ciudad arregloCiudades[20];  /**TEMPORAL PARA PRUEBAS**/
        int indiceActualArreglo=0;

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

            Ruta* tempRuta;
            tempRuta=listaRutas.Primero;

            for(int i=0;i<=listaRutas.Size;i++){
                //cout<<"Desde: "<<tempRuta->Desde.nombre<<" Hasta: "<<tempRuta->Hasta.nombre<<" Costo: "<<tempRuta->Costo<<endl;
                insertarArregloCiudades(tempRuta->Desde.nombre);
                insertarArregloCiudades(tempRuta->Hasta.nombre);
                tempRuta=tempRuta->Siguiente;
            }

            if (!infile.eof())
            {
            cerr << "Terminado!\n";
            }
        }

        void insertarArregloCiudades(string NombreCiudad)
        {
            if(indiceActualArreglo==0){
               /* Ciudad nueva(NombreCiudad);
                arregloCiudades[indiceActualArreglo]=nueva ;*/
                arregloCiudades[indiceActualArreglo].nombre=NombreCiudad;
                cout<<arregloCiudades[indiceActualArreglo].nombre<<endl;
                indiceActualArreglo++;
            }else
                {
                    for(int i=0;i<indiceActualArreglo;i++){
                        if(arregloCiudades[i].nombre==NombreCiudad){
                            return;
                        }
                    }
                    arregloCiudades[indiceActualArreglo].nombre=NombreCiudad;
                    indiceActualArreglo++;
                }
        }

        void imprimirArregloCiudades()
        {
            for(int i=0;i<indiceActualArreglo;i++){
               cout<<arregloCiudades[i].nombre<<endl;
            }
        }
};

