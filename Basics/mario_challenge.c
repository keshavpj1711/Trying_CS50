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
    // Taking user input 
    int input;
    do {
        printf("Enter a number: \n");
        scanf("%d", &input);
    }while (input < 0);

    for (int i = 0; i < input; i++) {
        space(input-i+1);

        for (int j = 0; j < i+1; j++){
            printf("#");
        }

        space(2);

        for (int j = 0; j < i+1; j++){
            printf("#");
        }

        space(input-i+1);
        printf("\n");
    }
}