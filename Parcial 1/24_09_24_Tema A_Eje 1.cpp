/*Se quiere modelar la venta de entradas para un show:
a) Implemente una clase Entrada para representar una entrada a un show. La clase debe guardar el nro de
asiento, el tipo de entrada (string), el precio y si está vendida o no. Todos estos datos deben inicializarse
en un constructor. La clase debe tener además métodos para consultar los datos, y registrar la venta de
esa entrada cuando se realice.
b) Reutilizando la clase Entrada, cree una clase Show para gestionar la venta de entradas a un show. La
clase debe recibir en su constructor el nombre del show, y tener métodos para: (1) consultar el nombre; (2)
habilitar entradas recibiendo un tipo, un precio, y un rango de nros (desde, hasta)*; (3) vender una entrada,
indicando su número (debe retornar true si la venta es posible, false si el número no existe o no está
disponible) (4) consultar la lista de entradas y (5) calcular la recaudación total.
*Por ejemplo: si se le pasa “platea”, 10000, 100, 299, debe agregar al show 200 entradas de tipo platea
disponibles a $10000 cada una, numeradas del 100 al 299 inclusive.
c) Escriba un programa de prueba que cree un Show llamado “Susy Plus Plus y los Compiladores en vivo",
registre entradas tipo “platea” a $15000 para los nrs 100 a 199; y entradas tipo “palco” a $8000 para los
nros 500 a 650. Luego el programa debe permitir vender N entradas: para cada venta primero se muestra
la lista de entradas disponibles (nro, tipo, precio de cada una), se le pide al usuario el nro de asiento que
quiere comprar, y se registra la venta, o se muestra un mensaje de error si el nro es incorrecto. Al final del
programa debe informar la recaudación del show.
*/

#include <iostream>
#include <vector>
using namespace std;

class Entrada {
	int m_nro_asiento;
	string m_tipo;
	float m_precio;
	bool m_esta_vendida;
public:
	Entrada(int a, string t, float p) : m_nro_asiento(a), m_tipo(t), m_precio(p), m_esta_vendida(false) {}
	int VerNroAsiento() const {return m_nro_asiento;}
	string VerTipo() const {return m_tipo;}
	float VerPrecio() const {return m_precio;}
	bool EstaVendida() const {return m_esta_vendida;}
	void Vender() {
		if (!m_esta_vendida){
			m_esta_vendida = true;
			cout << "La entrada de tipo " << m_tipo << " a sido vendida" << endl;
		} else { cout << "La entrada ya esta vendida" << endl;}
	}
};

class Show {
	string m_nombre;
	vector<Entrada>entradas;
public:
	Show(string nombre) : m_nombre(nombre) {}
	string VerNombre() const {return m_nombre;}
	void HabilitarEntradas(string t, float p, int a, int b) {
		for(int i=a;i<=b;i++) { 
			Entrada e(i,t,p);
			entradas.push_back(e);
		}
	}
	bool VenderEntrada(int nro) {
		for (Entrada &e : entradas) {
			if(e.VerNroAsiento() == nro){
				if(e.EstaVendida()){ return false; }
				e.Vender();
				return true;
			}
		}
		return false;
	}
	int CantidadEntradas() const {return entradas.size();}
	Entrada VerEntrada(int i) const {return entradas[i];}
	float RecaudacionTotal() {
		float total = 0;
		for (Entrada &e : entradas) {
			if(e.EstaVendida()) 
			total += e.VerPrecio();
		}
		return total;
	}
};

int main() {
	Show show("Susy Plus Plus y los Compiladores en vivo");
	show.HabilitarEntradas("platea",15000,100,199);
	show.HabilitarEntradas("palco",8000,500,650);
	int N; 
	cin >> N;
	for(int i=0;i<N;i++) { 
		for(int j=0;j<show.CantidadEntradas();j++) { 
			Entrada e = show.VerEntrada(j);
			if(e.EstaVendida()) continue;
			cout << e.VerNroAsiento() << " " << e.VerTipo() << " $" << e.VerPrecio() << endl;
		}
		int nro;
		cin >> nro;
		if(show.VenderEntrada(nro)) {
			cout << "Vendida Exitosamente" << endl; 
		} else {
			cout << "Entrada no disponible" << endl;
		}
	}
	cout << "Recaudacion Total: " << show.RecaudacionTotal() << endl;
	return 0;
}

