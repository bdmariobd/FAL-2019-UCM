// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste de la solucion: O(N)(solo se recorre una vez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
pair<int, int> resolver(vector <int>& v, int altura) {
	int actualL =0;
	pair<int, int> sol; //first = ini, second = cont
	sol.second = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > altura) {
			actualL++;
			if (actualL > sol.second) {
				sol.second = actualL;
				sol.first = i - actualL+1;
			}
		}
		else {
			actualL = 0;
		}
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n, altura;
	cin >> n>>altura;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
    
	pair<int, int> sol = resolver(v,altura);
    // escribir sol
	cout << sol.first << " " << sol.first+sol.second-1 << "\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}