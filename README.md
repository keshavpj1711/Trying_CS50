# Trying_CS50

## What are some things I actually learnt that should be kept in mind

### Code related stuff

- When we initialize a variable in C it stores a garbage value at first.
    - Not like GO which initializes the value to be zero itself if nothing is assigned.
- Using printf for debugging is ok sometimes but, 
    - main problem with that is we have to compile and run the program again and again to check for errors
    - **Learning the proper use of debugger is very important**.
- Each string ends in a **/0**, basically this **\0**(also known as NUL) marks the end of a string.
    - So each and every string is n+1 bytes if you have n characters in the string.
    - This NUL is different from NULL
- In C, we must use single quote to represent single characters
- Using command line arguements in C:   
    ```c
    #include <stdio.h>

    int main(int argc, char *argv[])
    {
        printf("This is the passed arguement: %s", argv[1]);
    }

    // when running the output you give the cmd line argument like
    // ./a.out Hello
    // where argv[0] is program name and,
    // argv[1] is the passed argument
    ```

## Realization(Understanding)

- Now while I was getting to know command line arguments in C one thing clicked, that these **argc and argv** are only **responsible for those flags and other arguments** that we give when running programs in terminal.
    - Example: when running `pacman -Syu` this is basically that argv, also when running `figlet anystring` this anystring is the argv here.
    - Another intresting thing was, remember setting those environment variables we only set those to access the so called program from any location via our terminal, so that we don't have to type its full location to run it. 