#include <stdio.h>

#define MAX 100

typedef int element;

void Read_data(element a[], int *n)
{
    FILE *f;
    int i = 0;
    f = fopen("data.txt", "r");
    if (f == NULL)
    {
        printf("The file can't be opened!\n");
    }
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d", &a[i]);
            i++;
        }
    }
    fclose(f);
    *n = i;
}

void Print_data(element a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertionSort(element a[], int n)
{
    int j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > temp))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    element a[MAX];
    int n;
    Read_data(a, &n);
    printf("Before sort: ");
    Print_data(a, n);
    InsertionSort(a, n);
    printf("After sort: ");
    Print_data(a, n);
    return 0;
}