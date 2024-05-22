// In the game of Scrabble, players create words to score points, 
// and the number of points is the sum of the point values of each letter in the word.
// "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
// 1, 3, 3, 2, 1, 4, 2,	4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10

#include <stdio.h>
#include <ctype.h>

// Storing the characs
const char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Storing the points wrt those characs
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2,	4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes for our functions
int find_char(char c);

int main(void)
{
    // Taking input from player 1 and 2
    char player1[50], player2[50];
    printf("Player 1: ");
    fgets(player1, 50, stdin); // Reads charac until newline or 49 charac
    printf("Player 2: ");
    fgets(player2, 50, stdin);

    // Changing our inputs to upper
    // And calculating points 
    int points1 = 0, points2 = 0;

    for (int i; i < 50; i++) {
        player1[i] = toupper(player1[i]);
        points1 += find_char(player1[i]);
        player2[i] = toupper(player2[i]);
        points2 += find_char(player2[i]);
    }

    // Comparing results
    if (points1>points2) {
        printf("Player1 Wins!!\n");
    }
    else if (points1<points2) {
        printf("Player2 Wins!!\n");
    }
    else {
        printf("Tie\n");
    }
}

// This function finds char and return it's respective points
int find_char(char c)
{
    for (int i = 0; i < 26; i++) {
        if (c == LETTERS[i])
        {
            return POINTS[i];
        }
        else {
            return 0;
        }
    }
    return 0;
}