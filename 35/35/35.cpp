// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tSol {
	int suma, l, ini;
};
// función que resuelve el problema
tSol resolver(const vector<int>&v) { //coste O(n)
	tSol sol = { 0,0,0 };
	int lActual = 0;
	int sumaActual = 0;
	for (int i = 0;i < v.size();i++) {
		lActual++;
		sumaActual += v[i];
		if (sumaActual<=0) {
			sumaActual = 0;
			lActual = 0;
		}
		else {
			if (sumaActual > sol.suma) {
				sol.suma = sumaActual;
				sol.l = lActual;
				sol.ini = i - lActual + 1;
			}
			else if (sumaActual == sol.suma) {
				if (lActual < sol.l) {
					sol.suma = sumaActual;
					sol.l = lActual;
					sol.ini = i - lActual + 1;
				}
			}
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (! std::cin)
        return false;
	vector<int>v(n);
	for (int& i : v)cin >> i;

    tSol sol = resolver(v);
    
    // escribir sol
	cout << sol.suma << " " << sol.ini << " " << sol.l << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-35.1.in");
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