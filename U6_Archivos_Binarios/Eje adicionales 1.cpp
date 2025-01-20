/*Escriba una funci�n CreateDummyFile(...) que reciba el nombre de un archivo y un entero con su tama�o en bytes.
La funci�n debe crear un archivo binario del tama�o especificado y llenarlo con valores aleatorios (basura). Escriba
una sobrecarga de la funci�n en la que se especifique el tama�o del archivo mediante un std::string, por ejemplo:
�100Mb�, �10Kb� � �893b�.*/

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

