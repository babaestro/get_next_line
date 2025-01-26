# get_next_line

Get Next Line is a project that involves creating a function to read a line from a file descriptor. This function allows you to read text from a file, standard input, or even a network connection, line by line.

## Function Prototype

```c
char *get_next_line(int fd);
```

The function takes a file descriptor (`fd`) as a parameter and returns a string containing the next line from the file.

## Key Features

- Reads from file descriptors one line at a time
- Handles files, standard input, and other sources
- Memory leak-free implementation
- Manages multiple file descriptors simultaneously

## Technical Aspects

- Uses static variables to keep track of the reading position between function calls
- Implements buffer management for efficient reading
- Handles lines of varying lengths
- Deals with different line endings (newline character or EOF)

## Compilation

To compile the project, use the following command:

```bash
cc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

Replace `<size>` with your desired buffer size.

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

This example opens a file, reads it line by line using get_next_line, prints each line, and then closes the file.

## Skills Developed

- File descriptor manipulation
- Buffer management
- Basic parsing
- Memory management
- Static variables usage

Get Next Line is an essential project for understanding file I/O operations and memory management in C programming.
