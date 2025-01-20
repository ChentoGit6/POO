/*Eje 5: Implemente una clase llamada Complejo para representar un número complejo. Sobrecargue los operadores <<, >>,
+, -, * e == para mostrar, leer, sumar, restar, multiplicar y comparar respectivamente dos objetos de tipo Complejo.
Compruebe el funcionamiento de los operadores desde un programa cliente.

Eje 6: Implemente una sobrecarga del operador [ ] para la clase Complejo del ejercicio anterior, que permita obtener las
partes real e imaginaria como si fueran 2 elementos en un arreglo:
Complejo c(1, 2); // 1+2i
cout << "Parte real: " << c[0] << endl; // muestra 1
cout << "Parte imag: " << c[1] << endl; // muestra 2
Explique: ¿Podría su sobrecarga utilizarse para modificar las partes del número complejo?
Complejo c;
cout << "Ingrese la parte real: ";
cin >> c[0];
cout << "Ingrese la parte imaginaria: ";
cin >> c[1];
*/

#include <iostream>
using namespace std;

class Complejo {
	float m_real;
	float m_imaginario;
public:
	Complejo(float real=0, float imaginario=0) : m_real(real), m_imaginario(imaginario) {}
	float VerParteReal() const {return m_real;}
	float VerParteImaginaria() const {return m_imaginario;}
	friend ostream &operator<<(ostream &o, const Complejo &c);
	friend istream &operator>> (istream &i, Complejo &c);
	Complejo operator+ (const Complejo &c1) const {
		return Complejo(m_real + c1.m_real, m_imaginario + c1.m_imaginario);
	}
	Complejo operator- (const Complejo &c1) const {
		Complejo resta (
			this->m_real - c1.m_real,
			this->m_imaginario - c1.m_imaginario);
		return resta;
	}
	Complejo operator* (const Complejo &c1) const {
		Complejo producto (
			this->m_real * c1.m_real,
			this->m_imaginario * c1.m_imaginario);
		return producto;
	}
	bool operator==(const Complejo& c) const {
		return m_real == c.m_real && m_imaginario == c.m_imaginario;
	}
	float operator[] (int i) const {
		if (i==0) return m_real;
		else return m_imaginario;
	}
	// Si a la sobrecarga le agrego el & y elimino el const, entonces si se va a poder utilizarse para modificar
	// las partes del nro complejo, ya que en este esquema le estoy pasando una referencia de la variable y no
	// el valor, por lo tanto habilita a ser modificado, en el de arriba retorna el valor(copia) y acá la variable(referencia)
	float& operator[] (int i) {
		if (i==0) return m_real;
		else return m_imaginario;
	}
};

ostream &operator<<(ostream &o, const Complejo &c){
	o << c.VerParteReal() << "+" << c.VerParteImaginaria() << "i" << endl;
	return o;
}

istream &operator>> (istream &i, Complejo &c){
	cout << "Ingrese la parte real: ";
	i >> c.m_real;
	cout << "Ingrese la parte imaginaria: ";
	i >> c.m_imaginario;
	return i;
}

int main() {
	Complejo c1(3, 4), c2(1, -2), c3;
	cout << "Ingrese un número complejo (c3):" << endl;
	cin >> c3;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	Complejo suma = c1 + c2;
	cout << "Suma (c1 + c2): " << suma << endl;
	Complejo resta = c1 - c2;
	cout << "Resta (c1 - c2): " << resta << endl;
	Complejo producto = c1 * c2;
	cout << "Producto (c1 * c2): " << producto << endl;
	if (c1 == c2)
		cout << "c1 y c2 son iguales." << endl;
	else
		cout << "c1 y c2 son diferentes." << endl;
	cout << endl;
	cout << c1[0] << "+" << c1[1] << "i" << endl;
	cout << endl;
	Complejo c;
	cout << "Ingrese la parte real: ";
	cin >> c[0];
	cout << "Ingrese la parte imaginaria: ";
	cin >> c[1];
	cout << c;
	return 0;
}

