#include <stdio.h>
#include <stdlib.h>

#define TAM_PESSOA (10 * sizeof(char) + sizeof(int) + 10 * sizeof(char))
void menu(int *pBuffer);
void adicionarPessoa(void *pBuffer);

int main() {
  //   void* pBuffer = malloc(2 * sizeof(int) + TAM_PESSOA);
  void *pBuffer = malloc(2 * sizeof(int));

  // inicializa o buffer
  ((int *)pBuffer)[0] = 0;  // menu
  ((int *)pBuffer)[1] = 0;  // quantidade de pessoas na agenda

  // LOOP principal
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
        ((int *)pBuffer)[1] = ((int *)pBuffer)[1] + 1;
        printf("quantidade de pessoas 1: %d \n", *((int *)pBuffer + 1));
        printf("quantidade de pessoas 2: %d \n", ((int *)pBuffer)[1]);

        pBuffer = realloc(pBuffer,
                          2 * sizeof(int) + TAM_PESSOA * ((int *)pBuffer)[1]);
        printf("Digite o nome:");
        scanf("%s", (char *)pBuffer + (2 * sizeof(int)));
        printf("Digite a idade:");
        scanf("%d", (int *)pBuffer + (2 * sizeof(int)) + 10 * sizeof(char));
        printf("Digite o e-mail:");
        scanf("%s", (char *)pBuffer + (2 * sizeof(int)) + 10 * sizeof(char) +
                        sizeof(int));
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
        for (void *p = ((int *)pBuffer + 2); p != NULL; p = p + TAM_PESSOA) {
          printf("Nome: %s\n", (char *)p);
          printf("Idade: %d\n", *(int *)(p + 10 * sizeof(char)));
          printf("E-mail: %s\n\n",
                 (char *)p + 10 * sizeof(char) + 2 * sizeof(int));
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