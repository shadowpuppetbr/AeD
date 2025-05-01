#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int menu = 0;
	char lista[100] = {'\0'};
	char *lista_d = malloc(sizeof(char));
	*lista_d = '\0';
	while (menu != 4)
	{
		printf("1 add nome \n2 remove nome \n3 lista \n4 sair\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case (1):
		{
			char nome[100] = {'\0'};
			printf("digite o nome\n");
			scanf("%s", nome);

			lista_d = realloc(lista_d, (strlen(lista_d) + strlen(nome)) * sizeof(char) + 2);

			// while (lista_d[0] != ' ')
			// 	strcpy(&lista_d[0], &lista_d[1]);

			if (lista_d[0] != '\0')
				strcat(lista_d, " ");
			strcat(lista_d, nome);
			break;
		};
		case (2):
		{
			char nome[100];
			int k, i, j;
			printf("digite o nome para remover\n");
			scanf("%s", nome);

			for (i = 0; lista_d[i] != '\0'; i = k)
			{
				j = 0;
				k = i;
				char temp[100];
				while (lista_d[k] != ' ' && lista_d[k] != '\0')
				{
					temp[j++] = lista_d[k++];
				}
				temp[j] = '\0';

				if (lista_d[k] == ' ')
					k++;

				if (strcmp(temp, nome) == 0)
				{
					memmove(&lista_d[i], &lista_d[k], strlen(&lista_d[k]) + 1);

					i = 0;
					continue;
				}
			}

			break;
		}
		case (3):
		{
			printf("%s\n", lista_d);
			break;
		}
		case (4):
		{
			printf("\n\t tchau!!!\n");
			break;
		}
		}
	}
	free(lista_d);
	return 0;
}
