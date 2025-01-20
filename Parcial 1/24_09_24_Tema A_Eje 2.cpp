/*Sin utilizar la clase std::vector: a) Escriba una función copia_sin_x que reciba un arreglo de
enteros a y un entero x. La función debe generar y retornar un nuevo arreglo que contenga todos los
elementos de a menos x. Ejemplo: si a={ 1,3,4,1,6,8,1,4,3 } y x=1, entonces debe retornar { 3,4,6,8,4,3 }.
b) Escriba un programa cliente que permita ingresar al usuario un arreglo de n enteros (n también es dato),
un entero x, y muestre el arreglo que genera la función.
*/

#include <iostream>
using namespace std;

struct Arreglo {
	int *p;
	int n;
};

Arreglo copia_sin_x (Arreglo a, int x) {
	Arreglo f;
	f.n = 0;
	for(int i=0;i<a.n;i++) { 
		if(a.p[i] != x) ++f.n;
	}
	f.p = new int [f.n];
	int cont = 0;
	for(int i=0;i<a.n;i++) { 
		if (a.p[i] != x) {
			f.p[cont] = a.p[i];
			++cont;
		}
	}
	return f;
}

int main() {
	Arreglo a;
	cout << "Ingrese tamamaño del array: ";
	cin >> a.n;
	a.p = new int[a.n];
	cout << "Ingrese los numeros del array:" << endl;
	for(int i=0;i<a.n;i++) { 
		cin >> a.p[i];
	}
	int x;
	cout << "Ingrese numero a eliminar del array: ";
	cin >> x;
	cout << "Arreglo antes de eliminar el " << x << endl;
	for(int i=0;i<a.n;i++) { 
		cout << a.p[i] << ",";
	}
	cout << endl;
	Arreglo f = copia_sin_x(a,x);
	cout << "Arreglo luego de eliminar el " << x << endl;
	for(int i=0;i<f.n;i++) { 
		cout << f.p[i] << ",";
	}
	delete []a.p;
	delete []f.p;
	return 0;
}

