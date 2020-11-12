// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste: O(n)


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct tJugador {
	string nom;
	int c;
};

// función que resuelve el problema
tJugador resolver(const vector<tJugador> &v, int ini, int fin) {
    // caso base dos jugadores
	tJugador sol;
	if (ini + 2 == fin) {
		if (v[ini].c < v[fin-1].c) {
			sol.nom = v[fin - 1].nom;
			sol.c = v[fin - 1].c + (v[ini].c / 2);
		}
		else{
			sol.nom = v[ini].nom;
			sol.c = v[ini].c + (v[fin - 1].c / 2);
		}
		return sol;
	}
	else{
		int mitad = (ini + fin) / 2;
		tJugador ji,jd;
		ji = resolver(v, ini, mitad);
		jd = resolver(v, mitad, fin);
		if (ji.c < jd.c) {
			jd.c += (ji.c /2);
			return jd;
		}
		else{
			ji.c += (jd.c / 2);
			return ji;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;	
    if (! std::cin)
        return false;
	vector <tJugador> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].nom >> v[i].c;
	}

    tJugador sol = resolver(v,0,n);
    
	cout << sol.nom << " " << sol.c << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-10.1.in");
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