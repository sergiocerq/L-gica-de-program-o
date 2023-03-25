#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_ALUNOS 3
// declarando a constante , NA DECLARAÇÃO NÃO USA-SE ';' NO FINAL!

// protótipo das funções (as funções estão ao final do código!)
void menuGeral();
void menuAluno();
void atualizarAluno();
void menuProfessor();

// definindo as structs de ALUNO e DATA
typedef struct
{
    int dia;
    int mes;
    int ano;
} DataNas;

typedef struct
{
    DataNas dataNas;
    int matricula;
    char nome[51]; // contém 50 caract
    char sexo;     // Usa-se F - p/ feminino e M p/ masculino
    char cpf[15];
} Aluno; // nome da stuct

typedef struct
{
    DataNas dataNas;
    int matricula;
    char nome[51]; // contém 50 caract
    char sexo;
    char cpf[11];
} Professor; // nome da struct

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int opcao;
    int sair = 0; // 0 usa-se como falso!

    // Variáveis de Aluno
    Aluno listaAluno[TAM_ALUNOS]; // váriavel listaAuluno do tipo Struct Aluno
    int qtdAluno = 0;

    int lnAluno; // vai ser usada para dizer qual o ultimo caractere
    int sairAluno = 0;
    int opcaoAluno;

    // usados na validação do CPF Aluno
    /* o tipo cpf usada na struct Aluno é MINUSCULO*/
    int corretoCPFAluno = 0;
    char validaCPFAluno[15];
    int existeMatriculaAluno = 1;
    // usados no menu excluir
    int sairExcluirAluno = 1;
    char ExcluirAluno;
    int posicaoExcluirAluno;
    int opcaoExcluirAluno;
    Aluno copiaAluno; // usado no for em EXCLUIR ALUNO
                      // usados no menu atualizar
    int opcaoAtualizarAluno;
    int posicaoDoAtualizarAluno;
    char confirmaAtualizarAluno;
    int sairDoAtualizarAluno = 0;

    // Variáveis de Professor

    Professor listaProfessor[TAM_ALUNOS]; // váriavel listaAuluno do tipo Struct Aluno
    int qtdProfessor = 0;

    int lnProfessor; // vai ser usada para dizer qual o ultimo caractere
    int sairProfessor = 0;
    int opcaoProfessor;

    // usados na validação do CPF
    /* o tipo cpf usada na struct Professor é MINUSCULO*/
    int corretoCPFProfessor = 0;
    char validaCPFProfessor[15];
    int existeMatriculaProfessor = 1;
    // usados no menu excluir
    int sairExcluirProfessor = 1;
    int posicaoExcluirProfessor;
    int opcaoExcluirProfessor;
    Professor copiaProfessor; // usado no for em EXCLUIR Professor

    int opcaoAtualizarProfessor;
    int posicaoDoAtualizarProfessor;
    char confirmaAtualizarProfessor;
    int sairDoAtualizarProfessor = 0;

    while (!sair)
                {
        men  uGeral();
        setbu  f(stdin, 0);
    
              scanf("%d", &opcao);
              do
              {
            switch (opcao)
              {
    
                  case 0:
                  {
                    sair = 1;
                  break;  
              }
      
              case 1:  
              {  
                  printf("\n>  MÓDULO DOS ALUNOS:\n"); // aqui dentro vou fazer as opções do modulo aluno

                while (!sairAluno)
                  {
                          menuAluno();
                        scanf("%d", &opcaoAluno);

                    switch (opcaoAluno)
                    {

                    case 0:
                    {
                        sairAluno = 1;
                        break;
                    }

                    case 1:
                    {

                        printf("Digite a quantidade de alunos que irá ser cadastrado:\n");
                        scanf("%d", &qtdAluno);
                        getchar(); // isso é pra limpar o buffer , usa-se sempre após o scanf

                        if (qtdAluno > TAM_ALUNOS)
                        {
                            printf("Lista cheia!\n");
                        }
                        else
                        {
                            for (int i = 0; i < qtdAluno; i++)
                            {
                                if (qtdAluno < TAM_ALUNOS)
                                {

                                    do
                                    {
                                        printf("Digite a matricula do aluno:\n");
                                        scanf("%d", &listaAluno[i].matricula);
                                        getchar();

                                        if (listaAluno[i].matricula <= 0)
                                        {
                                            printf("Matricula inválida!\n");
                                        }
                                        /* tem que fazer uma validação para matriculas iguais!*/

                                        if (existeMatriculaAluno == 1)
                                        {

                                            for (int k = 0; k <= TAM_ALUNOS; k++)
                                            {
                                                if (listaAluno[i].matricula == listaAluno[k].matricula)
                                                {
                                                    existeMatriculaAluno++;
                                                }
                                            }
                                        }

                                    } while (listaAluno[i].matricula <= 0 && existeMatriculaAluno != 1);

                                    printf("Digite o nome do aluno:");
                                    fgets(listaAluno[i].nome, 50, stdin); // - Aqui estava DANDO DUAS IDENTAÇÕES tirei o getchar!!!!!!!
                                    lnAluno = strlen(listaAluno[i].nome) - 1;
                                    // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
                                    if (listaAluno[i].nome[lnAluno] == '\n')
                                        listaAluno[i].nome[lnAluno] = '\0';
                                    fflush(stdin);

                                    do
                                    {
                                        printf("Digite F se for Feminino e M se for Masculino:\n");
                                        fflush(stdin);

                                        scanf("	%c", &listaAluno[i].sexo);

                                        if (listaAluno[i].sexo == 'm')
                                        {
                                            listaAluno[i].sexo = 'M';
                                        }
                                        else if (listaAluno[i].sexo == 'f')
                                        {
                                            listaAluno[i].sexo = 'F';
                                        }

                                    } while (listaAluno[i].sexo != 'M' && listaAluno[i].sexo != 'F'); // não é ou, é E.

                                    do
                                    {
                                        printf("Digite  CPF do Aluno com '.' e'-':");
                                        getchar();
                                        fgets(validaCPFAluno, 15, stdin);

                                        lnAluno = strlen(validaCPFAluno) - 1; // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
                                        if (validaCPFAluno[lnAluno] == '\n')
                                        {
                                            validaCPFAluno[lnAluno] = '\0';
                                        }

                                        if (validaCPFAluno[3] == '.' && validaCPFAluno[7] == '.' && validaCPFAluno[11] == '-')
                                        {
                                            strcpy(listaAluno[i].cpf, validaCPFAluno); // essa função copia a strcpy(destino,	copiada)

                                            corretoCPFAluno = 1;
                                        }
                                    } while (!corretoCPFAluno);

                                    do
                                    {
                                        printf("Digite a Data de Nascimento do Aluno:\n");
                                        scanf("%d %d %d", &listaAluno[i].dataNas.dia, &listaAluno[i].dataNas.mes, &listaAluno[i].dataNas.ano);
                                        printf("\n");

                                    } while (listaAluno[i].dataNas.dia < 1 || listaAluno[i].dataNas.dia > 31 || listaAluno[i].dataNas.mes < 1 || listaAluno[i].dataNas.mes > 12 || listaAluno[i].dataNas.ano > 2023);
                                }
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        printf(">  LISTAR ALUNO:\n");
                        // Em listar terá que reorganizar o vetor e tirar as opções que são 0 de matricula!

                        for (int i = 0; i < TAM_ALUNOS; i++)
                        {

                            if (listaAluno[i].matricula > 0)
                            {
                                printf("Matricula: %d\n", listaAluno[i].matricula);
                                printf("Nome: %s\n", listaAluno[i].nome);
                                printf("Sexo: %c\n", listaAluno[i].sexo);
                                printf("CPF: %s\n", listaAluno[i].cpf);
                                printf("\n");
                            }
                        }
                        break;
                    }

                    case 3:
                    {
                        printf(">    EXCLUIR ALUNO:\n");
                        printf("0   -  Voltar\n1   -   Excluir\n");
                        scanf("%d", &opcaoExcluirAluno);

                        switch (opcaoExcluirAluno)
                        {
                        // Ajeitar o menu do excluir aluno , copiar e editar p o professor!!!!!!!
                        case 0:
                        {

                            break;
                        }
                        case 1:
                        {
                            do
                            {
                                do
                                {
                                    printf("Digite a posição do vetor que deseja excluir:\n");
                                    scanf("%d", &posicaoExcluirAluno);
                                    getchar();
                                    if (posicaoExcluirAluno < 0)
                                    {
                                        printf("Posição inválida!\n");
                                    }
                                } while (posicaoExcluirAluno < 0);

                                printf("\nA posição tem nome: %s\nA matricula é:%d\nDeseja excluir?\nS "
                                       "- para Sim!\nN - para Não!\n",
                                       listaAluno[posicaoExcluirAluno].nome, listaAluno[posicaoExcluirAluno].matricula);
                                scanf("%c", &ExcluirAluno);

                                if (ExcluirAluno == 'S' || ExcluirAluno == 's')
                                {
                                    listaAluno[posicaoExcluirAluno].cpf[0] = '\0';
                                    listaAluno[posicaoExcluirAluno].dataNas.ano = 0;
                                    listaAluno[posicaoExcluirAluno].dataNas.mes = 0;
                                    listaAluno[posicaoExcluirAluno].dataNas.dia = 0;
                                    listaAluno[posicaoExcluirAluno].nome[0] = '\0';
                                    listaAluno[posicaoExcluirAluno].sexo = '\0';

                                    sairExcluirAluno = 0;

                                    for (int j = posicaoExcluirAluno + 1; posicaoExcluirAluno <= qtdAluno; j++)
                                    {
                                        copiaAluno = listaAluno[j];
                                        listaAluno[j] = listaAluno[posicaoExcluirAluno];
                                        listaAluno[posicaoExcluirAluno] = copiaAluno;
                                    }
                                    qtdAluno--; // para diminuir a qtd de alunos!
                                    break;
                                }
                                /* CRIAR UM LAÇO DE REPETIÇÃO PARA QUANDO EXCLUIR OU N EXCLUIR NÃO ACABAR O PROGRAMA!!!!!! */
                            } while (sairExcluirAluno == 1);
                            break;
                        }
                        }
                        break;
                    }
                    case 4:
                    {
                        printf(">    ATUALIZAR ALUNO:\n");

                        while (!sairDoAtualizarAluno)
                        {
                            printf("Qual posição do vetor você deseja  atualizar?(As posicoes começam com 0)\n");
                            scanf("%d", &posicaoDoAtualizarAluno);

                            printf("\nA posição tem nome: %s\nA matricula é:%d\nVocê deseja confirmar a Atualização?\n", listaAluno[posicaoDoAtualizarAluno].nome, listaAluno[posicaoDoAtualizarAluno].matricula);
                            getchar();
                            scanf("%c", &confirmaAtualizarAluno);

                            if (confirmaAtualizarAluno == 'S' || confirmaAtualizarAluno == 's')
                            {
                                atualizarAluno();
                                setbuf(stdin, 0);
                                scanf("%d", &opcaoAtualizarAluno);

                                switch (opcaoAtualizarAluno)
                                {
                                case 0:
                                {
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }

                                case 1:
                                {
                                    printf("-  Nova Matricula:\n");
                                    scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 2:
                                {
                                    printf("-  Novo Nome:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].nome, 50, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 3:
                                {
                                    printf("-  Novo sexo:\n");
                                    scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 4:
                                {
                                    printf("-  Nova Data de nascimento:\n");
                                    scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia, &listaAluno[posicaoDoAtualizarAluno].dataNas.mes, &listaAluno[posicaoDoAtualizarAluno].dataNas.ano);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 5:
                                {
                                    printf("-  Novo CPF:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].cpf, 15, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 6:
                                {
                                    printf("---  Refazer cadastro:  ---\n");

                                    printf("-  Nova Matricula:\n");
                                    scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
                                    getchar();

                                    printf("\n");
                                    printf("-  Novo Nome:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].nome, 50, stdin);

                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
                                    getchar();

                                    printf("-  Novo sexo:\n");
                                    scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
                                    getchar();

                                    printf("-  Nova Data de nascimento:\n");
                                    scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia, &listaAluno[posicaoDoAtualizarAluno].dataNas.mes, &listaAluno[posicaoDoAtualizarAluno].dataNas.ano);

                                    printf("-  Novo CPF:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].cpf, 15, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                }
                            }
                            else
                            {
                                sairDoAtualizarAluno = 1;
                            }
                        }
                    }
                    }
                }

                break;
            }

            case 2:
            {
                printf("\n>  MÓDULO DOS PROFESSORES:\n"); // aqui dentro vou fazer as opções do módulo de professores
                                                          // Copiar tudo de aluno e mudar o nome para Professor
                while (!sairProfessor)
                {
                    menuProfessor();
                    scanf("%d", &opcaoProfessor);

                    switch (opcaoProfessor)
                    {

                    case 0:
                    {
                        sairProfessor = 1;
                        break;
                    }

                    case 1:
                    {

                        printf("Digite a quantidade de professores que irá ser cadastrado:\n");
                        scanf("%d", &qtdProfessor);
                        getchar(); // isso é pra limpar o buffer , usa-se sempre após o scanf

                        if (qtdProfessor > TAM_ALUNOS)
                        {
                            printf("Lista cheia!\n");
                        }
                        else
                        {
                            for (int i = 0; i < qtdProfessor; i++)
                            {
                                if (qtdProfessor < TAM_ALUNOS)
                                {

                                    do
                                    {
                                        printf("Digite a matricula do Professor:\n");
                                        scanf("%d", &listaProfessor[i].matricula);
                                        getchar();

                                        if (listaProfessor[i].matricula <= 0)
                                        {
                                            printf("Matricula inválida!\n");
                                        }
                                        /* tem que fazer uma validação para matriculas iguais!*/

                                        if (existeMatriculaProfessor == 1)
                                        {

                                            for (int k = 0; k <= TAM_ALUNOS; k++)
                                            {
                                                if (listaProfessor[i].matricula == listaProfessor[k].matricula)
                                                {
                                                    existeMatriculaProfessor++;
                                                }
                                            }
                                        }

                                    } while (listaProfessor[i].matricula <= 0 && existeMatriculaProfessor != 1);

                                    printf("Digite o nome do Professor:");
                                    fgets(listaProfessor[i].nome, 50, stdin); // - Aqui estava DANDO DUAS IDENTAÇÕES tirei o getchar!!!!!!!
                                    lnProfessor = strlen(listaProfessor[i].nome) - 1;
                                    // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
                                    if (listaProfessor[i].nome[lnProfessor] == '\n')
                                        listaProfessor[i].nome[lnProfessor] = '\0';
                                    fflush(stdin);

                                    do
                                    {
                                        printf("Digite F se for Feminino e M se for Masculino:\n");
                                        fflush(stdin);

                                        scanf("	%c", &listaProfessor[i].sexo);

                                        if (listaProfessor[i].sexo == 'm')
                                        {
                                            listaProfessor[i].sexo = 'M';
                                        }
                                        else if (listaProfessor[i].sexo == 'f')
                                        {
                                            listaProfessor[i].sexo = 'F';
                                        }

                                    } while (listaProfessor[i].sexo != 'M' && listaProfessor[i].sexo != 'F'); // não é ou, é E.

                                    do
                                    {
                                        printf("Digite  CPF do Professor com '.' e'-':");
                                        getchar();
                                        fgets(validaCPFProfessor, 15, stdin);

                                        lnProfessor = strlen(validaCPFProfessor) - 1; // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
                                        if (validaCPFProfessor[lnProfessor] == '\n')
                                        {
                                            validaCPFProfessor[lnProfessor] = '\0';
                                        }

                                        if (validaCPFProfessor[3] == '.' && validaCPFProfessor[7] == '.' && validaCPFProfessor[11] == '-')
                                        {
                                            strcpy(listaProfessor[i].cpf, validaCPFProfessor); // essa função copia a strcpy(destino,	copiada)

                                            corretoCPFProfessor = 1;
                                        }
                                    } while (!corretoCPFProfessor);

                                    do
                                    {
                                        printf("Digite a Data de Nascimento do Professor:\n");
                                        scanf("%d %d %d", &listaProfessor[i].dataNas.dia, &listaProfessor[i].dataNas.mes, &listaProfessor[i].dataNas.ano);
                                        printf("\n");

                                    } while (listaProfessor[i].dataNas.dia < 1 || listaProfessor[i].dataNas.dia > 31 || listaProfessor[i].dataNas.mes < 1 || listaProfessor[i].dataNas.mes > 12 || listaProfessor[i].dataNas.ano > 2023);
                                }
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        printf(">  LISTAR PROFESSOR:\n");
                        // Em listar terá que reorganizar o vetor e tirar as opções que são 0 de matricula!

                        for (int i = 0; i < TAM_ALUNOS; i++)
                        {

                            if (listaProfessor[i].matricula > 0)
                            {
                                printf("Matricula: %d\n", listaProfessor[i].matricula);
                                printf("Nome: %s\n", listaProfessor[i].nome);
                                printf("Sexo: %c\n", listaProfessor[i].sexo);
                                printf("CPF: %s\n", listaProfessor[i].cpf);
                                printf("\n");
                            }
                        }
                        break;
                    }

                    case 3:
                    {
                        /* printf(">    EXCLUIR PROFESSOR:\n");



                                     printf("Digite a posição do vetor que deseja excluir:\n");
                         scanf("%d", &posicaoExcluirProfessor);
                         getchar();

                         printf( "\nA posição tem nome: %s\nA matricula é:%d\nDeseja excluir?\nS "
                             "- para Sim!\nN - para Não!\n",listaProfessor[posicaoExcluirProfessor].nome, listaProfessor[posicaoExcluirProfessor].matricula);
                         scanf("%c", &sairExcluirProfessor);

                                     if (sairExcluirProfessor == 'S' || sairExcluirProfessor == 's') {
                           listaAluno[posicaoExcluirProfessor].cpf[0] = '\0';
                           listaAluno[posicaoExcluirProfessor].dataNas.ano = 0;
                           listaAluno[posicaoExcluirProfessor].dataNas.mes = 0;
                           listaAluno[posicaoExcluirProfessor].dataNas.dia = 0;
                           listaAluno[posicaoExcluirProfessor].nome[0] = '\0';
                           listaAluno[posicaoExcluirProfessor].sexo = '\0';

                                 //falta mover para tras o vetor excluído  diminiuir a qtd de alunos.

                                         // CONFIRMAR ESSA TROCA!
                             for(int j = posicaoExcluirProfessor + 1 ; posicaoExcluirProfessor <= qtdProfessor; j++){
                                                 copiaProfessor = listaProfessor[j];
                                                 listaProfessor[j] = listaProfessor[posicaoExcluirProfessor];
                                                 listaProfessor[posicaoExcluirProfessor] = copiaProfessor;
                                             }
                                   qtdProfessor--; // para diminuir a qtd de alunos!
                                     }

                                 */
                        // CRIAR UM LAÇO DE REPETIÇÃO PARA QUANDO EXCLUIR OU N EXCLUIR NÃO ACABAR O PROGRAMA!!!!!!

                        break;
                    }
                    case 4:
                    {
                        printf(">    ATUALIZAR PROFESSOR:\n");

                        while (!sairDoAtualizarAluno)
                        {
                            printf("Qual posição do vetor você deseja  atualizar?(As posicoes começam com 0)\n");
                            scanf("%d", &posicaoDoAtualizarAluno);

                            printf("\nA posição tem nome: %s\nA matricula é:%d\nVocê deseja confirmar a Atualização?\n", listaAluno[posicaoDoAtualizarAluno].nome, listaAluno[posicaoDoAtualizarAluno].matricula);
                            getchar();
                            scanf("%c", &confirmaAtualizarAluno);

                            if (confirmaAtualizarAluno == 'S' || confirmaAtualizarAluno == 's')
                            {
                                atualizarAluno();
                                setbuf(stdin, 0);
                                scanf("%d", &opcaoAtualizarAluno);

                                switch (opcaoAtualizarAluno)
                                {
                                case 0:
                                {
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }

                                case 1:
                                {
                                    printf("-  Nova Matricula:\n");
                                    scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 2:
                                {
                                    printf("-  Novo Nome:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].nome, 50, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 3:
                                {
                                    printf("-  Novo sexo:\n");
                                    scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 4:
                                {
                                    printf("-  Nova Data de nascimento:\n");
                                    scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia, &listaAluno[posicaoDoAtualizarAluno].dataNas.mes, &listaAluno[posicaoDoAtualizarAluno].dataNas.ano);
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 5:
                                {
                                    printf("-  Novo CPF:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].cpf, 15, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                case 6:
                                {
                                          printf("---  Refazer cadastro:  ---\n");

                                    printf("-  Nova Matricula:\n");
                                    scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
                                    getchar();

                                    printf("\n");
                                    printf("-  Novo Nome:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].nome, 50, stdin);

                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
                                    getchar();

                                    printf("-  Novo sexo:\n");
                                    scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
                                    getchar();

                                    printf("-  Nova Data de nascimento:\n");
                                    scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia, &listaAluno[posicaoDoAtualizarAluno].dataNas.mes, &listaAluno[posicaoDoAtualizarAluno].dataNas.ano);

                                    printf("-  Novo CPF:\n");
                                    fgets(listaAluno[posicaoDoAtualizarAluno].cpf, 15, stdin);
                                    lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
                                    if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
                                        listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
                                    getchar();
                                    sairDoAtualizarAluno = 1;
                                    break;
                                }
                                }
                            }
                            else
                            {
                                sairDoAtualizarAluno = 1;
                            }
                        }
                    }
                    }
                }
                break;
            }

            case 3:
            {
                printf(
                    "\n>  MÓDULO DAS DISCIPLINAS:\n"); // aqui dentro vou fazer as opções do módulo de disciplinas

                break;
            }

            default:
                printf("Opção inválida!\n");
            }
        } while (opcao != 0);
    }

    return 0;
}

// Funções:

void menuGeral()
{
    printf(">    PROJETO ESCOLA\n");
    printf("0 - Sair.\n");
    printf("1 - Aluno.\n");
    printf("2 - Professor.\n");
    printf("3 - Disciplina.\n");
}
void menuAluno()
{
    printf("0 -  Voltar.\n");
    printf("1 -  Cadastrar Aluno.\n");
    printf("2 -  Listar Alunos.\n");
    printf("3 -  Excluir Aluno.\n");
    printf("4 -  Atualizar Aluno.\n");
}
void atualizarAluno()
{
    printf("0  -  Voltar\n");
    printf("1 - Mudar a matrícula\n");
    printf("2 - Mudar o nome\n");
    printf("3 - Mudar o sexo\n");
    printf("4 - Mudar a data de nascimento\n");
    printf("5 - Mudar o CPF\n");
    printf("6 - Refazer Cadastro\n");
}
void menuProfessor()
{
    printf("0 -  Voltar.\n");
    printf("1 -  Cadastrar Professor.\n");
    printf("2 -  Listar Professores.\n");
    printf("3 -  Excluir Professor.\n");
    printf("4 -  Atualizar Professor.\n");
}