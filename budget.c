#include <stdio.h>
#include <string.h>
#include "budget.h"

char department[MAX_DEPARTMENTS][50];
float allocated[MAX_DEPARTMENTS];
float expenditure[MAX_DEPARTMENTS];

int budgetCount = 0;

void addBudget()
{
    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("Maximum number of departments reached.\n");
        return;
    }

    printf("\nEnter department name: ");
    scanf(" %49[^\n]", department[budgetCount]);

    printf("Enter allocated budget: N$");
    scanf("%f", &allocated[budgetCount]);

    if (allocated[budgetCount] < 0)
    {
        printf("Budget cannot be negative.\n");
        return;
    }

    expenditure[budgetCount] = 0;

    budgetCount++;

    printf("Budget added successfully!\n");
}

void displayBudgets()
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budgets have been added.\n");
        return;
    }

    printf("\n============= BUDGET INFORMATION =============\n");

    for (i = 0; i < budgetCount; i++)
    {
        float remaining;

        remaining = allocated[i] - expenditure[i];

        printf("\nDepartment: %s\n", department[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", expenditure[i]);
        printf("Remaining Budget: N$%.2f\n", remaining);

        if (remaining >= 0)
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: EXCEEDED BUDGET\n");
        }
    }
}

void searchBudget()
{
    char searchName[50];
    int i;
    int found = 0;

    printf("\nEnter department name to search: ");
    scanf(" %49[^\n]", searchName);

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(department[i], searchName) == 0)
        {
            printf("\nDepartment found!\n");
            printf("Department: %s\n", department[i]);
            printf("Allocated Budget: N$%.2f\n", allocated[i]);
            printf("Expenditure: N$%.2f\n", expenditure[i]);
            printf("Remaining Budget: N$%.2f\n",
                   allocated[i] - expenditure[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Department not found.\n");
    }
}

void budgetSummary()
{
    int i;
    float totalAllocated = 0;
    float totalExpenditure = 0;

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated = totalAllocated + allocated[i];
        totalExpenditure = totalExpenditure + expenditure[i];
    }

    printf("\n============= BUDGET SUMMARY =============\n");
    printf("Total Allocated: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining: N$%.2f\n",
           totalAllocated - totalExpenditure);

    printf("\nDepartments exceeding budget:\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (expenditure[i] > allocated[i])
        {
            printf("- %s\n", department[i]);
        }
    }
}

void budgetMenu()
{
    int choice;

    do
    {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Budget Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                searchBudget();
                break;

            case 4:
                budgetSummary();
                break;

            case 5:
                printf("Exiting Budget Management...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);
}