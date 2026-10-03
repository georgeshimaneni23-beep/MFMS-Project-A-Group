#ifndef REPORTS_H
#define REPORTS_H

/* Employee Report */
void employeeReport(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count
);

/* Budget Report */
void budgetReport();

/* Supplier Report */
void supplierReport();

/* Asset Report */
void assetReport(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
);

/* Main Reports Menu */
void reportsMenu();

#endif