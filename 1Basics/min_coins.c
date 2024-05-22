// Write a C program which outputs the minimum number of coins if the input is the change amount
// The input is always in cents and we have only four coins
// penny(1 cent), nickel(5 cents), dime(10 cents), quarter(25 cents)

#include <stdio.h>

int main(void)
{
    // Taking input of how much change to give
    int change;
    // Note the change has to be input in cents 
    // let say you change is 1.13$ you have to enter as 113 
    do {
        printf("Enter the change amount in cents: \n");
        scanf("%d", &change);
    }while (change < 0);

    // Logic for seeing the numeber of coins required
    int coins = 0;
    int penny = 0, nickel = 0, dime = 0, quarter = 0;

    printf("Starting while loop\n");

    // What this does is it checks for the largest coin first and so on 
    // if the largest coin is subtracting with a postive result then we proceed
    // the if and else if provide the structure which is actually required
    // I also added the fucntionality to output the number of each coin required
    while (change != 0) {
        if (change-25 >= 0) {
            change -= 25;
            coins++;
            quarter++;
        }
        else if (change-10 >= 0){
            change -= 10;
            coins++;
            dime++;
        }
        else if (change-5 >= 0){
            change -= 5;
            coins++;
            nickel++;
        }
        else if (change-1 >= 0){
            change--;
            coins++;
            penny++;
        }
    }

    // Printing out the number of coins
    printf("\nMinimum coins required: %d\n", coins);
    printf("pennies: %d\nnickels: %d\ndimes: %d\nquarters: %d\n", penny, nickel, dime, quarter);
}