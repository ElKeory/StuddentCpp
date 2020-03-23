#include <stdio.h>
#include <stdlib.h>

int gauss(const int n, const double** m, const double* b, double* x);
int jordan(const int n, const double** m, const double* b, double* x);

int main()
{
    int n;
    printf("Print the matrix size.\n");
    scanf_s("%i", &n);
    double** m = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        m[i] = (double*)malloc(n * sizeof(double));

    printf("Enter the number.\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a[%i][%i] = ", i + 1, j + 1);
            scanf_s("%lf", &m[i][j]);
        }

    double* b = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        printf("b[%i] = ", i + 1);
        scanf_s("%lf", &b[i]);
    }

    double* x = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        x[i] = 0;

    gauss(n, m, b, x);
    printf("Метод Гаусса.\n");
    for (int i = 0; i < n; i++)
        printf("x[%i] = %lf\n", i + 1, x[i]);

    jordan(n, m, b, x);
    printf("Метод Гаусса.\n");
    for (int i = 0; i < n; i++)
        printf("x[%i] = %lf\n", i + 1, x[i]);

    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
    free(b);
    free(x);

    return 0;
}

int gauss(const int n, double** m, const double* b, double* x)
{
    return 0;
}

int jordan(const int n, const double** m, const double* b, double* x)
{
    return 0;
}