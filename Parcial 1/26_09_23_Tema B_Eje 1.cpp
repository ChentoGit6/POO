/*a) Dise�e una clase Pasajero para guardar los datos de un pasajero de un vuelo de avi�n.
La clase debe guardar un string con apellido y nombre, tipo de pasaje (est�ndar o 1ra clase) y peso del
equipaje a despachar. Estos datos deben inicializarse en el constructor de la clase.
b) Reutilizando la clase Pasajero, dise�e una clase Vuelo para representar los datos de un vuelo. La
clase debe tener un constructor que permita definir los aeropuertos de origen y destino, y la cantidad de
asientos disponibles de cada tipo. Debe tener adem�s:
- c) un m�todo para agregar un pasajero al vuelo; este m�todo deber� retornar true si el pasajero debe
pagar por exceso de equipaje (si su equipaje supera los 15ks para un pasaje est�ndar, o los 30ks para
1ra clase).
- d) un m�todo para consultar la cantidad de asientos disponibles de un cierto tipo (el tipo ser� el
argumento, est�ndar o 1ra clase, y se calcula restando al total los ocupados por pasajeros ya
cargados).
- e) un m�todo para obtener el peso total del equipaje (sumando el de todos los pasajeros).
Declare en ambas clases todos los m�todos que considere adecuados o necesarios, pero implemente
solo los constructores y los m�todos que se piden expl�citamente en c, d y e (para los dem�s, solo
escriba el prototipo).*/

#include <iostream>
#include <vector>
using namespace std;

class Pasajero {
	string m_ap_nom;
	string m_tipo_pasaje;
	float m_peso_equipaje;
	bool m_es_estandar;
public:
	Pasajero(string an, string tp, float pe, bool e) 
		: m_ap_nom(an), m_tipo_pasaje(tp), m_peso_equipaje(pe), m_es_estandar(e) {}
	string VerNombre() const {return m_ap_nom;}
	string VerPasaje() const {return m_tipo_pasaje;}
	float VerPesoEquipaje() const {return m_peso_equipaje;}
	bool EsEstandar() const {return m_es_estandar;}
};

class Vuelo {
	string m_origen;
	string m_destino;
	int m_asientos_estandar;
	int m_asientos_1ra_clase;
	vector<Pasajero>m_estandar;
	vector<Pasajero>m_1raclase;
public:
	Vuelo(string o, string d, int ae, int a1) : m_origen(o), m_destino(d), 
		m_asientos_estandar(ae), m_asientos_1ra_clase(a1) {}
	string VerOrigen() const { return m_origen; }
	string VerDestino() const { return m_destino; }
	bool AgregarPasajero(Pasajero p) {
		if(p.EsEstandar()){
			m_estandar.push_back(p);
			if(p.VerPesoEquipaje() > 15) return true;
		} else {
			m_1raclase.push_back(p);
			if(p.VerPesoEquipaje() > 30) return true;
			}
		return false;
	}
	int AsientosDisponibles(int nro_tipo_clase) {
		if(nro_tipo_clase == 1) {
			return (m_asientos_1ra_clase - m_1raclase.size());
		}
		return (m_asientos_estandar - m_estandar.size());
	}
	float TotalEquipaje() {
		float total;
		for(size_t i=0;i<m_estandar.size();i++) { 
			total += m_estandar[i].VerPesoEquipaje();
		}
		for(size_t i=0;i<m_1raclase.size();i++) { 
			total += m_1raclase[i].VerPesoEquipaje();
		}
		return total;
	}
};

int main() {
	
	return 0;
}

