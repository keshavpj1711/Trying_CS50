// Basically we need to achieve this:
//    #  #
//   ##  ##
//  ###  ###
// ####  ####
// and it's height should be according to user input

#include <stdio.h>

// function to print space 
void space(int n){
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

int main(void)
{
    // Taking user input until user inputs a number greater than or equal to 0
    int input;
    do {
        printf("Enter a number: \n");
        scanf("%d", &input);
    }while (input < 0);

    // This main loop is to change from one row to another
    for (int i = 0; i < input; i++) {
        // to print the initial spaces
        space(input-i+1);

        // to print the "#" accordingly
        for (int j = 0; j < i+1; j++){
            printf("#");
        }

        // Since we need to have two spaces between the walls
        space(2);

        // again to print "#"
        for (int j = 0; j < i+1; j++){
            printf("#");
        }

        // for spaces at the end 
        space(input-i+1);

        // finally changing to next line
        printf("\n");
    }
}