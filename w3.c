#include <stdio.h>

int main()
{
    int A[10][10],B[10][10],i,j,m,n;
    int row, col, isSymmetric;

    printf("Enter no. of rows :: ");
        scanf("%d", &m);
        printf("\nEnter no. of cols :: ");
        scanf("%d",&n);
        printf("\nEnter values to the matrix :: \n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                 printf("\nEnter a[%d][%d] value :: ",i,j);
                 scanf("%d", &A[i][j]);
        }
    }

    /*
     * Finds the transpose of matrix A
     */
    for(row=0; row<m; row++)
    {
        for(col=0; col<n; col++)
        {
            /* Stores each row of matrix A to each column of matrix B */
            B[row][col] = A[col][row];
        }
    }

    /*
     * Checks whether matrix A is equal to its transpose or not
     */
    isSymmetric = 1;
    for(row=0; row<m && isSymmetric; row++)
    {
        for(col=0; col<n; col++)
        {
            /* If matrix A is not equal to its transpose */
            if(A[row][col] != B[row][col])
            {
                isSymmetric = 0;
                break;
            }
        }
    }

    /*
     * If the given matrix is Symmetric Matrix.
     */
    if(isSymmetric==1)
    {
        printf("\nThe given matrix is Symmetric matrix : : \n\n");

        for (i = 0; i < m; ++i)
        {
        for (j = 0; j < n; ++j)
        {
            printf("\t%d", A[i][j]);
        }
        printf("\n\n");
    }
    }
    else
    {
        printf("\nThe given matrix is not Symmetric matrix.\n");
    }

    printf("The upper triangular matrix is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                printf("%d ", A[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("The lower triangular matrix is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                printf("%d ", A[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("The diagonal elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i][i]);
    }
 
}
