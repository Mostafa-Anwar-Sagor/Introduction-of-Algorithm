#include <stdio.h>
#include <string.h>

int main()
{
    // Employee data
    int employeeID[] = {101, 102, 103, 104};
    float employeeSalary[] = {40000.0, 55000.0, 50500.0, 75000.0};
    char employeeNames[][50] = {"Kim Yee", "John Reynolds", "Elena Gonzales", "Jim O'Shea"};

    // Input employee ID
    int inputID;
    printf("Enter employee ID: ");
    scanf("%d", &inputID);

    // Input employee name
    char inputName[50];
    printf("Enter employee name: ");
    fgets(inputName, sizeof(inputName), stdin);
    // Remove newline character if present
    inputName[strcspn(inputName, "\n")] = '\0';

    // Find corresponding salary
    int found = 0;
    float salary;

    for (int i = 0; i < 4; ++i)
    {
        if (strcmp(inputName, employeeNames[i]) == 0 && inputID == employeeID[i])
        {
            salary = employeeSalary[i];
            found = 1;
            break;
        }
    }

    // Display result
    if (found)
    {
        printf("Salary for %s (ID %d): $%.2f\n", inputName, inputID, salary);
    }
    else
    {
        printf("Employee not found.\n");
    }

    return 0;
}
