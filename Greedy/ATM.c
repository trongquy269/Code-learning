#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int Tien_so;
    char Tien_chu[25];
    int Phuong_an;
} Tien;

Tien *Read_data(int *n)
{
    FILE *f;
    int i = 0;
    Tien *money;
    money = (Tien *)malloc(sizeof(Tien));
    f = fopen("ATM.txt", "r");
    if (f == NULL)
    {
        printf("The file can't be opened!\n");
    }
    else
    {
        while(!(feof(f)))
        {
            fscanf(f, "%d", &money[i].Tien_so);
            fgets(money[i].Tien_chu, 25, f);
            money[i].Tien_chu[strlen(money[i].Tien_chu)] = '\0';
            money[i].Phuong_an = 0;
            i++;
            money = (Tien *)realloc(money, (i + 1) * sizeof(Tien));
        }
    }
    *n = i;
    fclose(f);
    return money;
}

void Print_data(Tien *money, int n, int sotienrut)
{
    int tien_chua_rut = sotienrut;
    int tien_da_rut = 0;
    printf("|----------------|--------|-----|----------------|\n");
    printf("|%-16s|%-8s|%-5s|%-16s|\n", "So tien chua rut", "Menh gia", "So to", " So tien da rut");
    printf("|----------------|--------|-----|----------------|\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("|%-16d", tien_chua_rut);
        printf("|%-8d", money[i].Tien_so);
        printf("|%-5d", money[i].Phuong_an);
        tien_da_rut += money[i].Phuong_an * money[i].Tien_so;
        printf("|%-16d|", tien_da_rut);
        printf("\n");
        tien_chua_rut = sotienrut - tien_da_rut;
    }
    printf("|----------------|--------|-----|----------------|\n");
    printf("\nSo tien can rut: %d\n", sotienrut);
    printf("So tien da rut: %d\n", tien_da_rut);
    for (int i = n - 1; i >= 0; i--)
    {
        if (money[i].Phuong_an > 0)
        {
            printf("%d to menh gia %d -%s\n", money[i].Phuong_an, money[i].Tien_so, money[i].Tien_chu);
        }
    }
    printf("So tien chua rut: %d", tien_chua_rut);
}

void Greedy(Tien *money, int n, int sotienrut)
{
    for (int i = n - 1; i >= 0; i--)
    {
        while (sotienrut - money[i].Tien_so >= 0)
        {
            sotienrut -= money[i].Tien_so;
            money[i].Phuong_an++;
        }
    }
}

int main()
{
    Tien *money;
    int n;
    int sotienrut;
    money = Read_data(&n);
    printf("Nhap so tien can rut: ");
    scanf("%d", &sotienrut);
    Greedy(money, n, sotienrut);
    Print_data(money, n, sotienrut);
    return 0;
}