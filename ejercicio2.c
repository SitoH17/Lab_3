#include <stdio.h>

#define SIZE 3

// Funcion para ver si es un cuadrado perfecto
int esCuadradoMagico(int matrix[][SIZE]) {
    int sumaObjetivo = 0;

    // Calcular la suma primera fila
    for (int j = 0; j < SIZE; j++) {
        sumaObjetivo += matrix[0][j];
    }

    // Todas las filas
    for (int i = 1; i < SIZE; i++) {
        int sumaFila = 0;
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matrix[i][j];
        }
        if (sumaFila != sumaObjetivo) {
            return 0;
        }
    }

    // Todas las columnas
    for (int j = 0; j < SIZE; j++) {
        int sumaCol = 0;
        for (int i = 0; i < SIZE; i++) {
            sumaCol += matrix[i][j];
        }
        if (sumaCol != sumaObjetivo) {
            return 0;
        }
    }

    // Diagonal 1
    int sumaDiag1 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumaDiag1 += matrix[i][i];
    }
    if (sumaDiag1 != sumaObjetivo) {
        return 0;
    }

    // Diagonal 2
    int sumaDiag2 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumaDiag2 += matrix[i][SIZE - 1 - i];
    }
    if (sumaDiag2 != sumaObjetivo) {
        return 0;
    }

    return 1;
}

int main() {
    int matriz[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    printf("Matriz:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");

