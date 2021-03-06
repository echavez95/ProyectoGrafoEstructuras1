#include <iostream>
using namespace std;

class Paquete
{
    public:
        int Value;
        Paquete* NextPaquete;

    Paquete(int val)
    {
        Value=val;
        NextPaquete = 0;
    }

    ~Paquete(){}
};

class PilaPaquetes
{
    public :
		Paquete *Tope;

	PilaPaquetes()
	{
        Tope =0;
	}

    void Push(int valor)
    {
        Paquete* nodo = new Paquete(valor);
        if(Vacia())
        {
            Tope=nodo;
        }
        else
            {
                nodo->NextPaquete=Tope;
                Tope=nodo;
            }
    }

    int Pop()
    {
        if(Vacia()){
            cout<<"Pila Vacia"<<endl;
        }
        else
            {
                int retorno;
                Paquete* nodoTemp;
                retorno=Tope->Value;

                nodoTemp=Tope;
                Tope=Tope->NextPaquete;

                delete nodoTemp;
                return retorno;
            }
    }

    bool Vacia()
    {
        if(Tope==0)
        {
            return true;
        }
        return false;
    }

    void VerPila()
    {
        if(Vacia()){
            cout<<"Pila Vacia"<<endl;
        }
        else
            {
                Paquete* nodoTemp=Tope;
                do
                {
                    cout<<nodoTemp->Value<<endl;
                    nodoTemp=nodoTemp->NextPaquete;
                }while(nodoTemp!=0);
            }
    }

};

class Ciudad
{
    public:
        PilaPaquetes pilaPaquetesCiudad;
        string nombre;

    Ciudad(string nombreC)
    {
        nombre=nombreC;
    }

    Ciudad()
    {
    }

    void ingresarPaquete(int valorPaquete)
    {
        pilaPaquetesCiudad.Push(valorPaquete);
    }

    void verPilaPaquetes()
    {
        pilaPaquetesCiudad.VerPila();
    }

    int sacarPaquete(int valorBuscar)
    {
        Paquete* paqueteTemp;
        int resultado =NULL;
        if(pilaPaquetesCiudad.Tope->Value==valorBuscar){
            resultado=pilaPaquetesCiudad.Pop();
            return resultado;
        }else
        {
            PilaPaquetes pilaTemporal;
            /*int a = pilaPaquetesCiudad.Pop(); *///debug
            pilaTemporal.Push(pilaPaquetesCiudad.Pop());
            paqueteTemp = pilaPaquetesCiudad.Tope;
            /*a=pilaPaquetesCiudad.Tope->Value;*///debug
            do{
                /*a=paqueteTemp->Value;*///debug
                if(paqueteTemp->Value==valorBuscar){
                    resultado = pilaPaquetesCiudad.Pop();
                    break;
                }
                pilaTemporal.Push(pilaPaquetesCiudad.Pop());
                paqueteTemp=pilaPaquetesCiudad.Tope;
            }while(pilaPaquetesCiudad.Vacia()!=true);
            /*Seccion para debugguear*/
            /*
            cout<<"Pila Paquetes Ciudad"<<endl;
            pilaPaquetesCiudad.VerPila();
            cout<<"Pila Temporal"<<endl;
            pilaTemporal.VerPila();
            */
            do
            {
                pilaPaquetesCiudad.Push(pilaTemporal.Pop());
            }while(pilaTemporal.Vacia()!=true);

            /*Seccion para debugguear*/
            /*
            cout<<"Pila Paquetes Ciudad"<<endl;
            pilaPaquetesCiudad.VerPila();
            cout<<"Pila Temporal"<<endl;
            pilaTemporal.VerPila();
            */
           return resultado;
        }
    }

};

class Ruta{
    public:
        Ciudad Desde;
        Ciudad Hasta;
        float Costo;
        Ruta* Siguiente;

    Ruta(string Cdesde, string Chasta, float costoEnvio)
    {
        Desde.nombre=Cdesde;
        Hasta.nombre=Chasta;
        Costo=costoEnvio;
    }

};

class ListaRutasCosto{
    public:
        Ruta* Primero;
        Ruta* Ultimo;
        int Size;

    ListaRutasCosto()
    {
        Primero=0;
        Size=0;
    }

    void InsertarRuta(string Rdesde, string Rhasta, float RcostoEnvio) /**Inserta un elemento al inicio**/
    {
        if(Primero==0)
        {
            Ruta* nuevaRuta = new Ruta(Rdesde,Rhasta,RcostoEnvio);
            Primero=Ultimo=nuevaRuta;
        }
        else
            {
                if(!existeRuta(Rdesde,Rhasta)){
                    Ruta* nuevaRuta = new Ruta(Rdesde,Rhasta,RcostoEnvio);
                    Ultimo->Siguiente=nuevaRuta;
                    Ultimo=nuevaRuta;
                    Size++;
                }else
                    {
                        cout<<"Ya existe esta ruta"<<endl;
                    }
            }
    }

    bool existeRuta(string Cdesde, string Chasta)
    {
        Ruta* tempRuta;
        tempRuta=Primero;
        for(int i=0;i<=Size;i++){
            if(tempRuta->Desde.nombre==Cdesde && tempRuta->Hasta.nombre==Chasta)
            {
                return true;
            }
            if(tempRuta->Desde.nombre==Chasta && tempRuta->Hasta.nombre==Cdesde)
            {
                return true;
            }
            tempRuta=tempRuta->Siguiente;
        }
        return false;
    }

    void imprimirListaRutas()
    {
        Ruta* tempRuta;
        tempRuta=Primero;
        for(int i=0;i<=Size;i++){
            cout<<"Desde: "<<tempRuta->Desde.nombre<<" Hasta: "<<tempRuta->Hasta.nombre<<" Costo: "<<tempRuta->Costo<<endl;
            tempRuta=tempRuta->Siguiente;
        }
    }
};

