#include <stdio.h>

int areOccurrencesEqual(char *s);

int main()
{
    char *s = "zpfupfkmsuistzmtkijj";
    printf("d", areOccurrencesEqual(s));
}

int areOccurrencesEqual(char *s)
{
    int count = 0, countB = 0, q_letras = 1;
    char letras[100] = {'\0'};

    for (int i = 0; s[i] != '\0'; i++)
    {
        letras[0] = *s;
        // cria o dicionario
        for (int d = 0; letras[d] != '\0'; d++)
        {

            if (letras[d] == s[i])
            {
                count = 0;
                // conta sempre que vê um caractere igual
                for (int j = 0; s[j] != '\0'; j++)
                {
                    if (s[i] == s[j])
                        count++;
                }
                // printf("%d\n", count);
                // retorna quando a quantidade de caracteres não são iguais
                if (count != countB && countB != 0)
                    return 0;

                countB = count;
            }
            while ()
            {
                letras[q_letras] = s[i];
                q_letras++;
            }
        }
    }
    return 1;
}