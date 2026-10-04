# Municipal Financial Management System

## Course
PAP521S – Programming in Practice

## Project
Project A: Municipal Financial Management System

## Group Number
Group 3

## Group Members and Roles

| No. | Name | Student Number | Role |
|---|---|---:|---|
| 1 | Rachel Grace Nelumbu | 225049511 | Employee Management |
| 2 | Virinao Kangumine | 225116358 | Budget Management |
| 3 | Heilly Sitali | 226134792 | Supplier Management |
| 4 | Johannes David | 225158787 | Asset Management |
| 5 | Hafeleni Nkandela | TBD | Reports |
| 6 | Given Shiimbunde | TBD | Functions, Integration and Validation |
| 7 | George Shimaneni | 225018497 | Testing, Documentation and Git Coordination |

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
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utils.c -o mfms
```

## How to Run

```bash
./mfms
```

The program will display a main menu. Use the number keys to navigate:
- **1** – Employee Management
- **2** – Budget Management
- **3** – Supplier Management
- **4** – Asset Management
- **5** – Reports
- **6** – Exit

## Individual Responsibilities

### Member 1 – Employee Management (Rachel Grace Nelumbu, 225049511)
**Files:** employees.c, employees.h, utils.c (shared)

**Functions developed:**
- `addEmployee()` – reads and validates employee details and stores them in arrays
- `displayEmployees()` – displays all stored employees with total salary
- `searchEmployee()` – searches for an employee by ID
- `calculateSalary()` – returns basic salary + housing + transport allowance

**Concepts used:** arrays, strings (`strcpy`, `strlen`, `strcspn`), functions, loops, conditions

**Validation:** rejects negative salaries, empty names, invalid numbers and duplicate IDs

### Member 2 – Budget Management (Virinao Kangumine, 225116358)
**Files:** budget.c, budget.h, utils.c (shared)

**Functions developed:**
- `addBudget()` – adds a department budget with validation
- `displayBudgets()` – shows all budgets with status (within or exceeded)
- `searchBudget()` – searches a budget by department name
- `recordExpenditure()` – records spending against a budget and warns if exceeded
- `budgetSummary()` – generates a summary of all budgets and exceeded departments

**Concepts used:** arrays, string comparison (`strcmp`), input validation, calculations

**Validation:** rejects negative budgets, empty department names, and duplicate departments

### Member 3 – Supplier Management (Heilly Sitali, 226134792)
**Files:** suppliers.c, suppliers.h

**Functions developed:**
- `addSupplier()` – adds a supplier with ID, name, email, telephone, and location
- `displaySuppliers()` – lists all suppliers
- `searchSupplier()` – searches by supplier ID
- `searchSupplierByName()` – searches by supplier name
- `getPositiveInteger()` – reads and validates positive integer input
- `isEmpty()` – checks if text is empty or whitespace

**Concepts used:** structures, arrays of structures, input validation, string handling

**Validation:** rejects empty fields, non-numeric IDs, zero or negative IDs

### Member 4 – Asset Management (Johannes David, 225158787)
**Files:** assets.c, assets.h, utils.c (shared)

**Functions developed:**
- `addAsset()` – adds an asset with ID, name, type, value, department, and condition
- `displayAssets()` – lists all assets
- `searchAsset()` – searches for an asset by ID
- `assetMenu()` – provides the asset management menu interface

**Concepts used:** arrays (parallel), input validation, loops, conditions

**Validation:** rejects negative purchase values, empty fields, duplicate asset IDs

### Member 5 – Reports (Hafeleni Nkandela)
**Files:** reports.c, reports.h (partial), utils.c (shared)

**Functions developed:**
- `employeeReport()` – displays total employees, average/highest/lowest salary
- `budgetReport()` – displays budget summary
- `supplierReport()` – displays supplier list
- `assetReport()` – displays asset list
- `reportsMenu()` – menu to select reports

**Concepts used:** loops, calculations, data aggregation

### Member 6 – Functions, Integration and Validation (Given Shiimbunde)
**Files:** main.c, reports.h, utils.h, utils.c

**Functions developed:**
- `main()` – entry point and main menu loop
- `displayMainMenu()` – displays the system menu
- Shared input validation routines in `utils.c`:
  - `readInt()` – reads a signed integer safely
  - `readPositiveInt()` – reads a positive integer
  - `readNonNegativeFloat()` – reads a non-negative float
  - `readText()` – reads text and rejects empty/whitespace-only input

**Concepts used:** menu-driven design, input validation, modular function design

### Member 7 – Testing, Documentation and Git Coordination (George Shimaneni, 225018497)
**Files:** README.md, contributions/ folder, all files (coordination)

**Tasks performed:**
- Set up the GitHub repository
- Added all members as collaborators
- Created member step-by-step guides
- Implemented the shared input utility module (`utils.c`, `utils.h`)
- Coordinated merging of all member contributions
- Ensured the project compiles without warnings
- Tested all modules end-to-end
- Prepared technical documentation
- Verified Git commit history and contributor records

## Project Notes
- All data is stored in static arrays and is not persisted between program runs.
- Input validation prevents common errors such as invalid numbers, empty fields, and negative values where appropriate.
- The system uses parallel arrays for data storage in employee and asset modules.
- Reports are generated dynamically from the data stored in memory.
- The project follows a modular design with separate files for each major feature.

## Repository
https://github.com/georgeshimaneni23-beep/MFMS-Project-A-Group
