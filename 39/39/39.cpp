// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tsol {
	int ini, l;
};
// función que resuelve el problema
tsol resolver(const vector<int>& datos) {
	int lActual=0,lMayor=0,iniMayor=0;
	for (int i = 1;i < datos.size();i++) {
		if (datos[i-1]+1 == datos[i]) { //consecutivos
			lActual++;
		}
		else {
			if (lActual+1 > lMayor) {
				lMayor = lActual+1;
				iniMayor = i - lActual-1;
			}
			lActual = 0;
		}
	}
	if (lActual+1 > lMayor) {
		lMayor = lActual+1;
		iniMayor = datos.size()-1 - lActual;
	}
	return{ iniMayor,lMayor };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
	if (n==0)
		return false;
	vector<int>datos(n);
	for (int& i : datos)cin >> i;

    tsol sol = resolver(datos);
    
    // escribir sol
	cout << sol.ini << " " << sol.l << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-39.1.in");
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
