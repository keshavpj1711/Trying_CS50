#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n = 5; 

    // Now what we want to do is look where this variable is actually stored
    // printf("Address of n: %p", &n);
    
    // Basically this "%p" is the format specifier for looking at the address of something.
    // or where is this thing pointing basically a pointer

    // Syntax for declaring a pointer 
    int *p = &n; // This * is different from the star used below

    printf("p stores address of n: %p\n", p);
    // Whereas
    printf("Doing *p points to the value p holds: %d\n", *p);
    // The * used is here actually points towards something 
    // Like here it points to value of p (i.e it points to value of &n)
    // And &n hold the value i.e. 5

    char *s = malloc(3*sizeof(char) + 1);
    // Now we can assign some values to the memory
    s[0] = 'H';
    s[1] = 'i';
    s[2] = '!';
    s[3] = '\0'; // To mark the end of this string

    printf("Our made up string: %c%c%c\n", s[0], s[1], s[2]);
}   