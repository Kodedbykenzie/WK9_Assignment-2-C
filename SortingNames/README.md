# Sorting Names

Brief
-----
C program that sorts a list of full names in ascending or descending order using bubble sort. The user inputs the names and types `asc` or `desc` to pick the order. Sorting is performed by a `bubbleSort` function that accepts a comparator function pointer.

Goals
-----------------
- Uses bubble sort for string sorting.
- Uses comparator function pointers (`ascending` / `descending`).
- Designed to handle up to 20 names (adjustable by `n`).

Compile & run
-------------
```bash
cd SortingNames
```

```bash
gcc -Wall -Wextra -o sorting_names sorting_names.c
./sorting_names
```
