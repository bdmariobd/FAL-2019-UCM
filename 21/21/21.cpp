// Nombre del alumno Mario Blanco
// Usuario del Juez E71 y E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct pieza {
	int usadas, total;
};

// función que resuelve el problema
bool esValida(vector<int>& sol, vector<pieza>& piezas, int k, int altura) {
	bool finalOk = true;

	if (k + 1 == altura) finalOk = piezas[1].usadas > piezas[0].usadas + piezas[2].usadas;

	return !(sol[k] == 2 && sol[k - 1] == 2)
		&& piezas[2].usadas <= piezas[0].usadas
		&& finalOk;
}
void escribe(vector<int>& sol) {
	for (int i = 0; i < sol.size(); i++) {
		if (sol[i] == 1) cout << "ROJO ";
		else if(sol[i]==0) cout << "AZUL ";
		else cout << "VERDE ";
	}
	cout << "\n";
}
void resolver(int altura, vector<pieza>& piezas, int k, vector<int>& sol, bool & torre) {
	for (int i = 0; i < 3; i++) {
		if (piezas[i].total > piezas[i].usadas) {
			sol[k] = i;
			piezas[i].usadas++;
			if (esValida(sol, piezas, k,altura)) {
				if (k + 1 == altura) {
					escribe(sol); torre = true;
				}
				else resolver(altura, piezas, k + 1, sol, torre);
			}
			piezas[i].usadas--; //backtracking
		}
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
	cin >> a >> r >> v;
	vector<int> sol(altura,-1); //rojo =1 , azul = 0,verde = 2
	vector<pieza> piezas(3);
	piezas[0] = { 0, a }; piezas[1] = { 1, r }; piezas[2] = { 0, v };
	sol[0] = 1; //base siempre es roja
	bool torre = false;
    resolver(altura,piezas,1,sol,torre);
	if (!torre) cout << "SIN SOLUCION\n";
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
