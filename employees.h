#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

int addEmployee(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count
);

void displayEmployees(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count
);

int searchEmployee(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count,
    int searchID
);

float calculateSalary(float basic, float housing, float transport);

void employeeMenu(void);
void showEmployeeReport(void);

#endif
