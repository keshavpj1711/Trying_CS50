#include <stdio.h>

int main(void)
{
    int n = 5; 

    // Now what we want to do is look where this variable is actually stored
    printf("Address of n: %p", &n);
    
    // Basically this "%p" is the format specifier for looking at the address of something.
    // or where is this thing pointing basically a pointer
}