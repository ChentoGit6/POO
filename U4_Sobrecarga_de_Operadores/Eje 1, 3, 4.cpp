/*Eje 1: Dada la clase Racional mostrada en el recuadro:
class Racional {
public:
Racional(int num, int den) : m_num(num), m_den(den) { }
int VerNum() const { return m_num; }
int VerDen() const { return m_den; }
private:
int m_num, m_den;
};
Implemente sobrecargas para los siguiente operadores:
• El operador + para sumar dos objetos de la clase Racional.
• El operador * para multiplicar un objeto de tipo Racional por un entero.
Finalmente, compruebe el funcionamiento de los operadores con el siguiente programa cliente:
int main() {
Racional a(3, 5), b(2, 3);
Racional aux = a + b;
cout << aux.VerNum() << '/' << aux.VerDen() << endl;
aux = a * b;
cout << p.VerNum() << '/' << p.VerDen() << endl;}
Si ocurren errores de compilación, explique su causa e implemente las correcciones necesarias. Analice: ¿Qué otro
operador se utiliza para la clase Racional en éste programa cliente? ¿Por qué no es necesario sobrecargarlo?

Eje 3: Implemente sobrecargas para los operadores >> y << para leer un objeto de tipo Racional desde la consola (mediante
cin) y mostrarlo en pantalla (mediante cout). La lectura se debe realizar leyendo el numerador y denominador por
separado (es decir, separados por un espacio o salto de línea). El operador << debe mostrar el numerador y el
denominador separados por el carácter '/'. Analice: la sobrecarga de este operador, ¿debe realizarse dentro o
fuera de una clase?

Eje 4: Implemente sobrecargas para pre y post incremento (operador ++) para la clase Racional de los ejercicios anteriores.
Proponga un programa de prueba donde se note la diferencia entre uno y otro.
*/

#include <iostream>
using namespace std;

class Racional {
	int m_num, m_den;
public:
	Racional(int num=0, int den=1) : m_num(num), m_den(den) { }
	int VerNum() const { return m_num; }
	int VerDen() const { return m_den; }
	Racional operator+ (const Racional& r) const {
		Racional suma (
			this->m_num * r.m_den + this->m_den * r.m_num,
			this->m_den * r.m_den);
		return suma;
	}
	Racional operator* (const Racional& r) const {
		Racional producto (
			this->m_num * r.m_num,
			this->m_den * r.m_den);
		return producto;
	}
	Racional operator* (int r) {
		Racional producto (
			this->m_num * r,
			this->m_den);
		return producto;
	}
	friend ostream& operator<<(ostream& o, const Racional& r);
	friend istream& operator>>(istream& i, Racional& r);
	Racional &operator++() {
		m_num += m_den;
		return *this;	
	}
	Racional operator++(int) {
		Racional aux = *this;
		m_num += m_den;
		return aux;
	} 
};

ostream& operator<<(ostream &o, const Racional& r){
	o << r.VerNum() << "/" << r.VerDen();
	return o;
}

istream& operator>>(istream &i, Racional& r){
	cout << "Ingrese el numerador: ";
	i >> r.m_num;
	cout << "Ingrese el denominador: ";
	i >> r.m_den;
	return i;
}

int main() {
	Racional a(3, 5), b(2, 3);
	Racional aux = a + b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	aux = a * b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	aux = a * 2;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
//	El operador = es el operador de asignación. En este caso, no necesitamos sobrecargarlo porque el compilador 
//	genera uno implícitamente, que copia los atributos de un objeto a otro. Esto es suficiente en este caso 
//	porque no hay atributos dinámicos (como punteros) que requieran manejo especial.
	cout << endl;
	Racional f;
	cin >> f; // Leyendo f implementando la sobrecarga de >>
	cout << f; // Mostrando f implementando la sobrecarga de <<
	cout << endl;
	cout << "Estado inicial: " << a << endl;
	cout << "Usando preincremento (++r): " << ++a << endl;
	cout << "Usando postincremento (r++): " << a++ << endl;
	cout << "Estado final después del postincremento: " << a << endl;
	return 0;
}
