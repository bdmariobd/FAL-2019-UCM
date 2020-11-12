//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Mario Blanco
// Usuario del juez de clase: E10 
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene
//vector sol->guarda el orden en el que se deben visitar las ciudades(partiendo de la 0)
//
//*******************************

template <class T>
using tMatriz = std::vector<std::vector<T>>;


// Aqui las funciones implementadas por el alumno
void resolver(const tMatriz<int> & billetes, vector<int>&sol, int k, int & minima, int actual,vector<bool>&marcas,int minimo) {
	for (int i = 1; i < sol.size(); i++) {
		if (!marcas[i]) { //si ya he ido a esa ciudad, no contemplo el caso
			sol[k] = i;
			actual += billetes[sol[k-1]][i]; //ciudad de origen, sol[k-1], destino [i]
			marcas[i] = true;
			if (k == sol.size() - 1) {
				if (actual + billetes[i][0] < minima) {
					actual += billetes[i][0];//suma el coste del viaje de vuelta a la ciudad 0 desde la final
					minima = actual;
				}
			}
			else {
				if(actual+minimo*(sol.size()-k)<minima)resolver(billetes, sol, k + 1, minima, actual, marcas,minimo);
			}
			actual -= billetes[sol[k - 1]][i];//desmarcar
			marcas[i] = false;//desmarcar
		}
		
	}
}



bool resuelveCaso() {
	int numCiudades;
	std::cin >> numCiudades;
	if (numCiudades == 0) return false;
	// Precio billetes entre ciudades
	tMatriz<int> billetes(numCiudades, std::vector<int>(numCiudades));
	for (int i = 0; i < numCiudades; ++i)
		for (int j = 0; j < numCiudades; ++j) {
			std::cin >> billetes[i][j];
		}

	// Preparacion de los datos para la llamada a la funcion que resuelve el problema
	vector<int> sol(numCiudades);
	vector<bool>marcas(numCiudades, false); //marco a las ciudades a las que he ido
	sol[0] = 0; //ciudad de origen es la primera
	// LLamada a la funcion que resuelve el problema
	int minima = 0;
	int j = 0;
	for (int i = numCiudades - 1; i >= 0; i--) { //diagonal inversa(hallar un minimo aproximado)
		minima += billetes[j][i];
		j++;
	}
	int minimo= billetes[0][0];
	for (int i = 0; i < numCiudades; ++i)
		for (int j = 0; j < numCiudades; ++j) {
			if (billetes[i][j] != 0 && billetes[i][j] < minimo) minimo = billetes[i][j];
		}
	resolver(billetes, sol, 1, minima, 0,marcas,minimo);
	// Escribir el resultado
	cout << minima << "\n";

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