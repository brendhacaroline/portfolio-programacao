#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Number Guessing Game
    --------------------
    Jogo onde o utilizador tenta adivinhar um número gerado aleatoriamente.

    Funcionalidades:
    - Menu interativo
    - Escolha do limite do número
    - Definição do número de tentativas
    - Sistema de ajuda
*/

int main() {

    int numeroSecreto;
    int palpite;
    int tentativas = 5;
    int limite = 100;
    int opcao;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera o primeiro número secreto
    numeroSecreto = rand() % (limite + 1);

    do {

        // -------- MENU PRINCIPAL --------
        printf("\n===== NUMBER GUESSING GAME =====\n");
        printf("1 - Jogar\n");
        printf("2 - Definir numero de tentativas\n");
        printf("3 - Definir limite do numero\n");
        printf("4 - Ajuda\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // -------- JOGAR --------
            case 1:
                printf("\nO jogo vai começar!\n");

                for(int i = 1; i <= tentativas; i++) {

                    printf("\nTentativa %d de %d\n", i, tentativas);
                    printf("Insira o seu palpite: ");
                    scanf("%d", &palpite);

                    if(palpite == numeroSecreto) {
                        printf("Parabens! Voce acertou o numero!\n");
                        break;
                    }

                    if(palpite > numeroSecreto) {
                        printf("O numero secreto e MENOR.\n");
                    } else {
                        printf("O numero secreto e MAIOR.\n");
                    }

                    if(i == tentativas) {
                        printf("\nVoce perdeu! O numero era: %d\n", numeroSecreto);
                    }
                }
                break;

            // -------- DEFINIR TENTATIVAS --------
            case 2:
                printf("Quantas tentativas deseja? ");
                scanf("%d", &tentativas);
                printf("Agora voce tem %d tentativas.\n", tentativas);
                break;

            // -------- DEFINIR LIMITE --------
            case 3:
                printf("Defina o limite maximo do numero: ");
                scanf("%d", &limite);

                // gera novo número com o novo limite
                numeroSecreto = rand() % (limite + 1);

                printf("Novo limite definido! Numero secreto atualizado.\n");
                break;

            // -------- AJUDA --------
            case 4:
                printf("\n===== AJUDA =====\n");
                printf("1 - Jogar: tenta adivinhar o numero secreto.\n");
                printf("2 - Tentativas: define quantas chances voce tem.\n");
                printf("3 - Limite: define o numero maximo do jogo.\n");
                printf("5 - Sair: encerra o jogo.\n");
                break;

            // -------- SAIR --------
            case 5:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while(opcao != 5);

    return 0;
}
