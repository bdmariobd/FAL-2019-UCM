//Nombre: Mario Blanco
//Usuario Juez: E10
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <cstdlib>
using namespace std;

bool esValida(vector<int>& sol, vector<int>& usoLuces, int k, int consumoMax, int consumoActual) {
	if(k>=2) if (sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) return false;
	if (consumoMax < consumoActual)return false;
	if(usoLuces[sol[k]] - 1 > (k+1) - usoLuces[sol[k]]) return false;
	return true;
}
void resolver(const vector<int> & consumoLuces,  vector<int>& sol,  vector<int>& usoLuces,int k,int & cont, int consumoMax, int & consumoActual) {
	for (int i = 0;i < consumoLuces.size();i++) {
		sol[k] = i;
		usoLuces[i]++;
		consumoActual += consumoLuces[i];
		if (esValida(sol,usoLuces,k,consumoMax,consumoActual)) {
			if (k == sol.size() - 1) cont++;
			else resolver(consumoLuces, sol, usoLuces, k + 1, cont, consumoMax, consumoActual);
		}
		usoLuces[i]--;
		consumoActual -= consumoLuces[i];
	}
}


bool resuelveCaso() {
	int longitud, numColores, consumoMax;
	std::cin >> longitud;
	if (longitud == 0) return false;
	std::cin >> numColores >> consumoMax;
	std::vector<int> consumoLuces(numColores);
	for (int& i : consumoLuces) std::cin >> i;
	vector<int> sol(longitud);
	vector<int>usoLuces(numColores, 0);
	int cont = 0, consumoActual=0;
	resolver(consumoLuces, sol, usoLuces, 0, cont, consumoMax, consumoActual);
	cout << cont << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-24.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
