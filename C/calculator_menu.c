#include <stdio.h>

/*
    Calculator Menu (C)
    -------------------
    Calculadora simples com menu interativo.

    Funcionalidades:
    - Soma
    - Subtração
    - Multiplicação
    - Divisão (com validação para não dividir por zero)
*/

int main() {
    int op;
    float v1, v2, res;

    do {
        // ---- MENU ----
        printf("\n========================\n");
        printf("===   CALCULADORA     ===\n");
        printf("========================\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("0 - Sair\n");
        printf("========================\n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);

        switch (op) {

            case 1:
                printf("\n--- SOMA ---\n");
                printf("Insira o valor 1: ");
                scanf("%f", &v1);
                printf("Insira o valor 2: ");
                scanf("%f", &v2);

                res = v1 + v2;
                printf("Resultado: %.2f\n", res);
                break;

            case 2:
                printf("\n--- SUBTRACAO ---\n");
                printf("Insira o valor 1: ");
                scanf("%f", &v1);
                printf("Insira o valor 2: ");
                scanf("%f", &v2);

                res = v1 - v2;
                printf("Resultado: %.2f\n", res);
                break;

            case 3:
                printf("\n--- MULTIPLICACAO ---\n");
                printf("Insira o valor 1: ");
                scanf("%f", &v1);
                printf("Insira o valor 2: ");
                scanf("%f", &v2);

                res = v1 * v2;
                printf("Resultado: %.2f\n", res);
                break;

            case 4:
                printf("\n--- DIVISAO ---\n");
                printf("Insira o valor 1: ");
                scanf("%f", &v1);

                // validação: v2 não pode ser 0
                do {
                    printf("Insira o valor 2 (diferente de 0): ");
                    scanf("%f", &v2);

                    if (v2 == 0) {
                        printf("Erro: nao e possivel dividir por zero. Tente novamente.\n");
                    }

                } while (v2 == 0);

                res = v1 / v2;
                printf("Resultado: %.2f\n", res);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (op != 0);

    return 0;
}
