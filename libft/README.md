# Libft - My Custom C Library

**Score:** 100/100

## About

Libft is the first project of the 42 cursus. The goal: rebuild the C standard library from scratch.

This isn't just about reinventing the wheel — it's about understanding how the wheel works. By recoding functions like `strlen`, `memset`, or `calloc`, you gain a deep understanding of memory management, pointer arithmetic, and data structures. This library becomes the foundation for all future C projects at 42.

## Implemented Functions

### Part 1 - Libc Re-implementation

These functions mimic the standard C library:

- **String Manipulation:** `ft_strlen`, `ft_strcpy`, `ft_strdup`, `ft_strjoin`, `ft_strchr`, `ft_strncmp`, etc.
- **Memory Manipulation:** `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`, `ft_bzero`
- **Conversion:** `ft_atoi` (ASCII to Integer), `ft_itoa` (Integer to ASCII)
- **Character Checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

### Part 2 - Additional Utilities

Functions that handle tasks often needed but missing from the standard library:

- **String Utils:** `ft_substr`, `ft_strtrim`, `ft_split` (creates an array of strings from a delimiter)
- **Functional Programming:** `ft_strmapi`, `ft_striteri` (applying functions to string characters)
- **File Descriptor Output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

## Compilation & Usage

```bash
make        # Compiles the library and generates libft.a
make clean  # Removes object files (.o)
make fclean # Removes object files and the library
make re     # Re-compiles everything from scratch
```

### How to use in your project

Include the header and link the static library during compilation:

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello 42");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

```bash
gcc main.c -L. -lft -o my_program
```

## What I Learned

- **Memory Management:** Understanding `malloc` and `free` to prevent memory leaks
- **Pointer Arithmetic:** Manipulating data directly via pointers
- **Makefile:** Creating a solid build system
- **Reading documentation:** Actually understanding what each function is supposed to do before coding it

---

*Project developed at 42 Lausanne*
