#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "reports.h"
#include "utils.h"

/* Employee data stored by the employee module (parallel arrays) */
static int   employeeIDs[MAX_EMPLOYEES];
static char  employeeNames[MAX_EMPLOYEES][50];
static char  employeeDepartments[MAX_EMPLOYEES][30];
static float employeeBasic[MAX_EMPLOYEES];
static float employeeHousing[MAX_EMPLOYEES];
static float employeeTransport[MAX_EMPLOYEES];
static int   employeeCount = 0;

int addEmployee(int ids[], char names[][50], char departments[][30],
                float basicSalaries[], float housingAllowances[],
                float transportAllowances[], int count)
{
    int id;
    int i;
    char name[50];
    char department[30];
    float basic, housing, transport;

    if (count >= MAX_EMPLOYEES)
    {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return count;
    }

    id = readPositiveInt("Enter Employee ID: ");

    /* Check for duplicate Employee ID */
    for (i = 0; i < count; i++)
    {
        if (ids[i] == id)
        {
            printf("Employee ID already exists. Employee not added.\n");
            return count;
        }
    }

    readText("Enter Employee Name: ", name, sizeof(name));
    readText("Enter Employee Department: ", department, sizeof(department));

    basic = readNonNegativeFloat("Enter Basic Salary: N$");
    housing = readNonNegativeFloat("Enter Housing Allowance: N$");
    transport = readNonNegativeFloat("Enter Transport Allowance: N$");

    ids[count] = id;
    strcpy(names[count], name);
    strcpy(departments[count], department);
    basicSalaries[count] = basic;
    housingAllowances[count] = housing;
    transportAllowances[count] = transport;

    printf("Employee added successfully.\n");

    return count + 1;
}

void displayEmployees(int ids[], char names[][50], char departments[][30],
                      float basicSalaries[], float housingAllowances[],
                      float transportAllowances[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No employees to display.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========" );

    for (i = 0; i < count; i++)
    {
        printf("\nEmployee ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Department: %s\n", departments[i]);
        printf("Basic Salary: N$%.2f\n", basicSalaries[i]);
        printf("Housing Allowance: N$%.2f\n", housingAllowances[i]);
        printf("Transport Allowance: N$%.2f\n", transportAllowances[i]);
        printf("Total Salary: N$%.2f\n",
               calculateSalary(basicSalaries[i],
                               housingAllowances[i],
                               transportAllowances[i]));
    }
}

int searchEmployee(int ids[], char names[][50], char departments[][30],
                   float basicSalaries[], float housingAllowances[],
                   float transportAllowances[], int count, int searchID)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (ids[i] == searchID)
        {
            printf("\nEmployee found!\n");
            printf("Employee ID: %d\n", ids[i]);
            printf("Name: %s\n", names[i]);
            printf("Department: %s\n", departments[i]);
            printf("Basic Salary: N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance: N$%.2f\n", housingAllowances[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowances[i]);
            printf("Total Salary: N$%.2f\n",
                   calculateSalary(basicSalaries[i],
                                   housingAllowances[i],
                                   transportAllowances[i]));

            return i;
        }
    }

    printf("\nEmployee with ID %d not found.\n", searchID);
    return -1;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void showEmployeeReport(void)
{
    employeeReport(employeeIDs, employeeNames, employeeDepartments,
                  employeeBasic, employeeHousing, employeeTransport,
                  employeeCount);
}

void employeeMenu(void)
{
    int choice;
    int searchID;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT ==========" );
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Return to Main Menu");
        printf("\n========================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                employeeCount = addEmployee(employeeIDs, employeeNames,
                                            employeeDepartments, employeeBasic,
                                            employeeHousing, employeeTransport,
                                            employeeCount);
                break;

            case 2:
                displayEmployees(employeeIDs, employeeNames,
                                 employeeDepartments, employeeBasic,
                                 employeeHousing, employeeTransport,
                                 employeeCount);
                break;

            case 3:
                if (employeeCount == 0)
                {
                    printf("No employees to search.\n");
                    break;
                }
                searchID = readPositiveInt("Enter Employee ID to search: ");
                searchEmployee(employeeIDs, employeeNames,
                               employeeDepartments, employeeBasic,
                               employeeHousing, employeeTransport,
                               employeeCount, searchID);
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }

    } while (choice != 4);
}
