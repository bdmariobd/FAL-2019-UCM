// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tDatos {
	int canciones, ida, vuelta;
};
// función que resuelve el problema
void resolver(tDatos datos, const vector<pair<int,int>>& sat, int & satMax, int satActual,int k, int tIda, int tVuelta) {
	satActual += sat[k].second;
	tIda += sat[k].first;
	if (tIda <= datos.ida) {
		if (k == datos.canciones - 1) {
			if (satActual > satMax&& tIda == datos.ida && tVuelta == datos.vuelta) satMax = satActual;
		}
		else resolver(datos, sat, satMax, satActual, k + 1, tIda, tVuelta);
	}
	tIda -= sat[k].first;
	tVuelta += sat[k].first;
	if (tVuelta <= datos.vuelta) {
		if (k == datos.canciones - 1) {
			if (satActual > satMax && tIda == datos.ida && tVuelta == datos.vuelta) satMax = satActual;
		}
		else resolver(datos, sat, satMax, satActual, k + 1, tIda, tVuelta);
	}
	tVuelta -= sat[k].first;
	satActual -= sat[k].second;
	//if (tIda <= datos.ida && tVuelta <= datos.vuelta) {
		if (k == datos.canciones - 1) {
			if (satActual > satMax&& tIda == datos.ida&& tVuelta == datos.vuelta) satMax = satActual;
		}
		else resolver(datos, sat, satMax, satActual, k + 1, tIda, tVuelta);
	//}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

	tDatos datos;
	cin >> datos.canciones;
    if (datos.canciones==0)
        return false;
	cin >> datos.ida >> datos.vuelta;
	vector<pair<int, int>>sat(datos.canciones);
	for (int i = 0;i < datos.canciones;i++) {
		cin >> sat[i].first>>sat[i].second;
	}
	int satMax = 0;
    resolver(datos,sat,satMax,0,0,0,0);
    
    // escribir sol
	if(satMax==0) cout << "Imposible" << "\n";
	else cout << satMax << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-28.1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
