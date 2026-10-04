# Member 1 Contribution Record

## Student Details
- Name: Rachel Nelumbu
- Student Number: 225049511
- GitHub Username: 225049511-Nelumbu

## Role
Employee Management

## Contribution Summary
I developed the employee management module, including the employee storage design, the add, display and search functions, the salary calculation and the duplicate ID check.

## Work Completed
- Wrote `employees.c` and `employees.h` for the employee module.
- Created `addEmployee()` to read employee details, check for duplicate IDs and store them in arrays.
- Created `displayEmployees()` to display all employees with their total salary.
- Created `searchEmployee()` to find an employee by ID using a loop.
- Created `calculateSalary()` to return basic salary + housing allowance + transport allowance.
- Added the Member 1 section to the project README.

## Testing Performed
- Manual testing by running the program.
- Added employees, displayed them and searched by ID.
- Tested invalid input: negative salary, empty name, letters instead of numbers and a duplicate employee ID.
- Each invalid input was rejected with an error message, and valid employees were stored and shown with their total salary.

## Commit Count
I made 3 commits of my own:
- `07001cc` – Add employee structure and employee storage array
- `6573d51` – Validate input and prevent duplicate employee IDs
- `6cd4416` – Add Member 1 section to README

## Notes
After my commits, `employees.c` was modified and integrated with the rest of the system by other group members (employee menu, reports link, and shared input validation through `utils.c`).