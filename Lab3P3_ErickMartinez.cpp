#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

char** CrearMatriz1_j1();
char** CrearMatriz2_j1();
char** CrearMatriz1_j2();
char** CrearMatriz2_j2();
void imprimirMatriz(char**, int, int);
void liberarMatriz(char**);
string shot();

int main() {
	cout << "-> BATTLESHOTS" << endl;
	char** matriz1_j1 = CrearMatriz1_j1();
	char** matriz2_j1 = CrearMatriz2_j1();
	char** matriz1_j2 = CrearMatriz1_j2();
	char** matriz2_j2 = CrearMatriz2_j2();
	int ganador = 0, turno = 1, num_shots1 = 0, num_shots2 = 0;	
	do {
		cout << endl;
		if (turno == 1) {
			cout << "- Turno Jugador 1" << endl;
			imprimirMatriz(matriz2_j1, 0, 0);
			int coord_x, coord_y;
			cout << "Ingrese la coordenada en x: ";
			cin >> coord_x;
			cout << "Ingrese la coordenada en y: ";
			cin >> coord_y;
			cout << endl;
			if (matriz1_j2[coord_x][coord_y] == '*') {
				matriz2_j1[coord_x][coord_y] = 'X';
				imprimirMatriz(matriz2_j1, 0, 0);
				cout << "Disparo Acertado!!" << endl;
				cout << "Castigo Jugador 2: " << shot() << endl;
				num_shots1++;
			} else {
				matriz2_j1[coord_x][coord_y] = '-';
				imprimirMatriz(matriz2_j1, 0, 0);
				cout << "Disparo Fallido!!" << endl;
			}
			if (num_shots1 == 5) {
				cout << endl;
				cout << "Jugador 1 ha Ganado!!" << endl;
				ganador++;
			}
			turno = 2;
		} else {
			cout << "- Turno Jugador 2" << endl;
			imprimirMatriz(matriz2_j2, 0, 0);
			int coord_x, coord_y;
			cout << "Ingrese la coordenada en x: ";
			cin >> coord_x;
			cout << "Ingrese la coordenada en y: ";
			cin >> coord_y;
			cout << endl;
			if (matriz1_j1[coord_x][coord_y] == '*') {
				matriz2_j2[coord_x][coord_y] = 'X';
				imprimirMatriz(matriz2_j2, 0, 0);
				cout << "Disparo Acertado!!" << endl;
				cout << "Castigo Jugador 1: " << shot() << endl;
				num_shots2++;
			} else {
				matriz2_j2[coord_x][coord_y] = '-';
				imprimirMatriz(matriz2_j2, 0, 0);
				cout << "Disparo Fallido!!" << endl;
			}
			if (num_shots2 == 5) {
				cout << endl;
				cout << "Jugador 2 ha Ganado!!" << endl;
				ganador++;
			}
			turno = 1;
		}
	} while (ganador == 0);
	liberarMatriz(matriz1_j1);
	liberarMatriz(matriz2_j1);
	liberarMatriz(matriz1_j2);
	liberarMatriz(matriz2_j2);
	return 0;
}

string shot() {
	string shot = "";	
	srand (time(NULL));
	int num = rand() % 7 + 1;
	if (num == 1) {
		shot = "Cheap_Tequila";
	}else{
		if (num == 2) {
			shot = "Jell-O";
		}else{
			if (num == 3) {
				shot = "Kamikaze";
			}else{
				if (num == 4) {
					shot = "MindEraser";
				}else{
					if (num == 5) {
						shot = "Bombs";
					}else{
						if (num == 6) {
							shot = "FireBalls";
						}else{
							if (num == 7) {
								shot = "Whiskey";
							}
						}
					}
				}
			}
		}
	}
	return shot;
}

void liberarMatriz(char** matriz) {
	for (int i = 0; i < 8; i++) {
		delete[] matriz[i];
		matriz[i] = NULL;
	}
	delete[] matriz;
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
