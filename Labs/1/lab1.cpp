#include <iostream>
#include <cstdio>

int main() {
    //1) Вычисление степени двойки
    int a = 32;
    if ((a - 1) & a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    //2) Ввод массива с клавиатуры
    char mas[21];
    int i = 0, count = 0, c, j = 0;
    for (i = 0; (c = getchar()) != '\n'; i++) {
        if (i < 20) {
            mas[j] = c;
            ++j;
        }
    }
    i = 0;
    mas[j] = '\0';
//3) Определение длины массива
    while (mas[i++]) count++;
    printf("%d\n", count);
    printf("%d\n", i); //4) Разворот массива
    i = 0;
    j = count - 1;
    char tmp;
    printf("%s\n", mas);
    while (i < j) {
        tmp = mas[i];
        mas[i++] = mas[j];
        mas[j--] = tmp;
    }
    printf("%s\n",
           mas);
    //5) С использованием указателей
    // Счёт длинны массива
    char *pmas = mas;
    count = 0;
    while (*pmas++) count++;
    printf("%d\n", count);
    printf("%c\n", *(pmas - 2));
    // Реверс симвлольного массива
    pmas -= 2;
    char *pmas1 = mas;
    for (int k = 0; k < count / 2; k++) {
        tmp = *pmas1;
        *pmas1++ = *pmas;
        *pmas-- = tmp;
    }

    printf("%s\n", mas);
    return 0;
}