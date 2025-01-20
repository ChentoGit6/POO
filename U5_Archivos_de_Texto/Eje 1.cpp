/*Escriba un programa que cargue en un vector de strings una lista de palabras desde un archivo de texto (que
contendrá una palabra por línea), muestre en pantalla la cantidad de palabras leídas, las ordene en el vector
alfabéticamente, y reescriba el archivo original con la lista ordenada. Ayuda: para ordenar un vector v de principio a
fin puede utilizar la sentencia sort(v.begin(), v.end());.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	vector<string>v;
	ifstream archi("lista_palabras.txt");
	if (not archi.is_open()) throw runtime_error("No se pudo leer lista_palabras.txt.");
	string s;
	while(getline(archi,s)){
		v.push_back(s);
	}
	archi.close();
	sort(v.begin(),v.end());
	ofstream archi1("lista_palabras.txt", ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		archi1 << v[i] << endl;
	}
	return 0;
}

