#include <stdio.h>
#include <stdlib.h>   // rand, srand
#include <time.h>     // time

#define SIZE 3 

// Verifica si matrix es un cuadrado mágico
int esCuadradoMagico(int matrix[][SIZE]) {
    int sumaObjetivo = 0;

    // Suma de referencia = primera fila
    for (int j = 0; j < SIZE; j++) sumaObjetivo += matrix[0][j];

    // Verificar filas
    for (int i = 1; i < SIZE; i++) {
        int sumaFila = 0;
        for (int j = 0; j < SIZE; j++) sumaFila += matrix[i][j];
        if (sumaFila != sumaObjetivo) return 0;
    }

    // Verificar columnas
    for (int j = 0; j < SIZE; j++) {
        int sumaCol = 0;
        for (int i = 0; i < SIZE; i++) sumaCol += matrix[i][j];
        if (sumaCol != sumaObjetivo) return 0;
    }

    // Diagonal 1
    int sumaDiag1 = 0;
    for (int i = 0; i < SIZE; i++) sumaDiag1 += matrix[i][i];
    if (sumaDiag1 != sumaObjetivo) return 0;

    // Diagonal 2
    int sumaDiag2 = 0;
    for (int i = 0; i < SIZE; i++) sumaDiag2 += matrix[i][SIZE - 1 - i];
    if (sumaDiag2 != sumaObjetivo) return 0;

    return 1; 
}

// Imprime una matriz SIZE x SIZE
void imprimirMatriz(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Generar una matriz con rand
void llenarMatrizAleatoria(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = (rand() % 9) + 1; 
}

int main(void) {
    srand((unsigned)time(NULL)); 
    int matriz[SIZE][SIZE];

    llenarMatrizAleatoria(matriz);

    printf("Matriz aleatoria (%dx%d):\n", SIZE, SIZE);
    imprimirMatriz(matriz);

    if (esCuadradoMagico(matriz))
        printf("La matriz es cuadrado magico.\n");
    else
        printf("La matriz NO es cuadrado magico.\n");

    return 0;
}

