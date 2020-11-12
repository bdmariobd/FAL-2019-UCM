//*****************
// IMPORTANTE
// Mario Blanco E10
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//*******************************
// Aqui especificación de la función que resuelve el problema.
// tieneVistas(v, i) ==> v[i].piso > alturaMayor ; alturaMayor = v[k].altura : max(i+1 <= k < v.size())
// [El edificio tiene vistas si el piso actual es mayor estricto que la altura mayor de los edificios acumulados -desde el
// sigueinte del actual hasta la costa-]
// P : { v.size() > 0 }
// 
// Q : { paraTodo k : 0 <= k < sol.size() cumple tieneVistas(sol, k) }
// Devuelve el vector solucion (con los ids)
//
// Aqui la justificación del coste de la función que resuelve el problema
// El coste es O(n) ya que hemos recorrido todo el vector para comparar la altura del piso que compramos es mayor que la 
// altura total del edificio siguiente
//
//*******************************

struct tDatos {
	std::string id;
	int altura;
	int piso;
};


// Aqui la función implementada por el alumno
vector<string> sol(vector<tDatos> const &v) {
	vector<string> ret;
	int alturaMayor = v[v.size()-1].altura;
	if (v[v.size() - 1].piso != -1)
		ret.push_back(v[v.size()-1].id);

	for (int i = v.size() - 2; i >= 0; --i) {
		if (v[i].piso > alturaMayor) ret.push_back(v[i].id);
		if (v[i].altura > alturaMayor) alturaMayor = v[i].altura;
	}
	return ret;
}



bool resuelveCaso() {
	int numEdificios;
	std::cin >> numEdificios;
	if (numEdificios == 0) return false;
	std::vector<tDatos> edificios(numEdificios);
	for (int i = 0; i < numEdificios; ++i) {
		std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
	}


	// LLamada a la funcion que resuelve el problema
	vector<string> solucion = sol(edificios);

	// Escribir el resultado
	if (solucion.size() == 0)
		cout << "Ninguno";
	else {
		cout << solucion.size() << '\n';
		for (int i = 0; i < solucion.size(); ++i)
			cout << solucion[i] << " ";
	}
	cout << '\n';

	return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
