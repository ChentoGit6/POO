/*Un banco tiene dos tipos de cuentas para los clientes; unas son cuentas de ahorro y las otras cuentas corrientes. Las
cuentas de ahorro tienen un interés compuesto y la posibilidad de reintegro, pero no admiten talonarios de cheques.
Las cuentas corrientes ofrecen talonarios de cheques, pero no tienen interés. Los titulares de una cuenta corriente
también deben mantener un saldo mínimo; si el saldo desciende por debajo de este nivel, se les cobra una comisión
por el servicio. Cree una clase Cuenta que almacene: el nombre del titular, el número de cuenta y el tipo de cuenta. A
partir de ésta, derive las clases CuentaCorriente y CuentaAhorro para adaptarlas a los requerimientos específicos.
Incluya las funciones miembro necesarias para realizar las siguientes tareas:
• Aceptar un ingreso de un titular y actualizar el saldo.
• Mostrar el saldo.
• Calcular y abonar los intereses.
• Permitir un reintegro y actualizar el saldo.
• Comprobar que el saldo no esté por debajo del mínimo, imponer la sanción si es necesario, y actualizar el
saldo.
*/

#include <iostream>
using namespace std;

class Cuenta {
protected:
	string m_titular;
	int m_nro_cuenta;
	string m_tipo_cuenta;
	float m_saldo;
public:
	Cuenta(string titular, int nro_cuenta, string tipo_cuenta, float saldo) : m_titular(titular), m_nro_cuenta(nro_cuenta), m_tipo_cuenta(tipo_cuenta), m_saldo(saldo) {}
	virtual void Depositar(float cantidad){
		m_saldo += cantidad;
		cout << "Deposito realizado. Saldo actual: " << m_saldo << endl;
	}
	virtual void Retirar(float cantidad) {
		if (cantidad > m_saldo) {
			cout << "Fondos insuficientes para el retiro.\n";
		} else {
			m_saldo -= cantidad;
			cout << "Retiro realizado. Saldo actual: " << m_saldo << endl;
		}
	}
	virtual void MostrarSaldo() const {
		cout << "Saldo actual: " << m_saldo << " (" << m_tipo_cuenta << ")" << endl;
	}
	virtual void CalcularIntereses() = 0;
	virtual ~Cuenta() {};
};

class CuentaAhorro : public Cuenta {
	float m_tasa_interes;
public:
	CuentaAhorro(string t, int nc, float s, float tasa_interes) : Cuenta(t,nc,"Cuenta Ahorro",s), m_tasa_interes(tasa_interes) {}
	void CalcularIntereses() override {
		float intereses = m_saldo * (m_tasa_interes / 100);
		m_saldo += intereses;
		cout << "Intereses abonados: " << intereses << ". Saldo actual: " << m_saldo << endl;
	}
};

class CuentaCorriente : public Cuenta {
	float m_saldo_minimo;
	float m_comision;
public:
	CuentaCorriente(string t, int nc, float s, float sm, float c) : Cuenta(t,nc,"Cuenta Corriente",s), m_saldo_minimo(sm), m_comision(c){}
	void CalcularIntereses() override {
		cout << "Las cuentas corrientes no generan interes.\n";
	}
	void Retirar(float cantidad) override {
		if (cantidad > m_saldo) {
			cout << "Fondos insuficientes para el retiro.\n";
		} else {
			m_saldo -= cantidad;
			cout << "Retiro realizado. Saldo actual: " << m_saldo << endl;
			if (m_saldo < m_saldo_minimo) {
				m_saldo -= m_comision;
				cout << "Saldo por debajo del minimo. Comision de " << m_comision << " aplicada. Saldo actual: " << m_saldo << endl;
			}
		}
	}
};

int main() {
	CuentaAhorro ahorro("Hola Chau", 12345, 1000, 5);
	ahorro.MostrarSaldo();
	ahorro.CalcularIntereses();
	ahorro.Retirar(200);
	ahorro.Depositar(500);
	cout << endl;
	CuentaCorriente corriente("Hello By", 67890, 500, 300, 50);
	corriente.MostrarSaldo();
	corriente.Retirar(250);
	corriente.Retirar(100);
	corriente.Depositar(200);
	
	return 0;
}

