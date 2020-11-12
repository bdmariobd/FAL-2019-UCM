// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

typedef vector<vector<int>> tMatriz;

int sumaC(const vector<vector<int>>& datos, int fila, int columna, int cuadrante) {
    int suma = 0;
    for (int i = fila;i < fila + cuadrante;i++)
        suma += datos[i][columna];
    return suma;
}
int sumaF(const vector<vector<int>>& datos, int fila, int cuadrante) {
    int suma = 0;
    for (int i = 0;i < cuadrante;i++)
        suma += datos[fila][i];
    return suma;
}
// función que resuelve el problema
int resolver(const vector<vector<int>>& datos, int c, int n) {
    int sumaActual = 0, sumaMax=-1,sumaIni;
    for (int i = 0;i < c;i++)
        for (int j = 0;j < c;j++)
            sumaActual += datos[i][j];
    sumaMax = sumaActual;
    sumaIni = sumaActual;
    for (int i = c;i < n;i++) {
        sumaActual -= sumaC(datos, 0, i-c, c);
        sumaActual += sumaC(datos, 0, i, c);
        if (sumaActual > sumaMax) sumaMax = sumaActual;
    }
    for (int f = c;f< n;f++) {
        sumaActual = sumaIni;
        sumaActual -= sumaF(datos, f - c, c);
        sumaActual += sumaF(datos, f, c);
        if (sumaActual > sumaMax) sumaMax = sumaActual;
        sumaIni = sumaActual;
        for (int i = c;i < n;i++) {
            sumaActual -= sumaC(datos, f, i - c, c);
            sumaActual += sumaC(datos, f, i, c);
            if (sumaActual > sumaMax) sumaMax = sumaActual;
        }

    }
    return sumaMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, c;
    cin >> n;
    if (! std::cin)
        return false;
    cin >> c;
    vector<vector<int>> datos(n, vector<int>(n));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> datos[i][j];

    int sol = resolver(datos,c,n);
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-41.1.in");
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