#include <stdio.h>

int areOccurrencesEqual(char *s);

int main()
{
    char *s = "zpfupfkmsuistzmtkijj";
    printf("%d\n", areOccurrencesEqual(s)); // expects: 1
    return 0;
}

int areOccurrencesEqual(char *s)
{
    int count = 0, countB = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count = 0;
        for (int j = 0; s[j] != '\0'; j++)
        {
            // conta sempre que vê um caractere igual
            if (s[j] == s[i])
            {
                count++;
            }
        }
        // retorna FALSO quando a quantidade de caracteres não são iguais E quando não é a primeira vez
        if (count != countB && countB != 0)
        {
            return 0;
        }
        // atualiza a contagem que apartir de agora deve ser sempre igual
        countB = count;
    }
    return 1;
}