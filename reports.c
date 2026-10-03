#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"


void employeeReport(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count
)
{
    if (count == 0)
    {
        printf("\n========== EMPLOYEE REPORT ==========\n");
        printf("No employees have been registered.\n");
        return;
    }

    float totalSalary = 0;
    float highestSalary;
    float lowestSalary;

    highestSalary = calculateSalary(
        basicSalaries[0],
        housingAllowances[0],
        transportAllowances[0]
    );

    lowestSalary = highestSalary;

    for (int i = 0; i < count; i++)
    {
        float salary;

        salary = calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

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

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", totalSalary / count);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);
}


void budgetReport()
{
    printf("\n========== BUDGET REPORT ==========\n");
    printf("Budget report will use the budget records.\n");
}


void supplierReport()
{
    printf("\n========== SUPPLIER REPORT ==========\n");
    displaySuppliers();
}


void assetReport(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
)
{
    printf("\n========== ASSET REPORT ==========\n");

    displayAssets(
        assetIDs,
        assetNames,
        assetTypes,
        purchaseValues,
        departments,
        conditions,
        count
    );
}


void reportsMenu()
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

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEmployee report selected.\n");
                printf("Employee data will be connected here.\n");
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                printf("\nAsset report selected.\n");
                printf("Asset data will be connected here.\n");
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);
}