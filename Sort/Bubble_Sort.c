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

void Swap(element *a, element *b)
{
    element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(element a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                Swap(&a[j - 1], &a[j]);
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
    Print_data(a, n);
    BubbleSort(a, n);
    printf("After sort: ");
    Print_data(a, n);
    return 0;
}