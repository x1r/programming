#include <cstdio>
#include <cmath>

long f1(long);

long f2();

long f3();

long f1(long a) {
    printf("\n double f1(int a)");
    long m = a;
    return m;
}

long f2() {
    printf("\n int f2(void)");
    return 200;
}

long f3() {
    printf("\n int f3(void)");
    return 300;
}

int main() {
    long (*pf2)();
    pf2 = f2;
    pf2();
    long (*pfMas[])(void) = {f2, f3};
    for (int i = 0; i < 2; i++)
        pfMas[i]();

    long Mas[3] = {(long)f1, (long)f2, (long)f3}; // комментарии (32 размер указателя)

    // call f1
    long (*pf1)(long);
    pf1 = (long (*)(long)) Mas[0];

    long k = pf1(5);
    printf("%ld\n", k);

    for (long Ma : Mas) {
        long (*pfpf2)();
        pfpf2 = (long (*)()) Ma;
        pfpf2();
    }


    //sin
    long (*pfT)(double);
    pfT = reinterpret_cast<long (*)(double)>(sin);

    printf("\n%ld", pfT(0.8));

    //cos
    pfT = reinterpret_cast<long (*)(double)>(cos);
    printf("\n%ld", pfT(0.8));

    return 0;
}

