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

## Project Structure
```text
MFMS-Project-A-Group/
├── main.c              # Entry point and main menu
├── employees.c         # Employee management logic
├── employees.h         # Employee prototypes
├── budget.c            # Budget management logic
├── budget.h            # Budget prototypes
├── suppliers.c         # Supplier management logic
├── suppliers.h         # Supplier prototypes
├── assets.c            # Asset management logic
├── assets.h            # Asset prototypes
├── reports.c           # Reporting logic
├── reports.h           # Report prototypes
├── utils.c             # Shared input validation routines
├── utils.h             # Utility function declarations
├── README.md           # Project documentation
├── tests/              # Demo/test inputs (if present)
└── contributions/      # Member contribution records
```

## Compilation Instructions
Use GCC to compile the system:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utils.c -o mfms
```

## How to Run
```bash
./mfms
```

## Notes
- The application is menu-driven and runs from the terminal.
- Input validation prevents invalid numbers, empty entries, and negative values in the relevant modules.
- Data is stored in memory while the program is running.
- Reports are generated from the data in the employee, budget, supplier, and asset modules.

## Repository
https://github.com/georgeshimaneni23-beep/MFMS-Project-A-Group
