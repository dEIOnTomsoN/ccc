#include <stdio.h>

// Function prototypes
int computeSum(int arr[], int size);
void printReverse(int arr[], int size);
void sortDescending(int arr[], int size);

int main() {
    int u,arr[5],i;
    printf("Enter size of the array : ");
    scanf("%d",&u);

    printf("Enter elements in array : ");
    for(i=0; i<u; i++)
    {
        scanf("%d",&arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = computeSum(arr, size);
    printf("Sum of all elements: %d\n", sum);

    printf("Array in reverse order: ");
    printReverse(arr, size);
    printf("\n");

    sortDescending(arr, size);
    printf("Array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int computeSum(int arr[], int size) {
    int sum = 0;
    int *ptr = arr;

    for (int i = 0; i < size; i++) {
        sum += *ptr;
        ptr++;
    }

    return sum;
}

void printReverse(int arr[], int size) {
    int *ptr = arr + size - 1;

    for (int i = 0; i < size; i++) {
        printf("%d ", *ptr);
        ptr--;
    }
}

void sortDescending(int arr[], int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                // Swap the elements using pointers
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
