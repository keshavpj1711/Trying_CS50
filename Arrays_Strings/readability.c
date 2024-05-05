// The Problem

// You’ll implement a program that calculates the approximate grade level 
// needed to comprehend some text. Your program should print as output “Grade X” 
// where “X” is the grade level computed, rounded to the nearest integer. 
// If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), 
// your program should output “Grade 16+” instead of giving the exact index number. 
// If the grade level is less than 1, your program should output “Before Grade 1”.

// Background

// A number of “readability tests” have been developed over the years 
// that define formulas for computing the reading level of a text. 
// One such readability test is the Coleman-Liau index. 
// The Coleman-Liau index of a text is designed to output that (U.S.) grade level 
// that is needed to understand some text. The formula is

// Formula

// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text, and 
// S is the average number of sentences per 100 words in the text.

#include <math.h>
#include <stdio.h>

int main(void)
{
    // So our first problem to tackle is to take a big string as input.
    int max_size = 400;
    char str[max_size];
    int num_chars = 0;

    // Taking input 
    printf("Enter paragraph: ");
    fgets(str, max_size, stdin);

    // In this program i am not taking note of actual length of the string 
    int num_letters=0, num_words=0, num_sentences=0;

    // Punctuations that mark end of sentences are 
    // ['!', '.', '?']

    // So we are going to look for first occurence of '\n'
    // By this we will find the len of out input string.
    while (str[num_chars] != '\n') {
        // Now inside this loop we can find other stuff to move on to next step
        // Like number of letters 
        // We could have used ASCII values but why take the pain of memorizing that
        if ((str[num_chars] >= 'A' && str[num_chars] <= 'Z') || (str[num_chars] >= 'a' && str[num_chars] <= 'z')) {
            num_letters++;
        }
        // Checking for number of spaces to guess the number of words
        else if (str[num_chars] == ' ') {
            num_words++;
        }
        // Checking for the mentioned punctuations to get the number of sentences
        else if (str[num_chars] == '!'||str[num_chars] == '?'||str[num_chars] == '.') {
            num_sentences++;
        }

        // incrementing as well as counting the number of chars
        // Basically we are using it as a flag as well as counter
        num_chars++;
    }

    // At the end since num_words is equal to num_spaces+1 so,
    num_words++;

    // printf("Number of chars: %d\n", num_chars);
    // printf("Number of letter: %d\n", num_letters);
    // printf("Number of words: %d\n", num_words);
    // printf("Number of sentences: %d\n", num_sentences);

    // Calculating L and S in Coleman-Liau index
    // For logic of L and S refer to above explanation mentioned in the begining
    float L = (num_letters/(float)num_words)*100.0;
    float S = (num_sentences/(float)num_words)*100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Rounding to nearest integer
    int grade_level = round(index);

    // Applying the conditions required by the question
    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else if (index > 16) {
        printf("Grade 16+");
    }
    else {
        printf("Grade %d\n", grade_level);
    }
}

