# Member 3 Contribution - Heilly Sitali
Student: Heilly Sitali
Student number: 226134792
Role: Supplier Management
## Contribution
I worked on the `supplier.c` module.
i updated the `getPositiveInteger()` function so that the program exits cleanly when `fgets()` reaches the end of input instead of continuing in a loop.
the change was :
```c
if (fgets(input, sizeof(input), stdin) == NULL)
{
    exit(0);
}