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