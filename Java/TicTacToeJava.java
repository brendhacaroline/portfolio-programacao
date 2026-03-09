import java.util.Scanner;

/*
    Tic Tac Toe Game (Java)
    -----------------------
    Jogo do Galo desenvolvido em Java.

    Funcionalidades:
    - Tabuleiro 3x3
    - Alternância entre jogadores X e O
    - Validação de posição ocupada
    - Verificação automática de vitória
    - Mensagem de empate
*/

public class TicTacToeJava {

    // Scanner global para leitura de dados
    static Scanner ler = new Scanner(System.in);

    // Verifica se um jogador venceu
    public static int verificaFim(char[][] mat, char c) {
        if ((mat[0][0] == c && mat[0][1] == c && mat[0][2] == c) ||
            (mat[1][0] == c && mat[1][1] == c && mat[1][2] == c) ||
            (mat[2][0] == c && mat[2][1] == c && mat[2][2] == c) ||
            (mat[0][0] == c && mat[1][0] == c && mat[2][0] == c) ||
            (mat[0][1] == c && mat[1][1] == c && mat[2][1] == c) ||
            (mat[0][2] == c && mat[1][2] == c && mat[2][2] == c) ||
            (mat[0][0] == c && mat[1][1] == c && mat[2][2] == c) ||
            (mat[0][2] == c && mat[1][1] == c && mat[2][0] == c)) {
            return 1;
        }
        return 0;
    }

    // Mostra o tabuleiro
    public static void mostraMat(char[][] m) {
        for (int i = 0; i < m.length; i++) {
            System.out.print("|");
            for (int j = 0; j < m.length; j++) {
                System.out.print(m[i][j] + "|");
            }
            System.out.println();
        }
    }

    // Preenche a jogada do jogador atual
    public static int preencheMat(char[][] m, int l, int c, int jogada) {
        int resto = jogada % 2;
        int fim;

        if (resto == 1) {
            m[l][c] = 'X';
            fim = verificaFim(m, 'X');
            if (fim != 0) {
                System.out.println("Terminou o jogo, jogador X ganhou!");
                return -1;
            }
        } else {
            m[l][c] = 'O';
            fim = verificaFim(m, 'O');
            if (fim != 0) {
                System.out.println("Terminou o jogo, jogador O ganhou!");
                return -1;
            }
        }
        return 1;
    }

    // Verifica se a posição está livre
    public static int verificaMat(char[][] m, int lin, int col) {
        if (m[lin][col] == ' ') {
            return 1;
        } else {
            return 0;
        }
    }

    // Lê um número inteiro
    public static int pedeInt(String st) {
        System.out.print(st);
        return ler.nextInt();
    }

    // Preenche o tabuleiro com espaços
    public static void preencheTab(char[][] m) {
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m.length; j++) {
                m[i][j] = ' ';
            }
        }
    }

    // Método principal do jogo
    public static void tabuleiro() {
        char[][] mat = new char[3][3];
        int l, c, verif, termina;
        int jogada = 1;

        System.out.println("=== Jogo do Galo ===");
        preencheTab(mat);
        mostraMat(mat);

        while (jogada <= 9) {
            l = pedeInt("Indique a linha (0 a 2): ");
            c = pedeInt("Indique a coluna (0 a 2): ");

            verif = verificaMat(mat, l, c);

            if (verif == 1) {
                termina = preencheMat(mat, l, c, jogada);
                mostraMat(mat);
                jogada++;

                if (termina == -1) {
                    jogada = 20;
                }

            } else {
                System.out.println("Posição ocupada. Escolha outra coordenada.");
            }
        }

        if (jogada == 10) {
            System.out.println("O jogo empatou.");
        }
    }

    public static void main(String[] args) {
        tabuleiro();
    }
}
