#include <iostream>
using namespace std;

int** CrearMatriz1_j1();
int** CrearMatriz2_j1();
int** CrearMatriz1_j2();
int** CrearMatriz2_j2();

int main() {
	cout << "-> BATTLESHOTS" << endl;
	int** matriz1_j1 = CrearMatriz1_j1();
	int** matriz2_j1 = CrearMatriz2_j1();
	int** matriz1_j2 = CrearMatriz1_j2();
	int** matriz2_j2 = CrearMatriz2_j2();
	return 0;
}
