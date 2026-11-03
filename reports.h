#ifndef REPORTS_H
#define REPORTS_H

void employeeReport(
    int ids[],
    char names[][50],
    char departments[][30],
    float basicSalaries[],
    float housingAllowances[],
    float transportAllowances[],
    int count
);

void budgetReport();
void supplierReport();

void assetReport(
    int assetIDs[],
    char assetNames[][50],
    char assetTypes[][30],
    float purchaseValues[],
    char departments[][30],
    char conditions[][30],
    int count
);

void reportsMenu();

#endif
