// Average of the scores you enter

// NOTE: 
// One thing to note is that you don't want to do this 
// scanf("%d\n", &somevar)
// the value that you enter first goes to somevar
// then we need to press enter which gives a new line to 
// satisfy the \n.

// So no \n in scanfs until you have some actual use case for it


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

// Function to get average for elements in arrays
float get_avg(int len, int array[])
{
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum / (float) len; // This is how we typecast in C
}