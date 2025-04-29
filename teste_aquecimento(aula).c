#include <stdio.h>
#include <string.h>
int main()
{
	int menu = 0;
	char lista[100] = {'\0'};
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
			if (lista[0] != '\0')
				strcat(lista, " ");
			strcat(lista, nome);
			break;
		};
		case (2):
		{
			char nome[100];
			int k, i, j;
			printf("digite o nome para remover\n");
			scanf("%s", nome);

			for (i = 0; lista[i] != '\0'; i = (k + 1))
			{
				j = 0;
				k = i;
				char temp[100];
				while (lista[k] != ' ' && lista[k] != '\0')
				{
					temp[j] = lista[k];
					j++;
					k++;
				}
				temp[j] = '\0';
				if (strcmp(temp, nome) == 0)
				{
					if (lista[k] == ' ')
						strcpy(&lista[i], &lista[k + 1]);
					else
						strcpy(&lista[i], &lista[k]);
				}
			}

			break;
		}
		case (3):
		{
			printf("%s\n", lista);
			break;
		}
		case (4):
		{
			printf("\n\t tchau!!!\n");
			break;
		}
		}
	}
	return 0;
}
