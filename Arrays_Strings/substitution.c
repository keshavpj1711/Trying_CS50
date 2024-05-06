// What you actually need to do:
    // Write a program which takes a Key as command line argument (example: NQXPOMAFTRHLZGECYJIUWSKDVB)
    // this key is then used to scramble the text accordingly like: 
    // A (the first letter of the alphabet) should be converted into N (the first character of the key) and so on,

    // Your program will then promt the user to enter the message to be encrypted
    // Output will be the encrypted message preserving the casing of each letter.


// Things to keep in mind
    // Your program must accept a single command-line argument, 
    // the key to use for the substitution. The key itself should be case-insensitive, 
    // so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.

    // If your program is executed without any command-line arguments or 
    // with more than one command-line argument, your program should print an error message of your choice 
    // (with printf) and return from main a value of 1 (which tends to signify an error) immediately.

    // If the key is invalid (as by not containing 26 characters, containing any character 
    // that is not an alphabetic character, or not containing each letter exactly once), your program 
    // should print an error message of your choice (with printf) and return from main a value of 1 immediately.

    // Your program must preserve case: 
    // capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.

    // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int is_key_allalpha(char str[], int len);
int is_alpha_repeating(char str[], int len);

int main(int argc, string argv[])
{
    int len_key = strlen(argv[1]);
    
    // Checking for a valid key 
    // if argv[1] is empty
    if (argv[1] == NULL) {
        printf("Usage: ./substitution key\n");
        return 1; // This is kind of our exit status code
    } 
    // if key is not 26 chars long
    else if (len_key != 26) {
        printf("Key should be 26 characters long\n");
        return 1;
    }
    // checking for alphabets
    else if (is_key_allalpha(argv[1], len_key) == 0) {
        printf("All characters in the key should be alphabets\n");
        return 1;
    }
    // checking if any alpha occurs more than once
    else if (is_alpha_repeating(argv[1], len_key) == 0) {
        printf("Each alphabet should occur only once\n");
        return 1;
    }
    else {
        // This is where we will actually proceed
        
    }

}

int is_key_allalpha(char str[], int len)
{
    // what i want to do is if any of the char is not alpha
    // we return a zero value
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int is_alpha_repeating(char str[], int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (toupper(str[i]) == toupper(str[j])) {
                return 0;
            }
        }
    }
    return 1;
}