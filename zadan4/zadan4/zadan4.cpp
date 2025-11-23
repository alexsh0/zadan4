#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void inputData(double& x, double& y, double& zn, double& s, int& num) 
{
    printf("Введите x: ");
    scanf_s("%lf", &x);

    printf("Введите y: ");
    scanf_s("%lf", &y);

    printf("Введите начальное значение z: ");
    scanf_s("%lf", &zn);

    printf("Введите шаг изменения z: ");
    scanf_s("%lf", &s);

    printf("Введите количество значений: ");
    scanf_s("%d", &num);
}

void calculateA(double x, double y, double zn, double s, int num, int& count, double res[]) 
{
    for (int i = 0; i < num; i++) 
    {
        double z = zn + i * s;
        res[i] = atan(z) - fabs(y - x);

    }
}
void calculateB(double x, double y, double zn, double s, int num, int& count, double res[]) 
{
    int i = 0;
    while (i < num) 
    {
        double z = zn + i * s;
        if (cos(x) != 0 and fabs(y * z) > 0 and fabs(y * z) != 1) 
        {
            res[i] = tan(x) + 1.0 / log(fabs(y * z));
        }
        i++;
    }
}
void calculateC(double x, double y, double zn, double s, int num, int& count, double res[]) 
{
    int i = 0;
    do 
    {
        double z = zn + i * s;
        if (y * z * z > 0) 
        {
            res[i] = cos(M_PI * x) / sqrt(y * z * z);
        }
        i++;
    } while (i < num);
}

void printResults(double* res, double& s, double& zn, int& num, const char* ABC)
{
    printf("| %5s |  %10s|\n", "z", ABC);
    for (int i = 0; i < num; i++) 
    {
        double z = zn + i * s;
        printf("| %5.0lf | %10.3lf | \n", z, res[i]);
    }
    printf("\n\n\n");
}

int main(int c, char* v[]) 
{
    setlocale(LC_ALL, "Russian");

    double x, y, zn, s;
    int num;

    if (c >= 6) 
    {
        x = atof(v[1]);
        y = atof(v[2]);
        zn = atof(v[3]);
        s = atof(v[4]);
        num = atoi(v[5]);
    }
    else 
    {
        inputData(x, y, zn, s, num);
    }

    int m;
    do 
    {
        printf("Введите номер запроса:\n 1 - Вычислить A\n 2 - Вычислить B\n 3 - Вычислить C\n 0 - Выход\n");
        scanf_s("%d", &m);

        int count = 0;
        double* res = new double[num];

        switch (m) 
        {
        case 1:
            calculateA(x, y, zn, s, num, count, res);
            printResults(res, s, zn, num, "A");
            delete[] res;
            break;

        case 2:
            calculateB(x, y, zn, s, num, count, res);
            printResults(res, s, zn, num, "B");
            delete[] res;
            break;

        case 3:
            calculateC(x, y, zn, s, num, count, res);
            printResults(res, s, zn, num, "C");
            delete[] res;
            break;

        case 0:
            break;
        }
    } while (m != 0);

    return 0;
}