import java.util.Scanner;

/*
    Car Price Calculator
    --------------------
    Aplicação em Java que calcula o preço final de um automóvel
    com base no preço de fábrica, impostos e percentagem do revendedor
    de acordo com a marca escolhida.

    Marcas disponíveis:
    - Skoda
    - Seat
    - VW
    - Audi
*/

public class CarPriceCalculator {

    public static void main(String[] args) {

        Scanner ler = new Scanner(System.in);

        int opcao;
        double precoFabrica;
        double imposto;
        double percentagemRevendedor;
        double precoFinal;

        do {

            // MENU
            System.out.println("====== MENU AUTOMÓVEIS ======");
            System.out.println("1 - Skoda");
            System.out.println("2 - Seat");
            System.out.println("3 - VW");
            System.out.println("4 - Audi");
            System.out.println("0 - Sair");
            System.out.print("Escolha a marca: ");

            opcao = ler.nextInt();

            if (opcao == 0) {
                System.out.println("Programa encerrado.");
                break;
            }

            System.out.print("Insira o preço de fábrica: ");
            precoFabrica = ler.nextDouble();

            // cálculo do imposto (45%)
            imposto = precoFabrica * 0.45;

            switch (opcao) {

                case 1:
                    percentagemRevendedor = precoFabrica * 0.18;
                    System.out.println("Marca: Skoda");
                    break;

                case 2:
                    percentagemRevendedor = precoFabrica * 0.22;
                    System.out.println("Marca: Seat");
                    break;

                case 3:
                    percentagemRevendedor = precoFabrica * 0.28;
                    System.out.println("Marca: VW");
                    break;

                case 4:
                    percentagemRevendedor = precoFabrica * 0.33;
                    System.out.println("Marca: Audi");
                    break;

                default:
                    System.out.println("Opção inválida.");
                    continue;
            }

            // cálculo do preço final
            precoFinal = precoFabrica + imposto + percentagemRevendedor;

            // RESULTADOS
            System.out.println("\n------ RESULTADO ------");
            System.out.println("Imposto: " + imposto);
            System.out.println("Percentagem Revendedor: " + percentagemRevendedor);
            System.out.println("Preço Final: " + precoFinal);
            System.out.println("-----------------------\n");

        } while (opcao != 0);

        ler.close();
    }
}
