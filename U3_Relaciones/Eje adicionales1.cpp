/*Se desea gestionar la venta de entradas de un teatro. Una sala de teatro est� compuesta por butacas y cada sala
puede tener diferente n�mero de butacas. a) Cada butaca tiene un tipo (cadena), un precio y un estado (si est�
libre u ocupada). Codifique una clase Butaca que tenga un constructor para cargar tipo y precio; y m�todos para
modificar o consultar sus datos, entre otras funcionalidades que considere necesarias. b) Defina una clase Sala que,
reutilizando la clase Butaca, guarde el nombre de la sala y la lista de butacas. La misma deber� tener:
� Un constructor que reciba el nombre de la sala.
� Un m�todo que permita agregar varias butacas de un mismo tipo y precio a la sala.
� Un m�todo para registrar la compra de una entrada recibiendo el n�mero de butaca. El m�todo debe verificar
que la butaca est� libre y retornar true si la compra se puede hacer, o false si ya estaba ocupada.
� Nota: asuma que el n�mero se determina por el orden en que se agreg� esa butaca a la sala
� Un m�todo para obtener la recaudaci�n total de una funci�n
� Un m�todo para obtener el porcentaje de ocupaci�n de la sala
*/

#include <iostream>
using namespace std;

class Butaca {
	string m_tipo;
	float m_precio;
	bool ocupada;
public:
	Butaca(string tipo, float precio) : m_tipo(tipo), m_precio(precio), ocupada(false) {}
	string VerTipo() const {return m_tipo;}
	float VerPrecio() const {return m_precio;}
	bool EstaOcupada() const {return ocupada;}
	void Ocupar() {
		if (!ocupada) {
			ocupada = true;
			cout << "La butaca de tipo " << tipo << " ha sido ocupada." << endl;
		} else {
			cout << "La butaca ya est� ocupada." << endl;
		}
	}
	void Liberar() {
		if (ocupada) {
			ocupada = false;
			cout << "La butaca de tipo " << tipo << " ha sido liberada." << endl;
		} else {
			cout << "La butaca ya est� libre." << endl;
		}
	}
};

class Sala {
	string nombre;
	vector<Butaca> butacas;
public:
	Sala(string nombre) : nombre(nombre) {}
	void agregarButacas(string tipo, float precio, int cantidad) {
		for (int i=0;i<cantidad;i++) {
			butacas.push_back(tipo, precio);
		}
		cout << cantidad << " butacas de tipo \"" << tipo << "\" agregadas a la sala " << nombre << "." << endl;
	}
	bool ComprarEntrada(int nrobutaca) {
		if (nrobutaca < 0 || nrobutaca >= butacas.size()) {
			cout << "Error: N�mero de butaca inv�lido." << endl;
			return false;
		}
		if (butacas[nrobutaca].EstaOcupada()) {
			cout << "Error: La butaca " << nrobutaca << " ya est� ocupada." << endl;
			return false;
		}
		butacas[nrobutaca].Ocupar();
		cout << "Compra exitosa. Butaca " << nrobutaca << " ahora est� ocupada." << endl;
		return true;
	}
	float ObtenerRecaudacionTotal() const {
		float total = 0.0f;
		for (const auto& butaca : butacas) {
			if (butaca.EstaOcupada()) {
				total += butaca.VerPrecio();
			}
		}
		return total;
	}
	float ObtenerPorcentajeOcupacion() const {
		int ocupadas = 0;
		for (const auto& butaca : butacas) {
			if (butaca.EstaOcupada()) {
				ocupadas++;
			}
		}
		return ocupadas / butacas.size()) * 100.0f;
	}
};

int main() {
	
	return 0;
}


