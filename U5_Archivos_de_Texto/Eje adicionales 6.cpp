/*Escriba una función reemplaza que permita modificar un archivo de texto reemplazando todas las ocurrencias de
una palabra o frase por otra. Por ejemplo, si se la invoca con reemplazar("texto.txt", "código abierto",
"open source"); debe buscar en el archivo texto.txt la frase código abierto y reemplazarla por open source 
todas las veces que la encuentre.
*/

#include <iostream>
#include <fstream>
using namespace std;

void reemplazar (string nom_archi, string s1, string s2){
	string texto;
	ifstream archi(nom_archi);
	if(not archi.is_open()) return;
	string aux;
	while(getline(archi,aux)){
		texto += aux + '\n';
	}
	archi.close();
	int pos = 0;
	while(texto.find(s1,pos) != string::npos){
		pos = texto.find(s1,pos);
		texto.replace(pos,s1.length(),s2);
		pos += s2.length();
	}
	ofstream archi2(nom_archi);
	archi2 << texto;
	archi2.close();
}

int main() {
	reemplazar("opensource_codigoabierto.txt","codigo abierto","open source");
	return 0;
}



