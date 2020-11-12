// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(int metros, const vector<int> & valla ) {
    int posMejor = 0;
    int mActual = 0;
    int mMejor = 0;
    for(int i=0;i<metros;i++)  if (valla[i] == 0) mActual++;
    mMejor=mActual;
    for (int i = metros;i < valla.size();i++) {
        if (valla[i] == 0) mActual++;
        if (valla[i - metros] == 0) mActual--;
        if (mActual > 0 && mActual >= mMejor) {
            mMejor = mActual;
            posMejor = i - metros +1;
        }
    }
    if (mMejor == 0)return -1;
    return posMejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, metros;
    cin >> n;
    if (n==0)
        return false;
    cin >> metros;
    vector<int> valla(n);
    for (int& i : valla)cin >> i;
    int sol = resolver(metros, valla);
    if (sol == -1) cout << "No hace falta\n";
    else cout << sol << "\n";
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-42.1.in");
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
