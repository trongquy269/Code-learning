#include <stdio.h>

#define MAX 100

typedef int element;

void Read_data(element a[], int *n)
{
    FILE *f;
    f = fopen("data.txt", "r");
    int i = 0;
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

void Printf_data(element a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Swap(element *a, element *b)
{
    element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(element a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                Swap(&a[i], &a[j]);
            }
        }
    }
}

int main()
{
    element a[MAX];
    int n;
    Read_data(a, &n);
    printf("Before sort: ");
    Printf_data(a, n);
    SelectionSort(a, n);
    printf("After sort: ");
    Printf_data(a, n);
    return 0;
}