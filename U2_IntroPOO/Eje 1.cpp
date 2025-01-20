#include <iostream>
using namespace std;
/*Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el volumen del cuerpo conociendo el
radio de su base y la altura del mismo.
1. La interfaz pública de la clase debe estar compuesta por los métodos AsignarDatos(...) y ObtenerVolumen(...)
para asignar los datos del problema y obtener el volumen del cuerpo.
2. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de Cilindro llamadas c1 y c2. El objeto
c1 debe utilizar datos ingresados por el usuario, mientras que para c2 utilice 5.3cm y 10.2cm para el radio y la
altura respectivamente.
3. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para inicializar el radio y la altura. Luego
intente compilar nuevamente el programa. ¿Puede explicar por qué se produce un error? Proponga una
solución.
*/
class Cilindro {
private: 
	float m_rad, m_alt;
public: 
	void asigdatos(float rad, float alt){
		m_rad = rad; m_alt = alt;
	};
	float obtener_vol();
};
float Cilindro::obtener_vol(){
	return 3.14 * m_rad * m_rad * m_alt;
}
int main() {
	float rad, alt;
	cout << "Ingrese el radio de la base del cilindro 1 y la altura: "<< endl;
	cout << "  Radio: "; cin >> rad;
	cout << "  Altura: "; cin >> alt;
	
	Cilindro c1;
	c1.asigdatos(rad, alt);
	cout << "El volúmen del cilindro 1 es: "<< c1.obtener_vol() << endl;
	
	Cilindro c2;
	c2.asigdatos(5.3, 10.2);
	cout << "El volúmen del cilindro 2 es: "<< c2.obtener_vol() << endl;
	return 0;
}

