/*Escriba una función que reciba 2 punteros indicando el comienzo y el final de un arreglo, y
un entero m. La función debe generar un nuevo arreglo que contenga m veces cada elemento del
arreglo original. Por ej, si el arreglo original es {2,4,6,8} y m=3, entonces el arreglo generado debe ser
{2,2,2,4,4,4,6,6,6,8,8,8} (se repite 3 veces cada uno). Escriba una programa cliente que permita al
usuario cargar un arreglo de n elementos (n es dato que ingresa el usuario), y muestre los arreglos que
genera la función para cada valor de m desde 2 hasta 5 (incluido).
*/

#include <iostream>
using namespace std;

int *funcion (int *inicio, int *fin, int m) {
	int n = (fin - inicio);
	int *array = new int[n*m];
	int cont = 0;
	for(int i=0;i<n;i++) { 
		for(int j=0;j<m;j++){
			array[cont] = inicio[i];
			++cont; 
		}
	}
	return array;
}

int main() {
	int n;
	cout << "Indique el tamaño del array: ";
	cin >> n;
	int *p = new int[n];
	cout << "Ingrese los valores:" << endl;
	for(int i=0;i<n;i++) { 
		cin >> p[i];
	}
	cout << "<Array inicial>" << endl;
	cout << "{";
	for(int i=0;i<n;i++) { 
		cout << p[i];
		if (i < n - 1) cout << ", ";
	}
	cout << "}" << endl;
	cout << endl;
	for(int m=2;m<6;m++){
		cout << "<Array con m=" << m << ">" << endl;
		int *f = funcion(p,p+n,m);
		cout << "{";
		for(int i=0;i<n*m;i++) { 
			cout << f[i];
			if (i < n*m - 1) cout << ", ";
		}
		cout << "}" << endl;
		cout << endl;
		delete [] f;
	}
	delete [] p;
	return 0;
}

