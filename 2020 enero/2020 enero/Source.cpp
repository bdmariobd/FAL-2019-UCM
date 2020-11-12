#include <iostream>
#include<vector>
using namespace std;

/*  PISTALARGA
	ESPECIFICACION
	P: N>=0

	Q: sol = 



	INVARIANTE
	para todo k menor que i son todos positivos AND para todo k mayor que j todos son negativos


	COSTE O(N)(caso peor de todos positivos o todos negativos)

*/
bool entretenido(long long int n) {
	while (n > 10) {
		if (n % 10 == (n / 10) % 10) return false;
		n /= 10;
	}
	return true;
}
bool procesa_caso1() {
	long long int n;
	cin >> n;
	
	//llamar a la solucion
	if(entretenido(n)) cout<<"SI" << endl;
	else cout << "NO" << endl;

	return true;
}
void entretenidos(long long int & n, int & sol) {
	if (n < 11) sol += n;
	else {
		bool ok = false;
		long long int aux = n;
		if (entretenido(n)) ok = true;
		aux--;
		if (ok) sol++;
		entretenidos(aux, sol);
	}
}
bool procesa_caso2() {
	long long int n;
	cin >> n;

	//llamar a la solucion
	bool ok = false;
	int sol = 0;
	entretenidos(n, sol);
	cout << sol << endl;
	return true;
}

void backtrack(long long int& number, int n,int k, int etapa, int& sol, int sumActual) {
	for (int i = 0;i < 10;i++) {
		if (number % 10 != i) {
			sumActual += i;
			if (sumActual <= k) {
				number = number * 10 + i;
				if (etapa + 1 == n) sol++;
				else backtrack(number, n, k, etapa + 1, sol, sumActual);
							   
				number = number / 10;
			}
			sumActual -= i;
		}
	}

}
bool procesa_caso3() {
	int n, d, k;
	cin >> n>>d>>k;
	long long int number = d;
	int sol = 0;
	backtrack(number, n, k, 1, sol, d);
	cout << sol << endl;

	return true;
}







int main() {
	//while (procesa_caso1());
	//while (procesa_caso2());
	while (procesa_caso3());
}