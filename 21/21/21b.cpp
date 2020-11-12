// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

void escribe(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i++) {
		if (sol[i] == 1) cout << "ROJO ";
		else if(sol[i]==0) cout << "AZUL ";
		else cout << "VERDE ";
	}
	cout << "\n";
}
void resolver(int altura, int k, vector<int>& sol) {
	for (int i = 0; i < 3; i++) {
		sol[k] = i;
		if (k + 1 == altura) {
			escribe(sol); 
		}
		else resolver(altura, k + 1, sol);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura, r, a, v;
	cin >> altura;
	
	
    if (altura==0)
        return false;
	
	vector<int> sol(altura,-1); //rojo =1 , azul = 0,verde = 2
	sol[0] = 1; //base siempre es roja
	
    resolver(altura,0,sol);
	
	cout << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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
