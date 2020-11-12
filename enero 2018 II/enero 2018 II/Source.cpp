#include <iostream>
#include<vector>
using namespace std;


int pistaLarga(const vector<int> & alturas) {
	int mayorTramos=0, actuales=0;
	for (int i = 1;i < alturas.size();i++) {
		if (alturas[i - 1] >= alturas[i]) {
			actuales++;
		}
		else {
			if (actuales > 0) {
				if (actuales + 1 > mayorTramos) mayorTramos = actuales + 1;
				actuales = 0;
			}
		}
	}
	if (actuales + 1 > mayorTramos) mayorTramos = actuales + 1;
	return mayorTramos;
}

/*  PISTALARGA
	ESPECIFICACION





	INVARIANTE



	COSTE O(N)

*/
bool procesa_caso1() {
	int n;
	cin >> n;
	vector<int> alturas(n);
	for (int& i : alturas)cin >> i;
	//llamar a la solucion
	if (n == 0) cout << "0\n";
	else cout << pistaLarga(alturas) << "\n";

	return true;
}

int masCerca(const vector<int>& v, int ini, int fin, int x) { //coste log(n)
	if (ini == fin - 1) return v[ini];
	else if (ini == fin-2) {
		if (abs(v[ini] - x) <= abs(v[ini + 1] - x)) return v[ini]; 
		return v[ini + 1];
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] == x) return x;
		if (abs(v[mitad] - x) <= abs(v[mitad + 1] - x)) return masCerca(v, ini, mitad+1, x);
		return masCerca(v, mitad, fin, x);
	}
}


bool procesa_caso2() {
	int x,n;
	cin >> x>>n;
	if (n == 0) return false;
	vector<int> v(n);
	for (int& i : v)cin >> i;
	//llamar a la solucion
	cout << masCerca(v,0,n,x) << "\n";

	return true;
}
void maxCalidad(const vector<int>& aMaq, const vector<int>& aCar, const vector<vector<int>>& calidades,
	int k, int actual, int & max, vector<bool> & marcasCar) {
	for (int i = 0;i < aCar.size();i++) {
		if (!marcasCar[i] && aMaq[k]<= aCar[i]) {
			marcasCar[i] = true;
			actual += calidades[k][i];
			if (k + 1 == aMaq.size()) {
				if (actual > max) max = actual;
			}
			else maxCalidad(aMaq, aCar, calidades, k + 1, actual, max, marcasCar);
			marcasCar[i] = false;
			actual -= calidades[k][i];
		}
	}
}
bool procesa_caso3() {
	int maq, car;
	cin >> maq >> car;
	if (maq == 0) return false;
	vector<int> aMaq(maq);
	vector<int> aCar(car);
	for (int& i : aMaq)cin >> i;
	for (int& i : aCar)cin >> i;
	vector<vector<int>> calidades(maq, vector<int>(car));
	for (int i = 0;i < maq;i++)
		for (int j = 0;j < car;j++)
			cin >> calidades[i][j];
	vector<bool> marcasCar(car, false);
	//llamar a la solucion
	int max = 0;
	maxCalidad(aMaq, aCar, calidades, 0, 0, max, marcasCar);
	cout << max << "\n";

	return true;
}
int main() {
	//while (procesa_caso1());
	//while (procesa_caso2());
	while (procesa_caso3());
}