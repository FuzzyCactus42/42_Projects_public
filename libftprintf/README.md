*This activity has been created as part of the 42 curriculum by hhailat.*

# ft_printf

## Description

ft_printf is my own version of the C function `printf`. The goal is to learn how variadic functions work in C (`<stdarg.h>`) and how to build a static library.

It is built as a library called `libftprintf.a` with one function:

```c
int ft_printf(const char *format, ...);
```

It prints to the standard output and returns the number of characters printed.

Supported conversions:

| Specifier | What it prints                    |
|-----------|-----------------------------------|
| `%c`      | a character                       |
| `%s`      | a string                          |
| `%p`      | a pointer in hexadecimal          |
| `%d` `%i` | a signed integer                  |
| `%u`      | an unsigned integer               |
| `%x` `%X` | a hexadecimal number (lower/upper)|
| `%%`      | a percent sign                    |

## Instructions

Build the library with:

```bash
make        # creates libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # rebuilds everything
```

Use it in your own program:

```c
#include "./printf_files/ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number %d, hex %x\n", "42", 42, 255);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o test
./test
```

## Algorithm and Data Structure

**Algorithm:** the program reads the format string once, from left to right.
- A normal character is printed right away.
- When it finds a `%`, it looks at the next character and calls the function for that conversion (`%d`, `%s`, ...).
- Every function returns how many characters it printed, and these are added up to give the return value.

**Why this choice:** it is simple and fast (each character is read only once), and it needs no `malloc`, so there are no memory leaks. Printing directly with `write` also avoids managing a buffer.

**Data structures:** no complex structure is needed.
- `va_list` is used to get the arguments one by one.
- A string like `"0123456789abcdef"` is used to convert numbers to digits, so the same function works for decimal and hexadecimal.

Numbers are printed with a recursive function: it divides the number by the base, prints the left part first, then the last digit. This prints the digits in the right order without a buffer.

## Resources

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Stack over flow](https://stackoverflow.com/)
- [Youtube](https://youtube.com)

**Use of AI:** AI was used to <describe the tasks, e.g. explain how `va_arg` works, suggest test cases, help write this README>. The code itself was written and tested by me.
