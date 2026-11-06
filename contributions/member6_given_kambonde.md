# Member 6 Contribution Record

## Student Details
- Name: Given Kambonde
- Student Number: 226068528

## Role
Functions, Integration and Validation

## Contribution Summary
I developed the main program and menu that join all the modules into one system, and I was responsible for the shared input validation that every module relies on.

## Work Completed
- Wrote `main.c`, which contains `main()` and `displayMainMenu()`.
- Built the main menu loop: Employee, Budget, Supplier, Asset, Reports and Exit. Each option calls the matching module's menu, and option 6 exits cleanly.
- Handled invalid main menu choices with an error message instead of crashing.
- Worked on the shared validation routines in `utils.c` and `utils.h`:
  - `readInt()` reads a whole number safely and rejects letters and mixed input.
  - `readPositiveInt()` requires a value greater than 0 (used for IDs).
  - `readNonNegativeFloat()` rejects negative and non-numeric amounts (used for salaries, budgets and values).
  - `readText()` rejects empty or whitespace-only text.
- Integrated the module headers so all files compile together into one program.

## Logic Used
The main menu runs in a `do ... while` loop that keeps showing the menu until the user chooses 6. A `switch` statement sends each choice to the correct module. All numeric input is read as text with `fgets` and converted with `strtol` / `strtod`, so invalid input is caught and the user is asked again.

## Concepts Used
Menu-driven design, modular programming (separate `.c` and `.h` files), `switch`, loops, input validation.

## Testing Performed
- Entered letters and out-of-range numbers at the main menu and confirmed an error message appears and the menu is shown again.
- Opened every module from the main menu and returned to it.
- Confirmed option 6 exits the program cleanly.

## Commit Count
My commits are recorded in the repository's Git history.

## Notes
The shared input functions in `utils.c` are used by all modules. Member 7 coordinated the integration and final testing of the complete system.
