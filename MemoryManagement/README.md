# Memory Management — Store Emails Dynamically

Brief
-----
C program that stores email addresses for a cohort using dynamic allocation (`malloc` for the pointer array and each string), demonstrates `free()` usage, removes duplicates using a function, and shows shrinking of the allocated array via `realloc()`. Also demonstrates use of function pointers to call display and duplicate-removal functions.

Goals
-----------------
- Uses `malloc()` for pointer array and for each string.
- Uses `free()` to release memory and demonstrates `realloc()` for shrinking.
- Implements function pointers to modularize display & duplicate removal.

Compile & run
-------------
```bash
cd MemoryManagement
```

```bash
gcc -Wall -Wextra -o memory_management memory_management.c
./memory_management
```
