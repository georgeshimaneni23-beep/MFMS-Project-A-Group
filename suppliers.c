#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;


/* Read a valid positive integer */
int getPositiveInteger(char message[])
{
    char input[50];
    char *end;
    long number;

    while (1)
    {
        printf("%s", message);

       if (fgets(input, sizeof(input), stdin) == NULL)
        {
            exit(0);
        }

        number = strtol(input, &end, 10);

        if (end == input || (*end != '\n' && *end != '\0'))
        {
            printf("Invalid input. Please enter numbers only.\n");
            continue;
        }

        if (number <= 0)
        {
            printf("Value must be greater than 0.\n");
            continue;
        }

        return (int)number;
    }
}


/* Check if text is empty or contains only spaces */
int isEmpty(char text[])
{
    int i;

    if (strlen(text) == 0)
    {
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            return 0;
        }
    }

    return 1;
}


/* Add a supplier */
void addSupplier()
{
    int i;
    int newID;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n========== ADD SUPPLIER ==========\n");

    /* Supplier ID */
    while (1)
    {
        newID = getPositiveInteger("Enter Supplier ID: ");

        for (i = 0; i < supplierCount; i++)
        {
            if (suppliers[i].supplierID == newID)
            {
                printf("Supplier ID already exists. Please enter another ID.\n");
                newID = 0;
                break;
            }
        }

        if (newID != 0)
        {
            break;
        }
    }

    suppliers[supplierCount].supplierID = newID;


    /* Supplier Name */
    do
    {
        printf("Enter Supplier Name: ");

        fgets(suppliers[supplierCount].name,
              sizeof(suppliers[supplierCount].name), stdin);

        suppliers[supplierCount].name[
            strcspn(suppliers[supplierCount].name, "\n")
        ] = '\0';

        if (isEmpty(suppliers[supplierCount].name))
        {
            printf("Supplier name cannot be empty.\n");
        }

    } while (isEmpty(suppliers[supplierCount].name));


    /* Email */
    do
    {
        printf("Enter Email: ");

        fgets(suppliers[supplierCount].email,
              sizeof(suppliers[supplierCount].email), stdin);

        suppliers[supplierCount].email[
            strcspn(suppliers[supplierCount].email, "\n")
        ] = '\0';

        if (isEmpty(suppliers[supplierCount].email))
        {
            printf("Email cannot be empty.\n");
        }

    } while (isEmpty(suppliers[supplierCount].email));


    /* Telephone */
    do
    {
        printf("Enter Telephone Number: ");

        fgets(suppliers[supplierCount].telephone,
              sizeof(suppliers[supplierCount].telephone), stdin);

        suppliers[supplierCount].telephone[
            strcspn(suppliers[supplierCount].telephone, "\n")
        ] = '\0';

        if (isEmpty(suppliers[supplierCount].telephone))
        {
            printf("Telephone number cannot be empty.\n");
        }

    } while (isEmpty(suppliers[supplierCount].telephone));


    /* Town / Location */
    do
    {
        printf("Enter Town/Location: ");

        fgets(suppliers[supplierCount].location,
              sizeof(suppliers[supplierCount].location), stdin);

        suppliers[supplierCount].location[
            strcspn(suppliers[supplierCount].location, "\n")
        ] = '\0';

        if (isEmpty(suppliers[supplierCount].location))
        {
            printf("Location cannot be empty.\n");
        }

    } while (isEmpty(suppliers[supplierCount].location));


    supplierCount++;

    printf("\nSupplier added successfully!\n");
}


/* Display all suppliers */
void displaySuppliers()
{
    int i;

    printf("\n========== SUPPLIER LIST ==========\n");

    if (supplierCount == 0)
    {
        printf("No suppliers have been registered.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID : %d\n", suppliers[i].supplierID);
        printf("Name        : %s\n", suppliers[i].name);
        printf("Email       : %s\n", suppliers[i].email);
        printf("Telephone   : %s\n", suppliers[i].telephone);
        printf("Location    : %s\n", suppliers[i].location);
    }
}


/* Search supplier by ID */
void searchSupplier()
{
    int searchID;
    int i;
    int found = 0;

    printf("\n========== SEARCH SUPPLIER BY ID ==========\n");

    searchID = getPositiveInteger("Enter Supplier ID: ");

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == searchID)
        {
            printf("\nSupplier Found!\n");
            printf("Supplier ID : %d\n", suppliers[i].supplierID);
            printf("Name        : %s\n", suppliers[i].name);
            printf("Email       : %s\n", suppliers[i].email);
            printf("Telephone   : %s\n", suppliers[i].telephone);
            printf("Location    : %s\n", suppliers[i].location);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSupplier not found.\n");
    }
}


/* Search supplier by name */
void searchSupplierByName()
{
    char searchName[100];
    int i;
    int found = 0;

    printf("\n========== SEARCH SUPPLIER BY NAME ==========\n");

    do
    {
        printf("Enter Supplier Name: ");

        fgets(searchName, sizeof(searchName), stdin);

        searchName[strcspn(searchName, "\n")] = '\0';

        if (isEmpty(searchName))
        {
            printf("Supplier name cannot be empty.\n");
        }

    } while (isEmpty(searchName));


    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].name, searchName) == 0)
        {
            printf("\nSupplier Found!\n");
            printf("Supplier ID : %d\n", suppliers[i].supplierID);
            printf("Name        : %s\n", suppliers[i].name);
            printf("Email       : %s\n", suppliers[i].email);
            printf("Telephone   : %s\n", suppliers[i].telephone);
            printf("Location    : %s\n", suppliers[i].location);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\nSupplier not found.\n");
    }
}


/* Supplier Management Menu */
void supplierMenu()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Search Supplier by Name\n");
        printf("5. Exit Supplier Management\n");
        printf("====================================\n");

        choice = getPositiveInteger("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                searchSupplierByName();
                break;

            case 5:
                printf("\nReturning to main menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 5.\n");
        }

    } while (choice != 5);
}