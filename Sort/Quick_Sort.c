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

int Pivot(element a[], int left, int right)
{
    element firstKey = a[left];
    int i = left + 1;
    while ((i <= right) && (a[i] == firstKey))
    {
        i++;
    }
    if (i > right)
    {
        return -1;
    }
    else if (a[i] > firstKey)
    {
        return i;
    }
    else
    {
        return (left);
    }
}

int Partition(element a[], int left, int right, element pivot)
{
    int pLeft = left;
    int pRight = right;
    while (pLeft <= pRight)
    {
        while ((a[pLeft] < pivot) && (pLeft < right)) 
        {
            pLeft++;
        }
        while ((a[pRight] >= pivot) && (pRight > left))
        {
            pRight--;
        }
        if (pLeft < pRight)
        {
            Swap(&a[pLeft], &a[pRight]);
        }
    }
    return pLeft;
}

void QuickSort(element a[], int left, int right)
{
    element pivot;
    int pPartition, pivotIndex;
    pivotIndex = Pivot(a, left, right);
    if (pivotIndex != -1)
    {
        pivot = a[pivotIndex];
        pPartition = Partition(a, left, right, pivot);
        QuickSort(a, left, pPartition - 1);
        QuickSort(a, pPartition, right);
    }
}

int main()
{
    element a[MAX];
    int n;
    Read_data(a, &n);
    printf("Before sort: ");
    Print_data(a, n);
    QuickSort(a, 0, n - 1);
    printf("After sort: ");
    Print_data(a, n);
    return 0;
}