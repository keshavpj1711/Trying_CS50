#include<stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 10;
    int y = 20;

    // Calling the swap function 
    swap(&x, &y);
    // Here we pass the addresses because pointers want address to point to not actual values

    // Then printing the values of x and y
    printf("values: x = %d, y = %d\n", x, y);
}

void swap(int *a, int *b)
{
    int temp = 0;

    // Swapping begins
    temp = *a; 
    // storing the value to which a is pointing to another variable
    *a = *b; 
    // changing the value in of place where a is pointing to the value where b was pointing
    *b = temp; 
    // changing value to which b is pointing to temp var which stores the value where a what pointing
}
