#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{

	//Si el primer parametro es -f...
	if (strcmp(*(argv + 1), "-s") == 0)
	{
		if (*(argv + 2) != NULL) //Chequear que el segundo parametro no sea nulo.
		{
			//entregar la suma total de las ventas de todas las tiendas, que existan en el archivo.csv.
		}

	}
	//Si el primer parametro es -f...
	else if (strcmp(*(argv + 1), "-a") == 0)
	{
		//Chequear que el segundo parametro no sea nulos.
		if (*(argv + 2) && *(argv + 3) != NULL)
		{
			//entregar la suma mensual de la tienda(de Enero a Diciembre) de la tienda especi?cada por “tienda”.
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
