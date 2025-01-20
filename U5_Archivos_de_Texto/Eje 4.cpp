/*Se tiene un archivo inscriptos.txt con una lista de nombres de alumnos inscriptos al cursado de Fundamentos de
Programaci�n. Se desea distribuir los estudiantes en comisiones de pr�ctica de no m�s de 30 alumnos. Escriba
un programa que determine cuantas comisiones deber�an formarse de acuerdo a la cantidad de inscriptos y reparta
los alumnos en comisiones de igual tama�o (igual dentro de lo posible podr�a ser que algunas comisiones tengan
un alumno m�s que las otras), guardando la lista de alumnos de cada comisi�n en archivo de texto comision1.txt,
comision2.txt, � comisionN.txt. Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en un
string texto y n�meros para formar los nombres de los archivos.*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	vector<string>lista;
	ifstream archi("inscriptos.txt");
	if(not archi.is_open()) cout << "El archivo no se pudo abrir" << endl;
	string s;
	while(getline(archi,s)){
		lista.push_back(s);
	}
	archi.close();
	int total = lista.size();
	int num = (lista.size() + 30) / 30;
	cout << "Total alumnos: " << lista.size() << endl;
	cout << "Comisiones necesarias: " << num << endl;
	int inicio = 0;
	for(int i=0;i<num;i++) { 
		stringstream nombre_archivo;
		nombre_archivo << "Comision " << i+1 << ".txt";
		ofstream archi1(nombre_archivo.str());
		int fin = min(inicio + 30, total);
		for (int j = inicio; j < fin; ++j) {
			archi1 << lista[j] << endl;
		}
		inicio = fin;
		archi1.close();
	}
	cout << "Archivos generados exitosamente." << endl;
	
	return 0;
}

