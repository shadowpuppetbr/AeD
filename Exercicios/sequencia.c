#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    char **resposta = malloc(sizeof(char) * n * 8);
    char **referencia;

    for (int i = 0; i < *returnSize; i++)
    {
        if (n % 3)
            strcpy(resposta[i], "Fizz");
        if (n % 5)
            strcat(resposta[i], "Buzz");

        strcpy(resposta[i], n);
    }
    referencia = resposta;
    return referencia;
}

int main(int argc,char *argv[])
{
    int returnSize = argc;
    for (int i = 0; i < argc; i++){
        int n = atoi(argv[i]);   
        printf("%s\n", fizzBuzz(n, returnSize)[i]);
    }
}