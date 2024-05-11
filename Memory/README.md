# Memory

## Addresses

### What is the address of a variable

Basically each variable we store has some address in the memory and that address can be accessed using:
Let say we have a variable num so, `&num` will have its address

### How does address of a variable look like?

```c
#include <stdio.h>

int main(void)
{
    int n = 5; 

    // Now what we want to do is look where this variable is actually stored
    printf("Address of n: %p", &n);
    
    // Basically this "%p" is the format specifier for looking at the address of something.
    // or where is this thing pointing (basically a pointer)

    // For example here the printf returns 
    // Address of n: 0x7ffd5ec87124
}
```

## Pointers

### Declaring pointers 

```c
    // Syntax for declaring a pointer 
    int *p = &n; // This * is different from the star used below
```

### Understanding what actually pointers do 

```c
printf("p stores address of n: %p\n", p);
    // Whereas
    printf("Doing *p points to the value p holds: %d", *p);
    // The * used is here actually points towards something 
    // Like here it points to value of p (i.e it points to value of &n)
    // And &n hold the value i.e. 5
```

> Just remember the *(asterisk) has different meaning in both the places. If its used during declaration then it's used for **declaring pointer**, and if used anywhere else it's used for basically **pointing to some location**.

### Pointer Arithematic

```c
char *s = "Hi";

// Printing this 
printf("%c", *s);
printf("%c", *(s + 1));
printf("%c\n", *(s + 2));

// This basically prints: Hi!
```

### Strings and copying them 

```c
char *s = "hi!";
// Now let us do 
char *t = s;
// Basically what this does is now both s and t are pointing to same thing 
// And to confirm that, see 

t[0] = toupper(t[0]);
// Now you might expect it changes something in  t right

// Let's print s 
printf("%c", s[0]);
printf("%c\n", s[1]);

// What you observe is that s[0] is uppercase now
// This proves our above point that s and t points to 
// first charac of "hi!"
```

So as we see above copying string is not so simple. One way of copying strings is **declaring a memory chunk** of the req size **using malloc** and then adding each element using a loop.

But a beter way to this is **declaring the mem chunk**(using malloc) and directly **copying using `stcpy`** whose prototype is in string.h.

### Malloc and memory leaks

Now this malloc is basically used to acquire certain amount of memory manually.
For example we want to store a string "Hi!", it requires 4 blocks of memory and to assign it we do:

```c
// To use malloc you must include stdlib
char *s = malloc(n*sizeof(char) + 1);
// This sizeof tells you the size of something as the size of datatypes vary accross different machines.
```

Also whenever we call malloc we have to free it and if we don't free the allocated memory the situation is called **memmory leak**.

Actually to check such situations we use a tool known as valgrind. 
This tool is especially used for checking the memory related stuff.

To use valgrind we do: `valgrind ./compiled_output`