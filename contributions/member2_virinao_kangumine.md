Member 2 – Budget Management

Name: Virinao Kangumine
Student Number: 225116358

Files: budget.c, budget.h
Shared file: utils.c

My Responsibility

I was responsible for developing the Budget Management part of the Municipal Financial Management System.

My module allows the user to add budgets, record expenditure, search for departments, display budgets and check whether a department is within or over its budget.

Functions I Developed

addBudget()

Adds a new department and its allocated budget.

It checks that:

The budget is not negative.
The department name is not empty.
The department does not already exist.
displayBudgets()

Displays all departments and their budget information.

It shows:

Department name
Allocated budget
Expenditure
Remaining budget
Budget status
searchBudget()

Searches for a department by name and displays its budget information.

I used strcmp() to compare the department name entered by the user with the names stored in the system.

recordExpenditure()

Allows the user to enter expenditure for a department.

It also checks whether the expenditure has gone over the allocated budget.

budgetSummary()

Shows the total allocated budget, total expenditure and remaining budget.

It also shows which departments have exceeded their budgets.

Concepts I Used

I used:

Arrays
Strings
strcmp()
Functions
Loops
if and if-else
Arithmetic calculations
Input validation
Budget Calculation

The remaining budget is calculated using:

remaining = allocated[i] - expenditure[i];
If the remaining amount is 0 or more, the department is:

WITHIN BUDGET
If the remaining amount is less than 0, the department is:

EXCEEDED BUDGET
Validation

My module checks for:

Negative budgets
Negative expenditure
Empty department names
Duplicate departments
Invalid number input
The shared utils.c functions are used to help with input validation.

Testing

I tested the module by:

Adding a valid department
Trying to add a duplicate department
Trying to enter an empty department name
Trying to enter a negative budget
Recording expenditure
Searching for a department
Checking departments that exceeded their budget
Viewing the budget summary
My Contribution

My contribution was the development of the Budget Management module, which helps the municipality keep track of departmental budgets and expenditure.

I also committed my work to the group's GitHub repository and worked with the other members to integrate the module into the main system.