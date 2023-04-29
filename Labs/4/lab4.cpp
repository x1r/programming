#include <stdio.h>
#include <math.h>
/* указатели на функции */

double f1(int);
int f2(void);
int f3(void);

int main()
{
  int(*pf2)(void);
  pf2 = f2;
  pf2();
  int(*pfMas[])(void) = { f2, f3 };
  for (int i = 0; i < 2; i++) pfMas[i]();

  int Mas[3] = { (int)f1, (int)f2, (int)f3 };
  double(*pf1)(int);
  pf1 = (double(*)(int))Mas[0];
  double m = pf1(5);
  printf("\n m = %f \n", m);

  for (int i = 0; i < 3; i++)
  {
    pf2 = (int(*)())Mas[i];
    pf2();
  }

  double(*ptrf)(double) = cos;
  printf("\n %f \n", ptrf(0.7));

  double(*ptrf1)(double) = sin;
  printf("\n %f \n", ptrf1(0.7));

  return 0;
}

double f1(int a)
{
  printf("\n double f1(int a)");
  double b = a;
  return b;
}

int f2()
{
  printf("\n int f2(void)");
  return 200;
}

int f3(void)
{
  printf("\n int f3(void)");
  return 300;
}