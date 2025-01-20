/*Generar aleatoriamente una matriz de números reales de doble precisión de 10 filas por 6 columnas mediante un
puntero a un arreglo. Usando notación de punteros determine e informe: a) el promedio de la fila que el usuario
ingrese como dato; b) la suma de cada columna. Analice: ¿sería posible, manteniendo la estructura de puntero a
arreglo, que el usuario ingresara el tamaño de la matriz (filas x columnas)?
*/

#include <iostream>
using namespace std;

int main() {
	float **m = new float *[10];
	for(int i=0;i<10;i++) { 
		m[i] = new float [6];
	}
	for (int i=0;i<10;i++) {
		for (int j=0;j<6;j++) {
			m[i][j] = (rand() % 10000) / 100.0; // Generar número real entre 0.00 y 100.00
		}
	}
	int f;
	cin >> f;
	float prom = 0;
	for(int i=0;i<6;i++) { 
		prom += m[f][i];
	}
	prom = prom/6;
	int sum = 0;
	for(int i=0;i<6;i++) { 
		for(int j=0;j<10;j++) { 
			sum += m[j][i];
		}
		cout << sum << "  ";
		sum = 0;
	}
	for(int i=0;i<10;i++) { 
		delete [] m[i];
	}
	delete []m;
	return 0;
}

