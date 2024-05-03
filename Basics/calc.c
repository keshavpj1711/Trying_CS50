#include <stdio.h>

float add(float x, float y);
float multiply(float x, float y);
float subtract(float x, float y);
float divide(float x, float y);

int main(void)
{
    // Taking two numbers as input
    float a, b;
    printf("Enter num1: \n");
    scanf("%f", &a);
    printf("Enter num2: \n");
    scanf("%f", &b);

    // Asking the user for a choice 
    int choice;
    printf("What do you want to do?\n1. add\n2. subtract\n3. multiply\n4. divide\nChoice: ");
    scanf("%d", &choice);

    // Defining a variable for result
    float result;

    if (choice == 1)
    {
        result = add(a, b);
        printf("Answer: %.2f\n", result);
    }    
    else if (choice == 2)
    {
        result = subtract(a, b);
        printf("Answer: %.2f\n", result);
    } 
    else if (choice == 3)
    {
        result = multiply(a, b);
        printf("Answer: %.2f\n", result);
    } 
    else if (choice == 4)
    {
        result = divide(a, b);
        printf("Answer: %.2f\n", result);
    } 
    else {
        printf("Not a valid choice\n");
    }
}

float add(float x, float y){
    return x + y;
}

float subtract(float x, float y){
    return x - y;
}

float divide(float x, float y){
    if (y == 0) {
        printf("Not divisible by 0\n");
    }
    return x / y;
}

float multiply(float x, float y){
    return x * y;
}