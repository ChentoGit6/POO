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
	int *p = new int [n];
	
	for(int i=0;i<n;i++) { 	
		p[i] = rand()%501 + 1000;
	}
	
	int mayor = 0, pos;
	
	for(int i=0;i<n;i++) { 
		if(p[i] > mayor){
		mayor = p[i];
		pos = i;
		}
	}
	for(int i=0;i<n;i++) { 
		cout << p[i] << "  -  ";
	}
	cout << endl;
	cout << &p[mayor]<< "   " << mayor << "   " << pos;
	delete []p;
	return 0;
}

