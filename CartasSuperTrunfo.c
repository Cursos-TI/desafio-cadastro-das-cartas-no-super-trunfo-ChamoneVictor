#include <stdio.h>
#include <string.h>

// Estrutura de Dados
typedef struct
{
    float area, pib, populacao;
    int pTuristicos;
    char nome[50];
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder; // Soma de todas as propriedades
} Cidade;

// Método para calcular propriedades derivadas
void calcularPropriedades(Cidade *cidade)
{
    cidade->densidadePopulacional = cidade->populacao / cidade->area; // População / Área
    cidade->pibPerCapita = cidade->pib / cidade->populacao;           // PIB / População
    cidade->superPoder = cidade->populacao + cidade->area + cidade->pib + cidade->pTuristicos;
}

// Método para exibir os dados
void exibirDados(Cidade cidade)
{
    printf("\n=====================\n");
    printf("Cidade: %s\n", cidade.nome);
    printf("População: %.2f habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", cidade.densidadePopulacional);
    printf("PIB per Capita: %.2f bilhões por habitante\n", cidade.pibPerCapita);
    printf("Super Poder: %.2f\n", cidade.superPoder);
    printf("=====================\n");
}

// Método para comparar duas cartas
void compararCartas(Cidade c1, Cidade c2)
{
    printf("\n=== Comparação entre %s e %s ===\n", c1.nome, c2.nome);

    // Comparação de densidade populacional (menor é melhor)
    printf("Densidade Populacional: ");
    if (c1.densidadePopulacional < c2.densidadePopulacional)
        printf("Vencedor: %s\n", c1.nome);
    else if (c1.densidadePopulacional > c2.densidadePopulacional)
        printf("Vencedor: %s\n", c2.nome);
    else
        printf("Empate!\n");

    // Comparação de outras propriedades (maior é melhor)
    printf("População: ");
    printf("Vencedor: %s\n", (c1.populacao > c2.populacao) ? c1.nome : c2.nome);

    printf("Área: ");
    printf("Vencedor: %s\n", (c1.area > c2.area) ? c1.nome : c2.nome);

    printf("PIB: ");
    printf("Vencedor: %s\n", (c1.pib > c2.pib) ? c1.nome : c2.nome);

    printf("Pontos Turísticos: ");
    printf("Vencedor: %s\n", (c1.pTuristicos > c2.pTuristicos) ? c1.nome : c2.nome);

    printf("Super Poder: ");
    printf("Vencedor: %s\n", (c1.superPoder > c2.superPoder) ? c1.nome : c2.nome);
}

int main()
{
    int nCidade;

    // Entrada de dados
    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &nCidade);
    getchar(); // Limpa o buffer após o scanf

    Cidade cidades[nCidade]; // Array para armazenar os dados das cidades

    for (int i = 0; i < nCidade; i++)
    {
        printf("\n=== Cadastro da Cidade %d ===\n", i + 1);

        printf("Nome da cidade: ");
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);
        cidades[i].nome[strcspn(cidades[i].nome, "\n")] = '\0'; // Remove o '\n' ao final

        printf("População (habitantes): ");
        scanf("%f", &cidades[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cidades[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cidades[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cidades[i].pTuristicos);

        getchar(); // Limpa o buffer do teclado após cada entrada

        // Calcula as propriedades derivadas da cidade
        calcularPropriedades(&cidades[i]);
    }

    // Exibição das cartas cadastradas
    printf("\n=== Cartas das Cidades Cadastradas ===\n");
    for (int i = 0; i < nCidade; i++)
    {
        exibirDados(cidades[i]);
    }

    // Comparação de duas cidades
    int c1Index, c2Index;
    printf("\nEscolha duas cidades para comparar (índice de 1 a %d):\n", nCidade);
    printf("Cidade 1: ");
    scanf("%d", &c1Index);
    printf("Cidade 2: ");
    scanf("%d", &c2Index);

    // Ajusta os índices para 0-based
    c1Index--;
    c2Index--;

    // Valida os índices escolhidos
    if (c1Index >= 0 && c1Index < nCidade && c2Index >= 0 && c2Index < nCidade)
    {
        compararCartas(cidades[c1Index], cidades[c2Index]);
    }
    else
    {
        printf("Índices inválidos! Certifique-se de escolher índices entre 1 e %d.\n", nCidade);
    }

    return 0;
}
