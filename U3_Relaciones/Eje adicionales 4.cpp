/*Una empresa de correos ofrece los siguientes tipos de envío: carta berreta y carta supermegaplus. El precio de
la carta berreta es de $55 (hasta 20 gramos), $90 (hasta 150 gramos) o $125 (más de 150 gramos). El precio
de la carta supermegaplus es de $650 (hasta 150 gramos) más un recargo de $165 si se excede de este peso.
La carta supermegaplus permite contratar el servicio opcional ”aviso de recibo” que tiene un costo adicional de
$195. a) Programe un struct Dirección que tenga como datos el nombre, dirección y código postal, y una
clase Carta que tenga como datos el peso de la pieza, la dirección del remitente y la del destinatario. Agregue
constructores y métodos que considere necesarios. b) Utilizando polimorfismo, programe las clases CartaBerreta
y CartaSuperMegaPlus, con un método calcularPrecio() que devuelva el precio del envío. c) Programe una
función libre calcularPrecioTotal(...) que reciba como parámetro un vector de cartas y devuelva el importe total
correspodiente a las mismas. Si el precio total es mayor a $5000 se aplicará una bonificación del 10%.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Direccion {
	string nombre;
	string direccion;
	string cod_postal;
};

class Carta {
protected:
	float m_peso_pieza;
	Direccion m_remitente, m_destinatario;
public:
	Carta(float peso_pieza, Direccion remitente, Direccion destinatario) : m_peso_pieza(peso_pieza), m_remitente(remitente), m_destinatario(destinatario) {}
	float VerGramos() {return m_peso_pieza;}
	virtual float CalcularPrecio() = 0;
	virtual ~Carta() {};
};

class CartaBerreta : public Carta {
public:
	CartaBerreta(float p, Direccion r, Direccion d) : Carta(p,r,d) {}
	float CalcularPrecio() override {
		if (m_peso_pieza <= 20) {return 55;}
		if (m_peso_pieza > 20 and m_peso_pieza <= 150 ) {return 90;}
		return 125;
	}
};

class CartaSuperMegaPlus : public Carta {
	bool m_aviso_recibo;
public:
	CartaSuperMegaPlus(float p, Direccion r, Direccion d, bool aviso_recibo) : Carta(p,r,d), m_aviso_recibo(aviso_recibo) {}
	float CalcularPrecio() override {
		float precio = (m_peso_pieza <= 150) ? 650.0 : 650.0 + 165.0;
		if (m_aviso_recibo) {precio += 195.0;}
		return precio;
	}
};

float CalcularPrecioTotal (vector<Carta*>cartas){
	float total = 0;
	for(size_t i=0;i<cartas.size();i++) { 
		total += cartas[i]->CalcularPrecio();
	}
	if (total > 5000) {
		total *= 0.9;
	}
	return total;
}

int main() {
	Direccion remitente {"Juan Perez", "Calle Falsa 123", "1000"};
	Direccion destinatario {"Maria Lopez", "Av. Siempre Viva 742", "2000"};
	Carta* carta1 = new CartaBerreta(50, remitente, destinatario); // Peso: 50g
	Carta* carta2 = new CartaSuperMegaPlus(200, remitente, destinatario, true); // Peso: 200g, aviso de recibo
	Carta* carta3 = new CartaBerreta(10, remitente, destinatario); // Peso: 10g
	Carta* carta4 = new CartaSuperMegaPlus(100, remitente, destinatario, false); // Peso: 100g, sin aviso de recibo
	vector<Carta*> cartas = { carta1, carta2, carta3, carta4 };
	float precioTotal = CalcularPrecioTotal(cartas);
	cout << "El precio total de los envíos es: $" << precioTotal << endl;
	for (auto carta : cartas) {
		delete carta;
	}
	return 0;
}

