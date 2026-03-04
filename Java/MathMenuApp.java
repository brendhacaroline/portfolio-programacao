import java.util.Scanner;

/*
    Math Menu Application
    ---------------------
    Programa em Java com menu interativo que realiza
    várias operações matemáticas.

    Funcionalidades:
    - Soma
    - Subtração
    - Multiplicação
    - Divisão
    - Par ou ímpar
    - Equação de 1º grau
    - Equação de 2º grau
    - Quadrado de um número
    - Verificar múltiplo de 5
*/

public class MathMenuApp {

    // Scanner global
    static Scanner ler = new Scanner(System.in);

    // -------- MENU --------
    public static void menu(){
        System.out.println("------ MENU ------");
        System.out.println("1 - Soma");
        System.out.println("2 - Subtração");
        System.out.println("3 - Multiplicação");
        System.out.println("4 - Divisão");
        System.out.println("5 - Par/Ímpar");
        System.out.println("6 - Eq. 1 grau");
        System.out.println("7 - Eq. 2 grau");
        System.out.println("8 - Quadrado");
        System.out.println("9 - Múltiplo de 5");
        System.out.println("0 - Sair");
    }

    // -------- SOMA --------
    public static int soma(int v1, int v2){
        return v1 + v2;
    }

    // -------- SUBTRAÇÃO --------
    public static int subtracao(int v1, int v2){
        return v1 - v2;
    }

    // -------- MULTIPLICAÇÃO --------
    public static int multiplicacao(int v1, int v2){
        return v1 * v2;
    }

    // -------- DIVISÃO --------
    public static double divisao(double v1, double v2){
        return v1 / v2;
    }

    // -------- PAR OU ÍMPAR --------
    public static boolean par(int v1){
        return v1 % 2 == 0;
    }

    // -------- EQUAÇÃO 1º GRAU --------
    public static double equacao1grau(double a, double b){
        return -b / a;
    }

    // -------- QUADRADO --------
    public static double quadrado(double v){
        return v * v;
    }

    // -------- MÚLTIPLO DE 5 --------
    public static boolean multiplo5(int v){
        return v % 5 == 0;
    }

    // -------- MAIN --------
    public static void main(String[] args){

        int op;

        do{

            menu();
            System.out.print("Escolha uma opção: ");
            op = ler.nextInt();

            switch(op){

                case 1:
                    System.out.println("Você escolheu Soma");
                    int a = ler.nextInt();
                    int b = ler.nextInt();
                    System.out.println("Resultado: " + soma(a,b));
                    break;

                case 2:
                    System.out.println("Você escolheu Subtração");
                    a = ler.nextInt();
                    b = ler.nextInt();
                    System.out.println("Resultado: " + subtracao(a,b));
                    break;

                case 3:
                    System.out.println("Você escolheu Multiplicação");
                    a = ler.nextInt();
                    b = ler.nextInt();
                    System.out.println("Resultado: " + multiplicacao(a,b));
                    break;

                case 4:
                    System.out.println("Você escolheu Divisão");
                    double x = ler.nextDouble();
                    double y = ler.nextDouble();
                    System.out.println("Resultado: " + divisao(x,y));
                    break;

                case 5:
                    System.out.println("Digite um número:");
                    int n = ler.nextInt();
                    if(par(n))
                        System.out.println("Número Par");
                    else
                        System.out.println("Número Ímpar");
                    break;

                case 6:
                    System.out.println("Equação ax + b = 0");
                    double aa = ler.nextDouble();
                    double bb = ler.nextDouble();
                    System.out.println("Resultado: " + equacao1grau(aa,bb));
                    break;

                case 8:
                    System.out.println("Digite um número:");
                    double q = ler.nextDouble();
                    System.out.println("Quadrado: " + quadrado(q));
                    break;

                case 9:
                    System.out.println("Digite um número:");
                    n = ler.nextInt();
                    if(multiplo5(n))
                        System.out.println("É múltiplo de 5");
                    else
                        System.out.println("Não é múltiplo de 5");
                    break;

                case 0:
                    System.out.println("Saindo do programa");
                    break;

                default:
                    System.out.println("Opção inválida");
            }

        } while(op != 0);
    }
}
