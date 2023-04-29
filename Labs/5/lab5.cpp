#include <stdio.h>
#include <stdlib.h>
// Динамическое выделение памяти
void vvod(double ***, int, int);

void swapRows(double **, int, int);
void swapColumns(double **, int, int);
void printMatrix(double **, int, int);
void bubbleSort(double **, int, int);
void quickSort(double **, int, int, int);

int main(){
    // одна функция - обмена строк между собой
    // выделить память под одномерный массив указателей
    // создаем указатель на указатель
    // выделяем с помощью каллок память
    // вторая функция - обмена столбцов между собой
    // третья функция - сортировка пузырьком
    printf("Programm started\n");
    double **b;
    int n = 3, m = 3;
    vvod(&b,n,m);
    for (int i = 0; i <n; i++){
        for (int j = 0; j < m; j++){
            b[i][j] = i+j*i;
            // printf("%lf %lf %lf ",i,j, b[i][j]);
        }
    }

    printMatrix(b,n,m);
    // row swapping
    swapRows(b, 0,1);
    printMatrix(b, n, m);
    swapRows(b, 0,1);
    printMatrix(b, n, m);
    // column swapping
    swapColumns(b, 0,1);
    printMatrix(b, n, m);
    swapColumns(b, 0,1);
    printMatrix(b, n, m);
    // bubble sort by sum of rows
    bubbleSort(b, n, m);
    printMatrix(b, n, m);

    for (int i = 0; i < n; i++){
        free(b[i]);
    }
    printf("Programm finished\n");
    return 0;
}

void vvod(double *** a, int index1, int index2){
    *a = (double **) calloc(index1, sizeof(double *));
    for (int i = 0; i < index1; i++)
        (*a)[i] = (double *) calloc(index2, sizeof(double));
}

void swapRows(double **a, int index1, int index2){
    double *temp;
    temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

void swapColumns(double **a, int index1, int index2){
    double *temp;
    temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

void printMatrix(double **a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bubbleSort(double **a, int n, int m){
    double sumi, sumj;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sumi = 0;
            sumj = 0;
            for (int k = 0; k < m; k++){
                sumi += a[i][k];
                sumj += a[j][k];
            }
            if (sumi < sumj){
                swapRows(a, i, j);
            }
        }
    }
}

void quickSort(double **a, int left, int right, int n, int m){
    double sumi, sumj;
    while (left < right){
        int i = left, j = right;
        double pivot = a[(left + right) / 2];
        while (i <= j){
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j){
                swapRows(a, i, j);
                i++;
                j--;
            }
        }
        if (left < j) quickSort(a, left, j, n, m);
        left = i;
    }
}