#include <stdio.h>

// Função recursiva para mover o Bispo usando loops aninhados
void moverBispo(int linha, int coluna, int maxMov) {
    if (maxMov == 0) return; // Condição de parada da recursão

    // Loop aninhado para simular o movimento diagonal
    for (int i = 0; i < 1; i++) {       
        for (int j = 0; j < 1; j++) {   
            printf("Bispo na linha %d, coluna %d (Cima e Direita)\n", linha, coluna);
        }
    }

    // Chamada recursiva para a próxima casa na diagonal
    moverBispo(linha - 1, coluna + 1, maxMov - 1); // diagonal direita para cima
}

// Função recursiva para mover a Torre — 5 casas para a direita
void moverTorre(int casa) {
    if (casa > 5) return;  
    printf("Torre na casa %d: Direita\n", casa);
    moverTorre(casa + 1);
}

// Função recursiva para mover a Rainha — 8 casas para a esquerda
void moverRainha(int casa) {
    if (casa > 8) return;  
    printf("Rainha na casa %d: Esquerda\n", casa);
    moverRainha(casa + 1);
}

// Função para mover o Cavalo — 3 casas em uma direção e 1 perpendicular
void moverCavalo(int etapa, int casasRestantes) {
    if (etapa > 1) return;

    if (etapa == 0) {
        // Andar 3 casas "para cima"
        if (casasRestantes > 0) {
            printf("Cavalo: Cima\n");
            moverCavalo(0, casasRestantes - 1);
        } else {
            // Após terminar as 3 casas, passa para o movimento perpendicular
            moverCavalo(1, 1);
        }
    } else if (etapa == 1) {
        // Movimento perpendicular (1 casa direita)
        printf("Cavalo: Direita\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== Simulador de Movimentos de Xadrez ===\n");
        printf("Escolha a peça digitando o número correspondente:\n");
        printf("1 - Bispo (5 casas na diagonal direita para cima)\n");
        printf("2 - Torre (5 casas para a direita)\n");
        printf("3 - Rainha (8 casas para a esquerda)\n");
        printf("4 - Cavalo (1 movimento em L: 3 cima, 1 direita)\n");
        printf("0 - Sair\n");
        printf("Opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite apenas números.\n");
            while(getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nMovimento do Bispo:\n");
                moverBispo(7, 0, 5); // começa na linha 7, coluna 0, 5 movimentos
                break;
            case 2:
                printf("\nMovimento da Torre:\n");
                moverTorre(1);
                break;
            case 3:
                printf("\nMovimento da Rainha:\n");
                moverRainha(1);
                break;
            case 4:
                printf("\nMovimento do Cavalo:\n");
                moverCavalo(0, 3); // 3 casas para cima, depois 1 para direita
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida. Digite um número entre 0 e 4.\n");
        }

    } while (opcao != 0);

    return 0;
}
