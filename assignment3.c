/*
 * Course: COMP 2510
 * Assignment: Assignment 3
 * Name: Ibrahim Abudalah
 * Student ID: A01166585
 * Date: 2025-11-20
 *
 * Description:
 * This program contains two projects:
 * Project 1 demonstrates Insertion Sort and Selection Sort.
 * Project 2 demonstrates a generic swap function using void pointers.
 * A main menu loop allows the user to run either project repeatedly.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Project 1 – Sorting
*/
// Method to print the array
void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion Sort Algorithm
void insertionSort(int *arr, int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j   = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort Algorithm
void selectionSort(int *arr, int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < minIndex[arr])
            {
                minIndex = j;
            }
        }

        temp          = arr[i];
        arr[i]        = arr[minIndex];
        arr[minIndex] = temp;
    }
}






/**
* Project 2 – Generic Swap
*
* This function swaps the values stored at two memory locations. It works
* for any data type because it operates on raw bytes.
*/

void genericSwap(void *a, void *b, size_t size)
{
    // Allocate temporary buffer of required size
    void *temp = malloc(size);

    // Check for allocation failure
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Copy 'a' into temporary storage
    memcpy(temp, a, size);

    // Copy 'b' into 'a'
    memcpy(a, b, size);

    // Copy saved value from 'temp' into 'b'
    memcpy(b, temp, size);

    // Free temporary buffer
    free(temp);
}

/*
* Program Driver
*/

int main(void)
{
    int choice = 0;

    while (choice != 3)
    {
        printf("1. Project 1 – Sorting Algorithms\n");
        printf("2. Project 2 – Generic Swap Function\n");
        printf("3. Exit Program\n");
        printf("Select one of the above programs to run: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            /**
             * Project 1 excution
             */
            int n, i, algorithm;

            printf("\nProject 1: Sorting\n");
            printf("Enter number of elements: ");
            scanf("%d", &n);

            int *arr = malloc(n * sizeof(int));

            if (arr == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter %d integers:", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("\nUnsorted array: ");
            printArray(arr, n);

            printf("\nChoose sorting algorithm:\n");
            printf("1. Insertion Sort\n");
            printf("2. Selection Sort\n");
            printf("Enter choice: ");
            scanf("%d", &algorithm);

            if (algorithm == 1)
            {
                insertionSort(arr, n);
                printf("\nSorted using Insertion Sort:\n");
            }
            else if (algorithm == 2)
            {
                selectionSort(arr, n);
                printf("\nSorted using Selection Sort:\n");
            }
            else
            {
                printf("Invalid choice.\n");
                free(arr);
                continue;
            }

            printArray(arr, n);
            free(arr);
        }
        else if (choice == 2)
        {
            /**
                  Project 2 excution
            */

            int type;
            printf("\nProject 2: Generic Swap\n");
            printf("Select a data type:\n");
            printf("1. Integer\n");
            printf("2. Float\n");
            printf("3. String\n");
            printf("Enter choice: ");
            scanf("%d", &type);
            getchar();

            if (type == 1)
            {
                int a, b;

                printf("Enter integer A: ");
                scanf("%d", &a);
                printf("Enter integer B: ");
                scanf("%d", &b);

                printf("\nBefore swap: A = %d, B = %d\n", a, b);
                genericSwap(&a, &b, sizeof(int));
                printf("After swap:  A = %d, B = %d\n", a, b);
            }
            else if (type == 2)
            {
                float a, b;

                printf("Enter float A: ");
                scanf("%f", &a);
                printf("Enter float B: ");
                scanf("%f", &b);

                printf("\nBefore swap: A = %.2f, B = %.2f\n", a, b);
                genericSwap(&a, &b, sizeof(float));
                printf("After swap:  A = %.2f, B = %.2f\n", a, b);
            }
            else if (type == 3)
            {
                char a[100];
                char b[100];

                printf("Enter string A: ");
                fgets(a, sizeof(a), stdin);
                a[strcspn(a, "\n")] = '\0';

                printf("Enter string B: ");
                fgets(b, sizeof(b), stdin);
                b[strcspn(b, "\n")] = '\0';

                printf("\nBefore swap: A = %s | B = %s\n", a, b);
                genericSwap(a, b, 100);
                printf("After swap:  A = %s | B = %s\n", a, b);
            }
            else
            {
                printf("Invalid type.\n");
            }
        }
        else if (choice == 3)
        {
            printf("\nExiting program.\n");
        }
        else
        {
            printf("Invalid selection. Try again.\n");
        }
    }

    return 0;
}
