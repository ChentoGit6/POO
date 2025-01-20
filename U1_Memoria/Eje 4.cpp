/*Se tiene un arreglo din�mico de n enteros, y se quiere aumentar su tama�o a un nuevo tama�o c. Implemente una
funci�n redimensionar() que reserve din�micamente memoria para un nuevo arreglo que contenga lugar suficiente
para guardar c datos (los n datos anteriores y los c-n nuevos). Copie en la nueva memoria los datos del vector viejo
e inicialice con ceros los nuevos elementos. La memoria del primer arreglo debe ser liberada y el struct actualizado
para que el programa cliente pueda seguir operando con el nuevo arreglo. La funci�n deber�a poder invocarse de la
siguiente manera:
arreglo a;
...incializar a con n elementos...
redimensionar(a, c);
El struct arreglo contendr�a el puntero a los datos y el entero con el tama�o
Finalmente, implemente un programa cliente que muestre el arreglo resultante.
*/

#include <iostream>
using namespace std;

struct arreglo {
	int *p;
	int size;
};

void redimensionar (arreglo &a, int c){
	int *v = new int [c];
	for(int i=0;i<a.size;i++) { 
		*(v+i) = *(a.p+i);
	}
	for(int i=a.size;i<c;i++){
		*(v+i) = 0;
	}
	delete []a.p;
	a.p = v;
	a.size = c;
}

int main() {
	arreglo a;
	cout << "Ingrese el tama�o inicial del arreglo: ";
	cin >> a.size;
	a.p = new int [a.size];
	for(int i=0;i<a.size;i++) { // inicializo el arreglo con valores entre 1 y 100
		*(a.p+i) = rand() % 100 + 1;
	}
	cout << "Arreglo inicial:\n";
	for (int i=0;i< a.size;i++) {
		cout << *(a.p+i) << " ";
	}
	cout << endl;
	int c;
	cout << "Ingrese el nuevo tama�o del arreglo: ";
	cin >> c;
	redimensionar(a,c);
	cout << "Arreglo redimensionado:\n";
	for (int i=0;i< a.size;i++) {
		cout << *(a.p+i) << " ";
	}
	delete []a.p;
	return 0;
}

