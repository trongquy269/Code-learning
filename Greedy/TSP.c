#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float do_dai;
    int first;
    int last;
} cung;

void Read_data(cung a[], int *n)
{
    FILE *f;
    int k = 0;
    f = fopen ("TSP.txt", "r");
    if (f == NULL)
    {
        printf("The file can't be opened!\n");
    }
    else
    {
        fscanf(f, "%d", n);
        for (int i = 0; i < *n; i++)
        {
            for (int j = 0; j < *n; j++)
            {
                if (j > i)
                {
                    a[k].first = i;
                    a[k].last = j;
                    fscanf(f, "%f", &a[k].do_dai);
                    k++;
                }
                else
                {
                    float temp;
                    fscanf(f, "%f", &temp);
                }
            }
        }
    }
    fclose(f);
}

void Print_data(cung a[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%c %c = %.2f\n", a[i].first + 97, a[i].last + 97, a[i].do_dai);
    }
}

void Swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(cung a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1].do_dai > a[j].do_dai)
            {
                Swap(&a[j - 1].do_dai, &a[j].do_dai);
            }
        }
    }
}

int Dinh_cap_3(int dinh, cung kiemtra)
{
    
}

void Greedy(cung a[], int n, cung kiemtra)
{
    for (int i = 0; i < n; i++)
    {
        if ((Dinh_cap_3(a[i].first, kiemtra) && Dinh_cap_3(a[i].last, kiemtra)) != 1)
        {

        }
    }
}

int main()
{
    cung a[100];
    int n;
    Read_data(a, &n);
    BubbleSort(a, n * (n - 1) / 2);
    Print_data(a, n * (n - 1) / 2);
    return 0;
}