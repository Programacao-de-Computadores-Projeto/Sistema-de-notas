#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("cls");

	int i, cont, lista, passarLista;
    passarLista = 0;

    printf("\n------------------------");
    printf("\n    Sistema de Notas    ");
    printf("\n------------------------");

    do{
    printf("\nQuantas notas gostaria de Registrar?(faca um valor de 1 a 100)\n");
    scanf("%d", &cont);
    printf("\n-------------------------------");
    }while(cont > 100 || cont <=0);

    //variaveis que v�o armazenar o valor do cont
    float nota1[cont], nota2[cont], recup[cont], soma[cont];
    bool Aprovado[cont];

    int verificar = cont;

    //anota��o das repostas dos alunos
    for( i = 0; i < cont; i++)
    {    
        do{
            nota1[i] = 0;
            printf("\nQual foi a nota do aluno %d da Institui��o?\n", i+1);
            scanf("%f", &nota1[i]);
        }while(nota1[i] > 5 || nota1[i] < 0); // while verifica se o valor � maior que 5 ou menor que 0

        do{
            nota2[i] = 0;
            printf("\nQual foi a nota do aluno %d do professor?\n", i+1);
            scanf("%f", &nota2[i]);
        }while(nota2[i] > 5 || nota2[i] < 0); // while verifica se o valor � maior que 5 ou menor que 0

        printf("\n-------------------------------");
        soma[i] = nota2[i] + nota1[i]; // soma dos valores 

        //arredondando os valores
        
    }

    system("cls");
    
    //verificando se aluno est�o reprovado
    for ( i = 0; i < cont; i++)
    {
        if(soma[i] >= 6)
        {
            printf("\nAluno %d: Aprovado\n", i+1);
            printf("\n-------------------------------");
            Aprovado[i] = true;
        }else{
            do{
                printf("\nQual a nota do aluno %d na recupera��o?\n", i+1);
                scanf("%f", &recup[i]);
            } while(recup[i] > 5 || recup[i] < 0);
            // verifica se a nota da recupera��o � maior que alguma das notas
            if (recup[i] > nota1[i] || recup[i] > nota2[i])
            {
                if (nota1[i] > nota2[i])//troca das notas
                {
                    nota2[i] = recup[i];
                }else{
                    nota1[i] = recup[i];
                }

                soma[i] = nota1[i] + nota2[i]; 

                Aprovado[i] = true;
                
                printf("\nAluno %d: Aprovado", i+1);
                printf("\n-------------------------------");
            }else{
                Aprovado[i] = false;
                printf("\nAluno %d: Reprovado", i+1);
                printf("\n-------------------------------");
            }
        }
    }
    //Buscando o aluno desejado
   
    Sleep(1500);
    system("cls"); 

    printf("\n----------------------------------");
    printf("\n      Apresentando os alunos      ");
    printf("\n----------------------------------");

    //lista de 10 em 10 alunos
    if (cont % 10 != 0)
    {
        cont = ceil(cont / 10 + 1)*10;
    }
    cont = cont/10;
    
    do{
        printf("\nEscolha uma lista de alunos desejados de 1 a %d\n", cont);
        scanf(" %d", &lista);
        printf("\n-------------------------------");
    }while (lista > cont || lista <= 0);

    do{
    switch (lista)
    {
    case 1:
        for ( i = 0; i < 10; i++)
        {   
            if (i >= verificar)
            {
                break;
            }
            
            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

        break;
    case 2:
        for ( i = 10; i < 20; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 3:
        for ( i = 20; i < 30; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 4:
        for ( i = 30; i < 40; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 5:
        for ( i = 40; i < 50; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;
    
    case 6:
        for ( i = 50; i < 60; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 7:
        for ( i = 60; i < 70; i++)
        {
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 8:
        for ( i = 70; i < 80; i++)
        {         
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 9:
        for ( i = 80; i < 90; i++)
        {       
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    case 10:
        for ( i = 90; i < 100; i++)
        {      
            if (i >= verificar)
            {
                break;
            }

            printf("\nAluno %d\n", i + 1);
            printf("\nNota da Institui��o: %.1f", nota1[i]);
            printf("\nNota do Professor: %.1f", nota2[i]);
            printf("\nNota Final: %.1f",soma[i]);
            if (Aprovado[i])
            {
                printf("\nStatus: Aprovado");
            }else{
                printf("\nStatus: Reprovado");
            }
            printf("\n-------------------------------");
        }

    break;

    default:
        printf("\nLista n�o encontrada");
        printf("\n-------------------------------");
    }

    if (cont > 1){
        do{
            printf("\n[0] Encerrar");
            printf(" | [1] Anterior");
            printf(" | [2] Pr�ximo\n");
            scanf(" %d" , &passarLista);//ATENCAO n�o tirar o espa�o do %d, sen�o o programa le o \n da linha de cima e o codigo se repete apenas uma vez, n�o entendi esse bug
            printf("\n-------------------------------");
        }while(passarLista != 0 && passarLista != 1 && passarLista != 2);

        switch (passarLista)
        {
        case 1:
            if(lista > 1){
                system("cls");
                lista = lista - 1;
            }else{
                printf("\nop��o invalida");
            }
            break;
        
        case 2:
            if(lista < 10){
                system("cls");
                lista = lista + 1;
            }else{
                printf("\nop��o invalida");
            }
            break;
        default:
            printf("\nAt� a Proxima");
            break;
        }
    } 
    }while(passarLista != 0);
    
    return 0;
}

