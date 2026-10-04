#include <stdio.h>
#include <string.h>
#include "employees.h"

int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
char employeeDepartments[MAX_EMPLOYEES][30];
float employeeBasicSalaries[MAX_EMPLOYEES];
float employeeHousingAllowances[MAX_EMPLOYEES];
float employeeTransportAllowances[MAX_EMPLOYEES];
int employeeCount = 0;

static void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int addEmployee(int ids[], char names[][50], char departments[][30],
                float basicSalaries[], float housingAllowances[],
                float transportAllowances[], int count)
{
    if (count >= MAX_EMPLOYEES)
    {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return count;
    }

    int id;
    char name[50];
    char department[30];
    float basic, housing, transport;

    printf("Enter Employee ID: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid input for Employee ID.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    for (int i = 0; i < count; i++)
    {
        if (ids[i] == id)
        {
            printf("Employee ID already exists. Employee not added.\n");
            return count;
        }
    }

    printf("Enter Employee Name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Failed to read employee name.\n");
        return count;
    }
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0)
    {
        printf("Employee name cannot be empty. Employee not added.\n");
        return count;
    }

    printf("Enter Employee Department: ");
    if (fgets(department, sizeof(department), stdin) == NULL)
    {
        printf("Failed to read department.\n");
        return count;
    }
    department[strcspn(department, "\n")] = '\0';

    if (strlen(department) == 0)
    {
        printf("Department cannot be empty. Employee not added.\n");
        return count;
    }

    printf("Enter Basic Salary: ");
    if (scanf("%f", &basic) != 1)
    {
        printf("Invalid salary input.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    printf("Enter Housing Allowance: ");
    if (scanf("%f", &housing) != 1)
    {
        printf("Invalid housing allowance input.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    printf("Enter Transport Allowance: ");
    if (scanf("%f", &transport) != 1)
    {
        printf("Invalid transport allowance input.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    if (basic < 0 || housing < 0 || transport < 0)
    {
        printf("Salary values cannot be negative. Employee not added.\n");
        return count;
    }

    ids[count] = id;
    strcpy(names[count], name);
    strcpy(departments[count], department);
    basicSalaries[count] = basic;
    housingAllowances[count] = housing;
    transportAllowances[count] = transport;

    count++;

    printf("Employee added successfully.\n");
    return count;
}

void displayEmployees(int ids[], char names[][50], char departments[][30],
                      float basicSalaries[], float housingAllowances[],
                      float transportAllowances[], int count)
{
    if (count == 0)
    {
        printf("No employees to display.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========");

    for (int i = 0; i < count; i++)
    {
        printf("\nEmployee ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Department: %s\n", departments[i]);
        printf("Basic Salary: %.2f\n", basicSalaries[i]);
        printf("Housing Allowance: %.2f\n", housingAllowances[i]);
        printf("Transport Allowance: %.2f\n", transportAllowances[i]);
        printf("Total Salary: %.2f\n",
               calculateSalary(basicSalaries[i],
                               housingAllowances[i],
                               transportAllowances[i]));
    }
}

int searchEmployee(int ids[], char names[][50], char departments[][30],
                   float basicSalaries[], float housingAllowances[],
                   float transportAllowances[], int count, int searchID)
{
    for (int i = 0; i < count; i++)
    {
        if (ids[i] == searchID)
        {
            printf("\nEmployee found!\n");
            printf("Employee ID: %d\n", ids[i]);
            printf("Name: %s\n", names[i]);
            printf("Department: %s\n", departments[i]);
            printf("Basic Salary: %.2f\n", basicSalaries[i]);
            printf("Housing Allowance: %.2f\n", housingAllowances[i]);
            printf("Transport Allowance: %.2f\n", transportAllowances[i]);
            printf("Total Salary: %.2f\n",
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

void employeeMenu()
{
    int choice;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT ==========" );
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Return to Main Menu");
        printf("\n========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please try again.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                employeeCount = addEmployee(employeeIDs, employeeNames,
                                           employeeDepartments,
                                           employeeBasicSalaries,
                                           employeeHousingAllowances,
                                           employeeTransportAllowances,
                                           employeeCount);
                break;

            case 2:
                displayEmployees(employeeIDs, employeeNames,
                                employeeDepartments,
                                employeeBasicSalaries,
                                employeeHousingAllowances,
                                employeeTransportAllowances,
                                employeeCount);
                break;

            case 3:
            {
                int searchID;
                printf("Enter Employee ID: ");
                if (scanf("%d", &searchID) != 1)
                {
                    printf("Invalid Employee ID.\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                searchEmployee(employeeIDs, employeeNames,
                               employeeDepartments,
                               employeeBasicSalaries,
                               employeeHousingAllowances,
                               employeeTransportAllowances,
                               employeeCount, searchID);
                break;
            }

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}



































































































































































































































































"},{"content":"#include <stdio.h>
#include <string.h>
#include "assets.h"

int assetIDs[MAX_ASSETS];
char assetNames[MAX_ASSETS][50];
char assetTypes[MAX_ASSETS][30];
float purchaseValues[MAX_ASSETS];
char assetDepartments[MAX_ASSETS][30];
char assetConditions[MAX_ASSETS][30];
int assetCount = 0;

static void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int addAsset(int assetIDs[], char assetNames[][50], char assetTypes[][30],
             float purchaseValues[], char departments[][30],
             char conditions[][30], int count)
{
    if (count >= MAX_ASSETS)
    {
        printf("Cannot add more assets. Maximum limit reached.\n");
        return count;
    }

    printf("\n---- Add New Asset ----\n");

    printf("Enter Asset ID: ");
    if (scanf("%d", &assetIDs[count]) != 1)
    {
        printf("Invalid asset ID.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    for (int i = 0; i < count; i++)
    {
        if (assetIDs[i] == assetIDs[count])
        {
            printf("Asset ID already exists. Asset not added.\n");
            return count;
        }
    }

    printf("Enter Asset Name: ");
    if (fgets(assetNames[count], 50, stdin) == NULL)
    {
        printf("Failed to read asset name.\n");
        return count;
    }
    assetNames[count][strcspn(assetNames[count], "\n")] = '\0';

    printf("Enter Asset Type: ");
    if (fgets(assetTypes[count], 30, stdin) == NULL)
    {
        printf("Failed to read asset type.\n");
        return count;
    }
    assetTypes[count][strcspn(assetTypes[count], "\n")] = '\0';

    printf("Enter Purchase Value: ");
    if (scanf("%f", &purchaseValues[count]) != 1)
    {
        printf("Invalid purchase value.\n");
        clearInputBuffer();
        return count;
    }
    clearInputBuffer();

    while (purchaseValues[count] < 0)
    {
        printf("Purchase value cannot be negative.\n");
        printf("Enter Purchase Value: ");
        if (scanf("%f", &purchaseValues[count]) != 1)
        {
            printf("Invalid purchase value.\n");
            clearInputBuffer();
            return count;
        }
        clearInputBuffer();
    }

    printf("Enter Department: ");
    if (fgets(departments[count], 30, stdin) == NULL)
    {
        printf("Failed to read department.\n");
        return count;
    }
    departments[count][strcspn(departments[count], "\n")] = '\0';

    printf("Enter Condition: ");
    if (fgets(conditions[count], 30, stdin) == NULL)
    {
        printf("Failed to read condition.\n");
        return count;
    }
    conditions[count][strcspn(conditions[count], "\n")] = '\0';

    printf("Asset added successfully!\n");

    return count + 1;
}

void displayAssets(int assetIDs[], char assetNames[][50], char assetTypes[][30],
                  float purchaseValues[], char departments[][30],
                  char conditions[][30], int count)
{
    if (count == 0)
    {
        printf("No assets to display.\n");
        return;
    }

    printf("\n---- Asset List ----\n");

    for (int i = 0; i < count; i++)
    {
        printf("Asset ID: %d\n", assetIDs[i]);
        printf("Asset Name: %s\n", assetNames[i]);
        printf("Asset Type: %s\n", assetTypes[i]);
        printf("Purchase Value: %.2f\n", purchaseValues[i]);
        printf("Department: %s\n", departments[i]);
        printf("Condition: %s\n", conditions[i]);
        printf("--------------------\n");
    }
}

void searchAsset(int assetIDs[], char assetNames[][50], char assetTypes[][30],
                 float purchaseValues[], char departments[][30],
                 char conditions[][30], int count)
{
    if (count == 0)
    {
        printf("No assets to search.\n");
        return;
    }

    int searchID;

    printf("Enter Asset ID to search: ");
    if (scanf("%d", &searchID) != 1)
    {
        printf("Invalid asset ID.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < count; i++)
    {
        if (assetIDs[i] == searchID)
        {
            printf("\n---- Asset Found ----\n");
            printf("Asset ID: %d\n", assetIDs[i]);
            printf("Asset Name: %s\n", assetNames[i]);
            printf("Asset Type: %s\n", assetTypes[i]);
            printf("Purchase Value: %.2f\n", purchaseValues[i]);
            printf("Department: %s\n", departments[i]);
            printf("Condition: %s\n", conditions[i]);
            return;
        }
    }

    printf("Asset with ID %d not found.\n", searchID);
}

void assetMenu()
{
    int choice;

    do
    {
        printf("\n========== ASSET MANAGEMENT ==========" );
        printf("\n1. Add Asset");
        printf("\n2. Display Assets");
        printf("\n3. Search Asset by ID");
        printf("\n4. Return to Main Menu");
        printf("\n====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please try again.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                assetCount = addAsset(assetIDs, assetNames, assetTypes,
                                     purchaseValues, assetDepartments,
                                     assetConditions, assetCount);
                break;

            case 2:
                displayAssets(assetIDs, assetNames, assetTypes,
                              purchaseValues, assetDepartments,
                              assetConditions, assetCount);
                break;

            case 3:
                searchAsset(assetIDs, assetNames, assetTypes,
                            purchaseValues, assetDepartments,
                            assetConditions, assetCount);
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}









































































































































































































































































































































