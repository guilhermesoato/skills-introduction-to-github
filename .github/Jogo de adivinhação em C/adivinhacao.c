#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    char jogar_novamente;

    do {
        // Imprime o cabeçalho do jogo
        printf("\n\n");
        printf("          P  /_\\  P                              \n");
        printf("         /_\\_|_|_/_\\                            \n");
        printf("     n_n | ||. .|| | n_n         Bem-vindo ao     \n");
        printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
        printf("    |\" \"  |  |_|  |\"  \" |                     \n");
        printf("    |_____| ' _ ' |_____|                         \n");
        printf("          \\__|_|__/                              \n");
        printf("\n\n");

        // Gera número aleatório
        srand(time(0));
        int numerosecreto = rand() % 100;
        int chute;
        int tentativas = 1;
        double pontos = 1000;
        int acertou = 0;
        int numerodetentativas;

        // Escolha do nível de dificuldade
        printf("Qual o nivel de dificuldade?\n");
        printf("(1) Facil (2) Medio (3) Dificil\n\n");
        printf("Escolha: ");
        int nivel;
        scanf("%d", &nivel);

        switch (nivel) {
            case 1:
                numerodetentativas = 20;
                break;
            case 2:
                numerodetentativas = 10;
                break;
            default:
                numerodetentativas = 5;
                break;
        }

        // Loop principal do jogo
        for (int i = 1; i <= numerodetentativas; i++) {
            printf("\nTentativa %d de %d\n", tentativas, numerodetentativas);
            printf("Qual eh o seu chute? ");
            scanf("%d", &chute);
            printf("Seu chute foi %d\n", chute);

            if (chute < 0) {
                printf("Voce nao pode chutar numeros negativos! Tente novamente.\n");
                continue;
            }

            acertou = (chute == numerosecreto);
            int maior = chute > numerosecreto;

            if (acertou) {
                break;  // Se acertou, sai do loop
            } else if (maior) {
                printf("Seu chute foi maior que o numero secreto\n");
            } else {
                printf("Seu chute foi menor que o numero secreto\n");
            }

            tentativas++;
            double pontosperdidos = fabs(chute - numerosecreto) / 2.0;
            pontos -= pontosperdidos;
        }

        // Mensagem de fim de jogo
        printf("\nFim de jogo!\n");

        if (acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");

            printf("Voce acertou em %d tentativas!\n", tentativas);
            printf("Total de pontos: %.1f\n", pontos);
        } else {
            printf("       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");

            printf("Voce perdeu! O numero secreto era %d. Tente de novo!\n", numerosecreto);
        }

        // Perguntar se quer jogar novamente
        printf("\nDeseja jogar novamente? (s/n): ");
        getchar();  // Consome a quebra de linha pendente do scanf
        jogar_novamente = getchar();

    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    // Pausa antes de fechar
    printf("\nPressione ENTER para sair...");
    getchar();  

    return 0;
}
