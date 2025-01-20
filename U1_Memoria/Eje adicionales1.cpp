/*Escriba una función que reciba un arreglo de enteros (y su tamaño), y busque elementos repetidos dentro del mismo.
La función debe retornar un struct con dos punteros apuntando a dos elementos del arreglo que tengan el mismo
valor. Si hay más de dos elementos repetidos, la función puede retornar cualquier par de ellos. Si no hay elementos
repetidos, la función debe retornar nullptr en ambos punteros.
Implemente un programa cliente que elimine de un arreglo todos sus elementos repetidos. No es necesario conservar el 
orden en los elementos, por lo que puede eliminar un elemento simplemente intercambiandolo con el último y reduciendo 
el tamaño del arreglo.
*/

#include <iostream>
using namespace std;

struct punteros {
	int *p1;
	int *p2;
};

punteros funcion (int *v, int n){
	punteros a;
	a.p1 = nullptr;
	a.p2 = nullptr;
	for(int i=0;i<n-1;i++) { 
		for(int j=i+1;j<n;j++) { 
			if (v[i] == v[j]){
				a.p1 = &v[i];
				a.p2 = &v[j];
				return a;
			}
		}
	}
	return a;
}

int main() {
	int n;
	cout << "Ingrese tamaño del array: ";
	cin >> n;
	int *v = new int [n];
	for(int i=0;i<n;i++) {
		v[i] = rand() % 50 + 1;
	}
	for(int i=0;i<n;i++) { 
		cout << v[i] << "  ";
	}
	while (true) {
		punteros repetidos = funcion(v, n);
		if (repetidos.p1 == nullptr || repetidos.p2 == nullptr) {
			break;
		}
		int *pos_repetido = repetidos.p2;
		int index = pos_repetido - v;
		v[index] = v[n - 1];
		n--;
	}

	int *nuevo_arreglo = new int[n];
	for (int i = 0; i < n; i++) {
		nuevo_arreglo[i] = v[i];
	}
	delete[] v;
	v = nuevo_arreglo;

	cout << "\nArreglo después de eliminar los repetidos:" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	delete[] v;
	return 0;
}

