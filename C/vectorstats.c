#include <stdio.h>

#define TAM_MIN 1
#define TAM_MAX 1000

// ---------- Utilitários ----------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int lerInt(const char *msg, int min, int max) {
    int v;
    int ok;
    do {
        printf("%s", msg);
        ok = scanf("%d", &v);
        if (ok != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();
        if (v < min || v > max) {
            printf("Valor fora do intervalo (%d a %d). Tente novamente.\n", min, max);
        }
    } while (ok != 1 || v < min || v > max);
    return v;
}

float lerFloat(const char *msg) {
    float v;
    int ok;
    do {
        printf("%s", msg);
        ok = scanf("%f", &v);
        if (ok != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            limparBuffer();
        } else {
            limparBuffer();
        }
    } while (ok != 1);
    return v;
}

// ---------- Funcionalidades ----------
void lerValores(float v[], int n) {
    printf("\nIntroduza %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        char msg[64];
        snprintf(msg, sizeof(msg), "vetor[%d] = ", i);
        v[i] = lerFloat(msg);
    }
}

void mostrarValores(const float v[], int n) {
    printf("\nValores inseridos:\n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %.2f\n", i, v[i]);
    }
}

float calcularSoma(const float v[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) soma += v[i];
    return soma;
}

float calcularMedia(const float v[], int n) {
    // n sempre >= 1 por validação
    return calcularSoma(v, n) / n;
}

float calcularMaximo(const float v[], int n) {
    float max = v[0];
    for (int i = 1; i < n; i++) if (v[i] > max) max = v[i];
    return max;
}

float calcularMinimo(const float v[], int n) {
    float min = v[0];
    for (int i = 1; i < n; i++) if (v[i] < min) min = v[i];
    return min;
}

void alterarValor(float v[], int n) {
    int idx = lerInt("\nQual o índice a alterar: ", 0, n - 1);
    printf("Valor atual: %.2f\n", v[idx]);
    v[idx] = lerFloat("Novo valor: ");
    printf("Valor atualizado com sucesso.\n");
}

// ---------- Menus ----------
int menu() {
    printf("\n»»»»» MENU «««««\n");
    printf("1 - Inserir valores\n");
    printf("2 - Mostrar valores\n");
    printf("3 - Calcular\n");
    printf("4 - Alterar valor\n");
    printf("5 - Reinserir valores (reset)\n");
    printf("0 - Sair\n");
    return lerInt("Escolha a opção: ", 0, 5);
}

int submenu() {
    printf("\n»»» SUBMENU CALCULAR «««\n");
    printf("1 - Soma\n");
    printf("2 - Média\n");
    printf("3 - Mínimo\n");
    printf("4 - Máximo\n");
    printf("5 - Estatísticas completas\n");
    printf("0 - Voltar\n");
    return lerInt("Escolha a opção: ", 0, 5);
}

void mostrarEstatisticas(const float v[], int n) {
    float soma = calcularSoma(v, n);
    float media = calcularMedia(v, n);
    float minimo = calcularMinimo(v, n);
    float maximo = calcularMaximo(v, n);

    printf("\nEstatísticas do vetor\n");
    printf("Soma:   %.2f\n", soma);
    printf("Média:  %.2f\n", media);
    printf("Mínimo: %.2f\n", minimo);
    printf("Máximo: %.2f\n", maximo);
}

// ---------- Main ----------
int main() {
    int tam = lerInt("Qual o tamanho do vetor (1 a 1000): ", TAM_MIN, TAM_MAX);

    // VLA (vetor com tamanho variável). Funciona em muitos compiladores C99+
    float vetor[tam];

    int op, subop;
    int inserido = 0;

    printf("\nVectorStats — Análise de Vetores em C\n");

    do {
        op = menu();

        switch (op) {
            case 1:
                lerValores(vetor, tam);
                inserido = 1;
                break;

            case 2:
                if (inserido) mostrarValores(vetor, tam);
                else printf("\nPrimeiro insira os valores (opção 1).\n");
                break;

            case 3:
                if (!inserido) {
                    printf("\nPrimeiro insira os valores (opção 1).\n");
                    break;
                }
                do {
                    subop = submenu();
                    switch (subop) {
                        case 1:
                            printf("Resultado (Soma): %.2f\n", calcularSoma(vetor, tam));
                            break;
                        case 2:
                            printf("Resultado (Média): %.2f\n", calcularMedia(vetor, tam));
                            break;
                        case 3:
                            printf("Resultado (Mínimo): %.2f\n", calcularMinimo(vetor, tam));
                            break;
                        case 4:
                            printf("Resultado (Máximo): %.2f\n", calcularMaximo(vetor, tam));
                            break;
                        case 5:
                            mostrarEstatisticas(vetor, tam);
                            break;
                        case 0:
                            printf("Voltando ao menu...\n");
                            break;
                    }
                } while (subop != 0);
                break;

            case 4:
                if (inserido) alterarValor(vetor, tam);
                else printf("\nPrimeiro insira os valores (opção 1).\n");
                break;

            case 5:
                // “reset” apenas marca como não inserido
                inserido = 0;
                printf("\nReset feito. Insira os valores novamente na opção 1.\n");
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;
        }

    } while (op != 0);

    return 0;
}
