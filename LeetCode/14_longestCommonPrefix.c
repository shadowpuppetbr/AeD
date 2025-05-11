#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main()
{
    char *strs[] = {"aaba", "aaa", "aa", "aa", "aa"};
    printf("%s\n", longestCommonPrefix(strs, 5));
}
char *longestCommonPrefix(char **strs, int strsSize)
{
    int len = strlen(strs[0]);
    int maxSizeOfAns = len;
    if (len == 0)
    {
        return "";
    };
    char *res = malloc(sizeof(char) * (len + 1));
    char *backup = malloc(sizeof(char) * (len + 1));
    if (strsSize == 1)
    {
        int j;
        for (j = 0; j < len; j++)
            res[j] = strs[0][j];
        res[j] = '\0';
    }
    else
    {
        for (int i = 0; i < strsSize - 1; i++)
        {

            char *str1 = strs[i];
            char *str2 = strs[i + 1];
            int j;
            for (j = 0; j < len && j <= maxSizeOfAns && str1[j] == str2[j]; j++)
                res[j] = str1[j];
            res[j] = '\0';
            if (maxSizeOfAns == 0)
                return "";
            if (maxSizeOfAns < strlen(res))
                return backup;
            maxSizeOfAns = strlen(res);
            strcpy(backup, res);
        }
    }
    return res;
}