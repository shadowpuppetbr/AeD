#include <stdio.h>
#include <stdlib.h>

#define TAM_PESSOA 10 * sizeof(char) + sizeof(int) + 10 * sizeof(char)

void menu(int *pBuffer);
void adicionarPessoa(void *pBuffer);

int main() {
  //   void* pBuffer = malloc(2 * sizeof(int) + TAM_PESSOA);
  void *pBuffer = malloc(2 * sizeof(int));

  // inicializa o buffer
  ((int *)pBuffer)[0] = 0;  // menu
  ((int *)pBuffer)[1] = 0;  // quantidade de pessoas na agenda
  // --------------------------------LOOP principal
  while (*((int *)pBuffer) != 5) {
    printf(
        "1 - Adicionar Pessoa (Nome, Idade, Email)\n2 - Remover Pessoa\n"
        "3 - Buscar Pessoa\n4 - Listar todos\n5 - Sair\n\n");
    scanf("%d", ((int *)pBuffer));
    switch (*((int *)pBuffer)) {
      /* -----------------
      BLOCO DE ADICIONAR PESSOAS
      ----------------------- */
      case (1): {
        // soma 1 no contador de pessoas da agenda
        *((int *)pBuffer + 1) = *((int *)pBuffer + 1) + 1;

        // realoca o tamanho do buffer
        pBuffer = realloc(
            pBuffer, 2 * sizeof(int) + (TAM_PESSOA) * *((int *)pBuffer + 1));

        void *pInicio = pBuffer + 2 * sizeof(int);
        void *pNome = pInicio + ((*((int *)pBuffer + 1) - 1) * (TAM_PESSOA));
        void *pIdade = (pNome + 10 * sizeof(char));
        char *pEmail = (char *)pIdade + sizeof(int);

        printf("Digite o nome:");
        scanf("%s", (char *)pNome);
        printf("Digite a idade:");
        scanf("%d", (int *)pIdade);
        printf("Digite o e-mail:");
        scanf("%s", (char *)pEmail);

        break;
      }
      /* -----------------
      BLOCO DE REMOVER PESSOA
      ----------------------- */
      case (2): {
        break;
      }
      /* -----------------
      BLOCO DE BUSCAR PESSOA
      ----------------------- */
      case (3): {
        break;
      }
      /* -----------------
      BLOCO DE LISTAR TODOS
      ----------------------- */
      case (4): {
        printf("\n---------------\nQuantidade de pessoas adicionadas: %d\n",
               *((int *)pBuffer + 1));
        void *pInicio = pBuffer + 2 * sizeof(int);
        void *pFim = pInicio + *((int *)pBuffer + 1) * (TAM_PESSOA);
        for (; pInicio < pFim; pInicio = pInicio + (TAM_PESSOA)) {
          void *pNome = pInicio;
          void *pIdade = (pNome + 10 * sizeof(char));
          char *pEmail = (char *)pIdade + sizeof(int);

          printf("Nome: %s\n", (char *)pNome);
          printf("Idade: %d\n", *(int *)pIdade);
          printf("E-mail: %s\n\n", (char *)pEmail);
        }

        break;
      }
      /* -----------------
      SAIR DO PROGRAMA
      ----------------------- */
      case (5): {
        ((int *)pBuffer)[0] = 5;
        break;
      }
    }
  }
  return 0;
}