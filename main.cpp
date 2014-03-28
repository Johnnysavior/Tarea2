#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include<conio.h>

using namespace std;

//devuelve el monto de la transaccion de una fila en formato int

int DevolverMonto(char cadena[128])
{

    string fila = cadena;
    int num_comillas = 0;
    string monto;
    string monto_sin_comillas;
    int monto_int;
    int max=fila.length();
    for (int i = 0; i<max; i++)
    {
        if (fila[i] == '"')num_comillas++;
        if (num_comillas == 4)
        {
            int pos = i + 1;
            monto = fila.substr(pos);
        }
    }
    int offset = 0;
    max=monto.length();
    for (int i = 0; i<max - 2; i++)offset++;
    monto_sin_comillas = monto.substr(1, offset);
    monto_int = atoi(monto_sin_comillas.c_str());
    return monto_int;
}


//busca palabra en cadena
bool isInCharString(char cadena[128], string palabra)
{
    const char *search = palabra.c_str();
    for (int i = 0; i < strlen(cadena); ++i)
    {
        if (strncmp(&cadena[i], search, strlen(search)) == 0)
            return true;
    }

    return false;
}


int main(int argc, char **argv)
{

    //Si el primer parametro es -f...
    if (strcmp(*(argv + 1), "-s") == 0)
    {
        if (*(argv + 2) != NULL) //Chequear que el segundo parametro no sea nulo.
        {
            //entregar la suma total de las ventas de todas las tiendas, que existan en el archivo.csv.
            char cadena[128];   //cadena que sirve de buffer para la lectura de archivo
            double monto_total=0;   //sumador para el monto total del archivo
            ifstream fe( *(argv + 2));  //abro el archivo con ifstream (lectura)
            int lineas=0;  //lineas de archivo
            while (!fe.eof())  //leo todas las lineas del archivo y las voy contando
            {
                fe.getline(cadena, 128);
                lineas++;
            }
            fe.close();  //cierro el archivo
            ifstream fe2( *(argv + 2));  //y lo vuelvo a abrir
            for(int i=0;i<lineas-1;i++){   //sumo todos los montos que se encuentran en cada linea hasta la penultima (la ultima linea es basura probablemente, porque no me la procesa)

                 fe2.getline(cadena, 128);
                 monto_total=monto_total+DevolverMonto(cadena);  //voy smando a medida que leo las lineas
            }

            cout<<"Monto total en "<< *(argv + 2)<<" : $"<<monto_total<<endl;   //monto total transacciones

        }

    }
    //Si el primer parametro es -f...
    else if (strcmp(*(argv + 1), "-a") == 0)
    {
        //Chequear que el segundo parametro no sea nulos.
        if (*(argv + 2) && *(argv + 3) != NULL)
        {
            //entregar la suma mensual de la tienda(de Enero a Diciembre) de la tienda especi?cada por �tienda�.
            //recordar que *(argv + 2) vendria siendo "tienda" y *(argv + 3) vendria siendo el nonbre del archivo.
        }
    }



    // O si el primer parametro es -v...
    else if (strcmp(*(argv + 1), "-v") == 0)
    {
        //Imprimo informacion de interes...
        cout << "Integrantes del grupo de trabajo : " << endl;
        cout << "1.Jonathan Leon S , rut:17.771.116-0" << endl;
        cout << "2.Francisca Sapiains Carrasco , rut:17707063-7" << endl;
        cout << "3.Cristian Mondaca Ruiz , rut:15610050-1" << endl;
        cout << "Fecha de compilacion: ";
        puts(__DATE__);  //Fecha de compilacion.

    }


    //O cualquier otra cosa...
    else
    {
        cout << "Error: Se necesitan parametros." << endl;
    }



}
