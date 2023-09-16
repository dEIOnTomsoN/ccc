#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

// Define the structure for employee details
struct Employee {
    char name[50];
    int empCode;
    float salary;
};

// Function to read and store employee details into a file
void storeEmployeeDetails(struct Employee employees[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee #%d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Employee Code: ");
        scanf("%d", &employees[i].empCode);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);

        fprintf(file, "%s %d %.2f\n", employees[i].name, employees[i].empCode, employees[i].salary);
    }

    fclose(file);
}

// Function to print employee details by employee code
void printEmployeeDetailsByCode(const char *filename, int targetEmpCode) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        exit(1);
    }

    struct Employee employee;
    int found = 0;

    while (fscanf(file, "%s %d %f", employee.name, &employee.empCode, &employee.salary) != EOF) {
        if (employee.empCode == targetEmpCode) {
            printf("Employee Details:\n");
            printf("Name: %s\n", employee.name);
            printf("Employee Code: %d\n", employee.empCode);
            printf("Salary: %.2f\n", employee.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with Employee Code %d not found.\n", targetEmpCode);
    }

    fclose(file);
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees. Please enter a value between 1 and %d.\n", MAX_EMPLOYEES);
        return 1;
    }

    // Input and store employee details in a file
    storeEmployeeDetails(employees, n, "employee_details.txt");

    int targetEmpCode;
    printf("Enter the employee code to search: ");
    scanf("%d", &targetEmpCode);

    // Print employee details by employee code
    printEmployeeDetailsByCode("employee_details.txt", targetEmpCode);

    return 0;
}
