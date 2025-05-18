#include <stdio.h>
#include <string.h>

int isPalindrome(int x);
int main(int argc, char const* argv[]) {
    int x[3] = { 121, -121, 1234567899 };
    for (int i = 0; i < 3; i++) {
        printf("%d\n", isPalindrome(x[i]));
    }
    return 0;
}

int isPalindrome(int x) {
    char str[10];
    sprintf(str, "%d", x);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}