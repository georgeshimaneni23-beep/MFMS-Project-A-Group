# Member 3 Contribution – Heilly Sitali

Student: Heilly Sitali  
Student Number: 226134792  
Role: Supplier Management

## Work Completed

I was responsible for the Supplier Management module (`suppliers.c`) in the MFMS project.

My work included:

- Reviewed the existing Supplier Management code.
- Updated the `getPositiveInteger()` function to handle the end of input correctly.
- Replaced the original `fgets()` statement with an `if` condition that exits cleanly when `fgets()` returns `NULL`.
- Compiled the complete MFMS program using GCC.
- Tested the Supplier Management module.
- Tested adding suppliers.
- Tested duplicate supplier IDs.
- Tested empty supplier names.
- Tested listing suppliers.
- Tested searching for suppliers by ID.
- Tested invalid numeric input.
- Tested searching for suppliers by name.
- Tested searching for a supplier that does not exist.
- Tested returning from Supplier Management to the main menu.
- Committed and pushed the updated `suppliers.c` file to the GitHub repository.
- Created this contribution record.

## Code Change

The `getPositiveInteger()` function was updated to:

```c
if (fgets(input, sizeof(input), stdin) == NULL)
{
    exit(0);
}