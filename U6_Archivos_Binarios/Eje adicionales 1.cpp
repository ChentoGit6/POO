/*Escriba una función CreateDummyFile(...) que reciba el nombre de un archivo y un entero con su tamaño en bytes.
La función debe crear un archivo binario del tamaño especificado y llenarlo con valores aleatorios (basura). Escriba
una sobrecarga de la función en la que se especifique el tamaño del archivo mediante un std::string, por ejemplo:
“100Mb”, “10Kb” ó “893b”.*/

#include <iostream>
#include <fstream>
using namespace std;

int CreateDummyFile(string s, int n){
	ofstream archivo(s,ios::binary);
	for(int i=0;i<n/4;i++) { 
		archivo.write(reinterpret_cast<char*>(&n),sizeof(n));
	}
	int tam_bytes = archivo.tellp();
	archivo.close();
	return tam_bytes;
}

int main() {
	int i = CreateDummyFile("datos.dat", 240000);
	cout << i <<"b";
	return 0;
}

