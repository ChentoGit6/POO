/*Escriba una clase AnalizaTexto con m�todos para analizar un archivo de texto (que contendr� varios p�rrafos) y
obtener los siguientes resultados:
� cantidad de caracteres en el texto (longitud del mismo)
� cantidad p�rrafos (nota: recuerde ignorar l�neas en blanco)
� cantidad de letras, cantidad de espacios en blanco, y de otros caracteres (como signos depuntuaci�n) por
separado.
Proponga un programa cliente que la utilice.*/

#include <iostream>
#include <fstream>
using namespace std;

class AgregarTexto {
	string texto;
public:
	AgregarTexto(string s) {
		ifstream archi(s);
		string aux;
		while(archi >> aux){
			texto += aux;
			archi.ignore();
		}
		archi.close();
	}
	int CantidadCaracteres() {
		return texto.length();
	}
	int CantidadParrafos() {
		int a = 0;
		int pos = 0;
		while (texto.find(".",pos) != string::npos) {
			pos = texto.find(".",pos+1);
			a++;
		}
		return a-1;
	}
	
};

int main() {
	AgregarTexto at("dad.txt");
	cout << at.CantidadCaracteres() << endl;
	cout << at.CantidadParrafos() << endl;
	return 0;
}

