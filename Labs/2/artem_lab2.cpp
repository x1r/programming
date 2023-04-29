#include <stdio.h>
#include <math.h>
#include <limits.h>
int main()
{
    // 1 part
    /*знаковые числа*/
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int max = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("signed char max = %d\n", ((char)((unsigned char)~0 >> 1)));
    printf("signed short max = %d\n", ((short)((unsigned short)~0 >> 1)));
    printf("signed int max = %d\n", ((int)((unsigned int)~0 >> 1)));
    printf("signed int max = %f\n", pow(2, 31) - 1);
    printf("(char)((unsigned char)~0>>1) = %d\n", (char)((unsigned char)~0 >> 1));
    /* (unsigned char)~0 = 255 (11111111 в двоичной системе счисления), то есть 8 битов, заполненные единицами.        
    После побитового сдвига вправо на 1 бит (>> 1) получим 01111111 в двоичной системе счисления.        
    После приведения двоичного числа 01111111 к char получим 127 - максимальное число, которое может хранить тип char.*/
    // перевод шестнадцатеричной строки в целое число
    // 0x0123456789ABCDEF
    char hex[21] = "0xAb1c2ef";
    int i = 0;
    if (hex[i] == '0')
    {
        i++;
        if (hex[i] == 'x' || hex[i] == 'X')
        {
            i++;
        }
    }
    int result = 0;
    for (; hex[i] != '\0'; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            result = result * 16 + (hex[i] - '0');
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            result = result * 16 + (hex[i] - 'A' + 10);
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            result = result * 16 + (hex[i] - 'a' + 10);
        }
        if (result < 0)
        {
            result = (INT_MAX + result) + 1;
            result++;
        }
        i++;
    }
    printf("Hex number %s is %d", hex, result);
    if (i == sizeof(hex))
    {
        printf("%d", result);
    }
    return 0;
}
