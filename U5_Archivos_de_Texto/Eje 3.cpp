/*Un conjunto de archivos de texto contiene informaci�n guardada en el formato que se muestra en el recuadro, donde
cada l�nea contiene el nombre de un campo y su respectivo valor separados por el signo igual (=). Las l�neas que
comienzan con el car�cter numeral (#) deben ser ignoradas.
#ejemplo de archivo de configuraci�n
materia=Programacion Orientada a Objetos
carrera=Ingenier�a en Inform�tica
facultad=Facultad de Ingenier�a y Ciencias H�dricas
universidad=Universidad Nacional del Litoral
#esta linea hay que ignorarla, igual que las 3 �ltimas
nro_unidad=5
nombre_unidad=Flujos de entrada/salida
otro_campo=otro_valor
otro_campo_mas=otro_valor_mas
#campo_que_no_se_lee_1=basura
#campo_que_no_se_lee_2=basura
#campo_que_no_se_lee_3=basura
Escriba una clase llamada ConfigFile que permita interpretar el contenido de estos archivos. La clase debe
poseer:
� un constructor que reciba el nombre del archivo y cargue sus datos en un vector de structs (cada elemento es
struct con dos strings: campo y valor).
� un m�todo para consultar el valor asociado a un campo
� un m�todo para modificar el valor asociado a un campo
� un m�todo para guardar el archivo con los datos actualizados
Nota: es aceptable que al guardar el archivo luego de hacer cambios se pierdan los comentarios originales*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct elementos {
	string campo;
	string valor;
};

class ConfigFile {
	string m_nombre_archi;
	vector<elementos>datos;
public:
	ConfigFile(string n_a) : m_nombre_archi(n_a) {
		ifstream archi(m_nombre_archi);
		string aux;
		elementos e;
		while (getline(archi, aux)) {
			if (aux.empty() || aux[0] == '#') continue; // Ignora comentarios y l�neas vac�as
			size_t l = aux.find('=');
			if (l != string::npos) { // Si se encuentra un '=' en la l�nea
				elementos e;
				e.campo = aux.substr(0, l); // Campo antes del '='
				e.valor = aux.substr(l + 1); // Valor despu�s del '='
				datos.push_back(e);
			}
		}
		archi.close();
	}
	string ConsultarValor(string campo) {
		for(size_t i=0;i<datos.size();i++) { 
			if(campo == datos[i].campo) {
				return datos[i].valor;
			}
		}
		return "";
	}
	void ModificarValor(string campo, string valor) {
		for(size_t i=0;i<datos.size();i++) { 
			if(campo == datos[i].campo) {
				datos[i].valor = valor;
				return;
			}
		}
	}
	void GuardarArchivo() {
		ofstream archi1(m_nombre_archi,ios::trunc);
		for(size_t i=0;i<datos.size();i++) { 
			archi1 << datos[i].campo << "=" << datos[i].valor << endl;
		}
	}
};

int main() {
	ConfigFile cf("campo_valor.txt");
	cf.GuardarArchivo();
	return 0;
}

