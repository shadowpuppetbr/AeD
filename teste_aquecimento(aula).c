#include<stdio.h>
#include<string.h>
int main(){
	int menu;
	char lista[100];
	while(menu !=4 ){
		printf("1 add nome \n2 remove nome \n3 lista \n4 sair\n");
		scanf("%d", &menu);
		
		switch (menu){
			case (1):{
				char nome[100];
				printf("digite o nome\n");
				scanf("%s", nome);
				strcat(lista, nome);
				strcat(lista, "_");
				break;
				};
			case (2):{
				char nome[100];
				
				printf("digite o nome para remover\n");
				scanf("%s", nome);
				int j = strcmp(lista, &nome[0]);
				for ( int i=0;  j != 0   ; i++ ){
					j = strcmp(lista, &nome[i]);
					if (j==1){
							
						}
					}
				
				break;
				}	
			case (3):{
				printf("%s", lista);
				break;
				}
			case (4):{
				printf("\n\t tchau!!!");
				break;
				}
			}
	}
	return 0;
}
