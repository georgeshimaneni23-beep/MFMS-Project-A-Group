#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

int addAsset(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
);

void displayAssets(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
);

void searchAsset(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
);

void assetMenu();

#endif