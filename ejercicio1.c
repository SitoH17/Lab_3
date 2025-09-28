#include <stdio.h>

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n--;
    }
    return i;
}

int main(void) {
    int n;
    printf("Digite un número entero no negativo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: el factorial no está definido para números negativos.\n");
        return 1;
    }

    int resultado = factorial(n);
    printf("%d! = %d\n", n, resultado);

    return 0;
}
