/*Proponga una clase CuentaObjetos que permita llevar cuenta de los objetos que son creados. Para ello defina un
constructor y un destructor que notifiquen por pantalla cuando un objeto fue creado/destruido y adem�s muestre la
cantidad de objetos que a�n se encuentran en memoria. Utilice un programa cliente para probar la clase y realice la
creaci�n/destrucci�n de los objetos de forma din�mica.
*/

#include <iostream>
using namespace std;

class CuentaObjetos {
private:
	static int m_contador;
public:
	CuentaObjetos() {
		m_contador++;
		cout << "Objeto creado. Objetos en memoria: " << m_contador << endl;
	}
	~CuentaObjetos() {
		m_contador--;
		cout << "Objeto destruido. Objetos en memoria: " << m_contador << endl;
	}
	static int ObjetosEnMemoria() {
		return m_contador;
	}
};

int CuentaObjetos::m_contador = 0;

int main() {
	cout << "Inicio del programa" << endl;

	CuentaObjetos* obj1 = new CuentaObjetos();
	CuentaObjetos* obj2 = new CuentaObjetos();
	
	cout << "Objetos en memoria: " << CuentaObjetos::ObjetosEnMemoria() << endl;

	delete obj1;
	delete obj2;

	cout << "Objetos en memoria despu�s de liberar memoria: " << CuentaObjetos::ObjetosEnMemoria() << endl;
	
	cout << "Fin del programa" << endl;
	return 0;
}
