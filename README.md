# Municipal Financial Management System

## Course
PAP521S – Programming in Practice

## Project
Project A: Municipal Financial Management System

## Group Number
[3]

## Group Members
- Member 1: Employee Management
- Member 2: Budget Management
- Member 3: Supplier Management
- Member 4: Asset Management
- Member 5: Reports
- Member 6: Functions, Integration and Validation
- Member 7: Testing, Documentation and Git Coordination

## System Features
- Employee management
- Budget management
- Supplier management
- Asset management
- Reports
- Input validation
- Search functions

## Compilation Instructions
Use GCC to compile the system:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## How to Run

```bash
./mfms
```

## Individual Responsibilities

### Member 1 - Employee Management (Rachel Grace Nelumbu, 225049511)
**Files:** employees.c, employees.h

**Functions developed:**
-'addEmployee()' - reads and validates employee details and stores them in arrays
-'displayEmployees()' - displays all stored employees with total salary
-'searchEmployee()' -searches for an employee by ID using a loop
-'calculateSalary()' - returns basic salary + housing + transport allowance

**Concepts used:** arrays, strings ('strcpy', 'strlen', 'strcspn'), functions, loops, conditions

**Validation:** rejects negative salaries, empty names, invalid numbers and duplicate IDs

**Testing performed:** added, displayed and searched employees; tested negative salary, empty name, letters instead of numbers and duplicate IDs