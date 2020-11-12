// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(const vector<int> & v, const int & num, int ini, int fin) {
	if (ini + 1 == fin) {
		if (num + ini == v[ini]) return v[ini];
		else return -1;
	}
	else {
		int mitad = (ini + fin) / 2;
		int sol;
		sol = resolver(v, num, ini, mitad);
		if (sol != -1) return sol;
		else {
			sol = resolver(v, num, mitad, fin);
			if (sol != -1) return sol;
		}
		return -1;
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int tam, num;
	cin >> tam >> num;
	vector<int> v (tam);
	for (int i = 0;i < tam;i++) {
		cin >> v[i];
	}
    int sol = resolver(v,num,0,tam);
    // escribir sol
	if (sol == -1)cout << "No\n";
	else cout << sol<<"\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-08.1.in");
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