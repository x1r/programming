#include <stdio.h>


int main(){
    // Число - степень двойки?
    int a = 32;
    if (a&(a-1)){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    // Индексное выражение, длина строки, реверс строки
    char mas[21];
    char c;
    int length = 0;
    for (int l = 0; (c=getchar())!= '\n'; l++){
        if (l<20){
            mas[length++] = c;
        }
    }
    mas[length] = '\0';
    int i = 0, count = 0;
    while(mas[i++]) count++;
    printf("%d\n", count);
    printf("%d\n", i); 
    printf("%s\n", mas);
    //Реверс строки
    i = 0;
    int j = count - 1;
    char tmp;
    while (i < j){
        tmp = mas[i];
        mas[i++] = mas[j];
        mas[j--] = tmp;
    }
    printf("%s\n", mas);
    // Указатели - длина строки и ревес строки
    char *pmas = mas;
    count = 0;
    while (*pmas++) count++;
    printf("%d\n", count);
    printf("%c\n", *(pmas-2));
    //Реверс строки
    pmas -= 2;
    char *pmas1 = mas;
    for (int k = 0; k < count/2; k++){
        tmp = *pmas1;
        *pmas1++ = *pmas;
        *pmas-- = tmp;
    }
    printf("%s\n", mas);
    return 0;   
}