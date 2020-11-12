// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
int resolver(const vector<int> & v, int ini, int fin) {
	if (ini + 1 == fin) return v[ini]; //caso base (1 elemento)
	else if (fin - ini == 2) { //caso base(2 elementos)
		if (v[ini] < v[fin - 1]) return v[ini];
		else return v[fin - 1];
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] < v[mitad - 1]) {
			if (v[mitad] < v[mitad + 1]) {
				return v[mitad];
			}
			else {
				return resolver(v, mitad + 1, fin);
			}
		}
		else {
			return resolver(v, ini, mitad);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (! std::cin) return false;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    int sol = resolver(v,0,n);
    
    // escribir sol
	cout << sol << endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
	
     std::ifstream in("sample-05.1.in");
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