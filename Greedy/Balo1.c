#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char Ten_DoVat[25];
    float TL, GT, DG;
    int PA;
} Balo;

Balo *Read_data(float *w, int *n)
{
    FILE *f;
    int i = 0;
    f = fopen("Balo1.txt", "r");
    Balo *b;
    b = (Balo *)malloc(sizeof(Balo));
    if (f == NULL)
    {
        printf("The file can't be opened!\n");
    }
    else
    {
        fscanf(f, "%f", w);
        while(!feof(f))
        {
            fscanf(f, "%f %f", &b[i].TL, &b[i].GT);
            fgets(b[i].Ten_DoVat, 25, f);
            b[i].Ten_DoVat[strlen(b[i].Ten_DoVat) - 1] = '\0';
            b[i].DG = b[i].GT / b[i].TL;
            b[i].PA = 0;
            i++;
            b = (Balo *)realloc(b, sizeof(Balo) * (i + 1));
        }
    }
    *n = i;
    fclose(f);
    return b;
}

void Print_data(Balo *b, float w, int n)
{
    float Total_weight = 0;
    printf("|---|------------------|-----|-----|-----|---|\n");
    printf("|%-3s|    %-10s    | %-4s| %-4s| %-4s|%-3s|\n", "STT", "TEN DO VAT", "TL", "GT", "DG", "SL");
    printf("|---|------------------|-----|-----|-----|---|\n");
    for (int i = 0; i < n; i++)
    {
        printf("|%-3d|%-18s|%5.2f|%5.2f|%5.2f|%3d|\n", i + 1, b[i].Ten_DoVat, b[i].TL, b[i].GT, b[i].DG, b[i].PA);
        printf("|---|------------------|-----|-----|-----|---|\n");
        Total_weight += b[i].PA * b[i].TL;
    }
    printf("\nWeight of backpack: %.2f\n", w);
    printf("Total weight of items: %.2f\n", Total_weight);
    printf("Remaining weight in the backpack: %.2f\n", w - Total_weight);
}

void Swap(Balo *a, Balo *b)
{
    Balo temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(Balo *b, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i].DG < b[j].DG)
            {
                Swap(&b[i], &b[j]);
            }
        }
    }
}

void Greedy(Balo *b, float w, int n)
{
    SelectionSort(b, n);
    for (int i = 0; i < n; i++)
    {
        b[i].PA = w / b[i].TL;
        w -= b[i].PA * b[i].TL;
    }
}

int main()
{
    Balo *b;
    int n;
    float w;
    b = Read_data(&w, &n);
    Greedy(b, w, n);
    Print_data(b, w, n);
    return 0;
}