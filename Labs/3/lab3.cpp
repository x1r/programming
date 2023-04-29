#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
    static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    // порядковый номер дня в году по месяцу и числу
    int year = 2022, month, day;
    int yearday = 0;
    int vysokosnyi, i;
    // проверка года на високосность
    vysokosnyi = ((year % 4) == 0 && (year % 100 != 0 || year % 400 == 0)); 
    month = 9;
    day = 16;
    // проверка на корректность ввода месяца и дня
    if (month < 1 || month > 12) 
        return -1;
    if (day < 1 || day > daytab[vysokosnyi][month])
        return -1;
    // считаем номер дня в году
    for (i = 1; i < month; i++) 
        // прибавляем к day количество дней в i-месяце
        day += daytab[vysokosnyi][i]; 
    yearday = day;
    printf("%d\n", yearday);
    // месяц и число по порядковому номеру дня в году
    vysokosnyi = ((year % 4) == 0 && (year % 100 != 0 || year % 400 == 0));
    yearday = 259;
    // указатели на месяц и день
    int *pmonth = &month; 
    int *pday = &day;
    // считаем количество месяцев, вычитая из номера дня в году количество дней в i-месяцах
    for (i = 1; i < 12 && yearday > daytab[vysokosnyi][i]; i++) 
        yearday -= daytab[vysokosnyi][i];
    if (i > 12 && yearday > daytab[vysokosnyi][i])
    { 
        // проверка на ошибку
        *pmonth = -1;
        *pday = -1;
    }
    else
    { 
        // присваивание указателям значения номеров месяца и дня
        *pmonth = i;
        *pday = yearday;
    }
    printf("%d\n", *pmonth); // вывод номеров месяца и дня
    printf("%d\n", *pday);
    // порядковый номер в году по месяцу и числу с использованием указателей
    yearday = 0; // ввод данных
    month = 9;
    day = 16;
    char *p;
    vysokosnyi = ((year % 4) == 0 && (year % 100 != 0 || year % 400 == 0));
    // пока существует вычитаемый месяц, к количеству дней прибавлять количество дней в месяце, но которое указывает указатель *p
    p = daytab[vysokosnyi]; 
    while (--month)
        day += *++p;
    yearday = day;
    printf("%d\n", yearday);
    // месяц и число по порядковому номеру дня в году с использованием указателей
    yearday = 259;
    month = 0;
    day = 0;
    char *p1;
    vysokosnyi = ((year % 4) == 0 && (year % 100 != 0 || year % 400 == 0));
    // присваивание значений указателям
    p1 = daytab[vysokosnyi]; 
    pmonth = &month;
    pday = &day;
    // пока общее количество дней больше дней в месяце, на который указывает указатель,
    // вычитаем из общего количества дней кол-во дней в месяце, на который указывает указатель
    while (yearday > *++p1)          
        yearday -= *p1;              
    // считаем номер месяца и дня, делаем вывод
    *pmonth = p1 - *(daytab + vysokosnyi); 
    *pday = yearday;
    printf("%d\n", *pmonth);
    printf("%d\n", *pday);
    return 0;
}