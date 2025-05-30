#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h> 
#include <math.h>
#include <time.h> 

#define MAX_ALUNOS 100

const char *nomes[] = {"Alice", "Bruno", "Carla", "Daniel", "Eduarda", "Fernando", "Gabriela", "Hugo", "Isabela", "Joao", "Maria", "Pedro", "Ana", "Lucas", "Mariana", "Gabriel", "Julia", "Rafael", "Laura", "Diego"};
const char *sobrenomes[] = {"Silva", "Santos", "Oliveira", "Souza", "Pereira", "Lima", "Costa", "Rocha", "Almeida", "Nunes", "Carvalho", "Martins", "Goncalves", "Rodrigues", "Fernandes", "Gomes", "Dias", "Borges", "Melo", "Barbosa"};
#define NUM_NOMES (sizeof(nomes) / sizeof(nomes[0]))
#define NUM_SOBRENOMES (sizeof(sobrenomes) / sizeof(sobrenomes[0]))

void RegistrarAlunos(int cont, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[]);
void Recuperacao(int cont, char nomeAluno[][30], float nota1[], float nota2[], float soma[], float recup[], bool Aprovado[]);
void Lista(int cont, int verificar, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]);
void MenuFinal(int *cont, int verificar, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[], float recup[]);
void NovoAluno(int i, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]);
void AlterarAluno(char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], int cont);
void ExcluirAluno(int indice, int *cont, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]);
void BuscarAluno(char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[], int verificar);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("cls");
    srand(time(NULL)); 

    char nomeAluno[MAX_ALUNOS][30];
    int RGM[MAX_ALUNOS];
    float nota1[MAX_ALUNOS], nota2[MAX_ALUNOS], soma[MAX_ALUNOS], recup[MAX_ALUNOS];
    bool aprovado[MAX_ALUNOS];
    int cont = 0, verificar = 0;

    printf("\n------------------------");
    printf("\n      Sistema de Notas    ");
    printf("\n------------------------");

    do {
        printf("\nQuantas notas gostaria de Registrar? (1 a %d)\n", MAX_ALUNOS);
        scanf("%d", &cont);
    } while (cont <= 0 || cont > MAX_ALUNOS);

    verificar = cont;

    RegistrarAlunos(cont, nomeAluno, RGM, nota1, nota2, soma);
    system("pause");
    system("cls");

    Recuperacao(cont, nomeAluno, nota1, nota2, soma, recup, aprovado);
    system("pause");
    system("cls");

    Lista(cont, verificar, nomeAluno, RGM, nota1, nota2, soma, aprovado);
    system("cls");
    MenuFinal(&cont, verificar, nomeAluno, RGM, nota1, nota2, soma, aprovado, recup);

    return 0;
}

void MenuFinal(int *cont, int verificar, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[], float recup[]) {
    int opcao;

    do {
        printf("\n------------------");
        printf("\n        Menu        ");
        printf("\n------------------\n");
        printf("\n1. Cadastrar novo Aluno");
        printf("\n2. Voltar para lista");
        printf("\n3. Alterar Aluno");
        printf("\n4. Excluir Aluno");
        printf("\n5. Buscar Aluno");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (*cont < MAX_ALUNOS) {
                    NovoAluno(*cont, nomeAluno, RGM, nota1, nota2, soma, Aprovado);
                    (*cont)++;
                    verificar = *cont;
                    Recuperacao(1, &nomeAluno[*cont - 1], &nota1[*cont - 1], &nota2[*cont - 1], &soma[*cont - 1], &recup[*cont - 1], &Aprovado[*cont - 1]);
                } else {
                    printf("Limite de alunos atingido.\n");
                }
                break;
            case 2:
                Lista(*cont, verificar, nomeAluno, RGM, nota1, nota2, soma, Aprovado);
                break;
            case 3:
                AlterarAluno(nomeAluno, RGM, nota1, nota2, soma, *cont);
                break;
            case 4: {
                int indice;
                printf("\nInforme o numero do aluno que deseja excluir (1 a %d): ", *cont );
                scanf("%d", &indice);
                if (indice >= 1 && indice <= *cont) { 
                    ExcluirAluno(indice, cont, nomeAluno, RGM, nota1, nota2, soma, Aprovado);
                    verificar = *cont;
                } else {
                    printf("Indice invalido.\n");
                }
                break;
            }
            case 5:
                BuscarAluno(nomeAluno, RGM, nota1, nota2, soma, Aprovado, *cont);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void RegistrarAlunos(int cont, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[]) {

    bool automatizar = (cont == MAX_ALUNOS);

    for (int i = 0; i < cont; i++) {
        if (automatizar) {
            int nome_idx = rand() % NUM_NOMES;
            int sobrenome_idx = rand() % NUM_SOBRENOMES;
            sprintf(nomeAluno[i], "%s %s", nomes[nome_idx], sobrenomes[sobrenome_idx]);

            printf("\nQual o nome do Aluno %d?", i + 1);
            printf("\n%s", nomeAluno[i]);

            RGM[i] = 100000000 + (rand() % 900000000); 

            printf("\nQual o RGM? (9 digitos)");
            printf("\n%d", RGM[i]);

            nota1[i] = (float)rand() / RAND_MAX * 5.0;
            nota2[i] = (float)rand() / RAND_MAX * 5.0;

            printf("\nQual é a nota da instituição?");
            printf("\n %.1f", nota1[i]);
            printf("\nQual é a nota do Professor");
            printf("\n %.1f", nota1[i]);
            
        }
        soma[i] = nota1[i] + nota2[i];
        printf("\n------------------\n"); 
    }
}

void NovoAluno(int i, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]) {
    printf("\nQual o nome do aluno %d?\n", i + 1);
    int nome_idx = rand() % NUM_NOMES;
    int sobrenome_idx = rand() % NUM_SOBRENOMES;
    sprintf(nomeAluno[i], "%s %s", nomes[nome_idx], sobrenomes[sobrenome_idx]);


    printf("\nQual o RGM? (9 digitos)\n");

    RGM[i] = 100000000 + (rand() % 900000000);
    printf("%d", RGM[i]);

    printf("\nNota da Instituicao: ");
    nota1[i] = (float)rand() / RAND_MAX * 5.0;
    printf("%.1f", nota1[i]);

    printf("\nNota do Professor: ");
    nota2[i] = (float)rand() / RAND_MAX * 5.0;
    printf("%.1f", nota2[i]);

    soma[i] = nota1[i] + nota2[i];
    printf("\n------------------\n");

    Aprovado[i] = (soma[i] >= 6);
}

void Lista(int cont, int verificar, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]) {
    int lista, passarLista = 0;
    int totalListas = (int)ceil(verificar / 10.0);

    
        do {
        printf("\nEscolha uma lista de alunos desejados de 1 a %d\n", totalListas);
            scanf(" %d", &lista);
            printf("\n-------------------------------");
        } while (lista > totalListas || lista <= 0);

    do{
        int inicio = (lista - 1) * 10;
        int fim = inicio + 10;
    
        for (int i = inicio; i < fim && i < verificar; i++) {
            printf("\nAluno %d\n", i + 1);
            printf("Nome: %s\n", nomeAluno[i]);
            printf("RGM: %d\n", RGM[i]);
            printf("Nota da Instituicao: %.1f\n", nota1[i]);
            printf("Nota do Professor: %.1f\n", nota2[i]);
            printf("Nota Final: %.1f\n", soma[i]);
            printf("Status: %s\n", Aprovado[i] ? "Aprovado" : "Reprovado");
            printf("-------------------------------\n");
        }

        if (totalListas > 1) {
            do {
                printf("\n[0] Encerrar | [1] Anterior | [2] Proximo\n");
                scanf(" %d", &passarLista);
                printf("\n-------------------------------\n");
            } while (passarLista != 0 && passarLista != 1 && passarLista != 2);

            switch (passarLista) {
                case 1:
                    if (lista > 1) {
                        lista--;
                    } else {
                        printf("\nOpcao invalida\n");
                    }
                    break;
                case 2:
                    if (lista < totalListas) {
                        lista++;
                    } else {
                        printf("\nOpcao invalida\n");
                    }
                    break;
                default:
                    printf("\nAte a proxima!\n");
                    break;
            }
        } else {
            system("pause");
        }
    } while (passarLista != 0);
}

void Recuperacao(int cont, char nomeAluno[][30], float nota1[], float nota2[], float soma[], float recup[], bool Aprovado[]) {
    bool automatizar_recuperacao = (cont == MAX_ALUNOS); 

    for (int i = 0; i < cont; i++) {
        if (soma[i] >= 6) {
            Aprovado[i] = true;
            printf("\nAluno %s: Aprovado\n", nomeAluno[i]);
            printf("\n------------------\n");
        } else {
            if (automatizar_recuperacao || (cont == 1 && i == 0)) { 
                recup[i] = (float)rand() / RAND_MAX * 5.0; 
                printf("\nQual e a nota de recuperacao de %s: ", nomeAluno[i]);
                printf("\n%.1f", recup[i]); 

            }

            if (recup[i] > nota1[i] || recup[i] > nota2[i]) {
                if (nota1[i] < nota2[i]) {
                    nota1[i] = recup[i];
                } else {
                    nota2[i] = recup[i];
                }
                soma[i] = nota1[i] + nota2[i];

                if (soma[i] >= 6) {
                    Aprovado[i] = true;
                    printf("\nAluno %s: Aprovado\n", nomeAluno[i]);
                    printf("\n------------------\n");
                } else {
                    Aprovado[i] = false;
                    printf("\nAluno %s: Reprovado\n", nomeAluno[i]);
                    printf("\n------------------\n");
                }
            }else {
                Aprovado[i] = false;
                printf("\nAluno %s: Reprovado\n", nomeAluno[i]);
                printf("\n------------------\n");
            }
        }
    }
}

void ExcluirAluno(int indice, int *cont, char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[]) {
    for (int i = indice - 1 ; i < (*cont); i++) {
        strcpy(nomeAluno[i], nomeAluno[i + 1]);
        RGM[i] = RGM[i + 1];
        nota1[i] = nota1[i + 1];
        nota2[i] = nota2[i + 1];
        soma[i] = soma[i + 1];
        Aprovado[i] = Aprovado[i + 1];
    }
    (*cont)--; 
    printf("\nAluno excluido com sucesso!\n");
}

void BuscarAluno(char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], bool Aprovado[], int verificar) {
    char nome[30];
    bool alunoEncontrado = false;

    printf("\nDigite o nome do aluno que deseja buscar:\n");
    fflush(stdin);
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0; 

    for (int i = 0; i < verificar; i++) {
        if (strcmp(nome, nomeAluno[i]) == 0) {
            printf("\nAluno %d\n", i + 1);
            printf("Nome: %s\n", nomeAluno[i]);
            printf("RGM: %d\n", RGM[i]);
            printf("Nota da Instituicao: %.1f\n", nota1[i]);
            printf("Nota do Professor: %.1f\n", nota2[i]);
            printf("Nota Final: %.1f\n", soma[i]);
            printf("Status: %s\n", Aprovado[i] ? "Aprovado" : "Reprovado");
            printf("\n------------------\n");
            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("\nAluno nao encontrado.\n");
    }
    system("pause");
}

void AlterarAluno(char nomeAluno[][30], int RGM[], float nota1[], float nota2[], float soma[], int cont) {
    char nome[30];
    bool alunoEncontrado = false;

    printf("\nQual o nome do aluno que gostaria de alterar?\n");
    fflush(stdin);
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0; 
    
    for (int i = 0; i < cont; i++) {
        if (strcmp(nome, nomeAluno[i]) == 0) {
            printf("\nQual o nome do aluno %d?\n", i + 1);
            fflush(stdin);
            fgets(nomeAluno[i], 30, stdin);
            nomeAluno[i][strcspn(nomeAluno[i], "\n")] = 0;
            printf("\n------------------\n");

            do {
                printf("\nQual o RGM? (9 digitos)\n");
                scanf("%d", &RGM[i]);
            } while (RGM[i] < 100000000 || RGM[i] >= 1000000000); 

            do {
                printf("\nNota da Instituicao: ");
                scanf("%f", &nota1[i]);
            } while (nota1[i] < 0 || nota1[i] > 5);

            do {
                printf("\nNota do Professor: ");
                scanf("%f", &nota2[i]);
            } while (nota2[i] < 0 || nota2[i] > 5);
            printf("\n------------------\n");

            soma[i] = nota1[i] + nota2[i];
            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("\nAluno nao encontrado.\n");
    }
    system("pause");
}