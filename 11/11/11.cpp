// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

struct tSol {
	int partidos;
	bool sePresento;
};
// función que resuelve el problema
tSol resolver(const vector<string>& v, int ini, int fin, const int & rondaLimite, int& rondaActual) {
	tSol sol;
	if(fin-2==ini){
		rondaActual = 1;
		if (v[ini] != "NP" && v[ini + 1] == "NP" || v[ini + 1] != "NP" && v[ini] == "NP") {//solo se presenta 1
			sol.sePresento = true;
			sol.partidos = 0;
		}
		else if (v[ini] != "NP" && v[ini + 1] != "NP") { //se presentan los 2
			sol.sePresento = true;
			sol.partidos = 1;
		}
		else {//no se presenta nadie
			sol.sePresento = false;
			sol.partidos = 0;
		}
		return sol;
	}
	else {
		int mitad = (ini + fin) / 2;
		tSol solI = resolver(v, ini, mitad, rondaLimite, rondaActual);
		tSol solD = resolver(v,mitad, fin, rondaLimite, rondaActual);
		if ((rondaLimite > rondaActual) && solI.sePresento&& solD.sePresento) {
			rondaActual++;
			sol.sePresento = true; sol.partidos = solD.partidos + solI.partidos + 1;
		}

		// Si solo se presentara uno de los dos jugadores (Ronda siguiente): 
		else if (solI.sePresento || solD.sePresento) {
			rondaActual++;
			sol.sePresento = true;
			sol.partidos = (solI.partidos + solD.partidos);
		}
		// Si se no se presentara ninguno de los dos jugadores (Ronda siguiente):
		else {
			rondaActual++;
			sol.sePresento = false;
			sol.partidos = (solI.partidos + solD.partidos);
		}
		return sol;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam, ronda;
	cin >> tam;
    if (! std::cin)
        return false;
	cin >> ronda;
	vector<string> v(tam);
	for (int i = 0;i < tam;i++) {
		cin >> v[i];
	}
	int rondaActual;
    tSol sol = resolver(v,0,tam,ronda,rondaActual);
    
    // escribir sol
	cout << sol.partidos << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-11.1.in");
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