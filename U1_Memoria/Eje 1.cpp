/*Declare una variable entera común y otra variable entera utilizando memoria dinámica (almacenando su dirección
de memoria en un puntero). Asigne a la primera variable el valor 10 y a la segunda variable un valor ingresado por
el usuario. Muestre luego los valores y las direcciones de memoria de ambas variables. IMPORTANTE: No olvide
liberar la memoria de la segunda variable antes de salir.
*/

#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int *b = new int;
	int n; cin >> n;
	*b = n;
	cout << &a << "  " << b << endl;
	cout << a << "  " << *b;
	delete b;
	return 0;
}

