/*Una empresa de turismo ofrece paquetes de vacaciones utilizando una combinación de distintos medios de transporte
using namespace std;
por viaje: barco, tren y colectivo. Escriba un programa C++ en donde se declare una clase Transporte para modelar
un tramo del recorrido que tendrá como atributos la distancia, costo y duración. Además declare otras tres clases:
TransporteBarco, TransporteTren y TransporteColectivo, que deben servir para representar un viaje en cada
medio de transporte. Puede agregar otros atributos si lo considera necesario. Las clases deben tener métodos
para consultar la distancia, la duración y el costo de ese trayecto. Los constructores reciben como datos cual
es la distancia a recorrer en kilómetros. La duración en horas y el costo se calcula a partir de la distancia de la
siguiente manera: • Barco: duración: 4+distancia/30 costo: 20+distancia*10 • Tren: duración: 1+distancia/120 costo:
distancia*6 • Colectivo: duración: distancia/80 costo: 2+distancia*3 Para calcular el costo total y la duración de un
paquete turístico, deberá crear una función independiente llamada viaje(...), que reciba como parámetro un vector
con todos recorridos del viaje. Cree un breve programa cliente para probar la función.*/

#include <iostream>
#include <vector>
using namespace std;

class Transporte {
protected:
	float m_distancia;
	float m_costo;
	float m_duracion;
public:
	Transporte(float distancia) : m_distancia(distancia), m_costo(0), m_duracion(0) {}
	virtual float VerDistancia() = 0;
	virtual float VerCosto() = 0;
	virtual float VerDuracion() = 0;
	virtual float CalcularCosto() = 0;
	virtual float CalcularDuracion() = 0;
	virtual ~Transporte() {};
};

class TransporteBarco : public Transporte {
public:
	TransporteBarco(float d) : Transporte(d) {}
	float VerDistancia() override {return m_distancia;}
	float VerCosto() override {return m_costo;}
	float VerDuracion() override {return m_duracion;}
	float CalcularCosto() override {
		m_costo = 20+m_distancia*10;
		return m_costo;
	}
	float CalcularDuracion() override {
		m_duracion = 4 + m_distancia / 30;
		return m_duracion;
	}
};

class TransporteTren : public Transporte {
public:
	TransporteTren(float d) : Transporte(d) {}
	float VerDistancia() override {return m_distancia;}
	float VerCosto() override {return m_costo;}
	float VerDuracion() override {return m_duracion;}
	float CalcularCosto() override {
		m_costo = m_distancia * 6;
		return m_costo;
	}
	float CalcularDuracion() override {
		m_duracion = 1 + m_distancia / 120;
		return m_duracion;
	}
};

class TransporteColectivo : public Transporte {
public:
	TransporteColectivo(float d) : Transporte(d) {}
	float VerDistancia() override {return m_distancia;}
	float VerCosto() override {return m_costo;}
	float VerDuracion() override {return m_duracion;}
	float CalcularCosto() override {
		m_costo = 2 + m_distancia * 3;
		return m_costo;
	}
	float CalcularDuracion() override {
		m_duracion = m_distancia / 80;
		return m_duracion;
	}
};

pair<float,float> viaje (vector<Transporte*>viajes) {
	float costo_total = 0, duracion_total = 0;
	for(const auto& tramo : viajes) { 
		costo_total += tramo->CalcularCosto();
		duracion_total += tramo->CalcularDuracion();
	}
	return {costo_total,duracion_total};
}

int main() {
	vector<Transporte*> viajes;
	viajes.push_back(new TransporteBarco(100));
	viajes.push_back(new TransporteTren(200));
	viajes.push_back(new TransporteColectivo(50));
	pair<float, float> resultado = viaje(viajes);
	cout << "Costo total: " << resultado.first << endl;
	cout << "Duración total: " << resultado.second << endl;
	for (auto& viaje : viajes) {
		delete viaje;
	}
	return 0;
}


