#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMALUNO 2
#define TAMPROF 2
#define TAMDIS 2
/*TAMALUNO é o tamanho da struct de aluno
  TAMPROF é o tamanho da struct de professores
  TAMDIS é o tamanho da struct de disciplinas*/
// Declaração das structs
typedef struct data { // struct para data de nascimento
  int dia, mes, ano;
} nasc;

typedef struct { // struct aluno
  int matricula;
  char nome[50];
  char sexo;        // M -> masculino e F -> feminino
  struct data nasc; // chamada para struct da data de nascimento
  char cpf[15];
  int ativo; // váriavel auxiliar para verificação de exclusão de cadastro
} fichaluno;

typedef struct { // struct professor
  int ativo;
  int matricula;
  char nome[50];
  char sexo;
  struct data nasc; // chamada para struct da data de nascimento
  char cpf[16];
} fichaprof;

typedef struct fichadisc { // struct disciplinas
  char nome[50];
  int codigo;
  int semestre; // somente numeros
  char professor[50];
  fichaluno alunodisc; // chamada para a struct de alunos
} fichadisc;

// Declaração de funções
int menuprincipal(int opcao);
int menualuno(int opcaoaluno);
int menuprof(int opcaoprof);
int menudisciplina(int opcaodisc);

// Inicialização da função main
int main() {
  setlocale(LC_ALL,
            "Portuguese"); // função que permite a acentuação em português
  int opcao, i, opcaoaluno, opcaoprof, opcaodisc,
      dataerrada = 1, qtdalunos = 0, qtdprof = 0, qtddisc = 0, ln, cadastro,
      matricula, alunocadastrado, codigo,
      achou; // declaração de váriaveis auxiliares

  fichaluno alunos[TAMALUNO];    // declaração da struct alunos
  fichaprof prof[TAMPROF];       // declaração da struct professor
  fichadisc disciplinas[TAMDIS]; // declaração da struct discipinas
  do {
    setbuf(stdin, 0);
    opcao = menuprincipal(opcao);
    switch (opcao) {
      do {
      case 1: {
        opcaoaluno = menualuno(opcaoaluno);
        switch (opcaoaluno) {
        case 1: {
          setbuf(stdin, 0);
          printf("*****Cadastro de alunos*****\n");
          if (qtdalunos == TAMALUNO) // teste para bloquear a inserção de alunos
                                     // acima do limite
            printf("Lista de alunos cheia!");
          else {
            printf("Aluno %d:\n", qtdalunos + 1);
            do {
              printf("Informe a matricula: ");
              scanf("%d", &alunos[qtdalunos].matricula);
            } while (alunos[qtdalunos].matricula < 0); // teste de matrícula
            setbuf(stdin, 0);

            printf("Informe o nome: "); // cadastro do nome do aluno
            fgets(alunos[qtdalunos].nome, 49, stdin);
            ln = strlen(alunos[qtdalunos].nome) -
                 1; // processo para remoção do '\n' do fgets
            if (alunos[qtdalunos].nome[ln] == '\n')
              alunos[qtdalunos].nome[ln] = '\0';
            do { // cadastro do sexo do aluno (apenas com F ou M)
              printf("Informe o sexo com F ou M: ");
              scanf("%c", &alunos[qtdalunos].sexo);
              getchar();
            } while (alunos[qtdalunos].sexo != 'F' &&
                     alunos[qtdalunos].sexo != 'M');
            do {
              dataerrada = 0;
              printf("Informe a data de nascimento no formato dd mm aaaa: ");
              scanf("%d%d%d", &alunos[qtdalunos].nasc.dia,
                    &alunos[qtdalunos].nasc.mes, &alunos[qtdalunos].nasc.ano);
              if (alunos[qtdalunos].nasc.dia > 32 ||
                  alunos[qtdalunos].nasc.mes > 12 ||
                  alunos[qtdalunos].nasc.ano > 2022 ||
                  alunos[qtdalunos].nasc.ano < 1930)
                dataerrada++;
            } while (dataerrada > 0);
            getchar();
            printf("Informe o cpf corretamente: "); // cadastro de cpf do aluno
            fgets(alunos[qtdalunos].cpf, 15, stdin);
            ln = strlen(alunos[qtdalunos].cpf) - 1; // remoção do '\n' do fgets
            if (alunos[qtdalunos].cpf[ln] == '\n')
              alunos[qtdalunos].cpf[ln] = '\0';
            setbuf(stdin, 0);
            qtdalunos++;
            alunos[qtdalunos].ativo = 1;
            printf("\n");
            break;
          }
          getchar();
          break;
        }

        case 2: {
          printf("*****Listar alunos*****\n");
          if (qtdalunos == 0) { // teste para verificar se a matrícula existe
            printf("Nenhum aluno cadastrado!\n");
            break;
          } else {
            for (i = 0; i < qtdalunos; i++) { // listagem dos alunos sem ordem
              printf("Aluno %d:\n", i + 1);
              printf("Nome: %s\n", alunos[i].nome);
              printf("Matricula: %d\n", alunos[i].matricula);
              printf("Sexo: %c\n", alunos[i].sexo);
              printf("CPF: %s\n", alunos[i].cpf);
              printf("Data de nascimento: %d/%d/%d\n", alunos[i].nasc.dia,
                     alunos[i].nasc.mes, alunos[i].nasc.ano);
              printf("\n");
            }
          }
          break;
        }

        case 3: {
          printf("*****Atualizar aluno*****\n");
          printf("Informe a matricula que deseja Atualizar: ");
          scanf("%d", &matricula);
          for (i = 0; i < qtdalunos;
               i++) { // procura para ver se uma matrícula existe
            achou = 0;
            if (matricula == alunos[i].matricula) {
              achou++;
              printf("Informe os novos dados:\n");
              do {
                printf("Informe a matricula: ");
                scanf("%d", &alunos[i].matricula);
              } while (alunos[i].matricula < 0); // teste de matrícula
              getchar();
              printf("Informe o nome: ");
              fgets(alunos[i].nome, 49, stdin);
              ln = strlen(alunos[i].nome) - 1;
              if (alunos[i].nome[ln] == '\n')
                alunos[i].nome[ln] = '\0';
              do {
                printf("Informe o sexo com F ou M: ");
                scanf("%c", &alunos[i].sexo);
                getchar();
              } while (alunos[i].sexo != 'F' && alunos[i].sexo != 'M');

              do {
                dataerrada = 0;
                printf("Informe a data de nascimento no formato dd mm aaaa: ");
                scanf("%d%d%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes,
                      &alunos[i].nasc.ano);
                if (alunos[i].nasc.dia > 32 || alunos[i].nasc.mes > 12 ||
                    alunos[i].nasc.ano > 2022 || alunos[i].nasc.ano < 1930)
                  dataerrada++;
              } while (dataerrada > 0);
              getchar();
              printf("Informe o cpf corretamente: ");
              fgets(alunos[i].cpf, 15, stdin);
              ln = strlen(alunos[i].cpf) - 1;
              if (alunos[i].cpf[ln] == '\n')
                alunos[i].cpf[ln] = '\0';
              alunos[i].ativo = 1;
              printf("\n");
            }
            if (achou == 0) {
              printf("Aluno não encontrado ou inativo!\n");
            }
          }
          break;
        }
        case 4: {
          printf("Excluir aluno");
          break;
        }
        case 5: {
          printf("Saindo do setor de alunos...\n");
          break;
        }
        default: {
          printf("Opcao invalida!\n");
          break;
        }
        }
      }
      } while (opcaoaluno != 5);
      break;

      do {
        setbuf(stdin, 0);
      case 2: {
        opcaoprof = menuprof(opcaoprof);
        switch (opcaoprof) {
        case 1: { // cadastro de professores
          printf("Professor %d\n", qtdprof + 1);
          do {
            printf("Informe a matricula: ");
            scanf("%d", &prof[qtdprof].matricula);
          } while (prof[qtdprof].matricula < 0);
          setbuf(stdin, 0);

          printf("Informe o nome: ");
          fgets(prof[qtdprof].nome, 50, stdin);
          ln = strlen(prof[qtdprof].nome) - 1;
          if (prof[qtdprof].nome[ln] == '\n')
            prof[qtdprof].nome[ln] = '\0';

          do {
            printf("Informe o sexo com F ou M: ");
            scanf("%c", &prof[qtdprof].sexo);
          } while (prof[qtdprof].sexo != 'F' && prof[qtdprof].sexo != 'M');
          getchar();
          do {
            dataerrada = 0;
            printf("Informe a data de nascimento no formato dd mm aaaa: ");
            scanf("%d%d%d", &prof[qtdprof].nasc.dia, &prof[qtdprof].nasc.mes,
                  &prof[qtdprof].nasc.ano);
            if (prof[qtdprof].nasc.dia > 31 || prof[qtdprof].nasc.mes > 12 ||
                prof[qtdprof].nasc.ano > 2023 || prof[qtdprof].nasc.ano < 1920)
              dataerrada++;
          } while (dataerrada > 0);
          getchar();

          printf("Informe o cpf: ");
          fgets(prof[qtdprof].cpf, 15, stdin);
          ln = strlen(prof[qtdprof].cpf) - 1;
          if (prof[qtdprof].cpf[ln] == '\n')
            prof[qtdprof].cpf[ln] = '\0';
          getchar();
          prof[qtdprof].ativo = 1;
          printf("\n");
          ++qtdprof;
          setbuf(stdin, 0);
          break;
        }
        case 2: {
          printf("*****Listar professores*****\n");
          if (qtdprof == 0) { // teste para verificar se a matrícula existe
            printf("Nenhum professor cadastrado!\n");
            break;
          } else {
            for (i = 0; i < qtdprof; i++) { // listagem dos alunos sem ordem
              if (prof[i].ativo == 1) {
                printf("Professor %d:\n", i + 1);
                printf("Nome: %s\n", prof[i].nome);
                printf("Matricula: %d\n", prof[i].matricula);
                printf("Sexo: %c\n", prof[i].sexo);
                printf("CPF: %s\n", prof[i].cpf);
                printf("Data de nascimento: %d/%d/%d\n", prof[i].nasc.dia,
                       prof[i].nasc.mes, prof[i].nasc.ano);
                printf("\n");
              }
            }
          }
          break;
        }
        case 3: { // Atualizar professores
          if (qtdprof == 0) {
            printf("Nao existe nenhum cadastro de professores!");
            break;
          }
          printf("*****Atualizar professores*****\n");
          printf("Informe a matricula que deseja Atualizar: ");
          scanf("%d", &matricula);
          for (i = 0; i < qtdprof;
               i++) { // procura para ver se uma matrícula existe
            achou = 0;
            if (matricula == prof[i].matricula) {
              achou++;
              printf("Informe os novos dados:\n");
              do {
                printf("Informe a matricula: ");
                scanf("%d", &prof[i].matricula);
              } while (prof[i].matricula < 0); // teste de matrícula
              getchar();
              printf("Informe o nome: ");
              fgets(prof[i].nome, 49, stdin);
              ln = strlen(prof[i].nome) - 1;
              if (prof[i].nome[ln] == '\n')
                prof[i].nome[ln] = '\0';
              do {
                printf("Informe o sexo com F ou M: ");
                scanf("%c", &prof[i].sexo);
                getchar();
              } while (prof[i].sexo != 'F' && prof[i].sexo != 'M');

              do {
                dataerrada = 0;
                printf("Informe a data de nascimento no formato dd mm aaaa: ");
                scanf("%d%d%d", &prof[i].nasc.dia, &prof[i].nasc.mes,
                      &prof[i].nasc.ano);
                if (prof[i].nasc.dia > 32 || prof[i].nasc.mes > 12 ||
                    prof[i].nasc.ano > 2022 || prof[i].nasc.ano < 1930)
                  dataerrada++;
              } while (dataerrada > 0);
              getchar();
              printf("Informe o cpf corretamente: ");
              fgets(prof[i].cpf, 15, stdin);
              ln = strlen(prof[i].cpf) - 1;
              if (prof[i].cpf[ln] == '\n')
                prof[i].cpf[ln] = '\0';
              prof[i].ativo = 1;
              printf("\n");
            }
            if (achou == 0) {
              printf("Professor não encontrado ou inativo!\n");
            }
          }
          break;
        }
        case 4: {
          printf("Excluir profesores");
          break;
        }
        case 5: {
          printf("Saindo do setor de professores...\n");
          break;
        }
        default: {
          printf("Opcao invalida!\n");
          break;
        }
        }
      }
      } while (opcaoprof != 5);
      break;

      do {
      case 3: {
        opcaodisc = menudisciplina(opcaodisc);
        switch (opcaodisc) {
        case 1: {
          if (qtddisc == TAMDIS) {
            printf("Lista de discipinas cheia!");
            break;
          } else {
            do {
              printf("*****Cadastro de disciplinas*****\n");
              printf("Informe o codigo da disciplina: ");
              scanf("%d", &disciplinas[qtddisc].codigo);
            } while (disciplinas[qtddisc].codigo <
                     0); // teste de codigo da discipina
            getchar();

            printf("Informe o nome do professor: "); // nome do professor
            fgets(disciplinas[qtddisc].professor, 50, stdin);
            ln = strlen(disciplinas[qtddisc].professor) - 1;
            if (disciplinas[qtddisc].professor[ln] == '\n')
              disciplinas[qtddisc].professor[ln] = '\0';

            printf(
                "Informe o semestre somente com numeros: "); // semestre somente
                                                             // com numeros
            scanf("%d", &disciplinas[qtddisc].semestre);
            getchar();

            printf("Informe o nome da discipina: "); // nome da discipina
            fgets(disciplinas[qtddisc].nome, 50, stdin);
            ln = strlen(disciplinas[qtddisc].nome) - 1;
            if (disciplinas[qtddisc].nome[ln] == '\n')
              disciplinas[qtddisc].nome[ln] = '\0';
            printf("\n");
            qtddisc++;
            setbuf(stdin, 0);
            break;
          }
        } break;

        case 2: { // atualização de disciplinas
          if (qtddisc == 0) {
            printf("Nao existe nenhum cadasatro de disciplinas!\n");
            break;
          }
          printf("*****Atualizar disciplina*****\n");
          printf("Informe o codigo que deseja Atualizar: ");
          scanf("%d", &matricula);
          for (i = 0; i < qtddisc;
               i++) { // procura para ver se uma matrícula existe
            achou = 0;
            if (matricula == disciplinas[i].codigo) {
              achou++;
              setbuf(stdin, 0);
              printf("Informe os novos dados:\n");
              do {
                printf("Informe o novo codigo: ");
                scanf("%d", &disciplinas[i].codigo);
              } while (disciplinas[i].codigo < 0); // teste de matrícula
              getchar();
              printf("Informe o nome da disciplina: ");
              fgets(disciplinas[i].nome, 49, stdin);
              ln = strlen(disciplinas[i].nome) - 1;
              if (disciplinas[i].nome[ln] == '\n')
                disciplinas[i].nome[ln] = '\0';
              setbuf(stdin, 0);
              do {
                printf("Informe o semestre apenas com numeros: ");
                scanf("%d", &disciplinas[i].semestre);
                getchar();
              } while (disciplinas[i].semestre < 0 &&
                       disciplinas[i].semestre > 16);

              printf("Informe o nome do professor: ");
              fgets(disciplinas[i].professor, 49, stdin);
              ln = strlen(disciplinas[i].professor) - 1;
              if (disciplinas[i].professor[ln] == '\n')
                disciplinas[i].professor[ln] = '\0';
              printf("\n");
            }
            if (achou == 0) {
              printf("Disciplina nao encontrada!\n");
            }
          }
          break;
        }
        case 3: { // listagem das disciplinas
          if (qtddisc == 0)
            printf("Não existe nenhum cadastro de disciplinas!\n");
          else {
            for (i = 0; i < qtddisc; i++) { // listagem dos alunos sem ordem
              getchar();
              printf("Disciplina %d:\n", i + 1);
              printf("Nome da discipina: %s\n", disciplinas[i].nome);
              printf("Codigo: %d\n", disciplinas[i].codigo);
              printf("Nome do professor: %s\n", disciplinas[i].professor);
              printf("Semestre: %d\n", disciplinas[i].semestre);
              printf("\n");
            }
          }
          break;
        } break;

        case 4: {

          ("*****Listagem de dados dos alunos!*****\n");
          if (qtddisc == 0 || qtdalunos == 0) {
            printf("Não existe nenhum cadastro de disciplinas ou alunos!\n");
            break;
          }
          if (alunocadastrado == 0) {
            printf("Nao existe nenhum aluno cadastrado em uma disciplina!\n");
          } else {
            for (i = 0; i < alunocadastrado;
                 i++) { // listagem dos alunos cadastrados sem ordem
              getchar();
              printf("Nome da discipina: %s\n", disciplinas[i].nome);
              printf("Codigo: %d\n", disciplinas[i].codigo);
              printf("Nome do professor: %s\n", disciplinas[i].professor);
              printf("Semestre: %d\n", disciplinas[i].semestre);
              printf("\n");
              printf("Nome do aluno: %s\n", disciplinas[i].alunodisc.nome);
              printf("Matricula do aluno: %d\n",
                     disciplinas[i].alunodisc.matricula);
              printf("Sexo do aluno: %c\n", disciplinas[i].alunodisc.sexo);
              printf("CPF do aluno: %s\n", disciplinas[i].alunodisc.cpf);
              printf("Data de nascimento do aluno: %d/%d/%d\n",
                     disciplinas[i].alunodisc.nasc.dia,
                     disciplinas[i].alunodisc.nasc.mes,
                     disciplinas[i].alunodisc.nasc.ano);
              printf("\n");
            }
          }
          break;
        }

        case 5: {
          achou = 0;
          if (qtddisc == 0 || qtdalunos == 0) {
            printf("Nao existe nenhum aluno matriculado em uma disciplina!\n");
            break;
          }
          printf("*****Cadastro de alunos em uma disciplina*****\n");
          achou = 0;
          printf("Informe a matricula do aluno a ser adicionada: ");
          scanf("%d", &matricula);
          printf("Informe o codigo da disciplina para adicionar o aluno: ");
          scanf("%d", &codigo);

          for (ln = 0; ln < qtdalunos; ln++) {
            if (matricula == alunos[ln].matricula)
              achou++;
          }
          --ln;
          for (i = 0; i < qtddisc; i++) {
            if (codigo == disciplinas[i].codigo)
              achou++;
          }
          --i;
          if (achou > 1) {
            disciplinas[i].alunodisc = alunos[ln];
            printf("Aluno cadastrado com sucesso!\n");
            alunocadastrado++;
          } else
            printf("Aluno nao encontrado!\n");
          break;
        }

        case 6: {
          printf("Saindo do setor de disciplinas...\n");
          break;
        }

        default: {
          printf("Opcao invalida!\n");
          break;
        }
        }
      }
      } while (opcaodisc != 6);

      break;

    case 4: {
      printf("Saindo do programa...");
      break;
    }
    default: {
      printf("Opcao invalida!\n");
    }
    }
  } while (opcao != 4);
  return 0;
}

// função menu principal
int menuprincipal(int opcao) {
  printf("*****MENU DA ESCOLA*****\n");
  printf("Digite 1 para setor dos alunos:\n");
  printf("Digite 2 para setor dos professores\n");
  printf("Digite 3 para setor das disciplinas:\n");
  printf("Digite 4 para sair do programa:\n");
  scanf("%d", &opcao);
  return opcao;
}
// função menu aluno
int menualuno(int opcaoaluno) {
  printf("*****MENU DO ALUNO*****\n");
  printf("Digite 1 para cadastrar um aluno:\n");
  printf("Digite 2 para listar um aluno:\n");
  printf("Digite 3 para atualizar um aluno:\n");
  printf("Digite 4 para excluir um aluno:\n");
  printf("Digite 5 para sair do menu de alunos:\n");
  scanf("%d", &opcaoaluno);
  return opcaoaluno;
}
// função menu professor
int menuprof(int opcaoprof) {
  printf("*****MENU DO PROFESSOR*****\n");
  printf("Digite 1 para cadastrar um professor:\n");
  printf("Digite 2 para listar um professor:\n");
  printf("Digite 3 para atualizar um professor:\n");
  printf("Digite 4 para excluir um professor:\n");
  printf("Digite 5 para sair do setor de professores:\n");
  scanf("%d", &opcaoprof);
  return opcaoprof;
}
// função menu disciplina
int menudisciplina(int opcaodisc) {
  printf("*****MENU DA DISCIPLINA*****\n");
  printf("Digite 1 para cadasatrar uma disciplina nova:\n");
  printf("Digite 2 para atualizar uma disciplina:\n");
  printf("Digite 3 para listar discipinas SEM dados do aluno:\n");
  printf("Digite 4 para listar discipinas COM dados do aluno\n");
  printf("Digite 5 para adicionar um aluno a uma disciplina:\n");
  printf("Digite 6 para sair do menu de disciplinas:\n");
  scanf("%d", &opcaodisc);
  return opcaodisc;
}