#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  long unsigned int maiorAB;

  maiorAB = (a + b + abs(a - b))/2;

  long unsigned int maiorAB2;
  maiorAB2 = (maiorAB + c + abs(maiorAB - c))/2;

  printf("%ld eh o maior\n", maiorAB2);
  return 0;
}
