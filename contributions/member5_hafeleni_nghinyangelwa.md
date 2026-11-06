# Member 5 Contribution Record

## Student Details
- Name: Hafeleni Nghinyangelwa
- Student Number: 226070042

## Role
Reports

## Contribution Summary
I developed the reports module, which gathers data from the employee, budget, supplier and asset modules and presents it as reports through a Reports menu.

## Work Completed
- Wrote `reports.c` and `reports.h` for the reports module.
- Created `employeeReport()` to calculate and display the total number of employees and the average, highest and lowest salary. Each salary is worked out with `calculateSalary()` (basic + housing + transport).
- Created `budgetReport()`, which displays the budget summary from the budget module.
- Created `supplierReport()`, which displays the supplier list.
- Created `assetReport()`, which displays the asset register.
- Created `reportsMenu()`, the menu that lets the user choose which report to view or return to the main menu.
- Used `readInt()` from `utils.c` so invalid menu input is handled safely.

## Logic Used (Employee Report)
The first employee's salary is used as the starting highest and lowest value. A loop then goes through all employees, adds each salary to a running total, and updates the highest and lowest whenever a larger or smaller salary is found. The average is the total divided by the number of employees. If no employees exist, the report shows a message instead of dividing by zero.

## Concepts Used
Loops, conditions, calculations, data aggregation, functions, `switch` menu.

## Testing Performed
- Opened each report with no data entered and confirmed a sensible message is shown.
- Added employees, budgets, suppliers and assets, then confirmed each report shows the stored data.
- Checked the average, highest and lowest salary against the entered values.
- Tested invalid menu choices and letters; the menu rejects them and asks again.

## Commit Count
My commits are recorded in the repository's Git history.

## Notes
Reports are generated from the data held in memory, so they always reflect the data entered in the current run of the program.
