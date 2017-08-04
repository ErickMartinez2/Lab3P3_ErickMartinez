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
	int ganador = 0, turno = 1;	
	do {
		if (turno == 1) {
			cout << "- Turno Jugador 1" << endl;
			int coord_x, coord_y;
			cout << "Ingrese la coordenada en x: ";
			cin >> coord_x;
			cout << "Ingrese la coordenada en y: ";
			cin >> coord_y;
			cout << endl;
			if (matriz2_j2[coord_x][coord_y] == '*') {
				matriz2_j1[coord_x][coord_y] == 'X';
				cout << "Disparo Acertado!!" << endl;
				cout << "Castigo Jugador 2: " << shot() << endl;
			} else {
				matriz2_j1[coord_x][coord_y] == '-';
				cout << "Disparo Fallido!!" << endl;
			}
			turno = 2;
		} else {
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
	switch (num) {
		case 1:
			shot = "Cheap_Tequila";
			break;
		case 2:
			shot = "Jell-O";
			break;
		case 3:
			shot = "Kamikaze";
			break;
		case 4:
			shot = "MindEraser";
			break;
		case 5:
			shot = "Bombs";
			break;
		case 6:
			shot = "FireBalls";
			break;
		case 7:
			shot = "Whiskey";
			break;
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
