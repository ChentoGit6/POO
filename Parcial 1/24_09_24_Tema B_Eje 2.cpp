/*Sin utilizar la clase std::vector: a) Escriba una función filtrar_rango que reciba un arreglo de
enteros a y dos valores min y max. La función debe generar y retornar un nuevo arreglo que contenga
todos los elementos de a que no estén en ese rango de valores [min;max]. Ejemplo: si a={ 1,3,4,2,6,8,1,4,3
}, min=3, y max=5, entonces debe retornar { 1,2,6,8,1 }. b) Escriba un programa cliente que permita
ingresar al usuario un arreglo de n enteros (n también es dato), dos enteros min y max, y muestre el
arreglo que genera la función.*/

#include <iostream>
using namespace std;

struct Array {
	int *p;
	int n;
};

Array filtrar_rango(Array a, int min, int max) {
	Array b;
	b.n = 0;
	for(int i=0;i<a.n;i++) { 
		if(a.p[i] < min or a.p[i] > max){
			++b.n;
		}
	}
	b.p = new int [b.n];
	int cont = 0;
	for(int i=0;i<a.n;i++) { 
		if(a.p[i] < min or a.p[i] > max){
			b.p[cont] = a.p[i];
			++cont;
		}
	}
	return b;
}

int main() {
	Array a;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> a.n;
	a.p = new int [a.n];
	cout << "Ingrese los numeros del arreglo:" << endl;
	for(int i=0;i<a.n;i++) { 
		cin >> a.p[i];
	}
	int min, max;
	cout << "Ingrese dos enteros para eliminar del arreglo ese rango de numeros:" << endl;
	cin >> min >> max;
	cout << "Arreglo antes de eliminar el rango de [" << min << ";" << max << "]" << endl;
	for(int i=0;i<a.n;i++) { 
		cout << a.p[i] << ",";
	}
	cout << endl;
	Array z = filtrar_rango(a,min,max);
	cout << "Arreglo luego de eliminar el rango de [" << min << ";" << max << "]" << endl;
	for(int i=0;i<z.n;i++) { 
		cout << z.p[i] << ",";
	}
	delete []a.p;
	delete []z.p;
	return 0;
}

