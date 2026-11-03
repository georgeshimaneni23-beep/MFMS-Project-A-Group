#include <stdio.h>
#include <string.h>

#include "assets.h"
#include "reports.h"
#include "utils.h"

static int registerIDs[MAX_ASSETS];
static char registerNames[MAX_ASSETS][50];
static char registerTypes[MAX_ASSETS][30];
static float registerValues[MAX_ASSETS];
static char registerDepartments[MAX_ASSETS][30];
static char registerConditions[MAX_ASSETS][30];
static int assetCount = 0;

int addAsset(int assetIDs[], char assetNames[][50], char assetTypes[][30],
             float purchaseValues[], char departments[][30],
             char conditions[][30], int count)
{
    int id;
    int i;

    if (count >= MAX_ASSETS)
    {
        printf("Cannot add more assets. Maximum limit reached.\n");
        return count;
    }

    printf("\n---- Add New Asset ----\n");
    id = readPositiveInt("Enter Asset ID: ");

    for (i = 0; i < count; i++)
    {
        if (assetIDs[i] == id)
        {
            printf("Asset ID already exists. Asset not added.\n");
            return count;
        }
    }

    assetIDs[count] = id;

    readText("Enter Asset Name: ", assetNames[count], 50);
    readText("Enter Asset Type (e.g. Vehicle, Computer, Building): ",
             assetTypes[count], 30);
    purchaseValues[count] = readNonNegativeFloat("Enter Purchase Value: N$");
    readText("Enter Department: ", departments[count], 30);
    readText("Enter Condition (e.g. Good, Fair, Poor): ", conditions[count], 30);

    printf("Asset added successfully!\n");
    return count + 1;
}

void displayAssets(int assetIDs[], char assetNames[][50], char assetTypes[][30],
                   float purchaseValues[], char departments[][30],
                   char conditions[][30], int count)
{
    int i;

    if (count == 0)
    {
        printf("No assets to display.\n");
        return;
    }

    printf("\n---- Asset List ----\n");

    for (i = 0; i < count; i++)
    {
        printf("Asset ID: %d\n", assetIDs[i]);
        printf("Asset Name: %s\n", assetNames[i]);
        printf("Asset Type: %s\n", assetTypes[i]);
        printf("Purchase Value: N$%.2f\n", purchaseValues[i]);
        printf("Department: %s\n", departments[i]);
        printf("Condition: %s\n", conditions[i]);
        printf("--------------------\n");
    }
}

void searchAsset(int assetIDs[], char assetNames[][50], char assetTypes[][30],
                 float purchaseValues[], char departments[][30],
                 char conditions[][30], int count)
{
    int searchID;
    int i;

    if (count == 0)
    {
        printf("No assets to search.\n");
        return;
    }

    searchID = readPositiveInt("Enter Asset ID to search: ");

    for (i = 0; i < count; i++)
    {
        if (assetIDs[i] == searchID)
        {
            printf("\n---- Asset Found ----\n");
            printf("Asset ID: %d\n", assetIDs[i]);
            printf("Asset Name: %s\n", assetNames[i]);
            printf("Asset Type: %s\n", assetTypes[i]);
            printf("Purchase Value: N$%.2f\n", purchaseValues[i]);
            printf("Department: %s\n", departments[i]);
            printf("Condition: %s\n", conditions[i]);
            return;
        }
    }

    printf("Asset with ID %d not found.\n", searchID);
}

void showAssetReport(void)
{
    assetReport(registerIDs, registerNames, registerTypes, registerValues,
               registerDepartments, registerConditions, assetCount);
}

void assetMenu(void)
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

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                assetCount = addAsset(registerIDs, registerNames, registerTypes,
                                      registerValues, registerDepartments,
                                      registerConditions, assetCount);
                break;

            case 2:
                displayAssets(registerIDs, registerNames, registerTypes,
                              registerValues, registerDepartments,
                              registerConditions, assetCount);
                break;

            case 3:
                searchAsset(registerIDs, registerNames, registerTypes,
                            registerValues, registerDepartments,
                            registerConditions, assetCount);
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }

    } while (choice != 4);
}
