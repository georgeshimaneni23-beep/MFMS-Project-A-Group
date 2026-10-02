#include <stdio.h>
#include <string.h>
#include "employees.h"

int addEmployee(int ids[], char names[] [50], char departments[][30],
                 float basicSalaries[], float housingAllowances[], float transportAllowances[],
                 int count) {

 if (count >= MAX_EMPLOYEES) {
    printf("Cannot add more employees. Maximum limit reached.\n");
    return count;
 }
 int id;
 char name[50];
 char department[30];
 float basic, housing, transport;

 printf("Enter Employee ID: ");
 if (scanf("%d", &id) != 1) {
    printf("Invalid input for Employee ID.\n");
    return count;
 }
 getchar();
 for (int i = 0; i < count; i++) {
    if (ids[i] == id) {
        printf("Employee ID already exists. Employee not added.\n");
        return count;
    }

 printf("Enter Employee Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("Employee name cannot be empty. Employee not added.\n");
        return count;
    }

    printf("Enter Employee Department: ");
    fgets(department, sizeof(department), stdin);
    department[strcspn(department, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housing);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transport);
    getchar();

    if (basic < 0 || housing < 0 || transport < 0) {
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
                          float basicSalaries[], float housingAllowances[], float transportAllowances[],
                          int count) {

    if (count == 0) {
        printf("No employees to display.\n");
        return;
    } 
    
    for (int i = 0; i < count; i++) {
        printf("Employee ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Department: %s\n", departments[i]);
        printf("Basic Salary: %.2f\n", basicSalaries[i]);
        printf("Housing Allowance: %.2f\n", housingAllowances[i]);
        printf("Transport Allowance: %.2f\n", transportAllowances[i]);
    }
                          }
        
        int searchEmployee(int ids[], char names[][50], char departments[][30],
                           float basicSalaries[], float housingAllowances[], float transportAllowances[],
                           int count, int searchID) {

    for (int i =0; i< count; i++) {
        if(ids[i] == searchID) {
            printf("\nEmployee found!\n");
            printf("Employee ID: %d\n", ids[i]);
            printf("Name: %s\n", names[i]);
            printf("Department: %s\n", departments[i]);
            printf("Basic Salary: %.2f\n", basicSalaries[i]);
            printf("Housing Allowance: %.2f\n", housingAllowances[i]);
            printf("Transport Allowance: %.2f\n", transportAllowances[i]);
            return i;
    }                        
    
}   
     
    printf("\nEmployee with ID %d not found.\n", searchID);
    return -1;
    
    }

    float calculateSalary(float basic, float housing, float transport) {
        return basic + housing + transport;
    }
                   
                 
