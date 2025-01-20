/*a) Escriba una función llamada espejo que reciba 2 punteros indicando el comienzo y el final
de un arreglo, y genere un nuevo arreglo que sea el doble de largo que el original, y contenga primero
los elementos del arreglo original en el orden original, y luego todos los elementos menos el último, pero
en el orden inverso. Por ejemplo, si el arreglo original contiene {1,2,3,4,5}, el nuevo debe contener
{1,2,3,4,5,4,3,2,1}. b) Escriba una programa cliente que permita al usuario cargar un arreglo de n
elementos (n es dato que ingresa el usuario), y muestre el arreglo que genera la función.
*/

#include <iostream>
using namespace std;

int *espejo (int *inicio, int *fin){
	int n = (fin - inicio);
	cout << n;
	int n1 = n*2-1;
	int *p = new int[n1];
	for(int i=0;i<n;i++) { 
		p[i] = inicio[i];
		p[n1-i-1] = inicio[i];
	}
	return p;
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
	int *f = espejo(p,p+n);
	cout << "<Array espejo>" << endl;
	cout << "{";
	for(int i=0;i<(n*2-1);i++) { 
		cout << f[i];
		if (i < n*2 - 2) cout << ", ";
	}
	cout << "}" << endl;
	delete [] f;
	delete [] p;
	return 0;
}

