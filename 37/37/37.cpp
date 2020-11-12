// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int>& datos, int l, int & masLarga, int & llanos) {
	vector<int>sol;
	int mayorEncontrado = datos[datos.size() - 1], lActual=0;
	for (int i = datos.size() - 2;i >= 0;--i) {
		if (datos[i]==datos[i+1]) {
			if (datos[i] >= mayorEncontrado) {
				lActual++;
				mayorEncontrado = datos[i];
			}
		}
		else {
			if (lActual +1>= l) {
				if (lActual +1 > masLarga) masLarga = lActual+1;
				llanos++;
				sol.push_back(i + lActual+1);
			}
			lActual = 0;
		}
	}
	if (lActual + 1 >= l) {
		if (lActual + 1 > masLarga) masLarga = lActual + 1;
		llanos++;
		sol.push_back(lActual);
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, l;
	cin >> n;
    if (! std::cin)
        return false;
	cin >> l;
	vector<int> datos(n);
	for (int& i : datos)cin >> i;
	int masLarga = 0, llanos = 0;
    vector<int> sol = resolver(datos,l,masLarga,llanos);
    
    // escribir sol
	cout << masLarga << " " << llanos << " ";
	for (int& i : sol) cout << i << " ";
	cout << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.in");
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