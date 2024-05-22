# Basic Stuff 

## Opening and closing files

```c
// Open the file for reading
FILE *fp = fopen("data.txt", "r");

// The file can be opened in different modes 
// fopen(filename, mode);

// File closing 
fclose("data.txt");
```

## Reading and writing 

```c
// Reading 
fread(ptr, size, count, file_pointer);

// Writing
fwrite(ptr, size, count, file_pointer)
```

To know more about usage of fread and fwrite check volumne multiplier program.
By manipulation of bytes as that's how data is stored in .wav files