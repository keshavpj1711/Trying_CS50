// Average of the scores you enter

#include <stdio.h>

float get_avg(int len, int array[]);

int main(void)
{
    // Taking the length of the array as input 
    int array_len;
    printf("Enter the number of scores to enter: \n");
    scanf("%d", &array_len);

    // Creating array of size n
    int scores[array_len];

    // Inserting values in array
    for (int i = 0; i < array_len; i++) {
        printf("Score %d: ", i);
        scanf("%d", &scores[i]);
    }

    // Printing out average
    printf("Average: %.2f", get_avg(array_len, scores));
}

float get_avg(int len, int array[])
{
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum / (float) len; // This is how we typecast in C
}