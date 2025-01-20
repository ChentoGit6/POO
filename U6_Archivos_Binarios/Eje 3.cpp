/*Con un software de tratamiento de imagenes llamado WellDesign se han generado 78 archivos con los nombres
”design1.wds”, ”design2.wds”, … ”design78.wds”. El software fue creado para Windows XP. Estos archivos presentan
el problema que en el sistema operativo Windows 10 al tratar de abrirlos con WellDesign presentan un molesto
mensaje. Al consultar al soporte técnico de la empresa que desarrolló WellDesign nos mencionan que si se modifica
la cabecera de cada archivo se soluciona el problema. A partir del byte 178 se debe reemplazar ”mswxp” por ”msw10”,
y a partir del byte 239 reemplazar el valor entero 2003 por el valor 2016. Escriba un programa en C++ que realice
esas correcciones en los 78 archivos almacenados.*/

#include <iostream>
#include <fstream>
using namespace std;

void corregir_archivo (string nombre){
	ofstream archi(nombre,ios::in | ios::out | ios::binary);
	archi.seekp(178);
	archi.write("msw10",5);
	archi.seekp(239);
	int n = 2016;
	archi.write(reinterpret_cast<char*>(&n),sizeof(int));
	archi.close();
}

int main() {
	for(int i=1;i<2;i++) { // itero hasta 1 archivo para no hacer tan largo hasta 78
		string s = "design" + to_string(i) + ".wsd";
		corregir_archivo(s);
	}
	return 0;
}

