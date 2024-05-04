# Trying_CS50

## What are some things I actually learnt that should be kept in mind

### General

- When we initialize a variable in C it stores a garbage value at first.
    - Not like GO which initializes the value to be zero itself if nothing is assigned.
- Using printf for debugging is ok sometimes but, 
    - main problem with that is we have to compile and run the program again and again to check for errors
    - **Learning the proper use of debugger is very important**.
- Each string ends in a **/0**, basically this **\0**(also known as NUL) marks the end of a string.
    - So each and every string is n+1 bytes if you have n characters in the string.
    - This NUL is different from NULL