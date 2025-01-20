/*Escriba un programa que genere un archivo binario con una lista de 100 enteros ordenados de forma creciente (por
ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba otro programa que permita insertar (no reemplazar) un nuevo dato
de tipo entero, ingresado por el usuario, en el archivo manteniendo el orden creciente. Importante: no debe utilizar
arreglos/vectores auxiliares.*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream archivo("numeros.bin", ios::binary);
	if (!archivo) {
		cerr << "No se pudo abrir el archivo para escritura." << endl;
		return 1;
	}
	for (int i = 0; i < 100; i++) {
		int numero = rand();
		ifstream archivo_lectura("numeros.bin", ios::binary);
		
		if (!archivo_lectura) {
			cerr << "No se pudo abrir el archivo para lectura." << endl;
			return 1;
		}
		
		bool insertado = false;
		int numero_archivo;
		while (archivo_lectura.read(reinterpret_cast<char*>(&numero_archivo), sizeof(numero_archivo))) {
			if (!insertado && numero < numero_archivo) {
				archivo.write(reinterpret_cast<char*>(&numero), sizeof(numero));
				insertado = true;
			}
			archivo.write(reinterpret_cast<char*>(&numero_archivo), sizeof(numero_archivo));
		}
		
		if (!insertado) {
			archivo.write(reinterpret_cast<char*>(&numero), sizeof(numero));
		}
		
		archivo_lectura.close();
	}
	
	archivo.close();
	return 0;
}

