#include <iostream>
#include <ctime>
using namespace std;

/*Utilizando notaci�n de punteros, generar un arreglo din�mico y lineal de N elementos num�ricos enteros, con valores
aleatorios entre 1000 y 1500, y muestre en pantalla la direcci�n de memoria del mayor elemento. N es un dato
ingresado por el usuario.
*/

int main() {
	srand(time(0));
	int n;
	cin >> n;
	int *v = new int [n];
	
	for(int i=0;i<n;i++) { 	
		v[i] = rand()%501 + 1000;
	}
	for(int i=0;i<n;i++) { 
		cout << *(v+i) << "  " << (v+i) << endl;
	}
	int *mayor = v;
	for(int i=0;i<n;i++) { 
		if(v[i] > *mayor) mayor = (v+i);
	}
	cout << "El mayor es: " << *mayor << "  " << mayor;
	delete []v;
	return 0;
}

