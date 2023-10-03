#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

// Define the CUSTOMER structure
struct CUSTOMER {
    char firstName[50];
    char middleName[50];
    char lastName[50];
    int accNo;
    char accType[3]; // SB, FD, or CURR
    float balance;
};

// Function prototypes
void searchCustomerByAccNo(struct CUSTOMER customers[], int n, int targetAccNo);
float getBalanceByAccNo(struct CUSTOMER customers[], int n, int targetAccNo);
void displayCustomersAlphabetically(struct CUSTOMER customers[], int n);
void listFDCustomers(struct CUSTOMER customers[], int n);

int main() {
    struct CUSTOMER customers[MAX_CUSTOMERS];
    int n;

    // Input the number of customers
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    // Input customer details
    for (int i = 0; i < n; i++) {
        printf("Enter details for customer #%d:\n", i + 1);
        printf("First Name: ");
        scanf("%s", customers[i].firstName);
        printf("Middle Name: ");
        scanf("%s", customers[i].middleName);
        printf("Last Name: ");
        scanf("%s", customers[i].lastName);
        printf("Account Number: ");
        scanf("%d", &customers[i].accNo);
        printf("Account Type (SB, FD, or CURR): ");
        scanf("%s", customers[i].accType);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }

    int choice;
    int targetAccNo;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search for a customer by Account Number\n");
        printf("2. Retrieve balance by Account Number\n");
        printf("3. Display customers sorted by first name\n");
        printf("4. List FD customers\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the Account Number to search: ");
                scanf("%d", &targetAccNo);
                searchCustomerByAccNo(customers, n, targetAccNo);
                break;
            case 2:
                printf("Enter the Account Number to retrieve balance: ");
                scanf("%d", &targetAccNo);
                float balance = getBalanceByAccNo(customers, n, targetAccNo);
                if (balance >= 0)
                    printf("Balance: %.2f\n", balance);
                else
                    printf("Customer not found.\n");
                break;
            case 3:
                displayCustomersAlphabetically(customers, n);
                break;
            case 4:
                listFDCustomers(customers, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void searchCustomerByAccNo(struct CUSTOMER customers[], int n, int targetAccNo) {
    for (int i = 0; i < n; i++) {
        if (customers[i].accNo == targetAccNo) {
            printf("Customer found:\n");
            printf("Name: %s %s %s\n", customers[i].firstName, customers[i].middleName, customers[i].lastName);
            printf("Account Number: %d\n", customers[i].accNo);
            printf("Account Type: %s\n", customers[i].accType);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Customer not found.\n");
}

float getBalanceByAccNo(struct CUSTOMER customers[], int n, int targetAccNo) {
    for (int i = 0; i < n; i++) {
        if (customers[i].accNo == targetAccNo) {
            return customers[i].balance;
        }
    }
    return -1.0; // Customer not found
}

void displayCustomersAlphabetically(struct CUSTOMER customers[], int n) {
    // Sort customers by first name
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(customers[j].firstName, customers[j + 1].firstName) > 0) {
                // Swap customers[j] and customers[j + 1]
                struct CUSTOMER temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }

    printf("List of customers sorted by first name:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %s\n", customers[i].firstName, customers[i].middleName, customers[i].lastName);
    }
}

void listFDCustomers(struct CUSTOMER customers[], int n) {
    printf("List of FD customers:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(customers[i].accType, "FD") == 0) {
            printf("Name: %s %s %s\n", customers[i].firstName, customers[i].middleName, customers[i].lastName);
            printf("Account Number: %d\n", customers[i].accNo);
            printf("Balance: %.2f\n", customers[i].balance);
        }
    }
}
