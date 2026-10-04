#include <stdio.h>
#include <string.h>

#include "budget.h"
#include "utils.h"

static char department[MAX_DEPARTMENTS][50];
static float allocated[MAX_DEPARTMENTS];
static float expenditure[MAX_DEPARTMENTS];
static int budgetCount = 0;

static int findDepartment(const char name[])
{
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(department[i], name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void addBudget(void)
{
    char name[50];
    float amount;

    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("Maximum number of departments reached.\n");
        return;
    }

    readText("\nEnter department name: ", name, sizeof(name));

    if (findDepartment(name) != -1)
    {
        printf("A budget for this department already exists.\n");
        return;
    }

    amount = readNonNegativeFloat("Enter allocated budget: N$");

    strcpy(department[budgetCount], name);
    allocated[budgetCount] = amount;
    expenditure[budgetCount] = 0;
    budgetCount++;

    printf("Budget added successfully!\n");
}

void recordExpenditure(void)
{
    char name[50];
    int index;
    float amount;

    if (budgetCount == 0)
    {
        printf("\nNo budgets have been added yet.\n");
        return;
    }

    readText("\nEnter department name: ", name, sizeof(name));

    index = findDepartment(name);
    if (index == -1)
    {
        printf("Department not found.\n");
        return;
    }

    amount = readNonNegativeFloat("Enter expenditure amount: N$");
    expenditure[index] += amount;

    printf("Expenditure recorded. Total expenditure for %s: N$%.2f\n",
           department[index], expenditure[index]);

    if (expenditure[index] > allocated[index])
    {
        printf("WARNING: %s has exceeded its allocated budget!\n", department[index]);
    }
}

void displayBudgets(void)
{
    int i;
    float remaining;

    if (budgetCount == 0)
    {
        printf("\nNo budgets have been added.\n");
        return;
    }

    printf("\n============= BUDGET INFORMATION =============\n");

    for (i = 0; i < budgetCount; i++)
    {
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

void searchBudget(void)
{
    char searchName[50];
    int index;
    float remaining;

    if (budgetCount == 0)
    {
        printf("\nNo budgets have been added.\n");
        return;
    }

    readText("\nEnter department name to search: ", searchName, sizeof(searchName));

    index = findDepartment(searchName);
    if (index == -1)
    {
        printf("Department not found.\n");
        return;
    }

    remaining = allocated[index] - expenditure[index];

    printf("\nDepartment found!\n");
    printf("Department: %s\n", department[index]);
    printf("Allocated Budget: N$%.2f\n", allocated[index]);
    printf("Expenditure: N$%.2f\n", expenditure[index]);
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

void budgetSummary(void)
{
    int i;
    int exceeded = 0;
    float totalAllocated = 0;
    float totalExpenditure = 0;

    printf("\n============= BUDGET REPORT =============\n");

    if (budgetCount == 0)
    {
        printf("No budgets have been added.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += allocated[i];
        totalExpenditure += expenditure[i];
    }

    printf("Total Allocated: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments exceeding budget:\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (expenditure[i] > allocated[i])
        {
            printf("- %s (over by N$%.2f)\n", department[i],
                   expenditure[i] - allocated[i]);
            exceeded++;
        }
    }

    if (exceeded == 0)
    {
        printf("None\n");
    }
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== BUDGET MANAGEMENT ==========" );
        printf("\n1. Add Department Budget");
        printf("\n2. Record Expenditure");
        printf("\n3. Display Budgets");
        printf("\n4. Search Budget by Department");
        printf("\n5. Budget Summary");
        printf("\n6. Return to Main Menu");
        printf("\n=====================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                recordExpenditure();
                break;

            case 3:
                displayBudgets();
                break;

            case 4:
                searchBudget();
                break;

            case 5:
                budgetSummary();
                break;

            case 6:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }

    } while (choice != 6);
}
