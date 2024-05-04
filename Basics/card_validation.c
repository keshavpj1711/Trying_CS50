// Basically we need to check for validity of a credit card
// Write a program that prompts the user for a credit card number and then reports (via printf) 
// whether it is a valid American Express, MasterCard, or Visa card number, 
// per the definitions of each’s format herein. 
// All American Express numbers start with 34 or 37; 
// most MasterCard numbers start with 51, 52, 53, 54, or 55 
// (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); 
// and all Visa numbers start with 4.
// So that we can automate some tests of your code, we ask that your program’s 
// last line of output be AMEX or MASTERCARD or VISA or INVALID, nothing more, nothing less.

// Luhn's Algorithm
// So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. 
// According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) 
// valid as follows:
//     Multiply every other digit by 2, starting with the number’s second-to-last digit, 
//     and then add those products’ digits together.
//     Add the sum to the sum of the digits that weren’t multiplied by 2.
//     If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), 
//     the number is valid!

// Algorithm developed to create cards according to this

// let’s try an example with David’s Visa: 4003600000000014.
//     For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:
//     4003600000000014
//     Okay, let’s multiply each of the underlined digits by 2:
//     1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
//     That gives us:
//     2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
//     Now let’s add those products’ digits (i.e., not the products themselves) together:
//     2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
//     Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):
//     13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
//     Yup, the last digit in that sum (20) is a 0, so David’s card is legit!


#include <stdio.h>
#include <math.h>

int get_sum(long int x);
int get_digits(long int a);
int get_card_type(long int y);

int main(void)
{
    // Taking input of card numeber
    long int card_no;
    printf("Enter your card number: \n");
    scanf("%ld", &card_no);

    // Thought process: 
    // So basically first of all i want to get hold of all the digits of the number 
    // Then hand pick the digits
        // First i am gonna get alternate numbers starting from second to last digit
        // Then i am gonna multiply each by 2 
        // Get the sum of there digits as shown in the example and store in sum1
        
        // Secondly we are gonna get the left over digits that we didn't multiply by 2 
        // Get there sum store in sum2

    // add sum1 and sum2 to check legitimacy

    // As i am done with checking actual validity there are some other parameters too 
    // like length of the card number 
    // it should be between 15(for American Express) and 16 digit length
    // For checking we also need to get the number of digits
    if (get_digits(card_no) < 15 || get_digits(card_no) > 16) {
        printf("INVALID\n");
    }
    else {
        // Now checking validity
        if (get_sum(card_no) == 0) {
            printf("INVALID\n");
        }
        else {
            // Checking for the type of card
            int card_type = get_card_type(card_no);

            if (card_type == 1){
                printf("American Express\n");
            }
            else if (card_type == 2) {
                printf("Master\n");
            }
            else if (card_type == 3){
                printf("Visa\n");
            }
            else {
                printf("Unknown provider\n");
            }
        }
    }

}

// So finally what this function does is check validity of the credit card 
int get_sum(long int x)
{
    int sum1 = 0; // sum of leftovers
    int sum2 = 0;

    int mod_alt_digit = 0;

    // Extracting digits 
    while(x != 0)
    {
        sum1 += x%10;
        x = x/10;
        // printf("%ld\n", x);

        mod_alt_digit = (x%10)*2;
        if (mod_alt_digit > 9){
            // Then break it into digits and then add to sum2
            // Since it'll always be a 2 digit number
            sum2 += (mod_alt_digit%10) + (mod_alt_digit/10);
        }
        else {
            sum2 += mod_alt_digit;
        }
        x = x/10;
        // printf("%ld\n", x);

    }

    int result = sum1+sum2;

    // printf("resultant sum : %d\n", result);

    if (result%10 == 0)
    {
        return 1;;
    }
    else {
        return 0;;
    }
}

// To count the number of digits
int get_digits(long int a)
{
    int count = 0;
    while (a != 0)
    {
        a = a/10;
        count++;
    }
    return count;
}


// Gets you the card type
int get_card_type(long int y)
{
    int digits = get_digits(y);
    long int num = 0;

    // Setting num to first two digits
    num = y / pow(10, digits-2);

    if (digits == 15){
        // printf("Num: %ld\n", num);
        if (num == 35 || num == 37) {
            return 1; // For American Express
        }
        else{
            return 0;
        }
    }
    else {
        if (num == 51 || num == 52 || num == 53 || num == 54 || num == 55) {
            return 2; // For Mastercard 
        }

        // Setting num to first digit
        num = y / pow(10, digits-1);
        // printf("Num: %ld\n", num);
        if (num == 4) {
            return 3; // For Visa
        }
        else {
            return 0;
        }
    }
}