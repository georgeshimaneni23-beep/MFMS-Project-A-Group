#include <stdio.h>

#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(int ids[], char names[][50], char departments[][30],
                   float basicSalaries[], float housingAllowances[],
                   float transportAllowances[], int count)
{
    int i;
    float totalSalary = 0;
    float highestSalary;
    float lowestSalary;

    if (count == 0)
    {
        printf("\n========== EMPLOYEE REPORT ==========" );
        printf("\nNo employees have been registered.\n");
        return;
    }

    highestSalary = calculateSalary(basicSalaries[0], housingAllowances[0], transportAllowances[0]);
    lowestSalary = highestSalary;

    for (i = 0; i < count; i++)
    {
        float salary = calculateSalary(basicSalaries[i], housingAllowances[i], transportAllowances[i]);
        totalSalary += salary;

        if (salary > highestSalary)
        {
            highestSalary = salary;
        }

        if (salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }

    printf("\n========== EMPLOYEE REPORT ==========" );
    printf("\nTotal Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", totalSalary / count);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);
}

void budgetReport(void)
{
    budgetSummary();
}

void supplierReport(void)
{
    printf("\n========== SUPPLIER REPORT ==========" );
    displaySuppliers();
}

void assetReport(int assetIDs[], char assetNames[][50], char assetTypes[][30],
                float purchaseValues[], char departments[][30],
                char conditions[][30], int count)
{
    printf("\n========== ASSET REPORT ==========" );
    displayAssets(assetIDs, assetNames, assetTypes, purchaseValues,
                  departments, conditions, count);
}

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("              REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                showEmployeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                showAssetReport();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
