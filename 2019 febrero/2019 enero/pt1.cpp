
#include <iostream>
#include<vector>
using namespace std;

/*1. Se desea desarrollar un algoritmo iterativo que, dado un entero positivo K y un vector
bool a[N], determine el tamaño del tramo más corto de a que contiene exactamente K valores
a true.En caso de que dicho tramo no exista, el algoritmo deberá devolver N + 1.
 0 0 1 0 0 1 0 1 (2)           sol=3*/

typedef struct {
	bool ok;
	int suma, digitos;
}tsol2;


/*Se dice que un entero positivo es “sumdivisible” si la suma de sus dígitos es divisible
por el número de dígitos y al quitar el último, el resultado es también “sumdivisible”.
*/
tsol2 segundo(long long n) {
	if (n == 0) return {true,0,1};
	else {
		tsol2 sol = segundo(n / 10);
		sol.suma += n % 10;
		if (sol.ok == true && sol.suma % sol.digitos == 0)
			return {true,sol.suma, sol.digitos+1};

		return { false,0,0 };
	}
}

int tercero(long long n, int fase, const int& k) {
	int solu = 0;
	n = n * 10;
	for (int i = 0;i < 10;i++) {
		if (segundo(n).ok == true) {
			if (fase + 1 == k)  solu++;
			else solu += tercero(n, fase + 1, k);
		}
		n++;
	}
	return solu;
}
bool procesa_caso1() {
	long long n;
	cout << "Tamanho: ";
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		//cout << num_alternados((t_num)n) << endl;
		cout << "Datos: ";
		vector<bool> datos(n,false);
		int aux;
		for (int i = 0;i < n;i++) {
			cin >> aux;
			if (aux == 1) datos[i] = true;
		}
		int k;
		cout << "La k: ";
		cin >> k;
		cout <<"La sol: "<<primero(datos, k) << "\n";
		return true;
	}

}
bool procesa_caso2() {
	long long n;
	cout << "Numero: ";
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << "La sol: " << segundo(n).ok << "\n";
		return true;
	}

}

bool procesa_caso3() {
	long long d;
	cout << "Numero: ";
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		int k;
		cin >> k;
		cout << "La sol: " << tercero(d, 1, k) << "\n";
		return true;
	}

}
void main1() {
	//while (procesa_caso1());
	//while (procesa_caso2());
	while (procesa_caso3());
}