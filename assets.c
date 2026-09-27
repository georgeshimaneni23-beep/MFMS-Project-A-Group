#include <stdio.h>
#include <string.h>
#include "assets.h"

int addAsset(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
) {
    if (count >= MAX_ASSETS) {
        printf("Cannot add more assets. Maximum limit reached.\n");
        return count;
    }

    printf("\n---- Add New Asset ---\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assetIDs[count]); 
    
    getchar(); 

    printf("Enter Asset Name: ");
    fgets(assetNames[count], 50, stdin);
    assetNames[count][strcspn(assetNames[count], "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assetTypes[count], 30, stdin);
    assetTypes[count][strcspn(assetTypes[count], "\n")] = '\0';

    printf("Enter Purchase Value: ");
    scanf("%f", &purchaseValues[count]);

    while (purchaseValues[count] < 0) {
        printf("Purchase value cannot be negative. Please enter a valid value: ");
        printf("Enter Purchase Value: ");
        scanf("%f", &purchaseValues[count]);
    }
    
    getchar();

    printf("Enter Department: ");
    fgets(departments[count], 30, stdin);
    departments[count][strcspn(departments[count], "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(conditions[count], 30, stdin);
    conditions[count][strcspn(conditions[count], "\n")] = '\0';

    printf("Asset added successfully!\n");

    return count + 1;
}

void displayAssets(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
) {
    if (count == 0) {
        printf("No assets to display.\n");
        return;
    }

    printf("\n---- Asset List ----\n");
    for (int i = 0; i < count; i++) {
        printf("Asset ID: %d\n", assetIDs[i]);
        printf("Asset Name: %s\n", assetNames[i]);
        printf("Asset Type: %s\n", assetTypes[i]);
        printf("Purchase Value: %.2f\n", purchaseValues[i]);
        printf("Department: %s\n", departments[i]);
        printf("Condition: %s\n", conditions[i]);
        printf("--------------------\n");
    }
}

void searchAsset(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
) {
    if (count == 0) {
        printf("No assets to search.\n");
        return;
    }

    int searchID;
    printf("Enter Asset ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (assetIDs[i] == searchID) {
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