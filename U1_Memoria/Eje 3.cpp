#include <iostream>
#include <ctime>
using namespace std;
/*Escriba una función que utilice punteros para buscar y retornar la dirección de un entero dentro de un arreglo. Se
pasan como parámetros el arreglo, su tamaño y el entero a buscar. Si el dato no se encuentra, debe retornar
la dirección de memoria nula (nullptr). ¿Desde un programa cliente, cómo se obtiene el índice del elemento
encontrado cuando la función no devuelve nullptr?
*/
int *funcion (int *p, int n, int entero){
	
	for(int i=0;i<n;i++) { 
		if (*(p+i) == entero){
			return p+i;
		}
	}
	return nullptr;
}

int main() {
	srand(time(0));
	int n, entero;
	cout << "Inserte el tamaño del vector: "; cin >> n;
	
	int *p = new int [n];
	
	for(int i=0;i<n;i++) { 
		p[i] = rand()%501 + 1000;
		cout << "pos [" << i << "] = " << p+i <<" = " << p[i];
		cout << endl;
	}
	entero = 10;
	cout << "Inserte el entero a buscar: "; cin >> entero;
	int *aux = funcion(p, n, entero);
	if (aux != nullptr){
		cout << "Su dirección de memoria es: " << aux << " en el indice " << aux - p << endl;
	}else{
		cout << "No se ha encontrado el valor en el array"<<endl;
	}
	// cuando la funcion no devuelve nullptr el indice del elemento encontrado se hace restando el puntero base menos el puntero encontrado
	delete []p;
	return 0;
}

