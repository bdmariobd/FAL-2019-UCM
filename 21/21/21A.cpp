

// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool esValida(vector<int>& sol, vector<int>& piezas, int k) {
	return !(sol[k] == 2 && sol[k - 1] == 2);	
}
void escribe(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i++) {
		if (sol[i] == 1) cout << "ROJO ";
		else if(sol[i]==0) cout << "AZUL ";
		else cout << "VERDE ";
	}
	cout << "\n";
}
void resolver(int altura, vector<int>& piezas, int k, vector<int>& sol) {
	for (int i = 0; i < 3; i++) {
		sol[k] = i;
		piezas[i]++;
		if (esValida(sol, piezas, k)) {
			if (k + 1 == altura) {
				escribe(sol);
			}
			else resolver(altura, piezas, k + 1, sol);
		}
		piezas[i]--; //backtracking
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	cin >> altura;
	
	
    if (altura==0)
        return false;
	
	vector<int> sol(altura,-1); //rojo =1 , azul = 0,verde = 2
	vector<int> piezas(3);
	piezas[0] = { 0 }; piezas[1] = { 1 }; piezas[2] = { 0 };
	sol[0] = 1; //base siempre es roja
	bool torre = false;
	if (altura == 1) escribe(sol);
    else resolver(altura,piezas,1,sol);
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
