// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
struct abrigo {
	int lluvia, usos;
};
bool esValida(const vector<int>& p, const vector<abrigo>& a, vector<int>& sol, int k, abrigo& masUsado) {
	if (k == 0) return p[k] <= a[sol[k]].lluvia;
	return sol[k] != sol[k - 1] && p[k] <= a[sol[k]].lluvia && masUsado.usos <= 2 + (k / 3);
}

void resolver(const vector<int> & p, vector<abrigo>& a, vector<int>& sol,int k, int & exito,abrigo & masUsado) {
	for (int i = 0;i < a.size();i++) {
		sol[k] = i;
		a[i].usos++;
		if (masUsado.usos < a[i].usos) masUsado = a[i];
		if (esValida(p, a, sol, k, masUsado)) {
			if (k == sol.size() - 1) {
				if (sol[0] != sol[k]) {exito++;}
			}
			else resolver(p, a, sol, k + 1, exito, masUsado);
		}	
		a[i].usos--;
		masUsado.usos--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int dias, abrigos;
	cin >> dias;
    if (dias==0)
        return false;
	cin >> abrigos;
	vector<int> p(dias);
	vector<abrigo> a(abrigos, {0,0});
	vector<int> sol(dias);
	for (int& i : p) cin >> i;
	for (abrigo& i : a) cin >> i.lluvia;
	int exito = 0;
	abrigo masUsado = { 0,0 };
	resolver(p, a, sol, 0, exito, masUsado);
	if (exito == 0) cout << "Lo puedes comprar";
	else cout << exito;
	cout << "\n";
    // escribir sol
    
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
