// In the game of Scrabble, players create words to score points, 
// and the number of points is the sum of the point values of each letter in the word.
// "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
// 1, 3, 3, 2, 1, 4, 2,	4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10

#include <stdio.h>

// Storing the characs
const char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Storing the points wrt those characs
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2,	4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes for our functions

int main(void)
{
        // Taking input from player 1 and 2
    char player1[50], player2[50];
    printf("Player 1: ");
    fgets(player1, 50, stdin); // Reads charac until newline or 49 charac
    printf("Player 2: ");
    fgets(player2, 50, stdin);

    // Comparing the two inputs 
}