// here we will use the knowledge of ASCII values to convert text to uppercase

#include <stdio.h>
#include <string.h>

int main(void)
{
    // Taking input
    char str[50];    
    printf("Before: ");
    fgets(str, 50, stdin);

    int len = strlen(str);

    printf("After: ");
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i] - 32); // This basically alters the ASCII value to it's uppercase counterpart
        }
        else {
            printf("%c", str[i]);
        }
    }
}