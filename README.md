# Municipal Financial Management System

A C-based command-line application for managing a municipality's financial records.

## Project Overview
This project provides a simple municipal accounting system with modules for:
- Employee management
- Budget tracking and expenditure monitoring
- Supplier management
- Asset management
- Reporting

It is designed as a multi-file C project for academic use and is structured around a main menu that routes to each management module.

## Course Information
**Course:** PAP521S – Programming in Practice  
**Group:** Group 3  
**Due:** 02 October 2026

## Group Members and Roles

| # | Name | Student ID | Role |
|---|------|-----------|------|
| 1 | Rachel Grace Nelumbu | 225049511 | Employee Management |
| 2 | Virinao Kangumine | 225116358 | Budget Management |
| 3 | Heilly Sitali | 226134792 | Supplier Management |
| 4 | Johannes David | 225158787 | Asset Management |
| 5 | Hafeleni Nkandela | TBD | Reports |
| 6 | Given Shiimbunde | TBD | Functions, Integration and Validation |
| 7 | George Shimaneni | 225018497 | Testing, Documentation and Git Coordination |

## Features
- Add, display, and search employees
- Calculate employee total salary from base salary + housing + transport allowances
- Manage budgets and record department expenditure
- Detect departments that are over budget
- Add, display, and search suppliers
- Add, display, and search assets
- Generate basic reports for employees, budgets, suppliers, and assets
- Input validation to reject invalid entries and handle edge cases

## Project Structure
```text
MFMS-Project-A-Group/
├── main.c              # Entry point and main menu
├── employees.c         # Employee management logic
├── employees.h         # Employee function prototypes
├── budget.c            # Budget management logic
├── budget.h            # Budget prototypes
├── suppliers.c         # Supplier management logic
├── suppliers.h         # Supplier prototypes
├── assets.c            # Asset management logic
├── assets.h            # Asset prototypes
├── reports.c           # Report generation logic
├── reports.h           # Report prototypes
├── utils.c             # Shared input validation helpers
├── utils.h             # Utility function declarations
├─�� README.md           # Project documentation
└── tests/              # Demo/test inputs (if present)
```

## Compilation
Use GCC to compile the project:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utils.c -o mfms
```

## Running
```bash
./mfms
```

Then follow the on-screen menu to navigate between modules.

## Key Implementation Details

### Modules
- **Employee Management** – Stores employee data in parallel arrays; supports adding, displaying, and searching by ID; calculates total salary.
- **Budget Management** – Manages department budgets and expenditure records; warns when a department exceeds its budget.
- **Supplier Management** – Maintains a list of suppliers with contact and location information; search by ID or name.
- **Asset Management** – Tracks municipal assets with ID, name, type, value, department, and condition.
- **Reports** – Generates summaries of employees (salary stats), budgets (expenditure summary), suppliers (supplier list), and assets (asset list).

### Input Validation
The project uses a utility module (`utils.c`) to provide safe input functions:
- `readInt()` – Reads a signed integer, rejects non-numeric input.
- `readPositiveInt()` – Reads an integer greater than zero.
- `readNonNegativeFloat()` – Reads a non-negative floating-point number.
- `readText()` – Reads text and rejects empty or whitespace-only input.

These functions eliminate common bugs such as infinite loops from invalid input.

## Notes
- This application is menu-driven and runs from the terminal.
- Data is stored in static arrays and is not persisted between program runs.
- Reports are generated from the data stored in each module at runtime.

## Repository
https://github.com/georgeshimaneni23-beep/MFMS-Project-A-Group
