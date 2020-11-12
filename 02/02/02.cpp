// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste: O(n) (por cada fila de la imagen)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
	bool cumple;
	int suma;
};


tSol resolver(const vector<int>& vfila, int ini, int fin) {
	tSol sol;
	sol.cumple = true;
	if (ini + 1 >= fin) return sol;
	else if (ini + 2 == fin) {
		if (vfila[ini] < vfila[ini + 1]) {
			sol.suma = vfila[ini] + vfila[ini + 1];
		}
		else sol.cumple = false;
		return sol;
	}
	else {
		int mitad = (ini + fin) / 2;
		tSol solI = resolver(vfila, ini, mitad);
		if (!solI.cumple) sol.cumple = false;
		else {
			tSol solD = resolver(vfila, mitad, fin);
			if ((solI.cumple && solD.cumple && solI.suma < solD.suma)) sol.suma = solI.suma + solD.suma;
			else sol.cumple = false;
		}
		return sol;
	}
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	cin >> n;
	if (!cin)
		return false;
	cin >> m;
	vector<vector<int>> matrix(n);
	//lectura de la matriz
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int aux;
			cin >> aux;
			matrix[i].push_back(aux);
		}
	}
	tSol sol;
	sol.cumple = true;
	for (int i = 0; sol.cumple && i < n; ++i) {
		sol = resolver(matrix[i], 0, m);
	}
	if (sol.cumple) cout << "Si\n";
	else cout << "No\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-02.1.in");
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


