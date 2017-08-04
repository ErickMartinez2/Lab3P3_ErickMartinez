#include <iostream>
using namespace std;

char** CrearMatriz1_j1();
char** CrearMatriz2_j1();
char** CrearMatriz1_j2();
char** CrearMatriz2_j2();
void imprimirMatriz(char**, int, int);

int main() {
	cout << "-> BATTLESHOTS" << endl;
	char** matriz1_j1 = CrearMatriz1_j1();
	char** matriz2_j1 = CrearMatriz2_j1();
	char** matriz1_j2 = CrearMatriz1_j2();
	char** matriz2_j2 = CrearMatriz2_j2();
	imprimirMatriz(matriz1_j1, 0, 0);
	return 0;
}

void imprimirMatriz(char** matriz, int fila, int columna) {
	if (fila != 8) {
		cout << "{" << matriz[fila][columna] << "}";
		columna++;
		if (columna == 8) {
			fila++;
			columna = 0;
			cout <<  endl;
		}
		return imprimirMatriz(matriz, fila, columna);
	}
}

char** CrearMatriz1_j1() {
	char** matriz = new char*[8];
	for (int i = 0; i < 8; i++) {
		matriz[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i == 1) && (j > 0 && j < 4)) {
				matriz[i][j] = '*';
			} else {
				if ((i == 2) && (j == 7)) {
					matriz[i][j] = '*';
				} else {
					if ((i == 3) && (j == 4 || j == 7)) {
						matriz[i][j] = '*';
					} else {
						if ((i == 4) && (j == 4 || j == 7)) {
							matriz[i][j] = '*';
						} else {
							if ((i == 5) && (j == 4)) {
								matriz[i][j] = '*';
							} else {
								if ((i == 7) && (j > 0 && j < 4)) {
									matriz[i][j] = '*';
								}else{
									matriz[i][j] = ' ';
								}
							}
						}
					}
				}
			}
		}
	}
	return matriz;
}

char** CrearMatriz2_j1() {
	char** matriz = new char*[8];
	for (int i = 0; i < 8; i++) {
		matriz[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			matriz[i][j] = ' ';
		}
	}
	return matriz;
}

char** CrearMatriz1_j2() {
	char** matriz = new char*[8];
	for (int i = 0; i < 8; i++) {
		matriz[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i == 0) && (j > 0 && j < 4)) {
				matriz[i][j] = '*';
			} else {
				if ((i == 3) && (j > 4 && j <= 7)) {
					matriz[i][j] = '*';
				} else {
					if ((i == 4) && (j == 4)) {
						matriz[i][j] = '*';
					} else {
						if ((i == 5) && (j == 1 || j == 4)) {
							matriz[i][j] = '*';
						} else {
							if ((i == 6) && (j == 1 || j == 4)) {
								matriz[i][j] = '*';
							} else {
								if ((i == 7) && (j == 1)) {
									matriz[i][j] = '*';
								}else{
									matriz[i][j] = ' ';
								}
							}
						}
					}
				}
			}
		}
	}
	return matriz;

}

char** CrearMatriz2_j2() {
	char** matriz = new char*[8];
	for (int i = 0; i < 8; i++) {
		matriz[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			matriz[i][j] = ' ';
		}
	}
	return matriz;
}
