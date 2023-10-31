/*　「コンピュータプログラミング」川添 良幸, 青山 智夫 (著)より引用
 *  乗算合同法による乱数生成
 *　Linear congruential generator for pseudo-random numbers　
 */

#include <stdio.h>

float rd00() {
  /* (-1,1)区間　乗算合同法による一様乱数発生ルーチン
   * LCG based uniform pseudo-random number generation
   * Standard values for modulus, multiplier and increment
   * static unsigned long int base=12345u;
   * static unsigned long int mult=913u;
   * static unsigned int add=1u;
   */
  static unsigned long int base = 123456789u;
  static unsigned long int mult = 9137715u;
  static unsigned int add = 1u;
  float w;

  base = base * mult + add;
  w = base;
  w = w * 4.656612874e-10 - 1.0;

  return w;
}

int main(int argc, char *argv[]) {
  /* Defining variabels */
  double sum;
  float w;
  int i, lmt;
  char cc;

  /* IO */
  printf("How many random numbers to generate?\n");
  scanf("%d", &lmt);

  /* Main LCG loop */
  sum = 0.0;
  for (int i = 0; i < lmt; i++) {
    w = rd00();
    sum += w;
    printf("%10.f\n", w);
    if (i % 10 == 9)
      cc = getchar();
  }

  /* Show average */
  sum /= lmt;
  printf("avg = %f\n", sum);

  return 0;
}
