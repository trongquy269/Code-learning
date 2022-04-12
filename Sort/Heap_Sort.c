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

void Print_ReverseData(element a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void PushDown(element a[], int n, int root)
{
    if (root < n )
    { 
        int left_child = 2 * root + 1;
        int right_child = 2 * root + 2;
        if (left_child < n)
        {
            // Adjest left child
            if ((a[root] > a[left_child]) && (a[left_child] <= a[right_child]) && (right_child < n))
            {
                Swap(&a[root], &a[left_child]);
                PushDown(a, n, left_child);
            }
            // Adjest right child
            else if ((a[root] > a[right_child]) && (a[left_child] > a[right_child]) && (right_child < n))
            {
                Swap(&a[root], &a[right_child]);
                PushDown(a, n, right_child);
            }
            // Adjest left child
            else if (a[root] > a[left_child])
            {
                Swap(&a[root], &a[left_child]);
            }
        }
    }
}

void HeapSort(element a[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        PushDown(a, n, i);
    }
    for (int i = n - 1; i >= 2; i--)
    {
        Swap(&a[0], &a[i]);
        PushDown(a,  i, 0);
    }
    Swap(&a[0], &a[1]);
}

int main()
{
    element a[MAX];
    int n;
    Read_data(a, &n);
    printf("Before sort: ");
    Print_data(a, n);
    HeapSort(a, n);
    printf("After sort: ");
    Print_ReverseData(a, n);
    return 0;
}