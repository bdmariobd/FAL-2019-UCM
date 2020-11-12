// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tSol {
	int racha, veces_racha, fin_ultima_racha;
};

// función que resuelve el problema
tSol resolver(const vector<int>& v) {//coste->O(N)
	tSol sol = { 0,0,0 };
	int racha = 0;
	for (int i = 0;i < v.size();i++) {
		if (v[i] > 0) {
			racha++;
		}
		else {
			if (racha > 0) {
				if (racha > sol.racha) {
					sol.racha = racha;
					sol.veces_racha = 1;
					sol.fin_ultima_racha = i;
				}
				else if (racha == sol.racha) {
					sol.veces_racha++;
					sol.fin_ultima_racha = i;
				}
				racha = 0;
			}
		}
	}
	if (racha > 0) {//en caso de que acabe el recorrido del vector y seguia la racha
		if (racha > sol.racha) {
			sol.racha = racha;
			sol.veces_racha = 1;
			sol.fin_ultima_racha = v.size();
		}
		else if (racha == sol.racha) {
			sol.veces_racha++;
			sol.fin_ultima_racha = v.size() ;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int partidos;
	cin >> partidos;
    if (! std::cin)
        return false;
	vector<int>v(partidos);
	for (int& i : v)cin >> i;

    tSol sol = resolver(v);
    
    // escribir sol
	cout << sol.racha << " " << sol.veces_racha << " " << v.size() -sol.fin_ultima_racha<<"\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-34.1.in");
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